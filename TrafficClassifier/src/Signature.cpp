/*
 * Signature.cpp
 *
 *  Created on: Mar 23, 2011
 *      Author: miguel
 */

#include "Signature.h"

Signature::Signature(std::string classe, std::vector<double> valores) {

	this->soma=0;
	this->classe=classe;
	this->valores=valores;
}

double Signature::getSoma(){

	return this->soma;


}

void Signature::viewValues(){

	std::cout<< "Classe: "<< this->classe<< std::endl;

	for(int i=0; i< this->valores.size();i++){

		std::cout<< this->valores[i] << "   ";

	}

	std::cout<<"   " << std::endl;
}

std::vector<double> Signature::getValores(){

	return this->valores;
}

std::string Signature::getClasse(){

	return this->classe;

}


void Signature::setSoma(double soma){

	this->soma=soma;

}


Signature::~Signature() {
	// TODO Auto-generated destructor stub
}
