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
	FILE *arquivo = fopen("files/alunos.txt", "wb");
	ALUNO novo;
	int opt = 0, cod = 0;
	
	if(!arquivo) {
		printf("Erro na abertura do arquivo");
		return;
	}
	
	do{
		
		printf("\nAluno %d\nDigite o nome do aluno: ", ++cod);
		fgets(novo.nome, 20, stdin);
		novo.cod = cod;
		
		printf("Digite a idade do aluno: ");
		scanf(" %d", &(novo.idade));
		
		printf("Digite o curso do aluno: ");
		getchar();
		fgets(novo.curso, 50, stdin);		
		
		printf("Digite a nota 1 do aluno: ");	
		scanf(" %f", &novo.nota1);
		
		printf("Digite a nota 2 do aluno: ");	
		scanf(" %f", &novo.nota2);
		
		novo.media = (novo.nota1 + novo.nota2) / 2;
		
		printf("\n1 - Armazenar outro aluno\n0 - Sair\n");
		scanf(" %d", &opt);
		getchar();
		
		fwrite(&novo, sizeof(ALUNO), 1, arquivo);
	} while (opt);
	

	fclose(arquivo);
	
	

}
