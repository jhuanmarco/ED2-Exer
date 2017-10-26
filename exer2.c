#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *arquivo = fopen("files/exer1.txt", "r");
	char string[100];
	
	if(!arquivo){
		printf("Erro na abertura do arquivo ou arquivo ainda não criado\n"); 
		return;	
	}

	printf("String lida:");
	fgets(string, 100, arquivo);
	printf(" %s", string);
	
	fclose(arquivo);

}
