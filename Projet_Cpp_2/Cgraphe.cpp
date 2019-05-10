#include "Cgraphe.h"

//Constructeurs & Destructeurs

Cgraphe::Cgraphe()
{
	ppSOMGRAsommets = nullptr;
	uiGRAnbSommets = 0;
}

Cgraphe::Cgraphe(Cgraphe & GRAparam)
{
	ppSOMGRAsommets = (Csommet **)malloc(sizeof(Csommet *) * GRAparam.GRAgetNbSommets());
	
	for (unsigned int uiCompt = 0; uiCompt < GRAparam.GRAgetNbSommets(); uiCompt++)
	{
		ppSOMGRAsommets[uiCompt] = new Csommet(*GRAparam.GRAgetSommets()[uiCompt]);
	}

	uiGRAnbSommets = GRAparam.GRAgetNbSommets();
}

Cgraphe::Cgraphe(unsigned int uiNbSommets)
{
	ppSOMGRAsommets = (Csommet **)malloc(sizeof(Csommet *) * uiNbSommets);

	for (unsigned int uiCompt = 1; uiCompt <= uiNbSommets; uiCompt++)
	{
		ppSOMGRAsommets[uiCompt] = new Csommet(uiCompt); //les num�ros des sommets sont attribu�s automatiquement
	}

	uiGRAnbSommets = uiNbSommets;
}

Cgraphe::~Cgraphe()
{
	for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
	{
		delete[] ppSOMGRAsommets[uiCompt];
	}

	delete[] ppSOMGRAsommets;

	//uiGRAnbSommets = 0; //inutile
}

//getter & setter

Csommet ** Cgraphe::GRAgetSommets()
{
	return ppSOMGRAsommets;
}

Csommet * Cgraphe::GRAgetSommet(unsigned int uiNumero)
{
	for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
	{
		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiNumero)
		{
			return ppSOMGRAsommets[uiCompt];
		}
	}

	return 0;
}

unsigned int Cgraphe::GRAgetNbSommets()
{
	return uiGRAnbSommets;
}

void Cgraphe::GRAsetNbSommets(unsigned int uiNbSommets)
{
	uiGRAnbSommets = uiNbSommets;
}

//m�thodes

void Cgraphe::GRAajouterSommet(unsigned int uiNumero)
{
	try
	{
		for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
		{
			if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiNumero)
			{
				throw new Cexception(ERR_AJOUT);
			}
		}

		ppSOMGRAsommets = (Csommet**)realloc(ppSOMGRAsommets, sizeof(Csommet*) * (uiGRAnbSommets + 1));
		ppSOMGRAsommets[uiGRAnbSommets] = new Csommet(uiNumero);

		uiGRAnbSommets++;
	}
	catch(Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

void Cgraphe::GRAsupprimerSommet(unsigned int uiNumero)
{
	try
	{
		bool fait = false;

		for (unsigned int uiComptSom0 = 0; uiComptSom0 < uiGRAnbSommets; uiComptSom0++)
		{
			if (ppSOMGRAsommets[uiComptSom0]->SOMgetNumero() == uiNumero)
			{

				//sauvegarde des arcs partants du sommet � supprimer
				Carc** ppARCarcsPartant = ppSOMGRAsommets[uiComptSom0]->SOMgetArcsPartant();
				unsigned int uiNbPartants = ppSOMGRAsommets[uiComptSom0]->SOMgetNbPartants();

				//sauvegarde des arcs arrivant au sommet � supprimer
				Carc** ppARCarcsArrivant = ppSOMGRAsommets[uiComptSom0]->SOMgetArcsArrivant();
				unsigned int uiNbArrivants = ppSOMGRAsommets[uiComptSom0]->SOMgetNbArrivants();

				//suppression des arcs dans les sommets connect�s au sommet � supprimer

				for (unsigned int uiComptSom1 = 0; uiComptSom1 < uiNbPartants; uiComptSom1++)
				{
					GRAgetSommet(ppARCarcsPartant[uiComptSom1]->ARCgetDestination())->SOMsupprimerArcArrivant(uiNumero);
				}

				for (unsigned int uiComptSom1 = 0; uiComptSom1 < uiNbPartants; uiComptSom1++)
				{
					GRAgetSommet(ppARCarcsArrivant[uiComptSom1]->ARCgetDestination())->SOMsupprimerArcPartant(uiNumero);
				}

				//suppression du sommet
				delete[] ppSOMGRAsommets[uiComptSom0];

				fait = true;
			}

			if (fait == true && uiComptSom0 < uiGRAnbSommets - 1)
			{
				ppSOMGRAsommets[uiComptSom0] = ppSOMGRAsommets[uiComptSom0 + 1];
			}
		}

		uiGRAnbSommets--;

		if (fait == true)
		{
			ppSOMGRAsommets = (Csommet**)realloc(ppSOMGRAsommets, sizeof(Csommet*) * uiGRAnbSommets);
		}
		else
		{
			throw new Cexception(ERR_SUPPRESSION);
		}
	}
	catch(Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

void Cgraphe::GRAajouterArc(unsigned int uiDepart, unsigned int uiDestination)
{
	for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
	{
		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDepart)
		{
			ppSOMGRAsommets[uiCompt]->SOMajouterArcPartant(uiDestination);
		}

		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDestination)
		{
			ppSOMGRAsommets[uiCompt]->SOMajouterArcArrivant(uiDestination);
		}
	}

	//TODO : exception arc d�j� existant
}

void Cgraphe::GRAsupprimerArc(unsigned int uiDepart, unsigned int uiDestination)
{
	try
	{
		bool faitPartant = false;
		bool faitArrivant = false;

		for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
		{
			if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDepart)
			{
				ppSOMGRAsommets[uiCompt]->SOMsupprimerArcPartant(uiDestination);
				faitPartant = true;
			}

			if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDestination)
			{
				ppSOMGRAsommets[uiCompt]->SOMsupprimerArcArrivant(uiDestination);
				faitPartant = true;
			}
		}

		if (faitPartant == false || faitArrivant == false)
		{
			throw new Cexception(ERR_SUPPRESSION);
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

void Cgraphe::GRAafficherGraphe()
{
}

void Cgraphe::GRAinverserGraphe()
{
}
