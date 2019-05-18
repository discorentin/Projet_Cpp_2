#include "Cgraphe.h"
#include "Cparseur.h"

#include <iostream>

int main()
{
	printf("\n---------CREATION DU GRAPHE---------\n\n");
	
	Cgraphe * grapheTest = new Cgraphe("testParseur.txt");

	grapheTest->GRAafficherGraphe();

	printf("\n--------------INVERSION--------------\n\n");

	grapheTest->GRAinverserGraphe();

	grapheTest->GRAafficherGraphe();

	return 0;
}