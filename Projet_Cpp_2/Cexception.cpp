#include "Cexception.h"

Cexception::Cexception(unsigned int uiErreur)
{
	EXCsetErreur(uiErreur);
}

Cexception::~Cexception()
{
}

unsigned int Cexception::EXCgetErreur()
{
	return uiEXCerreur;
}

void Cexception::EXCsetErreur(unsigned int uiErreur)
{
	uiEXCerreur = uiErreur;
}

void Cexception::EXCafficherErreur()
{
	switch (uiEXCerreur)
	{
	case ERR_CONSTRUCTEUR: fprintf(stderr, "erreur: l'objet n'a pas pu �tre cr��.\n"); break;
	case ERR_AJOUT: fprintf(stderr, "erreur : l'objet que vous essayez de cr�er existe d�j�.\n"); break;
	case ERR_SUPPRESSION: fprintf(stderr, "erreur : l'objet que vous essayez de supprimer n'existe pas.\n"); break;
	case ERR_LECTURE: fprintf(stderr, "erreur : la lecture du fichier n'a pas fonctionn�.\n"); break;
	}
}
