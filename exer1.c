#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *arquivo = fopen("files/exer1.txt", "w");
	char string[100];
	
	if(!arquivo){
		printf("Erro na abertura do arquivo"); 
		return;	
	}

	printf("Digite uma string:");
	fgets(string, 100, stdin);
	fputs(string, arquivo);
	
	fclose(arquivo);
	if(!arquivo) printf("\n\nopa\n\n");

}
