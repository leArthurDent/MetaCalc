#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inout.h"
#include "metabolism.h"
#include "calculation.h"

/*Definition of the banner*/
void
banner() {

    printf("******************************************\n");
    printf("*                                        *\n");
    printf("*               MetaCalc v0.3            *\n");
    printf("*                                        *\n");
    printf("******************************************\n");
    printf("\n");

}

void
license() {

    printf("\nMetaCalc is a program to calculate common (not individual!) \n"
           "metabolites of molecules.\n"
           "Its purpose is to avoid drawing every single possible structure in 2D \n"
           "drawing software to receive monoisotopic molecular masses of compounds.\n"
           "This tool might be usefull for high resolution mass spectrometry and \n"
           "in particular for metabolism studies using such techniques.\n\n"
           "Copyright (C) 2017  Sascha Manier (SaschaManier@posteo.de)\n\n"
           "This program is free software: you can redistribute it and/or modify\n"
           "it under the terms of the GNU General Public License as published by\n"
           "the Free Software Foundation version 3 of the License.\n\n"
           "This program is distributed in the hope that it will be useful,\n"
           "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
           "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"
           "GNU General Public License for more details.\n\n"
           "You should have received a copy of the GNU General Public License\n"
           "along with this program. If not, see http://www.gnu.org/licenses/.\n\n");

}

/*chemical
initChemical (int size)  {

	chemical compound[size];
	return *compound;

}*/

int
main (int argc, char **argv) {

    int i, choice, ionsource, polarity, size, metabolism[2] = {3, 2};
	char inputBuffer[33], bufferflush;
	chemical *compound;

    banner();

    while(1) {

        printf("\tCalculate metabolites...1\n"
               "\tAbout...................2\n"
               "\tExit....................0\n"
               "\n\n");
        printf("Please enter your choice: ");
        scanf(" %d", &choice);

        switch(choice) {

            case 1:
					printf("Please enter the molecular formula of your compound!\n");
					scanf("%33s", inputBuffer);

					do {

						bufferflush = getchar();

					}
					while(bufferflush != '\n' && bufferflush != EOF);
					printf("\n");
					printf("Please specifiy the ion source of the mass spectrometer:\n\n");
					printf("\tESI/APCI...1\n"
						   "\tEI/PCI.....2"
						   "\n\n");
					scanf("%d", &ionsource);
					size = ((2 * metabolism[0] + metabolism[1] + 2 * metabolism[0] * metabolism[1] + 1));
					compound = malloc(sizeof(chemical[size]));
					strcpy (compound[0].charFormula, inputBuffer);
					parseFormula (compound[0].charFormula, compound[0].intFormula);
					metabolise(compound, metabolism);
					for (i = 0; i < size; i++) {

						compound[i].nominalMass = nominalMass(compound[i].intFormula);

					}
					for (i = 0; i < size; i++) {

						compound[i].exactMass = exactMass(compound[i].intFormula);

					}
					for (i = 0; i < size; i++) {

						assembleFormula(compound[i].intFormula, compound[i].charFormula);

					}
					displayTable(compound, size);
	                exportTable(compound, size);
					free(compound);
					break;

            case 2: license();
                    break;

            case 0: printf("Good luck!\n");
                    return 0;

            default: printf("That's not a valid option, please choose again!\n");

        }

    }

}
