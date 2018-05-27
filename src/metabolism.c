/*
    Functions in this file:
    - metabolise (chemical *compound)
*/

#include <stdio.h>
#include <string.h>
#include <metabolism.h>

/*Function to calculate integer formulas of metabolites*/
void 
metabolise (chemical *compound, int metabolism[2]) {

	int i, j;
	int compoundIndex = 0;

	/*char assembleName(int a, int b, int c) {

		int a;
		char name[20];

		for(a = 0; a < 20; a++) {
			
    		name[a] = 'y';
			
		}

		

	}*/

	/*Hydroxylation of parent compound*/
    for (i = 1; i <= metabolism[0]; i++) {

		compoundIndex++;

		compound[compoundIndex].intFormula[0] = compound[0].intFormula[0];
		compound[compoundIndex].intFormula[1] = compound[0].intFormula[1];
		compound[compoundIndex].intFormula[2] = compound[0].intFormula[2];
		compound[compoundIndex].intFormula[3] = compound[0].intFormula[3];
		compound[compoundIndex].intFormula[4] = compound[0].intFormula[4];
		compound[compoundIndex].intFormula[5] = compound[0].intFormula[5];
		compound[compoundIndex].intFormula[6] = compound[0].intFormula[6];
		compound[compoundIndex].intFormula[7] = compound[0].intFormula[7] +i;
		compound[compoundIndex].intFormula[8] = compound[0].intFormula[8];
		compound[compoundIndex].intFormula[9] = compound[0].intFormula[9];

	}

    /*Formation of oxo-metabolites*/
	for (i = 1; i <= metabolism[1]; i++) {

		compoundIndex++;

		compound[compoundIndex].intFormula[0] = compound[0].intFormula[0];
		compound[compoundIndex].intFormula[1] = compound[0].intFormula[1] -2 *i;
		compound[compoundIndex].intFormula[2] = compound[0].intFormula[2];
		compound[compoundIndex].intFormula[3] = compound[0].intFormula[3];
		compound[compoundIndex].intFormula[4] = compound[0].intFormula[4];
		compound[compoundIndex].intFormula[5] = compound[0].intFormula[5];
		compound[compoundIndex].intFormula[6] = compound[0].intFormula[6];
		compound[compoundIndex].intFormula[7] = compound[0].intFormula[7] +i;
		compound[compoundIndex].intFormula[8] = compound[0].intFormula[8];
		compound[compoundIndex].intFormula[9] = compound[0].intFormula[9];

	}

    /*Formation of combinations of hydroxylations and oxo formations*/
	for (i = 1; i <= metabolism[0]; i++) {

		for (j = 1; j <= metabolism[1]; j++) {

			compoundIndex++;

			compound[compoundIndex].intFormula[0] = compound[0].intFormula[0];
			compound[compoundIndex].intFormula[1] = compound[0].intFormula[1]-2*j;
			compound[compoundIndex].intFormula[2] = compound[0].intFormula[2];
			compound[compoundIndex].intFormula[3] = compound[0].intFormula[3];
			compound[compoundIndex].intFormula[4] = compound[0].intFormula[4];
			compound[compoundIndex].intFormula[5] = compound[0].intFormula[5];
			compound[compoundIndex].intFormula[6] = compound[0].intFormula[6];
			compound[compoundIndex].intFormula[7] = compound[0].intFormula[7] +i +j;
			compound[compoundIndex].intFormula[8] = compound[0].intFormula[8];
			compound[compoundIndex].intFormula[9] = compound[0].intFormula[9];

		}

	}

    /*Glucuronidation of every metabolite that was merely hydroxylated*/
	for (i = 1; i <= metabolism[0]; i++) {

		compoundIndex++;

		compound[compoundIndex].intFormula[0] = compound[0].intFormula[0] +6;
		compound[compoundIndex].intFormula[1] = compound[0].intFormula[1] +8;
		compound[compoundIndex].intFormula[2] = compound[0].intFormula[2];
		compound[compoundIndex].intFormula[3] = compound[0].intFormula[3];
		compound[compoundIndex].intFormula[4] = compound[0].intFormula[4];
		compound[compoundIndex].intFormula[5] = compound[0].intFormula[5];
		compound[compoundIndex].intFormula[6] = compound[0].intFormula[6];
		compound[compoundIndex].intFormula[7] = compound[0].intFormula[7] +i +6;
		compound[compoundIndex].intFormula[8] = compound[0].intFormula[8];
		compound[compoundIndex].intFormula[9] = compound[0].intFormula[9];

	}

	/*Glucuronidation of combinations of hydroxy and oxo metabolites*/
	for (i = 1; i <= metabolism[0]; i++) {

		for (j = 1; j <= metabolism[1]; j++) {

			compoundIndex++;

			compound[compoundIndex].intFormula[0] = compound[0].intFormula[0] +6;
			compound[compoundIndex].intFormula[1] = compound[0].intFormula[1] +8 -2*j;
			compound[compoundIndex].intFormula[2] = compound[0].intFormula[2];
			compound[compoundIndex].intFormula[3] = compound[0].intFormula[3];
			compound[compoundIndex].intFormula[4] = compound[0].intFormula[4];
			compound[compoundIndex].intFormula[5] = compound[0].intFormula[5];
			compound[compoundIndex].intFormula[6] = compound[0].intFormula[6];
			compound[compoundIndex].intFormula[7] = compound[0].intFormula[7] +i +j +6;
			compound[compoundIndex].intFormula[8] = compound[0].intFormula[8];
			compound[compoundIndex].intFormula[9] = compound[0].intFormula[9];

		}

	}

	strcpy (compound[0].name, "Parent");
	strcpy (compound[1].name, "-M (HO-)");
	strcpy (compound[2].name, "-M (di-HO-)");
	strcpy (compound[3].name, "-M (tri-HO-)");
	strcpy (compound[4].name, "-M (oxo-)");
	strcpy (compound[5].name, "-M (di-oxo-)");                                
	strcpy (compound[6].name, "-M (oxo-HO-)");
	strcpy (compound[7].name, "-M (di-oxo-HO-)");
	strcpy (compound[8].name, "-M (oxo-di-HO-)");
	strcpy (compound[9].name, "-M (di-oxo-di-HO-)");
	strcpy (compound[10].name, "-M (oxo-tri-HO-)");
	strcpy (compound[11].name, "-M (tri-oxo-tri-HO-)");
	strcpy (compound[12].name, "-M (HO-) Gluc");
	strcpy (compound[13].name, "-M (di-HO-) Gluc");
	strcpy (compound[14].name, "-M (tri-HO-) Gluc");
	strcpy (compound[15].name, "-M (oxo-HO-) Gluc");
	strcpy (compound[16].name, "-M (di-oxo-HO-) Gluc");
	strcpy (compound[17].name, "-M (oxo-di-HO-) Gluc");
	strcpy (compound[18].name, "-M (di-oxo-di-HO-) Gluc");
	strcpy (compound[19].name, "-M (oxo-tri-HO-) Gluc");
	strcpy (compound[20].name, "-M (tri-oxo-tri-HO-) Gluc");


	/*Naming of the compounds*/
	/*strcpy(compound[0].name, "Parent");
	
	for (i = 1; i <= compoundIndex; i++) {

		int diffFormula[10];
		int a, b, c, d;

		for(a = 0; a < 20; a++) {
			
    		compound[i].name[a] = 'x';
			
		}

		for (j = 0; j < 10; j++) {

			diffFormula[0] = compound[i].intFormula[j] - compound[0].intFormula[j];

		}

		printf("%d %d %d %d %d %d %d %d %d %d\n", diffFormula[0], diffFormula[1], diffFormula[2], diffFormula[3] , diffFormula[4], diffFormula[5], diffFormula[6], diffFormula[7], diffFormula[8], diffFormula[9]);

		for (a = 0; a < 10; a++) {

			for (b = 0; b < 10; b++) {

				for (c = 0; c < 2; c++) {

					int nameFormula[10], compFormula[10], sum;

					nameFormula[0] = compound[0].intFormula[0] +6*c;
					nameFormula[1] = compound[0].intFormula[1] +8*c -2*b;
					nameFormula[2] = compound[0].intFormula[2];
					nameFormula[3] = compound[0].intFormula[3];
					nameFormula[4] = compound[0].intFormula[4];
					nameFormula[5] = compound[0].intFormula[5];
					nameFormula[6] = compound[0].intFormula[6];
					nameFormula[7] = compound[0].intFormula[7] +a +b;
					nameFormula[8] = compound[0].intFormula[8];
					nameFormula[9] = compound[0].intFormula[9];

					for (d = 0; d < 10; d++) {

						compFormula[d] = diffFormula[d] - nameFormula[d];

					}
					
					for (d = 0; d < 10; d++) {

						sum += compFormula[d];

					}

					if (sum == 0) {

					/*	compound[i].charFormula = assembleName (a, b, c);

					}
					
				}

			}
			
			
		}
		

	}*/

}
