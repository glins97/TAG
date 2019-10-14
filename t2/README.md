**Aluno**: Gabriel Lins e Nobrega - 15/0079371



**Funcionalidades**:

1. Gera o DAG a partir dos arquivos *resources/courses* e *resources/requisites*;
2. Mostra uma possível ordenação topológica;
3. Mostra dois caminhos críticos distintos;



**Observações**: 

1. A especificação de que os caminhos devam ser totalmente distintos, sem conter nenhuma matéria em comum, limita o segundo maior caminho crítico a poucas matérias do CIC e libera todas da matemática.
2. Os gráficos estão em .svg, não em .png ou .jpg como esperado. Por motivos desconhecidos, meu graphviz não aceita o argumento -Tpng, que requisita o output em .png. Não tive problemas em abrir arquivos .svg nem no linux nem no windows, então espero que seja ok!
3. Na eventualidade de o senhor não possuir o graphviz, já deixei todos os gráficos preparados. Eles são gerados usando o comando descrito abaixo. Se quiser ver os outputs em .txt, todos são gerados na execução do "out". De qualquer maneira, eles também já estão na pasta.



**Modo de uso**:

*$ make out* : compilará o programa para um output "out" e executará o arquivo.

*$ make svgs* : executa o arquivo "out" e gera os gráficos a partir de comandos no terminal.

*$ ./out* : executa programa que irá gerar outputs para "txt" e "dot", utilizados para gerar os grafos. 



Obrigado!