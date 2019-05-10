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
		ppSOMGRAsommets[uiCompt] = new Csommet(uiCompt); //les numéros des sommets sont attribués automatiquement
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

	//TODO : exception sommet non trouvé
}

unsigned int Cgraphe::GRAgetNbSommets()
{
	return uiGRAnbSommets;
}

void Cgraphe::GRAsetNbSommets(unsigned int uiNbSommets)
{
	uiGRAnbSommets = uiNbSommets;
}

//méthodes

void Cgraphe::GRAajouterSommet(unsigned int uiNumero)
{
	ppSOMGRAsommets = (Csommet**)realloc(ppSOMGRAsommets, sizeof(Csommet*) * (uiGRAnbSommets + 1));
	ppSOMGRAsommets[uiGRAnbSommets] = new Csommet(uiNumero);

	uiGRAnbSommets++;

	//TODO : exception sommet déjà existant
}

void Cgraphe::GRAsupprimerSommet(unsigned int uiNumero)
{
	bool fait = false;

	for (unsigned int uiComptSom0 = 0; uiComptSom0 < uiGRAnbSommets; uiComptSom0++)
	{
		if (ppSOMGRAsommets[uiComptSom0]->SOMgetNumero() == uiNumero)
		{
			
			//sauvegarde des arcs partants du sommet à supprimer
			Carc** ppARCarcsPartant = ppSOMGRAsommets[uiComptSom0]->SOMgetArcsPartant();
			unsigned int uiNbPartants = ppSOMGRAsommets[uiComptSom0]->SOMgetNbPartants();

			//sauvegarde des arcs arrivant au sommet à supprimer
			Carc** ppARCarcsArrivant = ppSOMGRAsommets[uiComptSom0]->SOMgetArcsArrivant();
			unsigned int uiNbArrivants = ppSOMGRAsommets[uiComptSom0]->SOMgetNbArrivants();

			//suppression des arcs dans les sommets connectés au sommet à supprimer

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

	//TODO : exception sommet non trouvé
}

void Cgraphe::GRAajouterArc(unsigned int uiDepart, unsigned int uiDestination)
{
	unsigned int uiCompt = 0;

	while (uiCompt < uiGRAnbSommets)
	{
		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDepart)
		{
			ppSOMGRAsommets[uiCompt]->SOMajouterArcPartant(uiDestination);
		}

		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDestination)
		{
			ppSOMGRAsommets[uiCompt]->SOMajouterArcArrivant(uiDestination);
		}
		
		uiCompt++;
	}

	//TODO : exception arc déjà existant
}

void Cgraphe::GRAsupprimerArc(unsigned int uiDepart, unsigned int uiDestination)
{
	unsigned int uiCompt = 0;

	while (uiCompt < uiGRAnbSommets)
	{
		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDepart)
		{
			ppSOMGRAsommets[uiCompt]->SOMsupprimerArcPartant(uiDestination);
		}

		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDestination)
		{
			ppSOMGRAsommets[uiCompt]->SOMsupprimerArcArrivant(uiDestination);
		}

		uiCompt++;
	}
}

void Cgraphe::GRAafficherGraphe()
{
}

void Cgraphe::GRAinverserGraphe()
{
}
