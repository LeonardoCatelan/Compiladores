#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 50
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
	const char caso[10] = "case";
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
//VERIFICAÇÕES PARA 
	do{
		if((palavras[i][0] >= 'a' && palavras[i][0] <= 'z') ||(palavras[i][0] >= 'A' && palavras[i][0] <= 'Z'))
		{
		//COMPARA SE A PALAVRA POSSUI ESPAÇO NA COMPOSIÇÃO, SE SIM = ERRO
			teste = strstr(palavras[i], " ");
			if(teste != NULL){
				erros[x] = i+1;
				x++;
			}else{ 
			//COMPARA SE A PALAVRA TEM _ NA COMPOSIÇÃO, SE SIM = ERRO
				teste = strstr(palavras[i], "_");
				if(teste != NULL){
					erros[x] = i+1;
					x++;
				}else{
					//COMPARA SE A PALAVRA TEM . NA COMPOSIÇÃO, SE SIM = ERRO	
					teste = strstr(palavras[i], ".");
					if(teste != NULL){
					erros[x] = i+1;
					x++;
					}else{
						// COMPARA SE A PALAVRA TEM INT NA COMPOSIÇÃO
						teste = strstr(palavras[i], inteiro);
						if(teste != NULL)
							printf("\n[%i] INT", i+1);
						else{
							//COMPARA SE EXISTE A PALAVRA FLOAT EM ALGUMA LINHA
							teste = strstr(palavras[i], ponto); 
							if(teste != NULL)
								printf("\n[%i] FLOAT", i+1);
							else{
								//COMPARA SE EXISTE A PALAVRA DOUBLE EM ALGUMA LINHA
								teste = strstr(palavras[i], dobro);
								if(teste != NULL)
									printf("\n[%i] DOUBLE", i+1);
								else{
									//COMPARA SE EXISTE A PALAVRA REAL EM ALGUMA LINHA
									teste = strstr(palavras[i], "real");
									if(teste != NULL)
										printf("\n[%i] REAL", i+1);
										else{
											//COMPARA SE EXISTE A PALAVRA BREAK EM ALGUMA LINHA
											teste = strstr(palavras[i], "break");
											if(teste != NULL)
												printf("\n[%i] BREAK", i+1);
											else{
												//COMPARA SE EXISTE A PALAVRA CASE EM ALGUMA LINHA
												teste = strstr(palavras[i], caso);
												if(teste != NULL)
													printf("\n[%i] CASE", i+1);
													else{
														//COMPARA SE EXISTE A PALAVRA CHAR EM ALGUMA LINHA
														teste = strstr(palavras[i], "char");
														if(teste != NULL) 
															printf("\n[%i] CHAR", i+1);
															else{
																//COMPARA SE EXISTE A PALAVRA CONST EM ALGUMA LINHA
																teste = strstr(palavras[i], "const");
																if(teste != NULL)
																	printf("\n[%i] CONST", i+1);
																else{
																	//COMPARA SE EXISTE A PALAVRA CONTINUE EM ALGUMA LINHA
																	teste = strstr(palavras[i], "continue");
																	if(teste != NULL)
																		printf("\n[%i] CONTINUE", i+1);
																	else{
																		//CASO NAO PASSE EM NENHUM IF DOS ANTERIORES, A PALAVRA É ENTENDIDA COMO UM IDENTIFICADOR
																		strcpy(identificadores[id].ind, palavras[i]);
																		printf("\n[%i] IDENTIFICADOR %i", i+1, id+1);
																		id++;
																	}
																}
															}
													}
											}
//											PROTOTIPO IDENTIFICADORES
//											for(int j = 0; j < id; j++){
//											if(!strcmp(palavra[i], identificador[j]);)
//											}
											
										}
									}
								}
							}
						}
					}
				}
			//SE A PALAVRA NAO COMEÇAR COM UMA LETRA ENTRE A E Z, SE VERIFICA SE A MESMA COMEÇA COM UM NÚMERO
			}else if(palavras[i][0] >= '0' && palavras[i][0] <= '9'){
					//COMPARA SE O SEGUNDO DIGITO DA PALAVRA É UM PONTO (EX: 9.99)
					if(palavras[i][1] == '.'){
						//COMPARA SE DEPOIS DO PRIMEIRO DIGITO SENDO ., SE O SEGUNDO OU O TERCEIRO DIGITO É UMA LETRA (EX: 9.A3 | 9.4K)
						if(palavras[i][2] == NULL || (palavras[i][2] >= 'a' && palavras[i][2] <= 'z')){
							erros[x] = i+1;
							x++;
						}else{
							//CASO NÃO SEJA, APROVA SENDO UM NÚMERO REAL (TEM .)
							strcpy(identificadores[id].ind, palavras[i]);
							printf("\n[%i] NUMERO REALhii %i", i+1, id+1);
							id++;
						}
						//COMPARA SE O TERCEIRO DIGITO DO NUMERO É ., E COMPARA SE O QUARTO É UMA LETRA DE A/Z
					}else if(palavras[i][2] == '.' && !(palavras[i][3] >= 'a' && palavras[i][3] <= 'z'))
					//COMPARE ANTERIOR QUE DEU PROBLEMA PORQUE ACEITA '44.'
//						if(palavras[i][3] == NULL || palavras[i][3] == ' '){
//							erros[x] = i+1;
//							x++;
//						}else{
//							strcpy(identificadores[id].ind, palavras[i]);
//							printf("\n[%i] NUMERO REALfon %i", i+1, id+1);
//							id++;
//						}

//					VERIFICA SE O QUARTO CARACTER DO NUMERO NÃO É NULO, EX: (99. )
					if(palavras[i][3] != NULL && palavras[i][4] != NULL){
								strcpy(identificadores[id].ind, palavras[i]);
								printf("\n[%i] NUMERO REALfon %i", i+1, id+1);
								id++;
							}else{
								//SE NÃO PASSAR, O TERCEIRO OU O QUARTO É NULO
								erros[x] = i+1;
								x++;
							}
					else{
						//SE PASSOU ATÉ AQUI, A STRING É UM NUMERO, FEITO CONVERSÃO DELA PARA NUMERO, E VERIFICADO SE É MAIOR QUE 0 E MENOR QUE 100
						int j;
						sscanf(palavras[i], "%d", &j);
						if(j >= 0 && j <= 99)
							printf("\n[%i] INTEIRO", i+1);
						else{
							//SE NÃO PASSAR, É < 0 OU >= 100
							erros[x] = i+1;
							x++;
						}
					}
			}else{
				//SE NAO PASSAR NO TESTE DE LETRA, NEM NO DE NUMERO, FEITO TESTE DE COMENTARIO
				if(palavras[i][0] == '/' && palavras[i][1] == '/'){
					teste = strstr(palavras[i], comentario);
					if(teste != NULL)
						printf("\n[%i] COMENTARIO", i+1);
					else{
						erros[x] = i+1;
						x++;
					}
				}
			}
		i++;
	}while(palavras[i] != NULL);
	
//PRINTA A TABELA DE SIMBOLOS
	printf("\nTabela de simbolos:");
	for(i = 0; i < id; i++){
		
		if(identificadores[i].ind != NULL)
			printf("\n%i", i+1);
		printf(" - %s", identificadores[i].ind);
	}
	//PRINTA AS LINHAS QUE DERAM ERRO
	printf("\nO programa possui erros nas linhas: ");
	for(i = 0; i < x; i++){
		if(erros[i] != NULL)
			printf("%i ", erros[i]);
	}
	//FECHA O ARQUIVO
	fclose(arquivo);
}
