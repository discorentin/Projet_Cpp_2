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
	uiSOMnumero = SOMparam.SOMgetNumero();

	for (unsigned int uiCompt = 0; uiCompt < SOMparam.SOMgetNbPartants(); uiCompt++)
	{
		SOMajouterArcPartant(SOMparam.SOMgetArcsPartant()[uiCompt]->ARCgetDestination());
	}

	for (unsigned int uiCompt = 0; uiCompt < SOMparam.SOMgetNbArrivants(); uiCompt++)
	{
		SOMajouterArcArrivant(SOMparam.SOMgetArcsArrivant()[uiCompt]->ARCgetDestination());
	}

	uiSOMnbPartants = SOMparam.SOMgetNbPartants();
	uiSOMnbArrivants = SOMparam.SOMgetNbArrivants();
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

void Csommet::SOMajouterArcPartant(unsigned int uiDestination)
{
	try
	{
		for (unsigned int uiCompt = 0; uiCompt < uiSOMnbPartants; uiCompt++)
		{
			if (ppARCSOMarcsPartant[uiCompt]->ARCgetDestination() == uiDestination)
			{
				throw new Cexception(ERR_AJOUT);
			}
		}
		
		ppARCSOMarcsPartant = (Carc**)realloc(ppARCSOMarcsPartant, sizeof(Carc*) * (uiSOMnbPartants + 1));
		ppARCSOMarcsPartant[uiSOMnbPartants] = new Carc(uiDestination);

		uiSOMnbPartants++;
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

void Csommet::SOMsupprimerArcPartant(unsigned int uiDestination)
{
	try
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
		}
		else
		{
			throw new Cexception(ERR_SUPPRESSION);
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}

}

void Csommet::SOMajouterArcArrivant(unsigned int uiDestination)
{
	try
	{
		for (unsigned int uiCompt = 0; uiCompt < uiSOMnbArrivants; uiCompt++)
		{
			if (ppARCSOMarcsArrivant[uiCompt]->ARCgetDestination() == uiDestination)
			{
				throw new Cexception(ERR_AJOUT);
			}
		}

		ppARCSOMarcsArrivant = (Carc**)realloc(ppARCSOMarcsArrivant, sizeof(Carc*) * (uiSOMnbArrivants + 1));
		ppARCSOMarcsArrivant[uiSOMnbArrivants] = new Carc(uiDestination);

		uiSOMnbArrivants++;
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

void Csommet::SOMsupprimerArcArrivant(unsigned int uiDestination)
{
	try
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
		}
		else
		{
			throw new Cexception(ERR_SUPPRESSION);
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}
