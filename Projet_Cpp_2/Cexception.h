#ifndef Cexception_H
#define Cexception_H 0

/*!
 * \file Cexception.h
 * \brief Exception
 * \author Antonin Lagarrigue & Corentin Bourdon
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERR_CONSTRUCTEUR 1
#define ERR_LECTURE 2
#define ERR_FORMAT 3

 /*!
 * \class Cexception
 * \brief Classe qui represente une exception
 *
 * Cexception gere la creation, la suppression et l'affichage des exceptions
 */
class Cexception
{

private :
	unsigned int uiEXCerreur; /*< Le numero d'erreur*/

public:
	/*!
	 * \brief Constructeur
	 * 
	 * Constructeur de la classe Cexception
	 * 
	 * \param uiErreur : numero de l'erreur
	 */
	Cexception(unsigned int uiErreur) throw();

	/*!
	 * \brief Destructeur
	 * 
	 * Destructeur de la classe Cexception
	 */
	~Cexception();

	/*!
	 * \brief Accesseur en lecture de uiEXCerreur
	 * 
	 * Accesseur en lecture du numero d'erreur
	 * 
	 * \return le numero d'erreur
	 */
	unsigned int EXCgetErreur();

	/*!
	 * \brief Affichage de l'erreur
	 * 
	 * Affiche le message d'erreur correspondant au numero d'erreur 
	 */
	void EXCafficherErreur();
};

#endif