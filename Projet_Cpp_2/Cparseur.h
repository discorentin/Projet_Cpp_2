#ifndef Cparseur_H
#define Cparseur_H 0

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Cexception.h"

#define SIZEMAX 256

using namespace std;

class Cparseur
{

private:
	char ** pcPARattributs;
	char ** ppcPARvaleurs[SIZEMAX];
	unsigned int uiPARnbAttributs;
	unsigned int uiPARnbValeurs;

public:

	//CONSTRUCTEUR & DESTRUCTEUR
	Cparseur(char * pcFichier);
	~Cparseur();

	//GETTERS
	char * PARgetAttribut(unsigned int uiInstance);
	char ** PARgetValeur(unsigned int uiInstance);
	unsigned int PARgetNbAttributs();
	unsigned int PARgetNbValeurs();
};

#endif