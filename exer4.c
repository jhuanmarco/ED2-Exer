#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *arquivo;
	char string[100];
	int opt;
	
	arquivo = fopen("files/exer4.txt", "w");
	if(!arquivo){
		printf("Erro na abertura");
		return;
	}
	do{
		printf("Digite a string a ser armazenada:");
		fgets(string, 100, stdin);
		fputs(string, arquivo);
		printf("1 - Digitar outra string\n0 - Encerrar execução\n");
		scanf(" %d", &opt);
		getchar();
	} while (opt);

	fclose(arquivo);
	
	

}
