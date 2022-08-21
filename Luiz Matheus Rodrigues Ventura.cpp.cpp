#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

/// variavel
int menup,menucad,menupedido,menurelatorio;

string resprincipal,menuprincipal,respcadastro,respcliente,respcardapio,respfuncionario,respostadelivery,maisdeumpedido,cadastraroutrocliente,respedido,resprelatorio, respcomprador;

string nome, datadolucro;
int topocardapio, topofuncionario,escolha,topopedido, contador,nomemotoboy,conte=1, topoexibir, topocompradores;
double km, ganhoporkm, valorlitro, totaldata;

/// REGISTRO DO CADASTRO CARDAPIO
struct cadastroCardapio{
  int ID;
  string tipo;
  string tamanho;
  double valor;
  string auxdocardapio;
};

cadastroCardapio cardapio[20];

/// REGISTRO DO CADASTRO FUNCIONARIO
struct cadastroFuncionario{
  int matricula;
  string nomefuncionario;
  string cargo;
  double salario;
  double somakm;
  double lucro;
  double totalganho;
  double pontos;
};

cadastroFuncionario funcionario [10]; 

///REGISTRO DOS COMPRADORES (clientes)
struct compradores{
	int idcliente;
	string nomecliente;
	string endereco;
	double distancia;
	
};

compradores cadastro[50]; //struct para cadastrar o cliente

/// RESGISTTRO DO PEDIDO 
struct cadastroCliente{
  string nome;
  int idpedido;
  string auxtipo;
  string auxtamanho;
  string auxdocliente;
  int ids;
  int escolha;
  int quantidade;
  double total; 
  double auxvalor;
  string data; 
  string auxdocardapio;
  double km;
  string enderecopedido;
};

cadastroCliente cliente[70];  //o nome ta cliente, mas esse struct � do card�pio

/// EXIBIR C�RDAPIO

void exibirmUmSum(){
    if(topocardapio == 0){
    	cout<<"Cadastre o primeiro item do card�pio: "<<endl;
    }else if(topocardapio > 0){
        cout<<"Card�pio do Restaurante"<<endl;
        for(int j = 0; j < topocardapio; j++){
            cout<<"ID do Prato: "<<cardapio[j].ID
            <<" Descri��o do prato: "<<cardapio[j].tipo
            <<" Tamanho do prato: "<<cardapio[j].tamanho
            <<" Valor do prato R$: "<<cardapio[j].valor<<endl;
        }
    }
}

/// VALIDAR IDENTIFICA��O(ID)

bool validaIdentificacao(int identificacao){
 bool valida = false;
 for(int j = 0; j < topocardapio; j++){
  if(cardapio[j].ID == identificacao){
   valida = true;
   break;
  }
 }
 return valida;
}

bool isCardapioCheio(){
	if(topocardapio == 20){
		return true;
	}else{
		return false;
	}
}

/// CADASTRAR O C�RDAPIO

void mUmSum(){    //menu Um Switch um
  do{
	exibirmUmSum();
    
    int identificacao = 0;
    string descricao;
    string porcao;
    cout<<"Cadastro do Cardapio"<<endl;
    if(isCardapioCheio()){
    	cout<<"Quantidade m�xima de itens no card�pio atingida."<<endl;
	}else{
		for(int j = 0; j < 20; j++){
	        if(cardapio[j].ID == 0){
	            cout<<"Informe o ID do prato"<<endl;
	            cin>>identificacao;
		        if(validaIdentificacao(identificacao)){
		          cout<<"J� existe um prato cadastrado com esse. Por favor, informe um diferente."<<endl;
		          break;
		   		}else{
		            cardapio[j].ID = identificacao;
		            cout<<"Informe o sabor (Ex: Pir�odeCarne / Pepsi): "<<endl;
		            cin>>descricao;
		            cout<<"Infome a descri��o do prato/item (Ex: TamanhoP / M / 1Litro): "<<endl;
		            cin>>porcao;
		            cardapio[j].tipo = descricao;
		            cardapio[j].tamanho = porcao;
		            cout<<"Informe o valor do item: "<<endl;
		            cin>>cardapio[j].valor;
		            
					topocardapio++;
					//system("cls");
					exibirmUmSum();
		            break;
		        }
	 		}
 		}
 		cout<<"Deseja adicionar mais um prato? (S/S = SIM ; N/n = N�O / Retornar ao Menu Principal): "<<endl;
        cin>>respcardapio;
	}
    
  }while(respcardapio == "S" || respcardapio == "s");
  respcadastro = "s";
}

/// VALIDA��O DE MATRICULA

bool validaMatricula(int matricula){
 bool valida = false;
 for (int l = 0; l < 10; l++){
  if(funcionario[l].matricula == matricula){
   valida = true;
   break;
  }
 }
 return valida;
}

/// EXIBIR DADOS DOS FUNCIONARIOS

void exibirmUmSdois(){	//exibir menu 1 switch 2
	//system("cls");
  if(topofuncionario == 0){
  	cout<<"N�o existe nenhum funcion�rio cadastrado ainda. Cadastre o primeiro funcion�rio: "<<endl;
  }else if(topofuncionario > 0){
  		cout<<"Dados dos funcionarios "<<endl;
	    for(int l = 0; l < topofuncionario; l++){
	        if(funcionario[l].matricula != 0){
		        cout<<" Matr�cula: "<<funcionario[l].matricula<<" - "
		        	<<" Nome: "<<funcionario[l].nomefuncionario<<" - "
		        	<<" Cargo: "<<funcionario[l].cargo<<" - "
		        	<<" Sal�rio: "<<funcionario[l].salario<<endl;	
			}
	  	}
	}
}

/// REGISTRAR FUNCIONARIO

void mUmSdois(){	// menu 1 switch 2
 do{
  exibirmUmSdois();
  cout<<"Registrar Funcion�rio"<<endl;
  int matricula = 0;
  
	cout<<"Informe a matr�cula do funcion�rio: "<<endl;
	cin>>matricula;
	if(validaMatricula(matricula)){
		cout<<"Um funcion�rio j� foi registrado com essa matr�cula. Por favor, informe outro. "<<endl;
		break;
	}else{
		for(int l = 0; l < 10; l++){			
			if(funcionario[l].matricula == 0){
				funcionario[l].matricula = matricula;
				cout<<"Informe o nome do funcion�rio: "<<endl;
				cin>>funcionario[l].nomefuncionario;
				cout<<"Informe o cargo do funcion�rio (Se for entregador, declare apenas como motoboy): "<<endl;
				cin>>funcionario[l].cargo;
		        cout<<"Informe o sal�rio do funcion�rio: "<<endl;
				cin>>funcionario[l].salario;
				
				topofuncionario++;
				exibirmUmSdois();
				break;	
			}
		}	
 }  
		cout<<"Deseja cadastrar outro funcion�rio? [S/S = SIM ; N/n = N�O]"<<endl;
		cin>>respfuncionario;
}while(respfuncionario == "S" || respfuncionario == "s");
	respcadastro = "s";
}



///EXIBIR CADASTRO CLIENTES
void exibirmUmStrez(){	//menu 1 switch 3
	if(topocompradores == 0){
		cout<<"N�o existe nenhum cliente cadastrado ainda. Cadastre o primeiro cliente. "<<endl;
	}else{
		cout<<"Lista de clientes: "<<endl;
		for (int z = 0; z < topocompradores; z++){
			cout<<"ID: "<<cadastro[z].idcliente<<" - "<<"Nome do cliente: "<<cadastro[z].nomecliente<<endl;		
		}
	}
}


bool validaIDCliente(int iddocliente){
 bool valida = false;
 for (int z = 0; z < topocompradores; z++){
  if(cadastro[z].idcliente == iddocliente){
   valida = true;
   break;
  }
 }
 return valida;
}

/// REGISTRAR CLIENTE
void mUmStrez(){	//menu 1 switch 3
	do{
		//exibirmUmStrez();
		string nomedocliente;
		int iddocliente;
		exibirmUmStrez();
		for (int z = 0; z < 50; z++){
			if(cadastro[z].idcliente == 0){
				cout<<"Informe o ID de registro do cliente: "<<endl;
				cin>>iddocliente;
				if(validaIDCliente(iddocliente)){
					cout<<"J� existe um cliente cadastrado com esse ID. Por favor, informe outro."<<endl;
					break;
				}else{
					cadastro[z].idcliente = iddocliente;
					cout<<"Informe o nome do cliente: "<<endl;
					cin>>cadastro[z].nomecliente;
				}
				cout<<"Informe o endere�o do cliente (Tudo junto, sem espa�o): "<<endl;
				cin>>cadastro[z].endereco;
				cout<<"Informe a dist�ncia em Km entre o restaurante e a casa do cliente (Ex: 3):"<<endl;
				cin>>cadastro[z].distancia;
				topocompradores++;
				//exibirmUmStrez(); - talvez
				break;	
			}
		}
		cout<<"Deseja cadastrar mais um cliente? [S/S = SIM ; N/n = N�O]"<<endl;
		cin>>respcomprador;
	}while(respcomprador == "S" || respcomprador == "s");
	menuprincipal = "s";
}

/// MENU DE CADASTRO///

void menuCad(){
	do{
		//system("cls") s� tirar o comentado de System no final do trabalho
	  cout<<"   Menu Cadastros"<<endl;
	  cout<<"1.1 - Cadastro Card�pio"<<endl;
	  cout<<"1.2 - Cadastro Funcionarios"<<endl;
	  cout<<"1.3 - Cadastro Cliente"<<endl;
	  cout<<"1.4 - Sair (Voltar ao Menu Principal)"<<endl;
	  cout<<"1.5 - Sair (Finalizar o programa)"<<endl;
	  cout<<"Informe o menu que deseja entrar: "<<endl;
	  cin>>menucad;


	  switch(menucad){

	    case 1:
			 mUmSum();
	    break;
	    case 2:
			mUmSdois();
	    break;
	    case 3:
	    	mUmStrez();
	    	break;
	    case 4:
        respcadastro = "n";
	      resprincipal = "s";
	    break;
	    case 5:
	    	menuprincipal = "n";
	    break;
	  }
	}while(respcadastro =="s" || respcadastro == "S");

}

/// EXIBIR PEDIDO DE UM CLIENTE ESPEC�FICO;

void exibirmDoisSdois(){	//exibir Menu dois Switch dois
	string respstatus;
	
	exibirmUmStrez();
	int validaridpedido;
	cout<<"Informe o ID do cliente para exibir os pedidos dele: "<<endl;
	cin>>validaridpedido;
    cout<<"  Descri��o dos Pedidos:  "<<endl;
	for(int i = 0; i < topopedido; i++){
		if(validaridpedido == cliente[i].ids){
			cout<<"Nome do cliente: "<<cliente[i].nome<<endl;
			cout<<"Sabor: "<<cliente[i].auxtipo<<endl;
			cout<<"Descri��o: "<<cliente[i].auxtamanho<<endl;
			cout<<"Valor do pedido: "<<cliente[i].auxvalor<<endl;
			cout<<"Data: "<<cliente[i].data<<endl;
			if(respostadelivery == "S"|| respostadelivery =="s"){
         		cout<<" Endere�o do cliente: "<<cliente[i].enderecopedido<<endl;
        	}
		}
        cout<<"Total: "<<cliente[i].total<<endl;
    }
      respostadelivery = "n"; 
}
///	EXIBIR HIST�RICOD E TODOS OS PEDIDOS
void exibirmDoisStrez(){	//exibir menu dois Switch Trez
	for(int i = 0; i < topopedido; i++){
		cout<<"ID do Pedido: "<<cliente[i].idpedido<<" - "
			<<"Nome do cliente: "<<cliente[i].nome<<" - "
			<<"Sabor: "<<cliente[i].auxtipo<<" - "
			<<"Descri��o: "<<cliente[i].auxtamanho<<" - "
			<<"Quantidade: "<<cliente[i].quantidade<<" - "
			<<"Valor do pedido: "<<cliente[i].auxvalor<<" - "
			<<"Data: "<<cliente[i].data<<endl;
		if(respostadelivery == "S"|| respostadelivery == "s"){
     		cout<<" Endere�o do cliente: "<<cliente[i].enderecopedido<<endl;
    	}
        cout<<" Total: "<<cliente[i].total<<endl;
        
      }
}
/// CADASTRO DE PEDIDOS
bool validaIDparapedido(int idparapedido){
	//bool valida = false;
	for(int i = 0; i < topopedido; i++){
		if(idparapedido == cliente[i].idpedido){
			return true;
			break;
		}
	//return valida;
	}
  return 0;
}

bool validaIDparacliente(int idparacliente){
	//bool valida = true;
	for(int z = 0; z < topocompradores; z++){
		if(idparacliente == cadastro[z].idcliente){ 
			return true;
			break;
		}
	}
  return 0; 
}

bool validaIDparaprato(int idparaprato){
	//bool valida = true;
	for(int j = 0; j < topocardapio; j++){
		if(idparaprato == cardapio[j].ID){ 
			return true;
			break;
		}
	}
  return 0;
}


bool validaIDparamotoboy(int nomemotoboy){
	//bool valida = true;
	for(int l = 0; l < topofuncionario; l++){
		if(nomemotoboy == funcionario[l].matricula && funcionario[l].cargo == "motoboy"){
			return true;
			break;
		}
	}
  return 0;
}

double somadatarelatorio(){
	double totaldata = 0;

	for(int i = 0; i < topopedido; i++){
		if(datadolucro == cliente[i].data){
			totaldata = totaldata + cliente[i].total;
		}
	}
	return totaldata;	
}

void mDoisSum(){	//menu Dois Switch Um
  do{
	  int idparapedido;
	  int idparacliente;
	  int idparaprato;
	  int quantidade;
	  
      //?exibirmDoisSdois();
	  cout<<"Cadastro dos Pedidos"<<endl;
    for (int i = 0; i < 10; i++){
    	if(cliente[i].idpedido == 0){
    		cout<<"Para registrar o pedido, informe o ID do pedido: "<<endl;
    		cin>>idparapedido;
			if(validaIDparapedido(idparapedido)){
				cout<<"J� existe um pedido cadastrado com esse ID. Por favor, informe outro ID: "<<endl;
				break;
			}else{
				cliente[i].idpedido = idparapedido;
				exibirmUmStrez();
				cout<<"Informe o ID do cliente que est� fazendo o pedido: "<<endl;
				cin>>idparacliente;
			
				if(validaIDparacliente(idparacliente) == false){
		          cout<<"N�o foi encontrado nenhum cliente cadastrado com esse ID. Por favor, informe o ID de um cliente j� cadastrado."<<endl;;
		          break;
		        }
				for (int z = 0; z < topocompradores; z++){
					if(idparacliente == cadastro[z].idcliente){
						cliente[i].ids = idparacliente;
						cliente[i].nome = cadastro[z].nomecliente;
					}	
				}
				
				cout<<"Informe se � delivery [S = SIM ; N = N�O]: "<<endl;
		        cin>>respostadelivery;
					
				if(respostadelivery == "s" || respostadelivery == "S"){
					
					exibirmUmSum();
					cout<<"Informe o ID do prato desejado: "<<endl;
					cin>>idparaprato;
					if(validaIDparaprato(idparaprato) == false){
						cout<<"N�o foi encontrado nenhum prato com o ID informado. Por favor, informe o ID de um prato j� cadastrado no card�pio."<<endl;
						break;
					}
				
					cliente[i].escolha = idparaprato;
					for (int j = 0; j < topocardapio; j++){
						if(cliente[i].escolha == cardapio[j].ID){
							cliente[i].auxtipo = cardapio[j].tamanho;
							cliente[i].auxtamanho = cardapio[j].tamanho;
							cliente[i].auxvalor = cardapio[j].valor;
						}
					}
					
					cout<<"Informe a quantidade: "<<endl;
					cin>>cliente[i].quantidade;
					cliente[i].total = cliente[i].quantidade * cliente[i].auxvalor;
					cout<<"Total: "<<cliente[i].total<<endl;
					cout<<"Informe a data ( XX/XX/XX): "<<endl;
					cin>>cliente[i].data;
				
					for (int z = 0; z < topocompradores; z++){
		      			cliente[i].enderecopedido = cadastro[z].endereco;	
		      			cliente[i].km = cadastro[z].distancia;	
						
						cout<<"Endere�o do cliente: "<<cliente[i].enderecopedido<<endl;
		      			cout<<"Informe a dist�ncia entre o restaurante e o local de entrega: "<<cliente[i].km<<endl;
					}
					
	      			//exibir os motoboys
	      			for (int l = 0; l < topofuncionario; l++){
						if(funcionario[l].cargo == "motoboy"){ 
							cout<<"ID Motoboy: "<<funcionario[l].matricula<<" Nome: "<<funcionario[l].nomefuncionario<<endl;
						}
					}
					
	      			cout<<"Informe o n�mero corresponte ao ID do motoboy que vai realizar a entrega: "<<endl;
					cin>>nomemotoboy; // ID do motoboy, int nomemotoboy
					
					if(validaIDparamotoboy(nomemotoboy) == false){
						cout<<"Informe um ID correspondente ao ID de funcion�rio cadastrado como motoboy cadastrado."<<endl;
						break;
					}
					
					for (int l = 0; l < topofuncionario; l++){
							if(nomemotoboy == funcionario[l].matricula){
								funcionario[l].pontos++;
								funcionario[l].somakm = funcionario[l].somakm + cliente[i].km;
								cout<<"Quantidade de entregas que o motoboy foi selecionado: "<<funcionario[l].pontos<<endl; //pra saber o motoboy que faz mais, com melhor desempenho
							}
				 }
					
				}else{
					
		        	exibirmUmSum();
					cout<<"Informe o ID do prato desejado: "<<endl;
					cin>>idparaprato;
					
					//idparaprato sem validacao
					
					cliente[i].escolha = idparaprato;
					for (int j = 0; j < topocardapio; j++){
						if(cliente[i].escolha == cardapio[j].ID){
							cliente[i].auxtipo = cardapio[j].tamanho;
							cliente[i].auxtamanho = cardapio[j].tamanho;
							cliente[i].auxvalor = cardapio[j].valor;
						}
					}
					cout<<"Informe a quantidade: "<<endl;
					cin>>cliente[i].quantidade;
					cliente[i].total = cliente[i].quantidade * cliente[i].auxvalor;
					cout<<"Total: "<<cliente[i].total<<endl;
					cout<<"Informe a data: "<<endl;
					cin>>cliente[i].data;
				}
				topopedido++;
				break;	
			}
		}
	}
	cout<<"Deseja cadastrar outro pedido? [S/s = Sim ; N/n = N�O]"<<endl;
	cin>>cadastraroutrocliente;
		
  }while(cadastraroutrocliente == "S" || cadastraroutrocliente == "s");
 respedido ="s";
}

/// MENU DO PEDIDO///

void menuPedido(){
    do{
      cout<<"      Menu Pedido"<<endl;
      cout<<"2.1 - Cadastro Pedidos"<<endl;
      cout<<"2.2 - Descri��o Pedidos (de um cliente espec�fico)"<<endl;
      cout<<"2.3 - Hist�rico de todos os pedidos"<<endl;
	  cout<<"2.4 - Sair (Voltar ao Menu Principal)"<<endl;
	  cout<<"2.5 - Sair (Encerrar o programa)"<<endl;
      cout<<"Informe o menu que deseja entrar: "<<endl;
        cin>>menupedido;
      switch(menupedido){
        case 1:
          mDoisSum();
        break;
        case 2:
          exibirmDoisSdois();
        break;
        case 3:
          exibirmDoisStrez();
        break;
        case 4:
          respedido ="n";
          menuprincipal = "s";
        break;
        case 5:
        	menuprincipal = "n";
        break;
      }
    }while(respedido == "S" || respedido == "s");
  }


// 1 - Soma dos valores dos pedidos feitos

void mTrezSum(){
	int somapontos = 0;
	double somatotal = 0;
	for (int i = 0; i < topopedido; i++){
		somatotal = somatotal + cliente[i].total;
	}
	for (int l = 0; l < topofuncionario; l++){
		somapontos = somapontos + funcionario[l].pontos;
	}
	cout<<"Soma dos valores dos pedidos feitos: "<<somatotal<<endl;
	cout<<"Quantidade de pedidos feitos: "<<somapontos<<endl;
	resprelatorio = "s";
}
	
	
// 2 - LUCRO ENTREGADOR
void mTrezSdois(){
	
	cout<<" Informe a data que deseja saber o valor de vendas obtido: "<<endl;
	cin>>datadolucro;
	
	cout<<"Total do dia: "<<somadatarelatorio()<<endl;
}
	
	
// 3 - Soma dos pedidos das entregas feitos por cada entregador
void mTrezStrez(){
	for (int l = 0; l < topofuncionario; l++){
		if(funcionario[l].cargo == "motoboy"){
			cout<<"Nome do motoboy: "<<funcionario[l].nomefuncionario<<endl;
			cout<<"Quantidades de pedidos entregues por ele: "<<funcionario[l].pontos<<endl;
		}
	}
}
// MENU DO RELATORIO///

void menuRelatorio(){
	do{
	  cout<<"   Menu Relat�rio"<<endl;
	  cout<<"3.1 - Soma dos valores dos pedidos feitos"<<endl;
	  cout<<"3.2 - Vendas do dia"<<endl;
	  cout<<"3.3 - Soma das entregas por entregador"<<endl;
	  cout<<"3.4 - Sair (Voltar ao Menu Principal)"<<endl;
	  cout<<"2.5 - Sair (Encerrar o programa)"<<endl;
	  cin>>menurelatorio;
	  
	  switch(menurelatorio){
	    case 1:
	    	mTrezSum();
	    break;
	    case 2:
			mTrezSdois();
	    break;
	    case 3:
	    	mTrezStrez();
	    break;
	    case 4:
	    	resprelatorio = "n";
	    	menuprincipal = "S";
	    break;
	    case 5:
	    	menuprincipal = "n";
	    break;
	  }		
	}while(resprelatorio == "S" || resprelatorio == "s");
}

/// MENU PRINCIPAL///

void menuP(){
  do{
	  cout<<"    Menu Principal"<<endl;
	  cout<<"1 - Cadastros"<<endl;
	  cout<<"2 - Pedidos"<<endl;
	  cout<<"3 - Relat�rios"<<endl;
	  cout<<"4 - Sair do Programa"<<endl;
	  cout<<"Informe o menu que deseja entrar: "<<endl;
	  cin>>menup;

	  switch(menup){
	    case 1:
	      menuCad();
	    break;
	    case 2:
	      menuPedido();
	    break;
	    case 3:
	      menuRelatorio();
	    break;
	    case 4:
	      menuprincipal = "n";
	      resprincipal = "n";
	    break;
	  }
	}while(menuprincipal == "S" || menuprincipal == "s");
  }

int main(){
  setlocale(LC_ALL,"Portuguese");

  do{
    menuP();
  }while(resprincipal == "S" || resprincipal == "s");

}
