/*
 * Signature.h
 *
 *  Created on: Mar 23, 2011
 *      Author: miguel
 */

#ifndef SIGNATURE_H_
#define SIGNATURE_H_
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
#include <deque>
class Signature {
private:
	double soma;
	std::string classe;
	std::vector<double> valores;

public:
	Signature(std::string classe, std::vector<double> valores);
	virtual ~Signature();
	double getSoma();
	void viewValues();
	std::vector<double> getValores();
	void setSoma(double soma);
	std::string getClasse();
};

#endif /* SIGNATURE_H_ */
