/*
 * Database.cpp
 *
 *  Created on: Mar 23, 2011
 *      Author: miguel
 */

#include "Database.h"

Database::Database(std::string path, int size) {

	this->path=path;
	this->size=size;
	this->signatures;

}



std::vector<Signature * > Database::getSignatures(){

	return this->signatures;

}


Signature * Database::carrega(std::string file){

	std::ifstream f(file.c_str());
	int i=0;
	std::string line_f;
	std::string classe;
	std::vector<double> values;

	 if (f.is_open()){
		 getline(f,classe);
			//std::cout << classe << std::endl;
			int contador=0;
			    while (!f.eof()){
			    	if(contador==100)
			    		break;
			      getline (f,line_f);
			     // std::cout<< atof(line_f.c_str())<< "    "<< std::endl;
			      values.push_back(atof(line_f.c_str()));
			    contador++;
			    }


	 }


Signature * pt= new Signature (classe,values);


return pt;
}

void Database::view_Signature(){

	for(int i=0; i< this->signatures.size();i++){

		Signature * c = this->signatures[i];
		std::cout<< "Classe: "<< c->getClasse() << std::endl;
		std::vector<double> values =c->getValores();

		for(int j=0; j<values.size();j++){

			std::cout<< values[j]<< "    " ;
		}

		std::cout<<""<< std::endl;

	}



}


void Database::carrega(){

	struct dirent *drnt;
	std::vector<std::string> files;
	DIR *dr;

			dr=opendir(this->path.c_str());
				 while(drnt = readdir(dr)){

					 if(strcmp(drnt->d_name,"..")==0)
						 continue;

					 if(strcmp(drnt->d_name,".")==0)
						 continue;

					 files.push_back(this->path + (const char *)drnt->d_name);
				     }
				closedir(dr);


				for(int i=0; i< files.size();i++){

							Signature * c=carrega(files[i]);
							this->signatures.push_back(c);
				}
}

Database::~Database() {
	// TODO Auto-generated destructor stub
}
