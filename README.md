<h1>Loader-USB-para-PlayStation-2</h1>

<p>Este projeto tem como objetivo economizar espaço no memory card do PlayStation 2, permitindo que o Open PS2 Loader (OPL) ou outro ELF que esteja nesse caminho <strong>mass0:/BOOT/OPL.ELF</strong> seja carregado diretamente de um pendrive. Dessa forma, não é necessário ter o ELF do OPL no memory card de 8 MB. O carregador USB que estou desenvolvendo funcionará de maneira semelhante ao <a href="https://github.com/ps2homebrew/wLaunchELF">wLaunchELF</a>, e parte do código foi baseada nele. Este carregador terá uma interface muito mais simples e um tamanho de arquivo reduzido, estimando que meu ELF ocupará cerca de 0,1 MB, enquanto o OPL normalmente pesa em média 1,5 MB.</p>

<h2>Como Usar</h2>
<p>Para utilizar o Loader-USB, siga estas etapas:</p>
<ol>
    <li>Mova a pasta chamada <strong>BOOT</strong> (contendo o arquivo <strong>Loader-USB.ELF</strong>) para a raiz do seu memory card.</li>
    <li>Segure o botão <strong>R1</strong> no controle enquanto liga o videogame.</li>
    <li>Crie a Pasta <strong>BOOT</strong> no <strong>PENDRIVE</strong> e Coloque o <strong>OPL</strong> dentro dela seguindo este caminho <strong>mass0:/BOOT/OPL.ELF</strong>.</li>
</ol>
<p>O caminho completo para o ELF deve ser <strong>mass0:/BOOT/OPL.ELF</strong>. Assim, o carregador poderá localizar e carregar o arquivo corretamente.</p>

<h2>Motivação</h2>
<p>A ideia deste projeto surgiu da necessidade de otimizar o espaço disponível no memory card, que pode ser rapidamente consumido por saves de jogos e outros arquivos. Com essa abordagem, os usuários poderão liberar espaço valioso para salvar mais dados no memory card e tambem podem testar novas versões de apps sem precisar está usando Wlauncher para mover os programas para o memory card toda hora.</p>

<h2>Contribuições</h2>
<p>Esse projeto ainda é muito grande para mim. Apesar de ser algo simples, ainda estou estudando desenvolvimento para o PS2 e abri este repositório com a intenção de guardar a ideia e ir avançando aos poucos. Além disso, também estou aberto a colaborações; caso algum desenvolvedor da comunidade esteja interessado em ajudar, ficaria muito grato. Acredito que a implementação seja fácil para quem já tem experiência, e pode ser que o projeto ainda não tenha recebido atenção devido à escassez de aplicações depois do sistema VLC do OPL, que salva os saves de PS2 em um pendrive como um memory card virtual. No entanto, vejo isso como uma ideia interessante para quem tem o pendrive cheio e o memory card também.</p>

<h2>Licença</h2>
<p>Este projeto está licenciado sob a <a href="https://opensource.org/licenses/GPL-3.0">GPL-3.0 license</a>.</p>

<h2>Recursos</h2>
<p>Para mais informações sobre o Open PS2 Loader, acesse: <a href="https://github.com/ps2homebrew/Open-PS2-Loader">Open PS2 Loader GitHub</a>.</p>
