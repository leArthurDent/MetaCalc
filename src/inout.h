#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED


/*Define chemicals as structs with the following properties:
 * - name:            description of the substance or the metabolite
 * - intFormula:      processible version of the sum formula
 * - charFormula:     readable version of the sum formula
 * - averageMass:     mass of the substance considering a statistical average
 *                    distribution of the contained isotopes
 * -monoisotopicMass: mass of the substance considering only one the most frequent
 *                    occuring isotope being contained */
typedef struct{
    char name [25];
    int intFormula [10];
    char charFormula [33];
    int averageMass;
    double monoisotopicMass;
}chemical;

void parseFormula (char charFormula[33], int intFormula[10]);

void assembleFormula (int intFormula[10], char charFormula[33]);

void displayTable (chemical *output, int size);

void exportTable (chemical *table, int size);

#endif
