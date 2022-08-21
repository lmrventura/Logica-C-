//registros
#include <iostream>

using namespace std;

int topo;

struct ficha{
	int matricula;
	string nome;
	double salario;
};
	
ficha empresa[10];

bool validaMatricula(int matricula){
	bool valida = false;
	for(int i = 0; i < topo; i++){
		if(empresa[i].matricula == matricula){
			valida = true;			
			break;
		}
	}
	return valida;
}

void cadastro(){
	cout<<"Digar o registro do funcionario "<<endl;
	int matricula = 0;
	for(int i = 0; i < 10; i++){
		if(empresa[i].matricula == 0){
			cout<<"Informe a matricula "<<endl;
			cin>>matricula;	//colocou o valor na variável para poder passar como parâmetro na boleana validaMatricula
			if(validaMatricula(matricula)){ // if(validaMatricula(matricula) == true) é redundante{
				cout<<"Por favor informe uma matricula diferente!"<<endl;
				break; // esse break é para finalizar o for da boleana. Se retornou verdadeiro e encontrou um igual não precisa continuar
			}else{
				empresa[i].matricula = matricula;
				cout<<"Informe o nome "<<endl;
				cin>>empresa[i].nome;
				cout<<"Informe o salario "<<endl;
				cin>>empresa[i].salario;
				topo++;
				break;
			}			
		}
	}
}

void exibir(){
	cout<<"Dados dos funcionarios "<<endl;
	for(int i = 0; i < topo; i++){
		cout<<"Matricula: "<<empresa[i].matricula
			<<" Nome: "<<empresa[i].nome
			<<" Salario: "<<empresa[i].salario<<endl;
	}
}

void menuPrincipal(){
	cout<<"Menu Principal            "<<endl;
	cout<<"1 - Cadastrar Funcionario "<<endl;
	cout<<"2 - Exibir Funcionarios   "<<endl;
	cout<<"3 - Sair                  "<<endl;	
}

int main(){
	string resp;
	int op;
	
	do{
		system("cls");	
		menuPrincipal();
		cout<<"Informe a opção desejada "<<endl;
		cin>>op;
		switch(op){
			case 1:
				//cadastro
				cadastro();
				break;
			case 2:
				//exibir
				exibir();
				break;				
		}
		cout<<"Deseja realizar outra operação? [S = sim]"<<endl;
		cin>>resp;
		
	}while(resp == "S" || resp == "s");
}



