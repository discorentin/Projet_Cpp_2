#include "Carc.h"

class Csommet
{

private:
	unsigned int uiSOMnumero;

	Carc ** ppARCSOMarcsPartant;
	Carc ** ppARCSOMarcsArrivant;

	unsigned int uiSOMnbPartants;
	unsigned int uiSOMnbArrivants;

public:
	//cCONSTRUCTEURS & DESTRUCTEUR
	//Csommet(); //inutile
	Csommet(Csommet & SOMparam);
	Csommet(unsigned int uiNumero);

	~Csommet();

	//GETTER
	unsigned int SOMgetNumero();
	Carc ** SOMgetArcsPartant();
	Carc * SOMgetArcPartant(unsigned int uiDestination);
	Carc ** SOMgetArcsArrivant();
	Carc * SOMgetArcArrivant(unsigned int uiDestination);
	unsigned int SOMgetNbPartants();
	unsigned int SOMgetNbArrivants();

	//METHODES
	void SOMajouterArcPartant(unsigned int uiDestination);
	void SOMsupprimerArcPartant(unsigned int uiDestination);
	void SOMajouterArcArrivant(unsigned int uiDestination);
	void SOMsupprimerArcArrivant(unsigned int uiDestination);
};