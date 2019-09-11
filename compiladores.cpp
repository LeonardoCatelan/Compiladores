#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 40

main(){
	FILE *arquivo;
	
	int i = 0;
	char *palavras[tamanho];
	char line[tamanho];
	
	
	arquivo = fopen("arquivo.txt", "r");
	
	if(arquivo == NULL)
		printf("Arquivo em branco\n");
	else
		printf("Arquivo aberto\n");
		
	system("pause");
	system("cls");
	
	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		palavras[i] = strdup(line);
		i++;
	}
	
	i = 0;
	
	do{
		if(i == 0){
			printf("%s\n", palavras[i]);
			i++;
		}else{
			i++;
		}
		printf("%s\n", palavras[i]);
	}while(palavras[i] != "  ");
	
	do{
		
	}while(palavras[i] != "  ");
	
	
	fclose(arquivo);
	
	
	
}
