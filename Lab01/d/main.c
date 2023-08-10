#include <stdio.h>
#include <stdlib.h>

typedef struct alunos{
    float nota[3], media;
}alunos;

int main()
{
    alunos aluno;
    float nota;
    printf("Insira as notas do aluno:\n");
    for(int i = 0; i < 3; i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &aluno.nota[i]);
    }
    aluno.media = (aluno.nota[0]+aluno.nota[1]+aluno.nota[2])/3.0;

    if(aluno.media <= 3){
        printf("REPROVADO(A)\n");
    }else if (aluno.media >= 7){
        printf("APROVADO(A)\n");
    }else{
        printf("EXAME FINAL\n");
        nota = 12.0 - aluno.media;
        printf("Nota minima necessaria eh %.1f\n", nota);
    }
    system("pause");
    return 0;
}
