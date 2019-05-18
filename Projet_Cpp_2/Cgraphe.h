#ifndef Cgraphe_H
#define Cgraphe_H 0

/*!
 * \file Cgraphe.h
 * \brief Graphe
 * \author Antonin Lagarrigue & Corentin Bourdon
 */
#include "Csommet.h"

/*!
* \class Cgraphe
* \brief Classe represantant un graphe
*
* Cgraphe gere la creation, la destruction, l'affichage et l'inversion d'un graphe,
* ainsi que l'ajout et la suppression des sommets et arcs d'un graphe
*/
class Cgraphe{

private:
	Csommet ** ppSOMGRAsommets; /*< Sommets du graphe*/
	unsigned int uiGRAnbSommets; /*< Nombre de sommets du graphe*/
	unsigned int uiGRAnbArcs; /*< Nombre d'arcs du graphe*/

public:
	/*!
	 * \brief Constructeur par defaut
	 *
	 * Constructeur par defaut de la classe Cgraphe
	 */
	Cgraphe();

	/*!
	 * \brief Constructeur de recopie
	 *
	 * Constructeur de recopie de la classe Cgraphe
	 *
	 * \param GRAparam : graphe a copier
	 */
	Cgraphe(Cgraphe & GRAparam);

	/*!
	 * \brief Constructeur de confort
	 *
	 * Constructeur de confort de la classe Cgraphe
	 * Les numeros des sommets sont attribues automatiquement de 1 a uiNbSommets + 1
	 *
	 * \param uiNbSommets : nombre de sommets du graphe a creer
	 */
	Cgraphe(unsigned int uiNbSommets);

	/*!
	 * \brief Constructeur par fichier de donnees
	 *
	 * Constructeur de la classe Csommet a partir d'un fichier texte contenant les donnes du graphe
	 * Le fichier doit etre du format :
	 * 
	 * NBSommets=<nombre_de_sommets_du_graphe>
	 * NBArcs=<nombre_d_arcs_du_graphe>
	 * Sommets=[
	 * Numero=<numero_sommet>
	 * Numero=<numero_sommet>
	 * ...
	 * Numero=<numero_sommet>
	 * ]
	 * Arcs=[
	 * Debut=<sommet_depart_arc>, Fin=<sommet_arrivee_arc>
	 * Debut=<sommet_depart_arc>, Fin=<sommet_arrivee_arc>
	 * ...
	 * Debut=<sommet_depart_arc>, Fin=<sommet_arrivee_arc>
	 * ]
	 *
	 * \param pcFichier : le nom du fichier de donnees
	 */
	Cgraphe(char * pcFichier);

	/*!
	 * \brief Destructeur
	 *
	 * Destructeur de la classe Cgraphe
	 */
	~Cgraphe();

	/*!
	 * \brief Accesseur en lecture de ppSOMGRAsommets
	 *
	 * Accesseur en lecture du tableau des sommets du graphe
	 *
	 * \return le tableau des sommets du grapheS
	 */
	Csommet ** GRAgetSommets();

	/*!
	 * \brief Accesseur en lecture de ppSOMGRAsommets
	 *
	 * Accesseur en lecture des sommets du graphe
	 *
	 * \param uiNumero : le numero du sommet auquel on veut acceder
	 * \return le sommet correspondant a uiNumero si present dans les sommets du graphe,
	 * nullptr sinon
	 */
	Csommet * GRAgetSommet(unsigned int uiNumero);

	/*!
	 * \brief Accesseur en lecture de uiGRAnbSommets
	 *
	 * Accesseur en lecture du nombre de sommets du graphe
	 *
	 * \return le nombre de sommets du graphe
	 */
	unsigned int GRAgetNbSommets();

	/*!
	 * \brief Accesseur en lecture de uiGRAnbArcs
	 *
	 * Accesseur en lecture du nombre d'arcs du graphe
	 *
	 * \return le nombre d'arcs du graphe
	 */
	unsigned int GRAgetNbArcs();

	/*!
	 * \brief Ajout d'un sommet au graphe
	 *
	 * Methode qui permet d'ajouter un sommet au graphe
	 *
	 * \param uiNumero : le numero du sommet a ajouter
	 * \return true si un sommet du graphe possede deja ce numero,
	 * false sinon
	 */
	bool GRAajouterSommet(unsigned int uiNumero);

	/*!
	 * \brief Suppression d'un sommet du graphe
	 *
	 * Methode qui permet de supprimer un sommet du graphe
	 *
	 * \param uiNumero : le numero du sommet a supprimer
	 * \return true si le sommet correspondant a uiNumero est deja absent des sommets du graphe,
	 * false sinon
	 */
	bool GRAsupprimerSommet(unsigned int uiNumero);

	/*!
	 * \brief Ajout d'un arc au graphe
	 *
	 * Methode qui permet d'ajouter un arc au graphe
	 *
	 * \return true si le graphe contient deja cet arc,
	 * false sinon
	 */
	bool GRAajouterArc(unsigned int uiDepart, unsigned int uiDestination);

	/*!
	 * \brief Suppression d'un arc du graphe
	 *
	 * Methode qui permet de supprimer un arc du graphe
	 *
	 * \param uiDepart : le numero du sommet dont part l'arc a supprimer
	 * \param uiDestination : le numero du sommet ou arrive l'arc a supprimer
	 * \return true si l'arc correspondant a uiDepart et uiDestination est deja absent des arcs du graphe,
	 * false sinon
	 */
	bool GRAsupprimerArc(unsigned int uiDepart, unsigned int uiDestination);

	/*!
	 * \brief Affichage du graphe
	 * 
	 * Methode qui affiche le graphe
	 */
	void GRAafficherGraphe();

	/*!
	 * \brief Inversion des arcs du graphe
	 * 
	 * Methode qui inverse le sommet de depart et le sommet de destination de tous les arcs du graphe	 * 
	 */
	void GRAinverserGraphe();

	/*!
	 * \brief Surcharge de l'operateur =
	 * 
	 * \param GRAparam le graphe a copier
	 * \return le nouveau graphe
	 */
	Cgraphe & operator=(Cgraphe & GRAparam);
};

#endif