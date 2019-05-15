#ifndef CparseurGraphe_H
#define CparseurGraphe_H 0

#include "Cparseur.h"
#include "Cgraphe.h"
#include <string>

class CparseurGraphe : public Cparseur
{

private :
	enum Attribut
	{
		NBSOMMETS, NBARCS, SOMMETS, ARCS, INVALIDE
	};

	Cgraphe * pGRAgraphe;

	//METHODES
	Attribut PGRtraduireAttribut(char * pcAttribut);
	void PGRgenererSommets(char ** ppcSommets, unsigned int uiNbSommets);
	void PGRgenererArcs(char ** ppcArcs, unsigned int uiNbArcs);

public:
	//CONSTRUCTEUR & DESTRUCTEUR
	CparseurGraphe(char * pcFichier);
	~CparseurGraphe();

	//GETTER
	Cgraphe & PGRgetGraphe();
};

#endif

