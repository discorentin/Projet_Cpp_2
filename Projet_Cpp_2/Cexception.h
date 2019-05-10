#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERR_AJOUT 1
#define ERR_SUPPRESSION 2

class Cexception
{
private :
	unsigned int uiEXCerreur;

public:
	//Constructeurs & Destructeur
	Cexception(unsigned int uiErreur) throw();

	~Cexception();

	//getter & setter
	unsigned int EXCgetErreur();
	void EXCsetErreur(unsigned int uiErreur);

	//m�thodes
	void EXCafficherErreur();
};
