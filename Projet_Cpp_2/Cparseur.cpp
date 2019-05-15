#include "Cparseur.h"

//CONSTRUCTEUR & DESTRUCTEUR

Cparseur::Cparseur(char * pcFichier)
{
	try
	{
		unsigned int uiCompt;
		unsigned int uiComptValeursInternes = 0;
		char cBuffer[SIZEMAX];
		bool bEstValeur = false;
		bool bEstDansTableau = false;

		uiPARnbAttributs = 0;
		uiPARnbValeurs = 0;

		pcPARattributs = (char **)malloc(sizeof(char *));

		for (uiCompt = 0; uiCompt < SIZEMAX; uiCompt++)
		{
			ppcPARvaleurs[uiCompt] = (char**)malloc(sizeof(char*));
		}

		ifstream oPARfichier(pcFichier);
		
		while (!(oPARfichier.eof()))
		{
			if (bEstDansTableau == false)
			{
				if (bEstValeur == false)
				{
					//pcPARattributs = (char **)realloc(pcPARattributs, sizeof(char *) * (uiPARnbAttributs + 1));

					if (oPARfichier.get(cBuffer, SIZEMAX, '='))
					{
						pcPARattributs[uiPARnbAttributs] = (char *)malloc(sizeof(char) * (strlen(cBuffer) + 1));
						strcpy_s(pcPARattributs[uiPARnbAttributs], (strlen(cBuffer) + 1), cBuffer);
						uiPARnbAttributs++;
					}
					else
					{
						throw new Cexception(ERR_LECTURE);
					}

					oPARfichier.ignore(1, EOF);

					bEstValeur = true;
				}
				else
				{
					if (!(oPARfichier.get(cBuffer, SIZEMAX, '\n')))
					{
						throw new Cexception(ERR_LECTURE);
					}

					if (cBuffer[0] == '[')
					{
						bEstDansTableau = true;
					}
					else
					{
						ppcPARvaleurs[uiPARnbValeurs][0] = (char *)malloc(sizeof(char) * (strlen(cBuffer) + 1));
						strcpy_s(ppcPARvaleurs[uiPARnbValeurs][0], strlen(cBuffer) + 1, cBuffer);
						uiPARnbValeurs++;
						bEstValeur = false;
					}

					oPARfichier.ignore(1, EOF);
				}
			}
			else
			{
				while (cBuffer[0] != ']')
				{
					if (oPARfichier.get(cBuffer, SIZEMAX, '\n'))
					{
						if (cBuffer[0] != ']')
						{
							ppcPARvaleurs[uiPARnbValeurs][uiComptValeursInternes] = (char *)malloc(sizeof(char) * (strlen(cBuffer) + 1));
							strcpy_s(ppcPARvaleurs[uiPARnbValeurs][uiComptValeursInternes], strlen(cBuffer) + 1, cBuffer);
							uiComptValeursInternes++;
						}
					}
					else
					{
						throw new Cexception(ERR_LECTURE);
					}

					oPARfichier.ignore(1, EOF);
				}

				uiPARnbValeurs++;
				uiComptValeursInternes = 0;
				bEstDansTableau = false;
				bEstValeur = false;
			}
		}

		oPARfichier.close();
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

Cparseur::~Cparseur()
{
	unsigned int uiCompt;

	//free(pcPARattributs); //fait planter

	for (uiCompt = 0; uiCompt < uiPARnbValeurs; uiCompt++)
	{
		//free(ppcPARvaleurs[uiCompt]); //fait planter
	}
}

//GETTERS

char * Cparseur::PARgetAttribut(unsigned int uiInstance)
{
	return pcPARattributs[uiInstance];
}

char ** Cparseur::PARgetValeur(unsigned int uiInstance)
{
	return ppcPARvaleurs[uiInstance];
}

unsigned int Cparseur::PARgetNbAttributs()
{
	return uiPARnbAttributs;
}

unsigned int Cparseur::PARgetNbValeurs()
{
	return uiPARnbValeurs;
}
