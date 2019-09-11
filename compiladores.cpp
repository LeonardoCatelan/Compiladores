#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 40

main(){
	FILE *arquivo;
	
	//=======DECLARAÇÃO DE VARIÁVEIS====
	int i = 0;
	char *palavras[tamanho];
	char line[tamanho];
	char *teste;
	const char inteiro[5] = "int";
	const char ponto[10] = "float";
	const char dobro[10] = "double";
	const char comentario[10] = "//";
	//===FIM DECLARAÇÃO DE VARIÁVEIS====
	
	//ABRE O ARQUIVO
	arquivo = fopen("arquivo.txt", "r");
	
	//VERIFICA SE O ARQUIVO ESTÁ PREENCHIDO
	if(arquivo == NULL)
		printf("Arquivo em branco\n");
	else
		printf("Arquivo aberto\n");
		
	system("pause");
	system("cls");
	
	//PERCORRE O ARQUIVO E ADICIONA O CONTEÚDO DO MESMO EM UMA VARIÁVEL
	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		palavras[i] = strdup(line);
		i++;
	}
	
	//SETANDO I PARA 0 PARA REAPROVEITAR O MESMO NOVAMENTE
	i = 0;

//PRINTA TODAS AS PALAVRAS PARA FIM DE TESTE	
	do{
		if(i == 0){
			printf("%s\n", palavras[i]);
			i++;
		}else{
			i++;
		}
		printf("%s\n", palavras[i]);
	}while(palavras[i] == "  ");
	system("cls");
	
	do{
		
		if(palavras[i][0] >= 'a' && palavras[i][0] <= 'z')
		{
		//Compara se existe a palavra IF em alguma linha	
			teste = strstr(palavras[i], inteiro);
			if(teste != NULL)
				printf("\n[%i] INT", i+1);
			else{
				teste = strstr(palavras[i], ponto);
				if(teste != NULL)
					printf("\n[%i] FLOAT", i+1);
				else{
					teste = strstr(palavras[i], dobro);
					if(teste != NULL)
						printf("\n[%i] DOUBLE", i+1);
					else{
						teste = strstr(palavras[i], comentario);
						printf("%s", teste);
						if(teste != NULL)
							printf("\n[%i] COMENTARIO", i+1);
					}
				}
			}
		}
	i++;
			
	}while(palavras[i] != "  ");
	
	
	fclose(arquivo);
	
	
	
}
