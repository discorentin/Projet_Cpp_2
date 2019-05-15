#include "Cgraphe.h"
#include "Cparseur.h"

#include <iostream>

int main()
{
	/*
	Cgraphe * test = new Cgraphe(3);

	test->GRAajouterArc(1, 2);
	test->GRAajouterArc(2, 3);
	test->GRAajouterArc(3, 1);

	test->GRAafficherGraphe();

	test->GRAsupprimerArc(2, 3);

	test->GRAafficherGraphe();

	test->GRAsupprimerSommet(3);

	test->GRAafficherGraphe();

	Cgraphe * testCopie = new Cgraphe();

	testCopie = test;

	testCopie->GRAafficherGraphe();
	//*/

	/*
	Cparseur * PARdata = new Cparseur("testParseur.txt");

	printf("%s = %s\n", PARdata->PARgetAttribut(0), PARdata->PARgetValeur(0)[0]);
	printf("%s = %s\n", PARdata->PARgetAttribut(1), PARdata->PARgetValeur(1)[0]);
	printf("%s =\n", PARdata->PARgetAttribut(2));
	printf("%s\n", PARdata->PARgetValeur(2)[0]);
	printf("%s\n", PARdata->PARgetValeur(2)[1]);
	printf("%s\n", PARdata->PARgetValeur(2)[2]);
	printf("%s =\n", PARdata->PARgetAttribut(3));
	printf("%s\n", PARdata->PARgetValeur(3)[0]);
	printf("%s\n", PARdata->PARgetValeur(3)[1]);
	printf("%s\n", PARdata->PARgetValeur(3)[2]);
	//*/


	Cgraphe * grapheTest = new Cgraphe("testParseur.txt");

	grapheTest->GRAafficherGraphe();

	printf("\n---------INVERSION---------\n\n");

	grapheTest->GRAinverserGraphe();

	grapheTest->GRAafficherGraphe();

	return 0;
}