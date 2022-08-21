#include <iostream>
#include <cstring>

using namespace std;

double valores[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
double topo = 0, topo2;
double troca, maior, menor;

void menuPrincipal(){
	cout<<"Menu Principal"<<endl;
	cout<<"1 - Adicionar valores no vetor"<<endl;
	cout<<"2 - Remover um valor especifico"<<endl;
	cout<<"3 - Rotinas Especiais"<<endl;
	cout<<"4 - Exibir os elementos"<<endl;
}
void ordemCrescente(){
	for (int i = 0; i < 10; i++){
		for (int j = i+1; j < 10; j++){
			if(valores[i] > valores [j]){
				troca = valores[i];
				valores[i] = valores[j];
				valores[j] = troca;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		if(valores[i] != 0){
			cout<<"Valores["<<i<<"]"<<valores[i]<<endl;	
		}
	}
}

void ordemDecrescente(){
	for (int i = 0; i < 10; i++){
		for (int h = i+1; h < 10; h++){
			if(valores [i] < valores [h]){
				troca = valores[i];
				valores[i] = valores[h];
				valores[h] = troca;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		if(valores[i] != 0){
			cout<<"Valores["<<i<<"]"<<valores[i]<<endl;	
		}
	}
}

void maiorelemento(){
	for (int i = 0; i < topo; i++){
	maior = valores[0];
		if(valores[i] > maior){
		maior = valores [i];
		}
	}	
}

void menorelemento(){
	for (int i = 0; i < topo; i++){
	menor = valores[0];
		if(valores[i] != 0){
			if(valores[i] < menor){
			menor = valores [i];
			}
		}
	}
}

double somatotal(){
	double total = 0;
	for (int i = 0; i < 10; i++){
		total = total + valores[i];		
	}
	return total;
}

double mediaelementos(){
	double mediaelementos = 0;
	double media = 0;
	if(somatotal() > 0){
		media = somatotal() / topo2;	
	}
	return media;
}

void menurotinas(int menur){
  while(menur != 7){
    cout<<"Menu Rotinas Especiais"<<endl;
    cout<<"1 - Exibir os elementos em ordem crescente"<<endl;
    cout<<"2 - Exibir os elementos em ordem decrescente"<<endl;
    cout<<"3 - Mostrar o maior elemento do vetor"<<endl;
    cout<<"4 - Mostrar o menor elemento do vetor"<<endl;
    cout<<"5 - Exibir a soma total dos elementos"<<endl;
    cout<<"6 - Exibir a media dos elementos"<<endl;
    cout<<"7 - Retornar ao menu Principal"<<endl;
    cout<<"Informe a operação que deseja realizar:";
    cin>>menur;
    
    switch(menur){
    	case 1:
    		ordemCrescente();
    		break;
    	case 2:
    		ordemDecrescente();
    		break;
    	case 3:
    		maiorelemento();
			cout<<"Maior elemento do vetor = "<<maior<<endl;
    		break;
    	case 4:
    		menorelemento();
			cout<<"Menor elemento do vetor = "<<menor<<endl;
    		break;
    	case 5:
    		cout<<"Soma total dos elementos: "<<somatotal()<<endl;
    		break;
    	case 6:
    		cout<<"Media dos elementos: "<<mediaelementos()<<endl;
    		break;
    	case 7:
    		cout<<"Deseja sair do Menu Rotinas Especiais? [SIM = 7]"<<endl;
    		cin>>menur;
			break;
    }
  }
}

bool isVetorCheio(){
	if(topo == 10){
		return true;
	}else{
		return false;
	}
}

void addValores(double elemento){
  	for(int i = 0; i < 10; i++){
	    if(valores[i] == 0){
	      valores[i] = elemento;
	      topo++;
	      topo2++;
	      break;
	    }
	}
	
	
  for(int i = 0; i < 10; i++){
	  if(valores[i] != 0){
	  cout<< "Vetor ["<<i<<"] = "<<valores[i]<<endl;	
	  }	
  } 
}

void removervalor(double remover){
	for (int i = 0; i < 10; i++){
		if(valores[i] == remover){
	      valores[i] = 0;
	      topo2--;
		}
	}
	for(int i = 0; i < 10; i++){
	  if(valores[i] != 0){
	  cout<< "Vetor ["<<i<<"] = "<<valores[i]<<endl;	
	  }	
  }
}

void exibirVetor(){
  for(int i = 0; i < topo; i++){
		cout<< "Vetor [" <<i<< "] = "<<valores[i] <<endl;
  } 
}

int main(){
	setlocale (LC_ALL, "");
	
	int menup, menur;
	string resp, respr;
	double maiorelemento = 0, menorelemento = 200, elemento, remover;

	do{
		menuPrincipal();
		
		cout<<"Informe o que deseja realizar:"<<endl;
		cin>>menup;
		
		switch(menup){
			case 1:
				//Adicionar valores no vetor
				if(isVetorCheio()){
					cout<<"Vetor cheio"<<endl;
				}else{
					cout<<"Informe os valores que deseja adicionar: "<<endl;
					cin>>elemento;
					addValores(elemento);
				}
			break;
			
			case 2:
				//Remover um valor específico
				exibirVetor();
				cout<<"Informe o valor que deseja remover: "<<endl;
				cin>>remover;
				removervalor(remover);
				break;
				
			case 3:
				//Rotinas principais
				menurotinas(menur);
				break;
				
			case 4:
			//Exibir os elementos
			  exibirVetor();
			break;
		}
		
		cout<<"Ir para o menu principal? [SIM = S; NÃO = N]"<<endl;
		cin>>resp;
	}while(resp == "S" || resp == "s");
  return 0;
}


