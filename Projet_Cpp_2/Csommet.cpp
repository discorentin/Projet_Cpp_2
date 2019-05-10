#include "Csommet.h"

//Constructeurs & Destructeurs

/*
Csommet::Csommet()
{
	uiSOMnumero = 0;
	uiSOMnbPartants = 0;
	uiSOMnbArrivants = 0;
	ppARCSOMarcsPartant = nullptr;
	ppARCSOMarcsArrivant = nullptr;
}
*/

Csommet::Csommet(Csommet & SOMparam)
{
	uiSOMnumero = SOMparam.SOMgetNumero();

	ppARCSOMarcsPartant = (Carc**)malloc(sizeof(Carc *) * SOMparam.SOMgetNbPartants());
	
	for (unsigned int uiCompt = 0; uiCompt < SOMparam.SOMgetNbPartants(); uiCompt++)
	{
		ppARCSOMarcsPartant[uiCompt] = new Carc(SOMparam.SOMgetArcsPartant[uiCompt]);
	}

	ppARCSOMarcsArrivant = (Carc**)malloc(sizeof(Carc *) * SOMparam.SOMgetNbArrivants());

	for (unsigned int uiCompt = 0; uiCompt < SOMparam.SOMgetNbArrivants(); uiCompt++)
	{
		ppARCSOMarcsArrivant[uiCompt] = new Carc(SOMparam.SOMgetArcsArrivant[uiCompt]);
	}

	uiSOMnbPartants = SOMparam.SOMgetNbPartants;
	uiSOMnbArrivants = SOMparam.SOMgetNbArrivants;
}

Csommet::Csommet(unsigned int uiNumero)
{
	uiSOMnumero = uiNumero;
	uiSOMnbPartants = 0;
	uiSOMnbArrivants = 0;
	ppARCSOMarcsPartant = nullptr;
	ppARCSOMarcsArrivant = nullptr;
}

Csommet::~Csommet()
{
	//uiSOMnumero = 0; //inutile

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
	{
		delete[] ppARCSOMarcsPartant[uiCompt];
	}

	delete[] ppARCSOMarcsPartant;

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
	{
		delete[] ppARCSOMarcsArrivant[uiCompt];
	}

	delete[] ppARCSOMarcsArrivant;

	//uiSOMnbPartants = 0; //inutile
	//uiSOMnbArrivants = 0; //inutile
}

//getter & setter

unsigned int Csommet::SOMgetNumero()
{
	return uiSOMnumero;
}

Carc ** Csommet::SOMgetArcsPartant()
{
	return ppARCSOMarcsPartant;
}

Carc * Csommet::SOMgetArcPartant(unsigned int uiDestination)
{
	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
	{
		if (ppARCSOMarcsPartant[uiCompt]->ARCgetDestination() == uiDestination)
		{
			return ppARCSOMarcsPartant[uiCompt];
		}
	}

	//TODO : exception arc non trouvé
}

Carc ** Csommet::SOMgetArcsArrivant()
{
	return ppARCSOMarcsArrivant;
}

Carc * Csommet::SOMgetArcArrivant(unsigned int uiDestination)
{
	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
	{
		if (ppARCSOMarcsArrivant[uiCompt]->ARCgetDestination() == uiDestination)
		{
			return ppARCSOMarcsArrivant[uiCompt];
		}
	}

	//TODO : exception arc non trouvé
}

unsigned int Csommet::SOMgetNbPartants()
{
	return uiSOMnbPartants;
}

unsigned int Csommet::SOMgetNbArrivants()
{
	return uiSOMnbArrivants;
}

void Csommet::SOMsetNumero(unsigned int uiNumero)
{
	uiSOMnumero = uiNumero;
}

//méthodes

void Csommet::SOMajouterArcPartant(unsigned int uiDestination)
{
	ppARCSOMarcsPartant = (Carc**)realloc(ppARCSOMarcsPartant, sizeof(Carc*) * (uiSOMnbPartants + 1));
	ppARCSOMarcsPartant[uiSOMnbPartants] = new Carc(uiDestination);

	uiSOMnbPartants++;

	//TODO : exception arc déjà existant
}

void Csommet::SOMsupprimerArcPartant(unsigned int uiDestination)
{
	bool fait = false;

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
	{
		if (ppARCSOMarcsPartant[uiCompt]->ARCgetDestination == uiDestination)
		{
			delete[] ppARCSOMarcsPartant[uiCompt];
			fait = true;
		}

		if (fait == true && uiCompt < uiSOMnbPartants - 1)
		{
			ppARCSOMarcsPartant[uiCompt] = ppARCSOMarcsPartant[uiCompt + 1];
		}
	}

	uiSOMnbPartants--;

	if (fait == true)
	{
		ppARCSOMarcsPartant = (Carc**)realloc(ppARCSOMarcsPartant, sizeof(Carc*) * uiSOMnbPartants);
	}

	//TODO : exception arc non trouvé
}

void Csommet::SOMajouterArcArrivant(unsigned int uiDestination)
{
	ppARCSOMarcsArrivant = (Carc**)realloc(ppARCSOMarcsArrivant, sizeof(Carc*) * (uiSOMnbArrivants + 1));
	ppARCSOMarcsArrivant[uiSOMnbArrivants] = new Carc(uiDestination);

	uiSOMnbArrivants++;

	//TODO : exception arc déjà existant
}

void Csommet::SOMsupprimerArcArrivant(unsigned int uiDestination)
{
	bool fait = false;

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
	{
		if (ppARCSOMarcsArrivant[uiCompt]->ARCgetDestination == uiDestination)
		{
			delete[] ppARCSOMarcsArrivant[uiCompt];
			fait = true;
		}

		if (fait == true && uiCompt < uiSOMnbArrivants - 1)
		{
			ppARCSOMarcsArrivant[uiCompt] = ppARCSOMarcsArrivant[uiCompt + 1];
		}
	}

	uiSOMnbArrivants--;

	if (fait == true)
	{
		ppARCSOMarcsArrivant = (Carc**)realloc(ppARCSOMarcsArrivant, sizeof(Carc*) * uiSOMnbArrivants);
	}

	//TODO : exception arc non trouvé
}
