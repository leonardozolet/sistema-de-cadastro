#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() {
	
	setlocale(LC_ALL, "Portuguese");//definindo o idioma
	
    // Criacao de variaveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[100];

    // Coletando informacao do usuario
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf);
    
    // Criando e escrevendo no arquivo
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return; // Retorna se nao puder criar o arquivo
    }
    fprintf(file, "%s,", cpf);
    
    // Continuando a coletar informacoes
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fprintf(file, "%s,", nome);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome);
    
    printf("Digite o cargo a ser cadastrado: ");
    getchar(); // Limpa o buffer para evitar problemas com fgets
    fgets(cargo, sizeof(cargo), stdin); // Le uma linha inteira para o cargo
    cargo[strcspn(cargo, "\n")] = 0; // Remove a nova linha se presente
    fprintf(file, "%s", cargo);
    
    fclose(file);
    
    printf("\nCadastro realizado com sucesso!\n");
    system("pause"); // Pausa para o usuario ver a mensagem

    return; // Retorna para o menu
}


int consulta()//funcao de consulta de usuarios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio das variaveis
	char cpf[40];//cpf do usuario cadastrado
	char conteudo[200];//conteudo do cadastro
	//encerramento das variaveis
	
	printf("Digite o cpf a ser consultado: ");//mensagem de consulta ao cliente
	scanf("%s",cpf);
	
	FILE *file;//cria um arquivo
	file = fopen(cpf,"r");//le o aquivo do cpf com o "r"
	
	if(file == NULL)//caso o arquivo não seja encontrado
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");//informa ao cliente
	}
	
	while(fgets(conteudo, 200, file) != NULL)//caso o usuario seja encontrado
	{
		printf("\nEssas sao as informacoes do usuario: ");//menssagens ao cliente
		printf("%s", conteudo);//mostra as informacoes do arquivo selecionado
		printf("\n\n");
	}
	
	system("pause");//mantem a tela
	
}

int deletar()//funcao deletar usuarios
{
	char cpf[40];//variavel unica, cpf do usuario
	
	printf("Digite o CPF do usuario a ser deletado: ");//pedindo as informacoes de usuario ao cliente
	scanf("%s",cpf);
	
	remove(cpf);//remocao do usuario
	
	FILE *file;//buscando o aruivo de usuario
	file = fopen(cpf,"r");//abrindo o arquivo
	
	if(file == NULL)//se os dados digitados nao forem encontrados
	{
		printf("Ususario nao encontrado!\n\n");//informando o usuario
		system("pause");
	}
	
	else//caso o usuario seja encontrado
	{
		remove(cpf);//remocao do usuario do banco de dados
		printf("\nUsuario deletado com sucesso!\n\n");//informando o cliente
		system("pause");
	
	}
}


	
int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Sistema de Cadastro ###\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
	
	
		for(laco=1;laco=1;)
		{

			system("cls");//responsavel por limpar a tela

			setlocale(LC_ALL, "pt_BR.UTF-8"); //Definindo a linguagem
			
			printf("### Sistema de Cadastro ###\n\n"); //inicio do menu
			printf("Escolha a opcao desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema.\n\n");
			printf("Opcao: ");//fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usuario
		
			system("cls");//responsavel por limpar a tela
	
			switch(opcao) //inicio da selecao do menu
			{
				case 1:
				registro();//chamada de funcoes
				break;
			
				case 2:
				consulta();
				break;
		
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
		
				default:
				printf("Essa opcao não esta disponivel!\n");
				system("pause");
				break;
			} //fim da selecao
		}
	}	
	else
		printf("Senha incorreta!");
}
