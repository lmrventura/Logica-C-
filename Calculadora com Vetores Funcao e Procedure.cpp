//Atividade Calculadora função e procedure
#include <iostream>
#include <cstring>

using namespace std;

double valores[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int topo;

void menuPrincipal(){
	cout<<"Menu Principal                "<<endl;
	cout<<"1 - Calculadora               "<<endl;
	cout<<"2 - Soma total das Operações  "<<endl;
	cout<<"3 - Media geral das Operações "<<endl;
	cout<<"4 - Sair do Sistema           "<<endl;
}

void calculadora(){
	cout<<"Menu Calculadora               "<<endl;
	cout<<"1 - Somar                      "<<endl;
	cout<<"2 - Subtrair                   "<<endl;
	cout<<"3 - Dividir                    "<<endl;
	cout<<"4 - Multiplicar                "<<endl;
	cout<<"5 - Exibir elementos           "<<endl;
	cout<<"6 - Retornar ao menu principal "<<endl;
}

double somar(double valor01, double valor02){	
	return valor01 + valor02;
}

double subtrair(double valor01, double valor02){
	return valor01 - valor02;
}

double dividir(double valor01, double valor02){
	return valor01 / valor02;
}

double multiplicar(double a, double valor02){
	return valor01 * valor02;
}

double calculos(double valor01, double valor02, int op){
	if(op == 1){
		return valor01 + valor02;
	}else if(op == 2){
		return valor01 - valor02;
	}else if(op == 3){
		return valor01 / valor02;
	}else if(op == 4){
		return valor01 * valor02;
	}else{
		return 0;
	}
}

void addVetor(double valor){
	for(int i = 0; i < 10; i++){
		if(valores[i] == 0){
			valores[i] = valor;
			topo++;
			break;
		}
	}
}

void exibirVetor(){	
	for(int i = 0; i < topo; i++){
		cout<<"vetor["<<i<<"] = "<<valores[i]<<endl;	
	}	
}

bool validarTotal(){
	//return true ou false
}

double somaGeral(){
	double total = 0;
	for(int i = 0; i < topo; i++){
		total = total + valores[i];
	}
	return total;
}

int main(){
	int menup, menuc;
	string resp, respc;
	
	double valor01, valor02;
	
	do{
		system("cls");
		menuPrincipal();
		
		cout<<"Informe a opção desejada."<<endl;
		cin>>menup;
		
		switch(menup){
			case 1:
				//menu calculadora
				do{
					system("cls");
					calculadora();
					cout<<"Informe a operação desejada."<<endl;
					cin>>menuc;
					
					cout<<"Informe o valor01"<<endl;
					cin>>valor01;
					
					cout<<"Informe o valor02"<<endl;
					cin>>valor02;
					
					switch(menuc){
						case 1:
							//somar
							addVetor(somar(valor01, valor02));
							break;
						case 2:
							//subtrair
							addVetor(subtrair(valor01, valor02));
							break;
						case 3:
							//dividir
							addVetor(calculos(valor01, valor02, 3));
							break;
						case 4:
							//multiplicar
							addVetor(calculos(valor01, valor02, 4));
							break;
						case 5:
							exibirVetor();
							break;
					}
					
					cout<<"Deseja realizar outra operação. [S = SIM]"<<endl;
					cin>>respc;
					
				}while(respc == "S" || respc == "s");
				
				break;
			case 2:
				//soma total
				cout<<"Total: "<<somaGeral()<<endl;
				
				break;
			case 3:
				criar uma função:
					antes de realizar a media, 
					verificar se o total foi gerado.
					função booleano
				break;
			case 4:
				break;
		}
		cout<<"Deseja realizar outra operação. [S= SIM]"<<endl;
		cin>>resp;
	}while(resp == "S" || resp == "s");
}


