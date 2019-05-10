#include "Csommet.h"

class Cgraphe{

private:
	Csommet ** ppSOMGRAsommets;
	unsigned int uiGRAnbSommets;

public:
	//Constructeurs & Destructeurs
	Cgraphe();
	Cgraphe(Cgraphe & GRAparam);
	Cgraphe(unsigned int uiNbSommets);

	~Cgraphe();

	//getter & setter
	Csommet ** GRAgetSommets();
	Csommet * GRAgetSommet(unsigned int uiNumero);
	unsigned int GRAgetNbSommets();

	void GRAsetNbSommets(unsigned int uiNbSommets);

	//méthodes
	void GRAajouterSommet(unsigned int uiNumero);
	void GRAsupprimerSommet(unsigned int uiNumero);
	void GRAajouterArc(unsigned int uiDepart, unsigned int uiDestination);
	void GRAsupprimerArc(unsigned int uiDepart, unsigned int uiDestination);
	void GRAafficherGraphe();
	void GRAinverserGraphe();
};