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
		cout<<"1 - Cálculo de IMC"<<endl;
		cout<<"2 - Mostrar todos os IMCs abaixo do peso"<<endl;
		cout<<"3 - Mostrar todos os IMCs Saudáveis"<<endl;
		cout<<"4 - Mostrar todos os IMCs Obesidade Grau I"<<endl;
		cout<<"5 - Exibir a soma total de todos os IMCs"<<endl;
		cout<<"6 - Exibir a média de todos os IMCs"<<endl;
		cout<<"7 - Sair"<<endl;
		cout<<"Informe a operação desejada"<<endl;
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
				cout<<"Deseja retornar ao menu para realizar outra operação? [0 = SIM ; 1 = NÃO]"<<endl;
				cin>>resp;
				break;
			case 2:
				do{
					for(int i = 0; i <= topo; i++){
						if(result[i] < 18.5){
						cout<<"IMC ["<<i<<"]: "<<result[i]<<" Classificação de IMC: Abaixo do Peso"<<endl;
						}else if(result[i] > 18.5){
						cout<<"Não houve nenhum IMC com classificação Abaixo do Peso."<<endl;
						}
					}
					cout<<"Mostrar calssificação novamente? [SIM =1 ]; [NÃO = 0]"<<endl;
					cin>>outclassificacao;
				}while (outclassificacao == 1);
				break;
				
			case 3:
				do{
					for(int i = 0; i <= topo; i++){
						if(result[i] >= 18.6 && result[i] <= 24.9){
						cout<<"IMC ["<<i<<"]: "<<result[i]<<" Classificação de IMC: Saudável"<<endl;
						}else if(result[i] < 18.6 || result[i] > 24.9){
						cout<<"Não houve nenhum IMC com classificação Saudável."<<endl;
						}
					}
					
					cout<<"Mostrar calssificação novamente? [SIM = 1 ; NAO = 0]"<<endl;
					cin>>outclassificacao;
				}while(outclassificacao == 3);
				
				break;
			case 4:
				do{
					for(int i = 0; i <= topo; i++){
						if(result[i] >= 30 && result[i] <= 34.9){
						cout<<"IMC ["<<i<<"]: "<<result[i]<<" Classificação de IMC: Obesudade Grau I"<<endl;
						}else if(result[i] < 30 || result[i] > 34.9){
						cout<<"Não houve nenhum IMC com classificação Obesidade Grau I."<<endl;
						}
					}
					cout<<"Mostrar calssificação novamente? [SIM = 1 ; NAO = 0]"<<endl;
					cin>>outclassificacao;	
				}while(outclassificacao == 4);
				
				break;
			case 5:
				total = 0;
				for(int i = 0; i <= topo; i++){
					somaimcs = somaimcs + result[i];
				cout<<"A soma total de todos os IMCs é: "<<somaimcs<<endl;
				}
				break;
			case 6:
				mediaimcs = somaimcs / topo;
				
				cout<<"A média de todos os IMCs = "<<mediaimcs;
				break;
		}
		system ("pause");
	}while(resp != 7);	
}
