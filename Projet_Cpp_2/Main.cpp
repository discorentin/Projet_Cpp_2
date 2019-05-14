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

	Cparseur * PARdata = new Cparseur("testParseur.txt");

	printf(PARdata->PARgetAttribut(0));

	return 0;
}