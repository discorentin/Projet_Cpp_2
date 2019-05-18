#ifndef Cparseur_H
#define Cparseur_H 0

/*!
 * \file Cparseur.h
 * \brief Parseur
 * \author Antonin Lagarrigue & Corentin Bourdon
 */
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Cexception.h"

#define SIZEMAX 256

using namespace std;

/*!
* \class Cparseur
* \brief Classe qui permet une analyse syntaxique d'un fichier
*
* Cparseur gere la lecture et le stockage de donnees a partir d'un fichier texte
* contenant des attributs et des valeurs correspondant a ces attributs
*/
class Cparseur
{

private:
	char ** pcPARattributs; /*< Attributs lus dans le fichier*/
	char ** ppcPARvaleurs[SIZEMAX]; /*< Valeurs lues dans le fichier*/
	unsigned int uiPARnbAttributs; /*< Nombre d'attributs lus dans le fichier*/
	unsigned int uiPARnbValeurs; /*< Nombre de valeurs lues dans le fichier*/

public:

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Cparseur
	 * Le fichier doit etre du format :
	 *
	 * <nom_attribut>=<valeur>
	 * <nom_attribut>=[
	 * <nom_attribut>=<numero_sommet>
	 * <nom_attribut>=<numero_sommet>
	 * ...
	 * <nom_attribut>=<numero_sommet>
	 * ]
	 * ...
	 * 
	 * \param pcFichier : le nom du fichier de donnees
	 */
	Cparseur(char * pcFichier);

	/*!
	 * \brief Destructeur
	 * 
	 * Destructeur de la classe Cparseur 
	 */
	~Cparseur();

	/*!
	 * \brief Accesseur en lecture de pcPARattributs
	 * 
	 * Accesseur en lecture des attributs lus dans le fichier
	 * 
	 * \param uiInstance : l'instance de l'attribut auquel on veut acceder
	 * \return l'attribut correspondant si uiInstance est inferieur au nombre d'attributs,
	 * nullptr sinon
	 */
	char * PARgetAttribut(unsigned int uiInstance);

	/*!
	 * \brief Accesseur en lecture de ppcPARvaleurs
	 *
	 * Accesseur en lecture des valeurs lues dans le fichier
	 *
	 * \param uiInstance : l'instance de la valeur a laquelle on veut acceder
	 * \return la valeur correspondante si uiInstance est inferieur au nombre de valeurs,
	 * nullptr sinon
	 */
	char ** PARgetValeur(unsigned int uiInstance);

	/*!
	 * \brief Accesseur en lecture de uiPARnbAttributs
	 * 
	 * Accesseur en lecture du nombre d'attributs lus dans le fichier
	 * 
	 * \return le nombre d'attributs lus dans le fichier
	 */
	unsigned int PARgetNbAttributs();

	/*!
	 * \brief Accesseur en lecture de uiPARnbValeurs
	 *
	 * Accesseur en lecture du nombre de valeurs lues dans le fichier
	 *
	 * \return le nombre de valeurs lues dans le fichier
	 */
	unsigned int PARgetNbValeurs();
};

#endif