//--------------------------------------------------------------
// File name:    loader.c
//--------------------------------------------------------------
// dlanor: This subprogram has been modified to minimize the code
// dlanor: size of the resident loader portion. Some of the parts
// dlanor: that were moved into the main program include loading
// dlanor: of all IRXs and mounting pfs0: for ELFs on hdd.
// dlanor: Another change was to skip threading in favor of ExecPS2
/*==================================================================
==                                          ==
==  Copyright(c)2004  Adam Metcalf(gamblore_@hotmail.com)    ==
==  Copyright(c)2004  Thomas Hawcroft(t0mb0la@yahoo.com)    ==
==  This file is subject to terms and conditions shown in the    ==
==  file LICENSE which should be kept in the top folder of    ==
==  this distribution.                            ==
==                                          ==
==  Portions of this code taken from PS2Link:                ==
==              pkoLoadElf                        ==
==              wipeUserMemory                    ==
==              (C) 2003 Tord Lindstrom (pukko@home.se)    ==
==              (C) 2003 adresd (adresd_ps2dev@yahoo.com)    ==
==  Portions of this code taken from Independence MC exploit    ==
==              tLoadElf                        ==
==              LoadAndRunHDDElf                    ==
==              (C) 2003 Marcus Brown <mrbrown@0xd6.org>    ==
==                                          ==
==================================================================*/
#include "tamtypes.h"
#include "debug.h"
#include "kernel.h"
#include "iopcontrol.h"
#include "sifrpc.h"
#include "loadfile.h"
#include "string.h"
#include "iopheap.h"
#include "errno.h"
#include "ps2sdkapi.h"
//--------------------------------------------------------------

//--------------------------------------------------------------
// Redefinition of init/deinit libc:
//--------------------------------------------------------------
// DON'T REMOVE is for reducing binary size.
// These funtios are defined as weak in /libc/src/init.c
//--------------------------------------------------------------
void _libcglue_init() {}
void _libcglue_deinit() {}
void _libcglue_args_parse(int argc, char **argv) {}

DISABLE_PATCHED_FUNCTIONS();
DISABLE_EXTRA_TIMERS_FUNCTIONS();
PS2_DISABLE_AUTOSTART_PTHREAD();

//--------------------------------------------------------------
// End of data declarations
//--------------------------------------------------------------
// Start of function code:
//--------------------------------------------------------------
// Clear user memory
// PS2Link (C) 2003 Tord Lindstrom (pukko@home.se)
//         (C) 2003 adresd (adresd_ps2dev@yahoo.com)
//--------------------------------------------------------------
static void wipeUserMem(void)
{
    int i;
    for (i = 0x100000; i < GetMemorySize(); i += 64) {
        asm volatile(
            "\tsq $0, 0(%0) \n"
            "\tsq $0, 16(%0) \n"
            "\tsq $0, 32(%0) \n"
            "\tsq $0, 48(%0) \n" ::"r"(i));
    }
}

//--------------------------------------------------------------
// End of func:  void wipeUserMem(void)
//--------------------------------------------------------------
// *** MAIN ***
//--------------------------------------------------------------
int main(int argc, char *argv[])
{
    static t_ExecData elfdata;
    // Definindo o caminho do ELF diretamente no código
    char *target = "mass0:/BOOT/BOOT1.ELF";
    char *path = "hdd0:"; // Modifique aqui se necessário
    int ret;

    // Initialize
    SifInitRpc(0);
    wipeUserMem();

    // Writeback data cache before loading ELF.
    FlushCache(0);
    ret = SifLoadElf(target, &elfdata);
    if (ret == 0) {
        char *args[1];

        args[0] = path;

        // Reset IOP se o caminho começar com "hdd"
        if (strncmp(path, "hdd", 3) == 0 && (path[3] >= '0' && path[3] <= ':')) {
            while (!SifIopReset("", 0)) {};
            while (!SifIopSync()) {};
        }

        SifExitRpc();

        FlushCache(0);
        FlushCache(2);

        ExecPS2((void *)elfdata.epc, (void *)elfdata.gp, 1, args);
        return 0;
    } else {
        SifExitRpc();
        return -ENOENT;
    }
}
//--------------------------------------------------------------
// End of func:  int main(int argc, char *argv[])
//--------------------------------------------------------------
// End of file:  loader.c
//--------------------------------------------------------------
