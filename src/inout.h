#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED

typedef struct{
    char name [25];
    int intFormula [10];
    char charFormula [33];
    int nominalMass;
    double exactMass;
}chemical;

void parseFormula (char charFormula[33], int intFormula[10]);

void assembleFormula (int intFormula[10], char charFormula[33]);

void displayTable (chemical *output, int size);

void exportTable (chemical *table, int size);

#endif
