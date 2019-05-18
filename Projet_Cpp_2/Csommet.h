#ifndef Csommet_H
#define Csommet_H 0

/*!
 * \file Csommet.h
 * \brief Sommet
 * \author Antonin Lagarrigue & Corentin Bourdon
 */
#include "Carc.h"

/*!
* \class Csommet
* \brief classe represantant un sommet
*
* Csommet gere la creation et la destruction d'un sommet, ainsi que
* l'ajout et la suppression d'arcs arrivant ou partant d'un sommet
*/
class Csommet
{

private:
	unsigned int uiSOMnumero; /*!< Numero du sommet*/

	Carc ** ppARCSOMarcsPartant; /*!< Arcs partant du sommet*/
	Carc ** ppARCSOMarcsArrivant; /*!< Arcs arrivant au sommet*/

	unsigned int uiSOMnbPartants; /*!< Nombre d'arcs partant du sommet*/
	unsigned int uiSOMnbArrivants;/*!< Nombre d'arcs arrivant au sommet*/

public:
	/*!
	 * \brief Constructeur de recopie
	 *
	 * Constructeur de recopie de la classe Csommet
	 *
	 * \param SOMparam : sommet a copier
	 */
	Csommet(Csommet & SOMparam);

	/*!
	 * \brief Constructeur de confort
	 *
	 * Constructeur de confort de la classe Csommet
	 *
	 * \param uiNumero : numero du sommet a creer
	 */
	Csommet(unsigned int uiNumero);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe Csommet
	 */
	~Csommet();

	/*!
	 * \brief Accesseur en lecture de uiSOMnumero
	 *
	 * Accesseur en lecture du numero du sommet
	 *
	 * \return le numero du sommet
	 */
	unsigned int SOMgetNumero();

	/*!
	 * \brief Accesseur en lecture de ppARCSOMarcsPartant
	 *
	 * Accesseur en lecture du tableau des arcs partant du sommet
	 *
	 * \return le tableau des arcs partant du sommet
	 */
	Carc ** SOMgetArcsPartant();

	/*!
	 * \brief Accesseur en lecture de ppARCSOMarcsPartant
	 *
	 * Accesseur en lecture des arcs partant du sommet
	 *
	 * \param uiDestination : le numero de destination de l'arc auquel on veut acceder
	 * \return l'arc correspondant a uiDestination si present dans les arcs partant du sommet,
	 * nullptr sinon
	 */
	Carc * SOMgetArcPartant(unsigned int uiDestination);

	/*!
	 * \brief Accesseur en lecture de ppARCSOMarcsArrivant
	 *
	 * Accesseur en lecture du tableau des arcs arrivant au sommet
	 *
	 * \return le tableau des arcs arrivant au sommet
	 */
	Carc ** SOMgetArcsArrivant();

	/*!
	 * \brief Accesseur en lecture de ppARCSOMarcsArrivant
	 *
	 * Accesseur en lecture des arcs arrivant au sommet
	 *
	 * \param uiDestination : le numero de destination de l'arc auquel on veut acceder
	 * \return l'arc correspondant a uiDestination si present dans les arcs arrivant au sommet,
	 * nullptr sinon
	 */
	Carc * SOMgetArcArrivant(unsigned int uiDestination);

	/*!
	 * \brief Accesseur en lecture de uiSOMnbPartants
	 *
	 * Accesseur en lecture du nombre d'arcs partant du sommet
	 *
	 * \return le nombre d'arcs partant du sommet
	 */
	unsigned int SOMgetNbPartants();

	/*!
	 * \brief Accesseur en lecture de uiSOMnbArrivants
	 *
	 * Accesseur en lecture du nombre d'arcs arrivant au sommet
	 *
	 * \return le nombre d'arcs arrivant au sommet
	 */
	unsigned int SOMgetNbArrivants();

	/*!
	 * \brief Ajout d'un arc partant du sommet
	 *
	 * Methode qui permet d'ajouter un arc partant du sommet
	 * 
	 * \return true si un arc correspondant a uiDestination est deja present dans les arcs partant du sommet,
	 * false sinon
	 */
	bool SOMajouterArcPartant(unsigned int uiDestination);

	/*!
	 * \brief Suppression d'un arc partant du sommet
	 *
	 * Methode qui permet de supprimer un arc partant du sommet
	 *
	 * \return true si l'arc correspondant a uiDestination est deja absent des arcs partant du sommet,
	 * false sinon
	 */
	bool SOMsupprimerArcPartant(unsigned int uiDestination);

	/*!
	 * \brief Ajout d'un arc arrivant au sommet
	 *
	 * Methode qui permet d'ajouter un arc arrivant au sommet
	 *
	 * \return true si un arc correspondant a uiDestination est deja present dans les arcs arrivant au sommet,
	 * false sinon
	 */
	bool SOMajouterArcArrivant(unsigned int uiDestination);

	/*!
	 * \brief Suppression d'un arc arrivant au sommet
	 *
	 * Methode qui permet de supprimer un arc arrivant au sommet
	 *
	 * \return true si l'arc correspondant a uiDestination est deja absent des arcs arrivant au sommet,
	 * false sinon
	 */
	bool SOMsupprimerArcArrivant(unsigned int uiDestination);
};

#endif