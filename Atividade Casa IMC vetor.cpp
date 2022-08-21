#include <iostream>
#include <stdlib.h>

#define TAM_MAX 10

using namespace std;

int main(){
	setlocale (LC_ALL, "");
	
	int topo, resp;
	double altura, peso, IMC, result[TAM_MAX];
	double somaimcs, mediaimcs, total;
	int outclassificacao;
	
	do{
		system("cls");
		
		cout<<"Menu principal"<<endl;
		cout<<"1 - C�lculo de IMC"<<endl;
		cout<<"2 - Mostrar todos os IMCs abaixo do peso"<<endl;
		cout<<"3 - Mostrar todos os IMCs Saud�veis"<<endl;
		cout<<"4 - Mostrar todos os IMCs Obesidade Grau I"<<endl;
		cout<<"5 - Exibir a soma total de todos os IMCs"<<endl;
		cout<<"6 - Exibir a m�dia de todos os IMCs"<<endl;
		cout<<"7 - Sair"<<endl;
		cout<<"Informe a opera��o desejada"<<endl;
		cin>>resp;	
		
		if(resp == 1){
			cout<<"Informe sua altura"<<endl;
			cin>>altura;
			cout<<"Informe seu peso em kg"<<endl;
			cin>>peso;	
		}
		
		switch(resp){
			case 1:
				result[topo] = peso / (altura * altura);
												
				cout<<"IMC = "<<result[topo]<<endl;
				topo++;
				cout<<"Deseja retornar ao menu para realizar outra opera��o? [0 = SIM ; 1 = N�O]"<<endl;
				cin>>resp;
				break;
			case 2:
				do{
					for(int i = 0; i <= topo; i++){
						if(result[i] < 18.5){
						cout<<"IMC ["<<i<<"]: "<<result[i]<<" Classifica��o de IMC: Abaixo do Peso"<<endl;
						}else if(result[i] > 18.5){
						cout<<"N�o houve nenhum IMC com classifica��o Abaixo do Peso."<<endl;
						}
					}
					cout<<"Mostrar calssifica��o novamente? [SIM =1 ]; [N�O = 0]"<<endl;
					cin>>outclassificacao;
				}while (outclassificacao == 1);
				break;
				
			case 3:
				do{
					for(int i = 0; i <= topo; i++){
						if(result[i] >= 18.6 && result[i] <= 24.9){
						cout<<"IMC ["<<i<<"]: "<<result[i]<<" Classifica��o de IMC: Saud�vel"<<endl;
						}else if(result[i] < 18.6 || result[i] > 24.9){
						cout<<"N�o houve nenhum IMC com classifica��o Saud�vel."<<endl;
						}
					}
					
					cout<<"Mostrar calssifica��o novamente? [SIM = 1 ; NAO = 0]"<<endl;
					cin>>outclassificacao;
				}while(outclassificacao == 3);
				
				break;
			case 4:
				do{
					for(int i = 0; i <= topo; i++){
						if(result[i] >= 30 && result[i] <= 34.9){
						cout<<"IMC ["<<i<<"]: "<<result[i]<<" Classifica��o de IMC: Obesudade Grau I"<<endl;
						}else if(result[i] < 30 || result[i] > 34.9){
						cout<<"N�o houve nenhum IMC com classifica��o Obesidade Grau I."<<endl;
						}
					}
					cout<<"Mostrar calssifica��o novamente? [SIM = 1 ; NAO = 0]"<<endl;
					cin>>outclassificacao;	
				}while(outclassificacao == 4);
				
				break;
			case 5:
				total = 0;
				for(int i = 0; i <= topo; i++){
					somaimcs = somaimcs + result[i];
				cout<<"A soma total de todos os IMCs �: "<<somaimcs<<endl;
				}
				break;
			case 6:
				mediaimcs = somaimcs / topo;
				
				cout<<"A m�dia de todos os IMCs = "<<mediaimcs;
				break;
		}
		system ("pause");
	}while(resp != 7);	
}
