#include "Cgraphe.h"
#include "CparseurGraphe.h"

//CONSTRUCTEURS & DESTRUCTEUR

Cgraphe::Cgraphe()
{
	ppSOMGRAsommets = (Csommet **)malloc(sizeof(Csommet *));
	uiGRAnbSommets = 0;
	uiGRAnbArcs = 0;
}

Cgraphe::Cgraphe(Cgraphe & GRAparam)
{
	ppSOMGRAsommets = (Csommet **)malloc(sizeof(Csommet *) * GRAparam.GRAgetNbSommets());
	
	for (unsigned int uiCompt = 0; uiCompt < GRAparam.GRAgetNbSommets(); uiCompt++)
	{
		ppSOMGRAsommets[uiCompt] = new Csommet(*GRAparam.GRAgetSommets()[uiCompt]);
	}

	uiGRAnbSommets = GRAparam.GRAgetNbSommets();
	uiGRAnbArcs = GRAparam.GRAgetNbArcs();
}

Cgraphe::Cgraphe(unsigned int uiNbSommets)
{
	try
	{
		uiGRAnbArcs = 0;
		uiGRAnbSommets = 0;

		ppSOMGRAsommets = (Csommet **)malloc(sizeof(Csommet *));

		for (unsigned int uiCompt = 0; uiCompt < uiNbSommets; uiCompt++)
		{
			GRAajouterSommet(uiCompt + 1); //les numéros des sommets sont attribués automatiquement
		}

		if (uiGRAnbSommets != uiNbSommets)
		{
			throw new Cexception(ERR_CONSTRUCTEUR);
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

Cgraphe::Cgraphe(char * pcFichier)
{
	CparseurGraphe PGRparseur(pcFichier);

	* this = PGRparseur.PGRgetGraphe();
}

Cgraphe::~Cgraphe()
{
	for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
	{
		delete(ppSOMGRAsommets[uiCompt]);
	}

	delete(ppSOMGRAsommets);
}

//GETTER

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

	return nullptr;
}

unsigned int Cgraphe::GRAgetNbSommets()
{
	return uiGRAnbSommets;
}

unsigned int Cgraphe::GRAgetNbArcs()
{
	return uiGRAnbArcs;
}

//METHODES

bool Cgraphe::GRAajouterSommet(unsigned int uiNumero)
{
	if (GRAgetSommet(uiNumero) != nullptr)
	{
		return true;
	}

	ppSOMGRAsommets = (Csommet**)realloc(ppSOMGRAsommets, sizeof(Csommet*) * (uiGRAnbSommets + 1));
	ppSOMGRAsommets[uiGRAnbSommets] = new Csommet(uiNumero);

	uiGRAnbSommets++;

	return false;
}

bool Cgraphe::GRAsupprimerSommet(unsigned int uiNumero)
{
	bool fait = false;

	for (unsigned int uiComptSom0 = 0; uiComptSom0 < uiGRAnbSommets; uiComptSom0++)
	{
		if (ppSOMGRAsommets[uiComptSom0]->SOMgetNumero() == uiNumero)
		{
			uiGRAnbArcs -= ppSOMGRAsommets[uiComptSom0]->SOMgetNbPartants;

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

			for (unsigned int uiComptSom1 = 0; uiComptSom1 < uiNbArrivants; uiComptSom1++)
			{
				GRAgetSommet(ppARCarcsArrivant[uiComptSom1]->ARCgetDestination())->SOMsupprimerArcPartant(uiNumero);
			}

			//suppression du sommet
			delete(ppSOMGRAsommets[uiComptSom0]);

			fait = true;
		}

		if ((fait == true) && (uiComptSom0 < uiGRAnbSommets - 1))
		{
			ppSOMGRAsommets[uiComptSom0] = ppSOMGRAsommets[uiComptSom0 + 1];
		}
	}

	uiGRAnbSommets--;

	if (fait == true)
	{
		ppSOMGRAsommets = (Csommet**)realloc(ppSOMGRAsommets, sizeof(Csommet*) * uiGRAnbSommets);
		return false;
	}
	else
	{
		return true;
	}
}

bool Cgraphe::GRAajouterArc(unsigned int uiDepart, unsigned int uiDestination)
{
	bool bDejaPresentDepart = false;
	bool bDejaPresentDestination = false;

	for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
	{
		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDepart)
		{
			if (ppSOMGRAsommets[uiCompt]->SOMajouterArcPartant(uiDestination) == true)
			{
				bDejaPresentDepart = true;
			}
		}


		if (ppSOMGRAsommets[uiCompt]->SOMgetNumero() == uiDestination)
		{
			if (ppSOMGRAsommets[uiCompt]->SOMajouterArcArrivant(uiDepart) == true)
			{
				bDejaPresentDestination = true;
			}
		}
	}

	if (bDejaPresentDepart == true && bDejaPresentDestination == true)
	{
		return true;
	}
	else
	{
		uiGRAnbArcs++;
		return false;
	}
}

bool Cgraphe::GRAsupprimerArc(unsigned int uiDepart, unsigned int uiDestination)
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
			ppSOMGRAsommets[uiCompt]->SOMsupprimerArcArrivant(uiDepart);
			faitArrivant = true;
		}
	}

	if ((faitPartant == false) || (faitArrivant == false))
	{
		return true;
	}
	else
	{
		uiGRAnbArcs--;
		return false;
	}
}

void Cgraphe::GRAafficherGraphe()
{
	unsigned int uiNbArcs = 0;

	for (unsigned int uiComptSom = 0; uiComptSom < uiGRAnbSommets; uiComptSom++)
	{
		for (unsigned int uiComptArc = 0; uiComptArc < ppSOMGRAsommets[uiComptSom]->SOMgetNbPartants(); uiComptArc++)
		{
			uiNbArcs++;
		}
	}

	printf("Graphe :\n	Nombre de sommets : %d\n	Nombre d'arcs : %d\n\n	Sommets :\n", uiGRAnbSommets, uiNbArcs);

	for (unsigned int uiCompt = 0; uiCompt < uiGRAnbSommets; uiCompt++)
	{
		printf("		%d\n", ppSOMGRAsommets[uiCompt]->SOMgetNumero());
	}

	printf("\n	Arcs :\n");

	for (unsigned int uiComptSom = 0; uiComptSom < uiGRAnbSommets; uiComptSom++)
	{
		for (unsigned int uiComptArc = 0; uiComptArc < ppSOMGRAsommets[uiComptSom]->SOMgetNbPartants(); uiComptArc++)
		{
			printf("		%d -> %d\n", ppSOMGRAsommets[uiComptSom]->SOMgetNumero(),
				ppSOMGRAsommets[uiComptSom]->SOMgetArcsPartant()[uiComptArc]->ARCgetDestination());
		}
	}

	printf("\n");
}

void Cgraphe::GRAinverserGraphe()
{
	unsigned int uiComptSom;
	unsigned int uiComptArc;
	Cgraphe * pGRAgrapheTmp = new Cgraphe(* this);

	for (uiComptSom = 0; uiComptSom < pGRAgrapheTmp->GRAgetNbSommets(); uiComptSom++)
	{
		for (uiComptArc = 0; uiComptArc < pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetNbPartants(); uiComptArc++)
		{
			ppSOMGRAsommets[uiComptSom]->SOMsupprimerArcPartant(pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetArcsPartant()[uiComptArc]->ARCgetDestination());
		}

		for (uiComptArc = 0; uiComptArc < pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetNbPartants(); uiComptArc++)
		{
			ppSOMGRAsommets[uiComptSom]->SOMajouterArcPartant(pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetArcsArrivant()[uiComptArc]->ARCgetDestination());
		}

		for (uiComptArc = 0; uiComptArc < pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetNbArrivants(); uiComptArc++)
		{
			ppSOMGRAsommets[uiComptSom]->SOMsupprimerArcArrivant(pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetArcsArrivant()[uiComptArc]->ARCgetDestination());
		}

		for (uiComptArc = 0; uiComptArc < pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetNbArrivants(); uiComptArc++)
		{
			ppSOMGRAsommets[uiComptSom]->SOMajouterArcArrivant(pGRAgrapheTmp->GRAgetSommets()[uiComptSom]->SOMgetArcsPartant()[uiComptArc]->ARCgetDestination());
		}
	}
}

//SURCHARGE D'OPERATEUR

Cgraphe & Cgraphe::operator=(Cgraphe & GRAparam)
{
	try
	{
		uiGRAnbSommets = 0;
		ppSOMGRAsommets = (Csommet **)malloc(sizeof(Csommet *) * GRAparam.GRAgetNbSommets());

		for (unsigned int uiCompt = 0; uiCompt < GRAparam.GRAgetNbSommets(); uiCompt++)
		{
			ppSOMGRAsommets[uiCompt] = new Csommet(*GRAparam.GRAgetSommets()[uiCompt]);
			uiGRAnbSommets++;
		}

		if (uiGRAnbSommets == GRAparam.GRAgetNbSommets())
		{
			return * this;
		}
		else
		{
			throw new Cexception(ERR_CONSTRUCTEUR);
		}		
	}
	catch(Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
		return * this;
	}
}
