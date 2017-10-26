#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	int cod;
	char nome[20];
	int idade;
	char curso[50];
	float nota1, nota2, media;
} ALUNO;

void main(){
	FILE *arquivo;
	char string[100];
	ALUNO novo;
	
	arquivo = fopen("files/alunos.txt", "rb");
	if(!arquivo){
		printf("Erro na abertura");
		return;
	}
	
	printf("APROVADOS\n");
	
	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		if(novo.media >= 7){
			printf("\nAluno %d", novo.cod);
			printf("\nNome %s", novo.nome);
			printf("Idade %d", novo.idade);
			printf("\nCurso %s", novo.curso);
			printf("Media %.2f\n", novo.media);
		}
	}
		
	rewind(arquivo);
	
	printf("\nREPROVADOS\n");
	
	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		if(novo.media < 7){
			printf("\nAluno %d", novo.cod);
			printf("\nNome %s", novo.nome);
			printf("Idade %d", novo.idade);
			printf("\nCurso %s", novo.curso);
			printf("Media %.2f\n", novo.media);
		}
	}	

	fclose(arquivo);
	
	

}
