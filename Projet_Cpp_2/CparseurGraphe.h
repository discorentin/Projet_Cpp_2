#ifndef CparseurGraphe_H
#define CparseurGraphe_H 0

/*!
 * \file CparseurGraphe.h
 * \brief Parseur pour un graphe
 * \author Antonin Lagarrigue & Corentin Bourdon
 */
#include "Cparseur.h"
#include "Cgraphe.h"
#include <string>

 /*!
 * \class CparseurGraphe
 * \brief Classe qui permet une analyse lexicale des donnees d'un graphe a partir d'un fichier
 *
 * Cparseur gere la lecture et le stockage des donnees d'un graphe a partir d'un fichier texte
 * contenant toutes les donnees necessaires a la creation d'un graphe
 */
class CparseurGraphe : public Cparseur
{

private :
	enum Attribut
	{
		NBSOMMETS, NBARCS, SOMMETS, ARCS, INVALIDE
	};

	Cgraphe * pGRAPGRgraphe; /*< Graphe cree a partir des donnees du fichier*/

	/*!
	 * \brief Traduction d'attribut
	 * 
	 * Traduit un attribut texte en champ de l'enumeration Attribut
	 * 
	 * \param pcAttribut : l'attribut a traduire
	 * \return NBSOMMETS, NBARCS, ou SOMMETS si l'attribut correspond a un de ces champs,
	 * INVALIDE sinon
	 */
	Attribut PGRtraduireAttribut(char * pcAttribut);

	/*!
	 * \brief Generation des sommets
	 * 
	 * Genere les sommets de pGRAgraphe a partir d'une liste de chaînes de caracteres decrivant des sommets
	 * Les membres de la liste doivent etre du format : Numero=<numero_sommet>
	 * 
	 * \param ppcSommets : la liste des chaines de caracteres decrivant les sommets a creer
	 * \param uiNbSommets : le nombre de sommets a creer
	 */
	void PGRgenererSommets(char ** ppcSommets, unsigned int uiNbSommets);

	/*!
	 * \brief Generation des arcs
	 *
	 * Genere les arcs de pGRAgraphe a partir d'une liste de chaines de caracteres decrivant des arcs
	 * Les membres de la liste doivent etre du format : Debut=<sommet_depart_arc>, Fin=<sommet_arrivee_arc>
	 *
	 * \param ppcArcs : la liste des chaines de caracteres devrivant les arcs a creer
	 * \param uiNbArcs : le nombre d'arcs a creer
	 */
	void PGRgenererArcs(char ** ppcArcs, unsigned int uiNbArcs);

public:
	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe CparseurGraphe
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
	CparseurGraphe(char * pcFichier);

	/*!
	 * \brief Destructeur
	 * 
	 * Destructeur de la classe CparseurGraphe
	 */
	~CparseurGraphe();

	/*!
	 * \brief Accesseur en lecture de pGRAPGRgraphe
	 * 
	 * Accesseur en lecture du graphe cree a partir des donnees du fichier
	 * 
	 * \return le graphe cree a partir des donnees du fichier
	 */
	Cgraphe & PGRgetGraphe();
};

#endif

