/*
    Functions in this file:
    - metabolise (chemical *compound)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metabolism.h"

/*Function to assemble name of the metabolite
 * by the number and kind of metabolisations steps
 *  that were performed on the parent compound*/
void
assembleMetaboliteName(char name[25],
             int  hydroxy,
             int  oxo,
             int  gluc)

{

        /*Start name with declaration that
         * it is a metabolite of the parent compound*/
        strcpy(name, "-M (");

        /*Declare number of oxo group formations in latin*/
        switch(oxo) {

                case 2:
                        strcat(name, "di-");
                        break;

                case 3:
                        strcat(name, "tri-");
                        break;

                case 4:
                        strcat(name, "quattro-");
                        break;

                case 5:
                        strcat(name, "penta-");
                        break;

                case 6:
                        strcat(name, "hexa-");
                        break;

                case 7:
                        strcat(name, "hepta-");
                        break;

                case 8:
                        strcat(name, "octa-");
                        break;

                case 9:
                        strcat(name, "nona-");
                        break;

                case 10:
                        strcat(name, "deca-");
                        break;

        }

        /*Declare that an oxo group formation took place*/
        if (oxo > 0) {

                strcat(name, "oxo-");

        }

        /*Declare number of hydroxylation steps in latin*/
        switch(hydroxy) {

                case 2:
                        strcat(name, "di-");
                        break;

                case 3:
                        strcat(name, "tri-");
                        break;

                case 4:
                        strcat(name, "quattro-");
                        break;

                case 5:
                        strcat(name, "penta-");
                        break;

                case 6:
                        strcat(name, "hexa-");
                        break;

                case 7:
                        strcat(name, "hepta-");
                        break;

                case 8:
                        strcat(name, "octa-");
                        break;

                case 9:
                        strcat(name, "nona-");
                        break;

                case 10:
                        strcat(name, "deca-");
                        break;

        }

        /*Declare if hydroxylation took place*/
        if (hydroxy > 0) {

                strcat(name, "HO-");

        }

        /*Declare if Hydroxylation took place*/
        if (gluc == 1) {

                strcat(name, ") Gluc");

        /*Close metabolite description parenthesis*/
        } else {

                strcat(name, ")");

        }



}

/*Function to calculate integer formulas of metabolites*/
void 
metabolise (chemical *compound,
            int       metabolism[2])
{
        int i, j;
        int compoundIndex = 0;


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
                compound[compoundIndex].intFormula[1] = compound[0].intFormula[1] +10;
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
                        compound[compoundIndex].intFormula[1] = compound[0].intFormula[1] +10 -2*j;
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

        /*Naming of the compounds*/
        strcpy(compound[0].name, "Parent");

        for (i = 1; i <= compoundIndex; i++) {

                int diffFormula[10];
                int hydroxy, oxo, gluc = 0;

                /*Set every element of the metabolites name a "x"*/
                for(j = 0; j < sizeof(compound->name); j++) {

                        compound[i].name[j] = 'x';

                }

                /*Calculate the difference of the metabolite to the parents sum formula*/
                for (j = 0; j < 10; j++) {

                        diffFormula[j] = compound[i].intFormula[j] - compound[0].intFormula[j];

                }

                /*Determine how the difference to parent sum formula does consist of known metabolisation steps*/
                for (gluc = 0; gluc <= 1; gluc++) {

                        for (oxo = 0; oxo <= metabolism[1]; oxo++) {

                                for (hydroxy = 0; hydroxy <= metabolism[0]; hydroxy++) {

                                        int compFormula[10], sum = 0;

                                        compFormula[0] = diffFormula[0] - 6*gluc;
                                        compFormula[1] = diffFormula[1] - 10*gluc +2*oxo;
                                        compFormula[2] = diffFormula[2];
                                        compFormula[3] = diffFormula[3];
                                        compFormula[4] = diffFormula[4];
                                        compFormula[5] = diffFormula[5];
                                        compFormula[6] = diffFormula[6];
                                        compFormula[7] = diffFormula[7] - hydroxy -oxo -6*gluc;
                                        compFormula[8] = diffFormula[8];
                                        compFormula[9] = diffFormula[9];

                                        for (j = 0; j < 10; j++) {

                                                sum += abs(compFormula[j]);

                                        }

                                        /*If the proper combination of metabolisation steps is found to
                                         * determine the difference to parent sum formula assemble
                                         * the name of the metabolite by the metabolisation steps*/
                                        if (sum == 0) {

                                                assembleMetaboliteName (compound[i].name, hydroxy, oxo, gluc);

                                        }

                                }

                        }

                }

        }

}
