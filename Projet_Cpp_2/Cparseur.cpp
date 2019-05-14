#include "Cparseur.h"

//CONSTRUCTEUR & DESTRUCTEUR

Cparseur::Cparseur(char * pcFichier)
{
	try
	{
		unsigned int uiCompt;
		unsigned int uiComptAttributs = 0;
		unsigned int uiComptValeursInternes = 0;
		char cBuffer[SIZEMAX];
		bool bEstValeur = false;
		bool bEstDansTableau = false;

		uiPARnbValeurs = 0;
		pcPARattributs = (char **)malloc(sizeof(char *));

		for (uiCompt = 0; uiCompt < SIZEMAX; uiCompt++)
		{
			ppcPARvaleurs[uiCompt] = (char**)malloc(sizeof(char*));
		}

		poPARfichier = new ifstream(pcFichier);
		
		while (!(poPARfichier->eof()))
		{
			if (bEstDansTableau == false)
			{
				if (bEstValeur == false)
				{
					pcPARattributs = (char **)realloc(pcPARattributs, sizeof(char *) * (uiComptAttributs + 1));

					if (poPARfichier->get(cBuffer, SIZEMAX, '='))
					{
						pcPARattributs[uiComptAttributs] = cBuffer;
						uiComptAttributs++;
					}
					else
					{
						throw new Cexception(ERR_LECTURE);
					}

					if (!(poPARfichier->get(cBuffer, 2)))
					{
						throw new Cexception(ERR_LECTURE);
					}

					bEstValeur = true;
				}
				else
				{
					if (!(poPARfichier->get(cBuffer, SIZEMAX, '\n')))
					{
						throw new Cexception(ERR_LECTURE);
					}

					if (cBuffer[0] == '[')
					{
						bEstDansTableau = true;
					}
					else
					{
						ppcPARvaleurs[uiPARnbValeurs][0] = cBuffer;
						uiPARnbValeurs++;
						bEstValeur = false;
					}

					if (!(poPARfichier->get(cBuffer, 2)))
					{
						throw new Cexception(ERR_LECTURE);
					}
				}
			}
			else
			{
				while (cBuffer[0] != ']')
				{
					if (poPARfichier->get(cBuffer, SIZEMAX, '\n'))
					{
						if (cBuffer[0] != ']')
						{
							ppcPARvaleurs[uiPARnbValeurs] = (char **)realloc(ppcPARvaleurs, sizeof(char *) * (uiComptValeursInternes + 1));
							ppcPARvaleurs[uiPARnbValeurs][uiComptValeursInternes] = cBuffer;
							uiComptValeursInternes++;
						}
					}
					else
					{
						throw new Cexception(ERR_LECTURE);
					}

					if (!(poPARfichier->get(cBuffer, 2)))
					{
						throw new Cexception(ERR_LECTURE);
					}
				}

				uiPARnbValeurs++;
				uiComptValeursInternes = 0;
				bEstDansTableau = false;
				bEstValeur = false;
			}
		}

		poPARfichier->close();
	}
	catch (Cexception EXCexception)
	{
		EXCexception.EXCafficherErreur();
	}
}

Cparseur::~Cparseur()
{
	unsigned int uiCompt;

	free(pcPARattributs);

	for (uiCompt = 0; uiCompt < uiPARnbValeurs; uiCompt++)
	{
		free(ppcPARvaleurs[uiCompt]);
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
