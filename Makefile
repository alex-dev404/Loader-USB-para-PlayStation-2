EE_CC = gcc
EE_CXX = g++
EE_AR = ar
EE_AS = as
EE_STRIP = strip

# Definições do compilador e do linker
EE_CFLAGS = -D_EE -Os -G0 -Wall
EE_CFLAGS += -fdata-sections -ffunction-sections
EE_LDFLAGS = -Tlinkfile -Wl,-zmax-page-size=128
EE_LDFLAGS += -s -Wl,--gc-sections

# Nome do arquivo binário gerado
EE_BIN = loader.elf

# Objetos que serão gerados
EE_OBJS = loader.o

# Bibliotecas adicionais
EE_LIBS =
ifeq ($(DEBUG),1)
EE_LIBS += -ldebug
endif

# Regras de compilação
all: $(EE_BIN)

$(EE_BIN): $(EE_OBJS)
	$(EE_CC) $(EE_CFLAGS) -o $(EE_BIN) $(EE_OBJS) $(EE_LDFLAGS) $(EE_LIBS)

# Compilação dos arquivos objeto
%.o: %.c
	$(EE_CC) $(EE_CFLAGS) -c $< -o $@

clean:
	rm -f -r $(EE_OBJS) $(EE_BIN)

include $(PS2SDK)/Defs.make
include Rules.make
