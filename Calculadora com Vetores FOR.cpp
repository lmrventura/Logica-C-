#include <iostream>
#include <stdlib.h>

using namespace std;

#define TAM_MAX 10

int main(){
	setlocale (LC_ALL, "");
		
	int topo, resp;
	double  total, media;
	double n1, n2, result[TAM_MAX] = {0};
	
	do{
		
		system("cls");
		
		cout<<"Informe a opera��o que deseja realizar:"<<endl;
		cout<<"1 - Somar"<<endl;
		cout<<"2 - Subtrair"<<endl;
		cout<<"3 - Dividir"<<endl;
		cout<<"4 - Multiplicar"<<endl;
		cout<<"5 - Total das opera��es"<<endl;
		cout<<"6 - Media geral das opera��es"<<endl;
		cout<<"7 - Sair"<<endl;
		cout<<"Informe a op��o desejada"<<endl;
		cin>>resp;
		
		if(resp == 1 || resp == 2 || resp == 3 || resp == 4){
			cout<<"Informe o valor 1: "<<endl;
			cin>>n1;
			cout<<"Informe o valor 2: "<<endl;
			cin>>n2;
		}
		
		switch(resp){
			case 1:
				/*
				for(int i = 0; i < 10; i++){
					if(result [i] == 0)
					result [i] = n1 + n2;
				}
				*/
				cout<<"Soma dos valores"<<endl;
					result[topo] = n1 + n2;
				cout<<"Soma = "<<result[topo]<<endl;
				
				topo++;
				
				cout<<"Deseja exibir a soma novamente? [0 = SIM, 1 = NAO]"<<endl;
				cin>>resp;	
				break;			
				
			case 2:	
				/*
				for(int i = 0; i < 10; i++){
					if(result [i] == 0)
					result [i] = n1 - n2;
				}
				*/
				cout<<"Subtra��o dos valores"<<endl;
					result[topo] = n1 - n2;
				cout<<"Subtra��o = "<<result[topo]<<endl;
				
				topo++;
				cout<<"Deseja exibir a subtra��o novamente? [0 = SIM, 1 = NAO]"<<endl;
				cin>>resp;	
				break;
				
			case 3:

				/*
				for(int i = 0; i < 10; i++){
					if(result [i] == 0)
					result [i] = n1 / n2;
				}
				*/
				cout<<"Divis�o dos valores"<<endl;
					result[topo] = n1 / n2;
				cout<<"Divis�o = "<<result[topo]<<endl;
				
				topo++;
				cout<<"Deseja exibir a divis�o novamente? [0 = SIM, 1 = NAO]"<<endl;
				cin>>resp;
				break;
			case 4:
				
				/*
				for(int i = 0; i < 10; i++){
					if(result [i] == 0)
					result [i] = n1 * n2;
				}
				*/
				cout<<"Multiplica��o dos valores"<<endl;
					result[topo] = n1 * n2;
				cout<<"Multiplica��o = "<<result[topo]<<endl;
				
				topo++;
				cout<<"Deseja exibir a multiplica��o novamente? [0 = SIM, 1 = NAO]"<<endl;
				cin>>resp;
				break;
			case 5:
				total = 0;
				for(int i = 0; i < topo; i++){
					total = total + result[i];
				}
				cout<<"Total: "<<total<<endl;
				cout<<"Total das opera��es: "<<topo<<endl;
				cout<<"Deseja exibir o total novamente? [0 = SIM, 1 = NAO]"<<endl;
				cin>>resp;
				break;			
			case 6:
				media = total / topo;
				cout<<"Media = "<<media<<endl;
				cout<<"Deseja exibir a m�dia novamente? [0 = SIM, 1 = NAO]"<<endl;
				cin>>resp;
				break;
		}
	}while(resp != 7);
}
