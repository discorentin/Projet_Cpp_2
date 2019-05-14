#ifndef Carc_H
#define Carc_H 0

#include <stdio.h> 
#include <stdlib.h>
#include "Cexception.h"

class Carc
{

private:
	unsigned int uiARCdestination;

public:
	//CONSTRUCTEURS & DESTRUCTEUR
	//Carc(); //inutile
	Carc(Carc & ARCparam);
	Carc(unsigned int uiDestination);

	~Carc();

	//GETTER
	unsigned int ARCgetDestination();
};

#endif