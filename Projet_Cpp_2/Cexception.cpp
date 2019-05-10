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
	case ERR_AJOUT: std::cerr << "erreur : l'objet que vous essayez de créer existe déjà." << std::endl; break;
	case ERR_SUPPRESSION: std::cerr << "erreur : l'objet que vous essayez de supprimer n'existe pas." << std::endl; break;
	}
}
