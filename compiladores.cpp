#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 40
#define array 15

//Definindo struct de indicadores (lista de strings neste caso)
struct reg{
	 char ind[array];
};

main(){
	FILE *arquivo;
	
	struct reg identificadores[tamanho];
	//=======DECLARAÇÃO DE VARIÁVEIS====
	int i = 0, x = 0, id = 0;
	char *palavras[tamanho];
	char line[tamanho];
	char *teste;
	int erros[10];
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
/*	
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
*/	
	do{
		if(palavras[i][0] >= 'a' && palavras[i][0] <= 'z')
		{
		//Compara se existe a palavra INT em alguma linha	
			teste = strstr(palavras[i], " ");
			if(teste != NULL){
				erros[x] = i+1;
				x++;
			}else{
				teste = strstr(palavras[i], "_");
				if(teste != NULL){
					erros[x] = i+1;
					x++;
				}else{
					teste = strstr(palavras[i], ".");
					if(teste != NULL){
					erros[x] = i+1;
					x++;
					}else{
						teste = strstr(palavras[i], inteiro);
						if(teste != NULL)
							printf("\n[%i] INT", i+1);
						else{
							//Compara se existe a palavra FLOAT em alguma linha
							teste = strstr(palavras[i], ponto);
							if(teste != NULL)
								printf("\n[%i] FLOAT", i+1);
							else{
								//Compara se existe a palavra DOUBLE em alguma linha
								teste = strstr(palavras[i], dobro);
								if(teste != NULL)
									printf("\n[%i] DOUBLE", i+1);
								else{
									teste = strstr(palavras[i], "real");
									if(teste != NULL)
										printf("\n[%i] REAL", i+1);
										else{
//											for(int j = 0; j < id; j++){
//											if(!strcmp(palavra[i], identificador[j]);)
//											}
											strcpy(identificadores[id].ind, palavras[i]);
											printf("\n[%i] IDENTIFICADOR %i", i+1, id+1);
											id++;
										}
								}
								
							
//									//Compara se existe a palavra // (Comentário) em alguma linha
//									teste = strstr(palavras[i], comentario);
//								//	printf("%s", teste);
//									if(teste != NULL)
//										printf("\n[%i] COMENTARIO", i+1);
//									}
								}
							}
						}
					}
				}	
			}
	i++;
	}while(palavras[i] != NULL);
	

	printf("\nTabela de simbolos:");
	for(i = 0; i < id; i++){
		
		if(identificadores[i].ind != NULL)
			printf("\n%i", i+1);
		printf(" - %s", identificadores[i].ind);
	}
	printf("\nO programa possui erros nas linhas: ");
	for(i = 0; i < x; i++){
		if(erros[i] != NULL)
			printf("%i ", erros[i]);
	}
	
	fclose(arquivo);
	
	
	
}
