#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *arquivo;
	char string[100];
	int opt = 1;
	
	arquivo = fopen("files/exer4.txt", "r");
	if(!arquivo){
		printf("Erro na abertura");
		return;
	}
	while(fgets(string, 100, arquivo)){
		printf("String %d : %s", opt++, string);
	
	}

	fclose(arquivo);
	
	

}
