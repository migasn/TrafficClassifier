/*
 * Classificator.cpp
 *
 *  Created on: Mar 23, 2011
 *      Author: miguel
 */

#include "Classificator.h"

Classificator::Classificator(const double &max, const int &size, const int &window_size) {
	this->contador=1;
		this->max=max;
		this->size=size;
		this->window_size=window_size;
		this->arr = (int*) calloc (size,sizeof(int));
		this->probability = (double*) calloc (size,sizeof(double));
		this->classe;
		this->soma=20;

}

void Classificator::distribuicao(const double &v, Database * database){

	if(v >= this->max)
	return;

	double aux;
	double aux2;
	int final ;


	if(this->window_size <= this->contador){
				int in, out;


				aux2=window.front();
				aux=(aux2/this->max);

				//posição do array ao qual vamos decrementar o numero de ocorrencias
				out=(int)(aux*this->size);



				aux=v/this->max;
				//in: posição a que temos de incrementar
				in=(int)(aux*this->size);


				//retiramos da janela o valor mais antigo
				this->window.pop_front();

				//colocamos na janela o valor novo
				this->window.push_back(v);

				//classificar
				this->dt(database,in,out);

				//incrementa o que entra, subtrai o que sai
				if(this->arr[out]!=0)
						this->arr[out]=this->arr[out]-1;

						this->arr[in]=this->arr[in]+1;

				this->contador++;

	}else{

			int final;
			aux=(v/this->max);
			final=(int)(aux*this->size);
			this->window.push_back(v);
			this->arr[final]++;
			this->dt(database);

			this->contador++;
	}

	if(this->contador==499){

		this->view_CHI_2_RESULTS(database);
		getchar();
	}


}




void Classificator::CHI(Signature * c){

	double x2=0;
	double powv;
	double prob;
	double ee, div;

	std::vector<double> e = c->getValores();


	for(int i=0; i<e.size();i++){

		if(e[i]==0 || probability[i]==0)
			continue;
		//std::cout<< "P[I]:  "<<this->probability[i]<< "       E[I]: "<< e[i]<< "   sIZE_WINDOW: "<< this->window.size() << std::endl;

		prob=this->window_size*(this->arr[i]/this->window_size);

		ee=(this->window_size*e[i]);

		//std::cout<< "Prob: "<<prob<< "         EE: "<< ee << std::endl;

		powv=pow(prob-ee,2);
		div=powv/(this->window_size*e[i]);
		//std::cout<<"div: "<< div  <<std::endl;

		x2=x2 + div;
		//std::cout<< "SOMA: "<< x2 << std::endl;
		//getchar();
	}

	c->setSoma(x2);
	//std::cout<< "SOMA FINAL: "<< c->getSoma() << std::endl;

}

void Classificator::CHI_C(Signature * c, int in,int out){

	double x2;
	double op1, op2, op3, op4;

	std::vector<double> e=c->getValores();

	/*std::cout<< "Classe: "<< c->getClasse()<<std::endl;
	std::cout<< "ARR[out]: "<< this->arr[out]<< " ARR[IN]: "<< this->arr[in]<< std::endl;
	std::cout<< "Window-Size: "<< this->window.size()<< " CONTADOR: "<< this->contador<< std::endl;
	std::cout<< "E[out]: "<< e[out]<< "E[IN]: "<< e[in]<< std::endl;
	std::cout<< "Soma antes da alteração: "<< c->getSoma() << std::endl;*/

	if(e[out]==0 || e[in]==0)
		return;



	op1=pow((this->window_size*(this->arr[out]/this->contador)) - (this->window.size()*e[out]),2)/ (this->window.size()*e[out]);
	//std::cout<< "OP1:" << op1 <<std::endl;

	op2=pow((this->window_size*((this->arr[out]-1)/this->contador)) - (this->window.size()*e[out]),2)/ (this->window.size()*e[out]);
	//std::cout<< "OP2:" << op2 <<std::endl;

	op3=pow((this->window_size*(this->arr[in]/this->contador)) - (this->window.size()*e[in]),2)/ (this->window.size()*e[in]);
	//std::cout<< "OP3:" << op3 <<std::endl;

	op4=pow((this->window_size*((this->arr[in]+1)/this->contador)) - (this->window.size()*e[in]),2)/ (this->window.size()*e[in]);
	//std::cout<< "OP4:" << op4 <<std::endl;




	x2 = c->getSoma() - (op1 + op2) + (op3 + op4);
	//std::cout<< "X2:" << x2 <<std::endl;
	c->setSoma(x2);


}

void  Classificator::dt(Database *database){

	struct dirent *drnt;
	DIR *dr;
	double * data_c;
	double sum_o=10;
	double sum_p=0;
	std::string cl=" ";

	std::vector <Signature *> sign1;

	sign1=database->getSignatures();

	this->probability_function();

		for(int i=0; i< sign1.size();i++){


					Signature * c=sign1[i];
					//c->viewValues();
					//getchar();
					this->CHI(c);
					//std::cout<< "SOMA FINAL DEPOIS DE ACTUALIZADA: "<< c->getSoma() << std::endl;
				   //getchar();


		}


}

void Classificator::dt(Database *database,int in, int out){

	struct dirent *drnt;
	DIR *dr;
	double * data_c;
	double sum_o=10;
	double sum_p=0;
	std::string cl=" ";

	std::vector <Signature *> sign1;

		sign1=database->getSignatures();

	for(int i=0; i< sign1.size() ;i++){


				Signature * c= sign1[i];

				this->CHI_C(c,in,out);
				//std::cout<< "SOMA FINAL DEPOIS DE ACTUALIZADA: "<< c->getSoma() << std::endl;
			   //getchar();
			}
}

void Classificator::view_CHI_2_RESULTS(Database *database){

	std::vector<Signature *> results=database->getSignatures();

	for(int i=0; i<results.size();i++){

		Signature * z= results[i];
		std::cout<< "Classe: "<< z->getClasse() << " soma: "<< z->getSoma()<<std::endl;

		double sum_v=z->getSoma();

		if(sum_v < this->soma){
			this->soma=sum_v;
			this->classe=z->getClasse();

		}
	}

}




Classificator::~Classificator() {
	// TODO Auto-generated destructor stub
}

void Classificator::viewValues(std::vector<double> e){

	for(int i=0; i < e.size(); i ++){

		std::cout<< e[i]<< "   ";

	}
std::cout<< "  "<< std::endl;

}

void Classificator::probability_function(){

	double p=0.0;
	double p2, p3;
	for(int i=0; i< this->size;i++){

		p=(((double)this->arr[i]) / ((double)this->contador));

	//	 printf("%.5f\n",round(2.5));
		// getchar();

		//std::cout<< "P:" << p << std::endl;
		p2=p*10000000000;
		p3=round(p2);
		p=p3/10000000000;
		//std::cout<< "P:" << p << std::endl;
		this->probability[i]=p;
	}
}
