#include "Cexception.h"

//CONSTRUCTEUR & DESTRUCTEUR

Cexception::Cexception(unsigned int uiErreur)
{
	uiEXCerreur = uiErreur;
}

Cexception::~Cexception()
{
}

//GETTER

unsigned int Cexception::EXCgetErreur()
{
	return uiEXCerreur;
}

//METHODE

void Cexception::EXCafficherErreur()
{
	switch (uiEXCerreur)
	{
	case ERR_CONSTRUCTEUR: fprintf(stderr, "erreur: l'objet n'a pas pu être créé.\n"); break;
	case ERR_LECTURE: fprintf(stderr, "erreur : la lecture du fichier n'a pas fonctionné.\n"); break;
	case ERR_FORMAT:fprintf(stderr, "erreur : le format du fichier que vous essayez de charger n'est pas conforme.\n"); break;
	}
}
