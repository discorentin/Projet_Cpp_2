#include "Csommet.h"

//CONSTRUCTEURS & DESTRUCTEUR

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
	try
	{
		uiSOMnumero = SOMparam.SOMgetNumero();
		uiSOMnbPartants = 0;
		uiSOMnbArrivants = 0;

		ppARCSOMarcsPartant = (Carc **)malloc(sizeof(Carc *));
		ppARCSOMarcsArrivant = (Carc **)malloc(sizeof(Carc *));

		for (unsigned int uiCompt = 0; uiCompt < SOMparam.SOMgetNbPartants(); uiCompt++)
		{
			SOMajouterArcPartant(SOMparam.SOMgetArcsPartant()[uiCompt]->ARCgetDestination());
		}

		for (unsigned int uiCompt = 0; uiCompt < SOMparam.SOMgetNbArrivants(); uiCompt++)
		{
			SOMajouterArcArrivant(SOMparam.SOMgetArcsArrivant()[uiCompt]->ARCgetDestination());
		}

		if (uiSOMnbPartants != SOMparam.SOMgetNbPartants() || uiSOMnbArrivants != SOMparam.SOMgetNbArrivants())
		{
			throw new Cexception(ERR_CONSTRUCTEUR);
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

Csommet::Csommet(unsigned int uiNumero)
{
	uiSOMnumero = uiNumero;
	uiSOMnbPartants = 0;
	uiSOMnbArrivants = 0;
	ppARCSOMarcsPartant = (Carc **)malloc(sizeof(Carc *));
	ppARCSOMarcsArrivant = (Carc **)malloc(sizeof(Carc *));
}

Csommet::~Csommet()
{
	//uiSOMnumero = 0; //inutile

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
	{
		delete(ppARCSOMarcsPartant[uiCompt]);
	}

	delete(ppARCSOMarcsPartant);

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
	{
		delete(ppARCSOMarcsArrivant[uiCompt]);
	}

	delete(ppARCSOMarcsArrivant);

	//uiSOMnbPartants = 0; //inutile
	//uiSOMnbArrivants = 0; //inutile
}

//GETTER

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

	return nullptr;
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

	return nullptr;
}

unsigned int Csommet::SOMgetNbPartants()
{
	return uiSOMnbPartants;
}

unsigned int Csommet::SOMgetNbArrivants()
{
	return uiSOMnbArrivants;
}

//METHODES

bool Csommet::SOMajouterArcPartant(unsigned int uiDestination)
{
	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
	{
		if (ppARCSOMarcsPartant[uiCompt]->ARCgetDestination() == uiDestination)
		{
			return true;
		}
	}
		
	ppARCSOMarcsPartant = (Carc**)realloc(ppARCSOMarcsPartant, sizeof(Carc*) * (uiSOMnbPartants + 1));
	ppARCSOMarcsPartant[uiSOMnbPartants] = new Carc(uiDestination);

	uiSOMnbPartants ++;

	return false;
}

bool Csommet::SOMsupprimerArcPartant(unsigned int uiDestination)
{
	bool fait = false;

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
	{
		if (ppARCSOMarcsPartant[uiCompt]->ARCgetDestination() == uiDestination)
		{
			delete(ppARCSOMarcsPartant[uiCompt]);
			fait = true;
		}

		if ((fait == true) && (uiCompt < (uiSOMnbPartants - 1)))
		{
			ppARCSOMarcsPartant[uiCompt] = ppARCSOMarcsPartant[uiCompt + 1];
		}
	}

	uiSOMnbPartants--;

	if (fait == true)
	{
		ppARCSOMarcsPartant = (Carc**)realloc(ppARCSOMarcsPartant, sizeof(Carc*) * uiSOMnbPartants);
		return false;
	}
	else
	{
		return true;
	}
}

bool Csommet::SOMajouterArcArrivant(unsigned int uiDestination)
{
	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
	{
		if (ppARCSOMarcsArrivant[uiCompt]->ARCgetDestination() == uiDestination)
		{
			return true;
		}
	}

	ppARCSOMarcsArrivant = (Carc**)realloc(ppARCSOMarcsArrivant, sizeof(Carc*) * (uiSOMnbArrivants + 1));
	ppARCSOMarcsArrivant[uiSOMnbArrivants] = new Carc(uiDestination);

	uiSOMnbArrivants++;

	return false;
}

bool Csommet::SOMsupprimerArcArrivant(unsigned int uiDestination)
{
	bool fait = false;

	for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
	{
		if (ppARCSOMarcsArrivant[uiCompt]->ARCgetDestination() == uiDestination)
		{
			delete(ppARCSOMarcsArrivant[uiCompt]);
			fait = true;
		}

		if ((fait == true) && (uiCompt < (uiSOMnbArrivants - 1)))
		{
			ppARCSOMarcsArrivant[uiCompt] = ppARCSOMarcsArrivant[uiCompt + 1];
		}
	}

	uiSOMnbArrivants--;

	if (fait == true)
	{
		ppARCSOMarcsArrivant = (Carc**)realloc(ppARCSOMarcsArrivant, sizeof(Carc*) * uiSOMnbArrivants);
		return false;
	}
	else
	{
		return true;
	}
}
