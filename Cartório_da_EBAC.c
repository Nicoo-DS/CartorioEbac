#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das Strings




int Registro() //Fun��o Respons�vel pelo cadastro de usu�rio no sistema
{
	//Inicio da cria��o de vari�veis/strings
	 char arquivo[40];
     char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40] ;
	 //Final da cria��o de vari�veis/strings
	 
	 printf("Digite o CPF a ser cadastrado: \n"); //Coletando informa��o do usu�rio
	 scanf("%s", cpf); //%s refere-se e salva string
	 
	 strcpy(arquivo, cpf); //Respons�vel por copiar os arquivos das Strings
	 
	 FILE *file; //cria o arquivo
	 file = fopen(arquivo, "w"); //cria o arquivo e abre o arquivo
	 fprintf(file, cpf); //salva o arquivo
	 fclose(file); //fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // Cria e abre o arquivo
	 fprintf(file, ","); // P�e uma , no arquivo
	 fclose(file);
	 
	 printf("Digite o nome a ser cadastrado: \n"); // Coletando informa��o do usu�rio
	 scanf("%s", nome); //%s refere-se e salva string
	 
	 file = fopen(arquivo, "a"); // Cria e abre o arquivo
	 fprintf(file, nome); // Adiciona o texto(Nome) ao arquivo
	 fclose(file); // Fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // Cria e abre o arquivo
	 fprintf(file, "_"); // Adiciona espa�o ao texto (nome_sobrenome) do arquivo
	 fclose(file); // Fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado: \n"); // Coletando informa��o do usu�rio
	 scanf("%s", sobrenome); //%s refere-se e salva string
	 
	 file = fopen(arquivo, "a"); // Cria, abre o arquivo e adiciona o conte�do ao final
	 fprintf(file, sobrenome); // Adiciona o texto(sobrenome) ao arquivo
	 fclose(file); //Fecha o arquivo
	 
	 file = fopen(arquivo, "a"); // Crie, abre o arquivo e adiciona o conte�do ao final
	 fprintf(file, ","); // Adiciona uma virgula ao texto do arquivo
	 fclose(file);
	 
	 printf("Digite o Cargo a ser cadastrado: \n"); // Coletando informa��o do usu�rio
	 scanf("%s", cargo); //%s refere-se e salva string
	 
	 file = fopen(arquivo, "a"); // Cria, abre o arquivo e adicio o arquivo ao final
	 fprintf(file, cargo); // Adicione o texto(cargo) ao arquivo
	 fclose(file); // fceha o arquivo
	 
	 system("pause");
	 
}

int Consultar() // Fun��o respons�vel por Consultar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// Inicio da cria��o de Var./strings
	char cpf[40];
	char conteudo[200];
	// Final da cria��o de Var./strings
	
	printf("Digite o CPF que voc� quer consultar:"); // Escolha do CPF a ser Consultado
	scanf("%s",cpf); // Refere-se a e salva strings
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // Abre o arquivo
	
	if(file == NULL) // se n�o ouver o CPF cadastrado
	{
		printf(" CPF n�o localizado!"); // Aviso caso o CPF n�o esteja cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Encontra e l�  as informa��es do usu�rio e se n�o tiver usu�rio volta NULL
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Mostra as info. do usu�rio
		printf("%s", conteudo); // Refere-se e salva string
		printf("\n\n"); // Espa�amento de linhas
	}
	system("pause");
        
}

int Deletar() // Fun��o de Deletar usu�rios do Banco de dados.
{
	// Inicio da cria��o de Var./strings
	char cpf[40];
	// Final da cria��o de Var./strings
	
	printf("Digite o CPF que voc� quer Deletar: "); // Escolha do CPF a ser deletado
	scanf("%s", cpf); // Refere-se e salva string
	
	remove(cpf); 
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // Abre e l� as informa��es
	
	if(file == NULL); // Usu�rio n�o foi encontrado
	{
		printf("O usu�rio foi Deletado!\n"); // Delete feito com sucesso
		system("pause");
	}
}





int main()
{
	int opcao=0; //Definindo Variaveis]
	int laco=1;
	
		for(laco=1; laco=1;)
	{
		
		system("cls"); //  respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
        printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
	    printf("Escolha a op��o que tu deseja:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao);  
		//Armazenando a escolha do usu�rio
	
	    system("cls"); // Respons�vel por limpar a tela
	
	    switch(opcao)
	    {
		   case 1:
		   	 Registro(); // Inicio da chamada de fun��es
	         break;
		   
		   case 2:
		   	 Consultar(); 
	         break;
	         
	       case 3:
	       	Deletar(); 
	       	break;
	       	
	       	case 4:
	       		printf("Agradecemos pelo uso do nosso sistema! \n");
	       		return 0;
	       		break;
	       	
	       	default:
	       		printf("Desculpe, mas esta op��o n�o est� dispon�vel\n"); // Outra op��o que seja as acima volta que n�o est� disponivel
	       		system("pause"); //Fim da sele��o}
	       		
	    }
		   
		   

	    
	 }
	 
	 
}


