/*
Os alunos de uma turma com numAlunos fizeram numProva provas. 
Leia cada uma das numProva provas feitas por cada um dos numAlunos alunos. 
Imprima na tela: a média de cada aluno, a média da turma e 
o percentual dos alunos que tiveram média maior ou igual a 80%.
*/

#include <stdio.h>

int main(void) {
    int numAlunos, numProvas, numDestaque, numMedia, notaMax;
    float somaAluno, mediaAluno, notaAluno, mediaTurma, percentMedia;
    numDestaque = 0;
    somaAluno = 0;
    mediaAluno = 0;
    printf("=============================================\n\n");
    printf("Digite quantas provas foram aplicadas:\n ->");
    scanf("%d", &numProvas);
    printf("\nDigite a nota máxima da prova:\n ->");
    scanf("%d", &notaMax);
    printf("\nDigite o número de Alunos:\n ->");
    scanf("%d", &numAlunos);


    for(int i = 1; i <= numAlunos; i++){
        printf("\n------------------------------\nAluno %d\n\n", i);
        somaAluno = 0;
        for(int j=1; j<=numProvas; j++){
            printf("• Prova %d\nNota: ", j);
            scanf("%g", &notaAluno);
            printf("\n");
            somaAluno += notaAluno;
        }
        mediaAluno = somaAluno/numProvas;
        printf("-> A média do Aluno %d é: %g\n", i, somaAluno/numProvas);
        if(mediaAluno >= 0.9*notaMax){
            numDestaque++;
        }
        mediaTurma += somaAluno/numAlunos;
    }
    printf("\n\n-->A média da turma é: %g\n", mediaTurma/numAlunos);
    percentMedia = numDestaque*100/numAlunos;
    printf("-->O percentual de alunos com média acima de 80%% é: %g%% de %d\n", percentMedia, numAlunos);
    printf("\n\n=============================================");
    return 0;
}