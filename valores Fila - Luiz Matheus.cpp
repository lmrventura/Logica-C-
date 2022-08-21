#include <iostream>
#include <cstring>
#include <locale.h>

using namespace std;

#define TAM_MAX 5

double valores[TAM_MAX] = {0};

int primeiro= 0, ultimotopo = 0;


bool isVetorCheio(){
	if(ultimotopo - primeiro == TAM_MAX){
		return true;
	}else{
		return false;
	}
}

//ADD VALOR		
void addValores(double elemento){
	if(isVetorCheio()){
		cout<<"O vetor da lista está cheio."<<endl;
	}else{
		valores[ultimotopo] = elemento;
		ultimotopo++;	
	}
}

bool isVetorVazio(){
	if(primeiro == ultimotopo){
		return true;
	}
	return 0; 
}

//REMOVER ELEMENTO  -  TODA VEZ QUE REMOVE 1, o primeiro vai para o próximo
void removerElemento(){
	if(isVetorVazio()){
		cout<<"A fila está vazia. Não há elementos no vetor da fila para serem removidos."<<endl;
	}else{
		cout<<"Item removido: "<<valores[primeiro]<<endl;
		for(int i = 0; i < ultimotopo - 1; i++){
			valores[i] = valores[i+1];
		}
		ultimotopo--;
	}	
}

//EXIBIR ELEMENTOS
void exibirVetor(){
	if(isVetorVazio()){
		cout<<"A fila está vazia. Não há elementos no vetor da fila para serem exibidos."<<endl;
	}else{
		for(int i = primeiro; i < ultimotopo; i++){
		cout<<"i="<<i<<" - "<<"Elemento: "<<valores[i % TAM_MAX]<<endl;
	//	cout<<"Elemento: "<<valores[i % TAM_MAX]<<endl;
		}
	//	cout<<"Primeiro: "<<primeiro<<endl;
	//	cout<<"Ultimotopo: "<<ultimotopo<<endl;	
	}
}

int main(){
	
	setlocale(LC_ALL, "");	
	string resp;
	int op;
	double elemento;
	do{
		//system("cls");
		cout<<" 	Menu Fila"<<endl;
		cout<<"1 - Adicionar um elemento da fila."<<endl;
		cout<<"2 - Remover um elemento da fila (após remoção reorganizar)"<<endl;
		cout<<"3 - Exibir os elementos da Fila"<<endl;
		cout<<"4 - Sair"<<endl;
		cout<<"Informe a operação que deseja realizar: "<<endl;
		cin>>op;
		
		switch(op){
			case 1:
				cout<<"Informe o número que deseja adicioanar à fila: "<<endl;
				cin>>elemento;
				addValores(elemento);
				exibirVetor();
			break;
			case 2:
				exibirVetor();
				cout<<"Remover um elemento da fila: "<<endl;
				removerElemento();
				exibirVetor();
			break;
			case 3:
				exibirVetor();
				break;
			break;
			case 4:
				resp = "n";
				resp = "N";
			break;
		}
		
		cout<<"Deseja realizar outra operação? [S/s = SIM ; N/n = NÃO]"<<endl;
		cin>>resp;
	}while(resp == "S" || resp == "s");
}
