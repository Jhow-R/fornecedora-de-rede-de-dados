#include <stdio.h>
#include <string.h>

#define TAMANHO 500

struct infoCliente {
   char CNPJ[14];
   char atividade_economica[15];
   int consumo_dados;
};
	
typedef struct infoCliente Cliente;	

// Função LE_REGISTROS
int Le_Registros(Cliente clientes[TAMANHO])
{
	int i=0;
	char resp;
	
	do {		
		fflush(stdin);
    	printf("Digite o CNPJ (sem pontuacoes): ");
		gets(clientes[i].CNPJ);
		
		fflush(stdin);
		printf("Digite a atividade_economica: ");
		gets(clientes[i].atividade_economica);
		
		fflush(stdin);
		printf("Digite o consumo de rede de dados: ");
		scanf("%d", &clientes[i].consumo_dados);
		
		fflush(stdin);
		printf("Deseja continuar [S/N]? ");		
		scanf("%c", &resp);
		printf("\n");
		i++;
	}while (i<TAMANHO && resp=='S');
	return i;
}

// Função CONSUMO_SUPERIOR_500
int Consumo_Superior_500(Cliente clientes[], int num, char CNPJ_500[][14]){
	int i;
	int cont = 0;
	for(i = 0; i < num; i++)
  	{			
		if((strcmp(clientes[i].atividade_economica, "agronegocio") == 0) && clientes[i].consumo_dados > 500) { 
			strcpy(CNPJ_500[i], clientes[i].CNPJ);				  
			cont++;	 
  		}
	}
	return cont;
}

// Função MAIOR_E_MENOR_CONSUMO
void Maior_e_Menor_Consumo(Cliente clientes[], int num, Cliente *pos_maior, Cliente *pos_menor){	
	*pos_maior = clientes[0];
	*pos_menor = *pos_maior;
	
	int aux_maior, aux_menor;
	aux_maior = clientes[0].consumo_dados;
	aux_menor = aux_maior;
	
	int i=0;
	for(i = 0; i < num; i++){
		if(clientes[i].consumo_dados > aux_maior){
			aux_maior = clientes[i].consumo_dados;
			*pos_maior = clientes[i];
			
		} else if (clientes[i].consumo_dados < aux_menor){
			aux_menor = clientes[i].consumo_dados;
			*pos_menor = clientes[i];
		}
	}
}

// Função EXBIBE_CNPJ
void Exibe_CNPJ(char CNPJ_500[][14], int cont){
	int i=0;
	printf("Cliente tem atividade agronegocio e consumo superior 500GB: \n");
	for(i = 0; i < cont; i++){		
		printf("%s \n", CNPJ_500[i]);  
	}
}
	
// FUNÇÃO MAIN	
int main(){
	Cliente clientes[TAMANHO];
	int i=0, j=0;
	int num = 0;
	int cont = 0;
	Cliente maior, menor;
	
	num = Le_Registros(clientes);
	
	/* Testar exibição dos dados digitados
	for(i = 0; i < num; i++)
  	{
    	printf("CNPJ do puto %d e %s \n", i, clientes[i].CNPJ);
    	printf("Atividade economica do puto %d e %s \n", i, clientes[i].atividade_economica);
    	printf("Consumo de dados do puto %d e %d GB \n", i, clientes[i].consumo_dados);
    	printf("\n");
  	}
  	  	agronegocio
	*/
	
	char CNPJ_500[num][14];
	
	cont = Consumo_Superior_500(clientes, num, CNPJ_500);
	
	Maior_e_Menor_Consumo(clientes, num, &maior, &menor);
	
	printf("O CNPJ %s tem o maior consumo de dados: %dGB \n", maior.CNPJ, maior.consumo_dados );  
	printf("O CNPJ %s tem o menor consumo de dados: %dGB \n", menor.CNPJ, menor.consumo_dados );  
	printf("\n");
	
	Exibe_CNPJ(CNPJ_500, cont);	  

}
