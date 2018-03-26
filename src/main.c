#include <stdio.h>
#include <inout.h>
#include <metabolism.h>
#include <calculation.h>

int ionsource;
int polarity;

chemical compound[16];

/*Import of functions*/
/*extern void metabolise(chemical *compound);
extern void chemscanf (int formula[10]);
extern void assembleFormula(int intFormula[10], char charFormula[33]);
extern void displayTable(chemical *output, int size);
extern void exportTable(chemical *table, int size);
extern double exactMass(int intFormula[10]);
extern int nominalMass(int intFormula[10]);*/

/*Definition of the banner*/
void banner()
{
    printf("******************************************\n");
    printf("*                                        *\n");
    printf("*               MetaCalc v0.3            *\n");
    printf("*                                        *\n");
    printf("******************************************\n");
    printf("\n");
}

void license()
{
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

int main(int argc, char **argv)
{
    int i, choice;
    char correction = 'y';

    banner();

    while(1) {
        printf("\tCalculate metabolites...1\n"
            "\tAbout...................2\n"
            "\tExit....................0\n"
            "\n\n");
        printf("Please enter your choice: ");
        scanf(" %d", &choice);

        switch(choice){

            case 1:do {
                        printf("Please enter the molecular formula of your compound!\n");
                        chemscanf(compound[0].intFormula);
                        assembleFormula(compound[0].intFormula, compound[0].charFormula);
                        printf("The molecular formula of your compound is:\n");
                        printf("%s\n", compound[0].charFormula);
                        printf("Would you like to correct your input (y/n)? ");
                        scanf(" %c", &correction);
                        printf("\n");
                    }
                    while(correction == 'y');
                    printf("Please specifiy the ion source of the mass spectrometer:\n\n");
                    printf("\tESI/APCI...1\n"
                           "\tEI/PCI.....2"
                           "\n\n");
                    scanf("%d", &ionsource);
                    metabolise(compound);

                    for(i = 0; i < (sizeof(compound)/sizeof(chemical)); i++)
                        compound[i].nominalMass = nominalMass(compound[i].intFormula);
                    for(i = 0; i < (sizeof(compound)/sizeof(chemical)); i++)
                        compound[i].exactMass = exactMass(compound[i].intFormula);
                    for(i = 0; i < (sizeof(compound)/sizeof(chemical)); i++)
                        assembleFormula(compound[i].intFormula, compound[i].charFormula);
                    displayTable(compound, (sizeof(compound)/sizeof(chemical)));
                    exportTable(compound, (sizeof(compound)/sizeof(chemical)));
                    break;

            case 2: license();
                    break;

            case 0: printf("Good luck!\n");
                    return 0;

            default: printf("That's not a valid option, please choose again!\n");
        }
    }
}
