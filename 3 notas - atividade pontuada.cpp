#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	setlocale (LC_ALL, "");
	
	double nota1, nota2, nota3, media, resp, somamedias, quantasmedias, mediageral;
	
	do{
	cout<<"Informe a nota1 do aluno: "<<endl;
	cin>>nota1;
	cout<<"Informe a nota2 do aluno: "<<endl;
	cin>>nota2;
	cout<<"Informe a nota3 do aluno: "<<endl;
	cin>>nota3;
	
	media = (nota1 + nota2 + nota3) / 3;
	
		if(media >= 7){
		cout<<"Aluno Aprovado com m�dia: "<<media<<endl;
	}
	else if(media <= 3){
		cout<<"Aluno reprovado com m�dia "<<media<<endl;
	}
	else if(media > 3 && media < 7){
		cout<<"Aluno em recupera��o com m�dia: "<<media<<endl;
	}
	
	somamedias = somamedias + media;
	quantasmedias = quantasmedias + 1;	
	mediageral = somamedias / quantasmedias; 
	
	cout<<"Deseja calcular uma nova m�dia? [N�O = 0 ; SIM = 1]"<<endl;
	cin>>resp;
	
	system ("cls");
		
	}while(resp==1);
	
	cout<<"A soma das m�dias � igual a "<<somamedias<<endl;
	cout<<"O n�mero de m�dias calculadas foi: "<<quantasmedias<<endl;
	cout<<"A m�dia geral da turma �: "<<mediageral<<endl; 
	
	return 0;
	}		

