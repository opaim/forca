#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
void procuraLetra(char *palavra, char letra, char *atual){
	int count;
	
	for(count=0; count < strlen(palavra); count++){
		if(letra == palavra[count])
			atual[count]=letra;
	}
}

void pegaPalavra(FILE *arq, char palavra[30]){
	int key, cod;
    
        key = sorteio(0,9);
	arq = fopen("palavras", "r");
	if(arq == NULL)
		printf("Não foi possível abrir o arquivo");
	else{
			while((fscanf(arq, "%d %s", &cod, palavra))!=EOF){
				if(cod==key)
					break;				
			}
		}
		
	}

//função que gera um número aleatório entre 0 e 9
int sorteio(int min_num, int max_num){
 	    int result=0,low_num=0,hi_num=0;
            if(min_num<max_num)
            {
                low_num=min_num;
                hi_num=max_num+1; // this is done to include max_num in output.
            }else{
                low_num=max_num+1;// this is done to include max_num in output.
                hi_num=min_num;
            }
            srand(time(NULL));
            result = (rand()%(hi_num-low_num))+low_num;
            return result;
}


int main()
{
	int pontos, erros, count;
	char *palavra = (char *) malloc(20*sizeof(char));
	char *atual = (char *) malloc(20*sizeof(char));
	char letra;
	FILE *arq;

	
	pegaPalavra(arq, palavra);
	
	for(count=0; count < strlen(palavra); count++)
		atual[count]='-';

	do
	{	
		system("clear");
		printf("Bem vindo ao Jogo da Forca!!!\n Preparem Seus Pescoços...\n\n");
		for(count=0; count < strlen(atual); count++)
			printf("%c ", atual[count]);
		printf("\nDigite uma letra:\n");
		scanf("%c", &letra);
		procuraLetra(palavra, letra, atual);
	}while(strcmp(palavra, atual) != 0);

	system("clear");
	for(count=0; count < strlen(atual); count++)
		printf("%c ", atual[count]);
	
	printf("\nVocê acertou a palavra! \n");
	return 0;
}
