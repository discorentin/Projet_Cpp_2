#include "CparseurGraphe.h"

//CONSTRUCTEUR & DESTRUCTEUR

CparseurGraphe::CparseurGraphe(char * pcFichier)
	:Cparseur(pcFichier)
{
	unsigned int uiCompt;
	unsigned int uiNbSommets;
	unsigned int uiNbArcs;
	bool bModifNbSommets = false;
	bool bModifNbArcs = false;

	GRAgraphe = new Cgraphe();

	for (uiCompt = 0; uiCompt < PARgetNbAttributs(); uiCompt++)
	{
		switch (PGRtraduireAttribut(PARgetAttribut(uiCompt)))
		{
		case NBSOMMETS : 
			uiNbSommets = (unsigned int)(std::stoi(PARgetValeur(uiCompt)[0]));
			bModifNbSommets = true;
			break;

		case NBARCS :
			uiNbArcs = (unsigned int)(std::stoi(PARgetValeur(uiCompt)[0]));
			bModifNbArcs = true;
			break;

		case SOMMETS :
			if (bModifNbSommets = true)
			{
				PGRgenererSommets(PARgetValeur(uiCompt), uiNbSommets);
				break;
			}
			else
			{
				throw new Cexception(ERR_FORMAT);
			}

		case ARCS :
			if (bModifNbArcs = true)
			{
				PGRgenererArcs(PARgetValeur(uiCompt), uiNbArcs);
				break;
			}
			else
			{
				throw new Cexception(ERR_FORMAT);
			}

		case INVALIDE :
			throw new Cexception(ERR_FORMAT);
			break;
		}
	}
}

CparseurGraphe::~CparseurGraphe()
{
}

//GETTER

Cgraphe & CparseurGraphe::PGRgetGraphe()
{
	return * GRAgraphe;
}

//METHODES

CparseurGraphe::Attribut CparseurGraphe::PGRtraduireAttribut(char * pcAttribut)
{
	if (strcmp(pcAttribut, "NBSommets") == 0)
	{
		return NBSOMMETS;
	}
	else if (strcmp(pcAttribut, "NBArcs") == 0)
	{
		return NBARCS;
	}
	else if (strcmp(pcAttribut, "Sommets") == 0)
	{
		return SOMMETS;
	}
	else if (strcmp(pcAttribut, "Arcs") == 0)
	{
		return ARCS;
	}
	else
	{
		return INVALIDE;
	}
}

void CparseurGraphe::PGRgenererSommets(char ** ppcSommets, unsigned int uiNbSommets)
{
	try
	{
		unsigned int uiCompt;
		unsigned int uiEmplacementEgal;
		unsigned int uiNumero;
		std::string sSommet;

		for (uiCompt = 0; uiCompt < uiNbSommets; uiCompt++)
		{
			sSommet = ppcSommets[uiCompt];
			uiEmplacementEgal = sSommet.find('=');

			if ((uiEmplacementEgal != std::string::npos) && (sSommet.substr(0, uiEmplacementEgal) == "Numero"))
			{
				uiNumero = (unsigned int)(std::stoi(sSommet.substr(uiEmplacementEgal + 1)));
				GRAgraphe->GRAajouterSommet(uiNumero);
			}
			else
			{
				throw new Cexception(ERR_FORMAT);
			}
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

void CparseurGraphe::PGRgenererArcs(char ** ppcArcs, unsigned int uiNbArcs)
{
	try
	{
		unsigned int uiComptArcs;
		unsigned int uiEmplacementVirgule;
		unsigned int uiEmplacementEgalDebut;
		unsigned int uiEmplacementEgalFin;
		unsigned int uiDebut;
		unsigned int uiFin;
		std::string sArc;
		std::string sDebut;
		std::string sFin;

		for (uiComptArcs = 0; uiComptArcs < uiNbArcs; uiComptArcs++)
		{
			sArc = ppcArcs[uiComptArcs];
			uiEmplacementVirgule = sArc.find(", ");

			if (uiEmplacementVirgule != std::string::npos)
			{
				sDebut = sArc.substr(0, uiEmplacementVirgule);
				uiEmplacementEgalDebut = sDebut.find('=');
				sFin = sArc.substr(uiEmplacementVirgule + 2);
				uiEmplacementEgalFin = sFin.find('=');
			}
			else
			{
				throw new Cexception(ERR_FORMAT);
			}

			if ((uiEmplacementEgalDebut != std::string::npos) && (sDebut.substr(0, uiEmplacementEgalDebut) == "Debut"))
			{
				uiDebut = (unsigned int)(std::stoi(sDebut.substr(uiEmplacementEgalDebut + 1)));
			}
			else
			{
				throw new Cexception(ERR_FORMAT);
			}

			if ((uiEmplacementEgalFin != std::string::npos) && (sFin.substr(0, uiEmplacementEgalFin) == "Fin"))
			{
				uiFin = (unsigned int)(std::stoi(sFin.substr(uiEmplacementEgalFin + 1)));
			}
			else
			{
				throw new Cexception(ERR_FORMAT);
			}

			GRAgraphe->GRAajouterArc(uiDebut, uiFin);
		}
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}
