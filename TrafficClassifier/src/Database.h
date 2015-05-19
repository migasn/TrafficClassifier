/*
 * Database.h
 *
 *  Created on: Mar 23, 2011
 *      Author: miguel
 */

#ifndef DATABASE_H_
#define DATABASE_H_
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

class Database {

private:
	std::string path;
	int size;
	std::vector<Signature *> signatures;


public:
	Database(std::string path, int size);
	void carrega();
	std::vector<Signature*> getSignatures();
	Signature * carrega(std::string file);
	void view_Signature();
	virtual ~Database();
};

#endif /* DATABASE_H_ */
