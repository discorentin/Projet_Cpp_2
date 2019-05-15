#ifndef Cgraphe_H
#define Cgraphe_H 0

#include "Csommet.h"

class Cgraphe{

private:
	Csommet ** ppSOMGRAsommets;
	unsigned int uiGRAnbSommets;

public:
	//CONSTRUCTEURS & DESTRUCTEUR
	Cgraphe();
	Cgraphe(Cgraphe & GRAparam);
	Cgraphe(unsigned int uiNbSommets);
	Cgraphe(char * pcFichier);

	~Cgraphe();

	//GETTER
	Csommet ** GRAgetSommets();
	Csommet * GRAgetSommet(unsigned int uiNumero);
	unsigned int GRAgetNbSommets();

	//METHODES
	void GRAajouterSommet(unsigned int uiNumero);
	void GRAsupprimerSommet(unsigned int uiNumero);
	void GRAajouterArc(unsigned int uiDepart, unsigned int uiDestination);
	void GRAsupprimerArc(unsigned int uiDepart, unsigned int uiDestination);
	void GRAafficherGraphe();
	void GRAinverserGraphe();

	//SURCHARGE D'OPERATEUR
	Cgraphe & operator=(Cgraphe & GRAparam);
};

#endif