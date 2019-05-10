#include "Carc.h"

//Constructeurs & Destructeurs

/*
Carc::Carc()
{
	uiARCdestination = 0;
}
*/

Carc::Carc(Carc & ARCparam)
{
	uiARCdestination = ARCparam.ARCgetDestination;
}

Carc::Carc(unsigned int uiDestination)
{
	uiARCdestination = uiDestination;
}

Carc::~Carc()
{
	//uiARCdestination = 0; //inutile
}

//getter & setter

unsigned int Carc::ARCgetDestination()
{
	return uiARCdestination;
}

void Carc::ARCsetDestination(unsigned int uiDestination)
{
	uiARCdestination = uiDestination;
}
