/*
        Functions in this file:
        - double monoisotopicMass(int intFormula[10])
        - int averageMass(int intFormula[10])
*/

#include "calculation.h"

/*Import properties of the mass spectrometer*/
extern int ionsource;
extern int polarity;

/*Function to calculate monoisotopic masses*/
double
monoisotopicMass (int intFormula[10])
{

        /*Initialise index counter, and monoisotopic masses of several atoms*/
        int i;
        double monoisotopicMass = 0;
        double proton = 1.007276466879;
        double monoisotopicMassAtoms[10] = {12, 1.007825037, 78.9183, 34.9689, 18.9984, 126.9045, 14.003074, 15.99491464, 30.973763, 31.9721};

        /*Calculate monoisotopic mass from integer sum formula*/
        for (i = 0; i < 10; i++)
                monoisotopicMass = monoisotopicMass + (double)intFormula[i] * monoisotopicMassAtoms[i];

        /*Return result of the calculation*/
        return monoisotopicMass;
}

/*Function to calculate average masses*/
int
averageMass (int intFormula[10])
{
        /*Initialise index counter, and masses of several atoms*/
        int i;
        int averageMass = 0;
        int averageMassAtoms[10] = {12, 1, 79, 35, 19, 127, 14, 16, 31, 32};

        /*Calculate average mass from integer sum formula*/
        for (i = 0; i < 10; i++)
                averageMass = averageMass + intFormula[i] * averageMassAtoms[i];

         /*Return result of the calculation*/
        return averageMass;
}
