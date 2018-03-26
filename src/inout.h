#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED

typedef struct{
    char name[20];
    int intFormula[10];
    char charFormula [33];
    int nominalMass;
    double exactMass;
}chemical;

void chemscanf (int formula[10]);

void assembleFormula(int intFormula[10], char charFormula[33]);

void displayTable(chemical *output, int size);

void exportTable(chemical *table, int size);

#endif