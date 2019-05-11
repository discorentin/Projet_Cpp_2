#include "Carc.h"

//CONSTRUCTEURS & DESTRUCTEUR

/*
Carc::Carc()
{
	uiARCdestination = 0;
}
*/

Carc::Carc(Carc & ARCparam)
{
	uiARCdestination = ARCparam.ARCgetDestination();
}

Carc::Carc(unsigned int uiDestination)
{
	uiARCdestination = uiDestination;
}

Carc::~Carc()
{
	//uiARCdestination = 0; //inutile
}

//GETTER

unsigned int Carc::ARCgetDestination()
{
	return uiARCdestination;
}
