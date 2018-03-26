/*
    Functions in this file:
    - double exactMass(int intFormula[10])
    - int nominalMass(int intFormula[10])
*/

#include <calculation.h>

extern int ionsource;
extern int polarity;

/*Function to calculate exact masses*/
double exactMass(int intFormula[10])
{

    int i;
    double exactMass = 0;
    double proton = 1.007276466879;
    double monoisotopicMassAtoms[10] = {12, 1.007825037, 78.9183, 34.9689, 18.9984, 126.9045, 14.003074, 15.99491464, 30.973763, 31.9721};

    for(i = 0; i < 10; i++)
    {
        exactMass = exactMass + (double)intFormula[i] * monoisotopicMassAtoms[i];
    }
    return exactMass;
}

/*Function to calculate nominal masses*/
int nominalMass(int intFormula[10])
{
    int i;
    int nominalMass = 0;
    int nominalMassAtoms[10] = {12, 1, 79, 35, 19, 127, 14, 16, 31, 32};

    for(i = 0; i < 10; i++)
    {
        nominalMass = nominalMass + intFormula[i] * nominalMassAtoms[i];
    }
    return nominalMass;
}
