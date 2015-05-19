/*
 * Classificator.h
 *
 *  Created on: Mar 23, 2011
 *      Author: miguel
 */

#ifndef CLASSIFICATOR_H_
#define CLASSIFICATOR_H_
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <pcapwrap.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>
#include "Signature.h";
#include "Database.h";
#include <deque>
#include "Signature.h"
class Classificator {
private:
	int contador;
		int size;
		double max;
		int * arr;
		double * probability;
		double soma;
		std::string classe;
		int window_size;
		std::deque<double> window;

public:
	Classificator(const double &max,const int &size, const int &window_size);
	void  CHI(Signature * c);
	void  dt(Database *database);
	void  distribuicao(const double &v, Database * database);
	void  CHI_C(Signature * c, int in,int out);
	void  probability_function();
	void  viewValues(std::vector<double> e);
	void  dt(Database *database,int in, int out);
	void  view_CHI_2_RESULTS(Database *database);
	virtual ~Classificator();
};

#endif /* CLASSIFICATOR_H_ */
