#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *arquivo;
	char string[100];
	
	arquivo = fopen("files/exer3.txt", "w");
	if(!arquivo){
		printf("Erro na abertura");
		return;
	}
	printf("Digite a string a ser armazenada:");
	fgets(string, 100, stdin);
	fputs(string, arquivo);
	
	fclose(arquivo);
	
	arquivo = fopen("files/exer3.txt", "r");
	printf("String lida:");
	fgets(string, 100, arquivo);
	printf("%s", string);
	

}
