// Correção IMC
#include <iostream>

using namespace std;

double imc[10] = {0};
int topo = 0;

void menuPrincipal(){
	cout<<"Menu Principal                 "<<endl;
	cout<<"1 - Calcular IMC               "<<endl;
	cout<<"2 - Exibir IMC Abaixo do Peso  "<<endl;
	cout<<"3 - Exibir IMC Saudaveis       "<<endl;
	cout<<"4 - Exibir IMC Obesidade Grau 1"<<endl;
	cout<<"5 - Exibir soma total dos Imcs "<<endl;
	cout<<"6 - Exibir a media dos Imcs    "<<endl;
	cout<<"7 - Sair                       "<<endl;
}

bool isVetorCheio(){
	if(topo == 10){
		return true;
	}else{
		return false;
	}
}

void add(double valorImc){
	if(isVetorCheio()){
		cout<<"Vetor cheio"<<endl;
	}else{
		for(int i = 0; i < 10; i++){
			if(imc[i] == 0){
				imc[i] = valorImc;
				topo++;
				break;
			}
		}	
	}	
}

double calculoImc(double peso, double altura){
	return (peso / (altura * altura));
}

void imcAbaixoPeso(){
	cout<<"Imc abaixo do peso"<<endl;
	for(int i = 0; i < topo; i++){
		if(imc[i] <= 18.5){
			cout<<"Imc["<<i<<"] = "<<imc[i]<<endl;
		}
	}
}

void imcSaudaveis(){
	cout<<"Imc saudaveis"<<endl;
	for(int i = 0; i < topo; i++){
		if(imc[i] >= 18.6 && imc[i] <= 24.9){
			cout<<"Imc["<<i<<"] = "<<imc[i]<<endl;
		}
	}
}

void imcObesidadeI(){
	cout<<"Imc obesidade grau I"<<endl;
	for(int i = 0; i < topo; i++){
		if(imc[i] >= 30 && imc[i] <= 34.9){
			cout<<"Imc["<<i<<"] = "<<imc[i]<<endl;
		}
	}
}

double totalImc(){
	double total = 0;
	for(int i = 0; i < topo; i++){
		total = total + imc[i];
	}
	return total;
}

double mediaImc(){
	double media = 0;
	if(totalImc() > 0){
		media = totalImc() / topo;
	}
	
	return media;
}

int main(){
	int op;
	string resp;
	double peso, altura;
	
	do{
		system("cls");
		menuPrincipal();
		cout<<"Informe a opção desejada "<<endl;
		cin>>op;
		
		switch(op){
			case 1:
				//calculo imc
				cout<<"Informe o peso"<<endl;
				cin>>peso;
				cout<<"Informe a altura"<<endl;
				cin>>altura;
				add(calculoImc(peso, altura));
				break;
			case 2:
				//Imc abaixo do peso
				imcAbaixoPeso();
				break;
			case 3:
				//Saudaveis
				imcSaudaveis();
				break;
			case 4:				
				//Imc Obesidade I
				imcObesidadeI();
				break;
			case 5:
				//Total
				cout<<"Total: "<<totalImc()<<endl;
				break;
			case 6:
				//Media
				cout<<"Media: "<<mediaImc()<<endl;
				break;			
		}
		
		cout<<"Deseja realizar outra operação? [S = SIM]"<<endl;
		cin>>resp;
		
	}while(resp == "S" || resp == "s");
}
