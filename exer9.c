#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	char nome[20];
	int idade;
	char curso[50];
	float nota1, nota2, media;
	int totalAula, faltas;
	float freq;
} ALUNO;


void inserirAluno(){
	FILE *arquivo = fopen("files/alunos2.txt", "ab");
	ALUNO novo;
	
	if(!arquivo) {
		printf("Erro na abertura do arquivo");
		return;
	}

	getchar();
	printf("Digite o nome do aluno: ");
	fgets(novo.nome, 20, stdin);
		
	printf("Digite a idade do aluno: ");
	scanf(" %d", &(novo.idade));
		
	printf("Digite o curso do aluno: ");
	getchar();
	fgets(novo.curso, 50, stdin);		
		
	printf("Digite a nota 1 do aluno: ");	
	scanf(" %f", &novo.nota1);
		
	printf("Digite a nota 2 do aluno: ");	
	scanf(" %f", &novo.nota2);
	
	printf("Digite a quantidade de aulas do curso: ");	
	scanf(" %d", &novo.totalAula);
		
	printf("Digite a qnt de faltas do aluno: ");	
	scanf(" %d", &novo.faltas);
	
	novo.freq = 100 - (novo.faltas * 100)/ (float) novo.totalAula;
	novo.media = (novo.nota1 + novo.nota2) / 2;
	
	fwrite(&novo, sizeof(ALUNO), 1, arquivo);
	
	fclose(arquivo);

}

void printaAlunos(){
	FILE *arquivo = fopen("files/alunos2.txt", "rb");
	ALUNO novo;

	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		printf("\nAluno %s", novo.nome);
		printf("Idade %d", novo.idade);
		printf("\nCurso %s", novo.curso);
		printf("Media %.2f\n", novo.media);
		printf("Faltas %d\n", novo.faltas);
		printf("Frequencia %.2f\n", novo.freq);
	
	}
	
	fclose(arquivo);
}

void printaAprovados(){
	FILE *arquivo = fopen("files/alunos2.txt", "rb");
	ALUNO novo;

	printf("\nAPROVADOS\n");
	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		if(novo.media >= 7 && novo.freq >= 75){
			printf("\nAluno %s", novo.nome);
			printf("Idade %d", novo.idade);
			printf("\nCurso %s", novo.curso);
			printf("Media %.2f\n", novo.media);
			printf("Faltas %d\n", novo.faltas);
			printf("Frequencia %.2f\n", novo.freq);
		}
	}
	
	fclose(arquivo);
}

void printaReprovados(){
	FILE *arquivo = fopen("files/alunos2.txt", "rb");
	ALUNO novo;

	printf("\nREPROVADOS\n");
	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		if(novo.media < 7 || novo.freq < 75){
			printf("\nAluno %s", novo.nome);
			printf("Idade %d", novo.idade);
			printf("\nCurso %s", novo.curso);
			printf("Media %.2f\n", novo.media);
			printf("Faltas %d\n", novo.faltas);
			printf("Frequencia %.2f\n", novo.freq);
		}
	}
	
	fclose(arquivo);
}

void listaTudo(){
	FILE *arquivo = fopen("files/alunos2.txt", "rb");
	ALUNO novo;

	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		printf("\nAluno %s", novo.nome);
		printf("Idade %d", novo.idade);
		printf("\nCurso %s", novo.curso);
		printf("Media %.2f\n", novo.media);
		printf("Faltas %d\n", novo.faltas);
		printf("Frequencia %.2f\n", novo.freq);
		if(novo.media >= 7 && novo.freq >= 75){
			printf("ALUNO APROVADO\n");
		} else {
			printf("ALUNO REPROVADO\n");
		}
	
	}
	
	fclose(arquivo);
}

void printaCondicao(){
	int nota;
	FILE *arquivo = fopen("files/alunos2.txt", "rb");
	ALUNO novo;

	printf("\nDigite o valor minimo da media para impressao: ");
	scanf(" %d", &nota);

	while(fread(&novo, sizeof(ALUNO), 1, arquivo)){
		if(novo.media >= nota){
			printf("\nAluno %s", novo.nome);
			printf("Idade %d", novo.idade);
			printf("\nCurso %s", novo.curso);
			printf("Media %.2f\n", novo.media);
			printf("Faltas %d\n", novo.faltas);
			printf("Frequencia %.2f\n", novo.freq);
		}
	}
	
	fclose(arquivo);


}

void main(){
	FILE *arquivo = NULL;
	ALUNO novo;
	int check = 0, option;
	
	
	do{	
		printf("\nMENU\n1 - Criar arquivo\n2 - Inserir dados\n3 - Listar todos os dados\n4 - Listar aprovados\n5 - Listar reprovados\n6 - Listar alunos e dados\n7 - Listar alunos com nota acima de...\n0 - Sair\n");
		scanf(" %d", &option);
	
		switch(option){
			case 1:
				if(check) {
					printf("\nArquivo já criado\n");
					break;
				}
				arquivo = fopen("files/alunos2.txt", "wb");
				fclose(arquivo);
				check = 1;
				printf("\nArquivo criado\n");
			break;
			case 2:
				if(check == 0) {
					printf("\nArquivo ainda não criado, vá para opcao 1\n");
					break;
				}
				
				inserirAluno();
			break;
			case 3:
				if(check == 0) {
					printf("\nArquivo ainda não criado, vá para opcao 1\n");
					break;
				}
				printaAlunos();
			break;
			case 4:
				if(check == 0) {
					printf("\nArquivo ainda não criado, vá para opcao 1\n");
					break;
				}
				printaAprovados();
			break;
			case 5:
				if(check == 0) {
					printf("\nArquivo ainda não criado, vá para opcao 1\n");
					break;
				}
				printaReprovados();
			break;
			case 6:
				if(check == 0) {
					printf("\nArquivo ainda não criado, vá para opcao 1\n");
					break;
				}
				listaTudo();
			break;
			case 7:
				if(check == 0) {
					printf("\nArquivo ainda não criado, vá para opcao 1\n");
					break;
				}
				printaCondicao();
			break;	
			
		}
	}while(option != 0);
	
	

}
