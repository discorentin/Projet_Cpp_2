#ifndef Carc_H
#define Carc_H 0

/*!
 * \file Carc.h
 * \brief Arc
 * \author Antonin Lagarrigue & Corentin Bourdon
 */
#include <stdio.h> 
#include <stdlib.h>
#include "Cexception.h"

/*!
 * \class Carc
 * \brief Classe represantant un arc
 * 
 * Carc gere la creation et la destruction d'un arc 
 */
class Carc
{

private:
	unsigned int uiARCdestination; /*!< Numero de la destination de l'arc*/

public:
	/*!
	 * \brief Constructeur de recopie
	 * 
	 * Constructeur de recopie de la classe Carc
	 * 
	 * \param ARCparam : arc a copier
	 */
	Carc(Carc & ARCparam);

	/*!
	 * \brief Constructeur de confort
	 *
	 * Constructeur de confort de la classe Carc
	 *
	 * \param uiDestination : numero de destination de l'arc a creer
	 */
	Carc(unsigned int uiDestination);

	/*!
	 * \brief Destructeur
	 * 
	 * Destructeur de la classe Carc
	 */
	~Carc();

	/*!
	 * \brief Accesseur en lecture de uiARCdestination
	 * 
	 * Accesseur en lecture du numero de destination de l'arc
	 * 
	 * \return le numero de destination de l'arc
	 */
	unsigned int ARCgetDestination();
};

#endif