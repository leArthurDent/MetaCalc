#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inout.h"
#include "metabolism.h"
#include "calculation.h"

/*Definition of the banner that appears in the beginning of the programm*/
void
banner ()
{
        printf ("******************************************\n");
        printf ("*                                        *\n");
        printf ("*               MetaCalc v0.4            *\n");
        printf ("*                                        *\n");
        printf ("******************************************\n");
        printf ("\n");
}

/*Display license of the code*/
void
license ()
{
        printf ("\nMetaCalc is a program to calculate common (not individual!) \n"
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


/*Initialise main function*/
int
main (int    argc,
      char **argv)
{
        /*Initialise basic variables*/
        int i, choice, ionsource, polarity, size, metabolism[2] = {3, 2};
        char inputBuffer[33], bufferflush;

        /*Compounds are structs that contain information about the parent compound and its metabolites
         * such as chemical formula, average and monoisotopic mass as well as the metabolites name*/
        chemical *compound;

        /*Print banner after starting the programm*/
        banner ();

        /*Start the command line loop*/
        while (1) {

                /*Print the menu and record the users choice*/
                printf ("\tCalculate metabolites...1\n"
                        "\tAbout...................2\n"
                        "\tExit....................0\n"
                        "\n\n");
                printf ("Please enter your choice: ");
                scanf (" %d", &choice);

                /*Run the functionality the user chose*/
                switch (choice) {

                        case 1:
                                /*Receive sum formula from user*/
                                printf ("Please enter the molecular formula of your compound!\n");
                                scanf ("%33s", inputBuffer);

                                do {

	                                bufferflush = getchar ();

                                }
                                while (bufferflush != '\n' && bufferflush != EOF);

                                /*Record user's ion source*/
                                printf ("\n");
                                printf ("Please specifiy the ion source of the mass spectrometer:\n\n");
                                printf ("\tESI/APCI...1\n"
	                                "\tEI/PCI.....2"
	                                "\n\n");
                                scanf ("%d", &ionsource);

                                /*Allocate memory for number of metabolism steps.
                                 * Currently the number of steps is fix,
                                 * but it will be adjustable in further versions.*/
                                size = (2 * metabolism[0] + metabolism[1] + 2 * metabolism[0] * metabolism[1] + 1);
                                compound = malloc (sizeof (chemical[size]));

                                /*Fill the parent slot of the struct with the sum formula entered by the user*/
                                strcpy (compound[0].charFormula, inputBuffer);

                                /*Translate it to a processable sum formula consisting of integers*/
                                parseFormula (compound[0].charFormula, compound[0].intFormula);

                                /*Metabolise the parent sum formula*/
                                metabolise (compound, metabolism);

                                /*Calculate average masses for all metabolites*/
                                for (i = 0; i < size; i++) {

	                                compound[i].averageMass = averageMass (compound[i].intFormula);

                                }

                                /*Calculate the monoisotopic masses for all metabolites*/
                                for (i = 0; i < size; i++) {

	                                compound[i].monoisotopicMass = monoisotopicMass (compound[i].intFormula);

                                }

                                /*Translate the processible integer formula into a readable sum formula*/
                                for (i = 0; i < size; i++) {

	                                assembleFormula (compound[i].intFormula, compound[i].charFormula);

                                }

                                /*Print the table containing name of the metabolite, average and monoisotopic
                                 * masses for the whole struct*/
                                displayTable (compound, size);

                                /*Ask if the user wants to export the table into a csv file*/
                                exportTable (compound, size);

                                /*Free allocated memory for the compound struct*/
                                free (compound);
                                break;

                        case 2:
                                /*Print the license text*/
                                license ();
                                break;

                        case 0:
                                /*Farewell*/
                                printf ("Good luck!\n");
                                return 0;

                        default:
                                /*Default text, if the users input is not recognized*/
                                printf ("That's not a valid option, please choose again!\n");

                }
        }
}
