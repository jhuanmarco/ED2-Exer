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
	FILE *arquivo = fopen("files/alunos.txt", "ab");
	ALUNO novo;
	
	if(!arquivo) {
		printf("Erro na abertura do arquivo");
		return;
	}

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
	
	printf("Digite a qnt aulas do curso: ");	
	scanf(" %d", &novo.totalAula);
		
	printf("Digite a qnt de faltas do aluno: ");	
	scanf(" %d", &novo.faltas);
	
	novo.freq = (novo.totalAula * 100)/ (float) novo.faltas;
	novo.media = (novo.nota1 + novo.nota2) / 2;
	
	fwrite(&novo, sizeof(ALUNO), 1, arquivo);
	
	fclose(arquivo);

}

void printaAlunos(){
	FILE *arquivo = fopen("files/alunos.txt", "rb");
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

void main(){
	FILE *arquivo = NULL;
	ALUNO novo;
	int check = 0, option;
	
	
	do{	
		printf("MENU\n1 - Criar arquivo\n2 - Inserir dados\n3 - Listar todos os dados\n4 - Listar aprovados\n5 - Listar reprovados\n6 - Listar alunos e dados\n7 - Listar alunos com nota acima de...\n0 - Sair");
		scanf(" %d", &option);
	
		switch(option){
			case 1:
				if(arquivo) {
					printf("Arquivo já criado");
					break;
				}
				arquivo = fopen("files/alunos2.txt", "wb");
				fclose(arquivo);
				check = 1;
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
					printf("Arquivo ainda não criado, vá para opcao 1");
					break;
				}
				printaAlunos();
			break;
			case 4:
				if(check == 0) {
					printf("Arquivo ainda não criado, vá para opcao 1");
					break;
				}
			break;
			case 5:
				if(check == 0) {
					printf("Arquivo ainda não criado, vá para opcao 1");
					break;
				}
			break;
			case 6:
				if(check == 0) {
					printf("Arquivo ainda não criado, vá para opcao 1");
					break;
				}
			break;
			case 7:
				if(check == 0) {
					printf("Arquivo ainda não criado, vá para opcao 1");
					break;
				}
			break;	
		}
	}while(option != 0);
	

	fclose(arquivo);
	
	

}
