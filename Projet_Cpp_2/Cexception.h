#ifndef Cexception_H
#define Cexception_H 0

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERR_CONSTRUCTEUR 1
#define ERR_AJOUT 2
#define ERR_SUPPRESSION 3
#define ERR_LECTURE 4

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

	//méthodes
	void EXCafficherErreur();
};

#endif