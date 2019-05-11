#include "Cgraphe.h"

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

int main()
{
	Cgraphe * test = new Cgraphe(3);

	test->GRAajouterArc(1, 2);
	test->GRAajouterArc(2, 3);
	test->GRAajouterArc(3, 1);

	test->GRAafficherGraphe();

	test->GRAsupprimerArc(2, 3);

	test->GRAafficherGraphe();

	test->GRAsupprimerSommet(3);

	test->GRAafficherGraphe();

	return 0;
}