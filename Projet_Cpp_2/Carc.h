#include <stdio.h> 
#include <stdlib.h>
#include "Cexception.h"
class Carc
{

private:
	unsigned int uiARCdestination;

public:
	//Constructeurs & Destructeurs
	//Carc(); //inutile
	Carc(Carc & ARCparam);
	Carc(unsigned int uiDestination);

	~Carc();

	//getter & setter
	unsigned int ARCgetDestination();

	void ARCsetDestination(unsigned int uiDestination);
};