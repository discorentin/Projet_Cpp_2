#include "Carc.h"

//CONSTRUCTEURS & DESTRUCTEUR

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
}

//GETTER

unsigned int Carc::ARCgetDestination()
{
	return uiARCdestination;
}
