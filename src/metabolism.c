/*
    Functions in this file:
    - metabolise (chemical *compound)
*/

#include <string.h>
#include <metabolism.h>

/*Function to calculate integer formulas of metabolites*/
void metabolise(chemical *compound)
{
    /*Naming of the compounds*/
    strcpy(compound[0].name, "Parent");
    strcpy(compound[1].name, "oxo-");
    strcpy(compound[2].name, "HO-");
    strcpy(compound[3].name, "di-oxo-");
    strcpy(compound[4].name, "oxo-HO-");
    strcpy(compound[5].name, "di-HO-");
    strcpy(compound[6].name, "tri-oxo-");
    strcpy(compound[7].name, "di-oxo-HO-");
    strcpy(compound[8].name, "oxo-di-HO-");
    strcpy(compound[9].name, "tri-HO-");
    strcpy(compound[10].name, "HO-Gluc");
    strcpy(compound[11].name, "oxo-HO-Gluc");
    strcpy(compound[12].name, "di-HO-Gluc");
    strcpy(compound[13].name, "di-oxo-HO-Gluc");
    strcpy(compound[14].name, "oxo-di-HO-Gluc");
    strcpy(compound[15].name, "tri-HO-Gluc");

    /*Alteration of the native formula for an oxo-metabolite*/
    compound[1].intFormula[0] = compound[0].intFormula[0];
    compound[1].intFormula[1] = compound[0].intFormula[1]-2;
    compound[1].intFormula[2] = compound[0].intFormula[2];
    compound[1].intFormula[3] = compound[0].intFormula[3];
    compound[1].intFormula[4] = compound[0].intFormula[4];
    compound[1].intFormula[5] = compound[0].intFormula[5];
    compound[1].intFormula[6] = compound[0].intFormula[6];
    compound[1].intFormula[7] = compound[0].intFormula[7]+1;
    compound[1].intFormula[8] = compound[0].intFormula[8];
    compound[1].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a hydroxy-metabolite*/
    compound[2].intFormula[0] = compound[0].intFormula[0];
    compound[2].intFormula[1] = compound[0].intFormula[1];
    compound[2].intFormula[2] = compound[0].intFormula[2];
    compound[2].intFormula[3] = compound[0].intFormula[3];
    compound[2].intFormula[4] = compound[0].intFormula[4];
    compound[2].intFormula[5] = compound[0].intFormula[5];
    compound[2].intFormula[6] = compound[0].intFormula[6];
    compound[2].intFormula[7] = compound[0].intFormula[7]+1;
    compound[2].intFormula[8] = compound[0].intFormula[8];
    compound[2].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a di-oxo-metabolite*/
    compound[3].intFormula[0] = compound[0].intFormula[0];
    compound[3].intFormula[1] = compound[0].intFormula[1]-4;
    compound[3].intFormula[2] = compound[0].intFormula[2];
    compound[3].intFormula[3] = compound[0].intFormula[3];
    compound[3].intFormula[4] = compound[0].intFormula[4];
    compound[3].intFormula[5] = compound[0].intFormula[5];
    compound[3].intFormula[6] = compound[0].intFormula[6];
    compound[3].intFormula[7] = compound[0].intFormula[7]+2;
    compound[3].intFormula[8] = compound[0].intFormula[8];
    compound[3].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for an oxo-hydroxy-metabolite*/
    compound[4].intFormula[0] = compound[0].intFormula[0];
    compound[4].intFormula[1] = compound[0].intFormula[1]-2;
    compound[4].intFormula[2] = compound[0].intFormula[2];
    compound[4].intFormula[3] = compound[0].intFormula[3];
    compound[4].intFormula[4] = compound[0].intFormula[4];
    compound[4].intFormula[5] = compound[0].intFormula[5];
    compound[4].intFormula[6] = compound[0].intFormula[6];
    compound[4].intFormula[7] = compound[0].intFormula[7]+2;
    compound[4].intFormula[8] = compound[0].intFormula[8];
    compound[4].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a di-hydroxy-metabolite*/
    compound[5].intFormula[0] = compound[0].intFormula[0];
    compound[5].intFormula[1] = compound[0].intFormula[1];
    compound[5].intFormula[2] = compound[0].intFormula[2];
    compound[5].intFormula[3] = compound[0].intFormula[3];
    compound[5].intFormula[4] = compound[0].intFormula[4];
    compound[5].intFormula[5] = compound[0].intFormula[5];
    compound[5].intFormula[6] = compound[0].intFormula[6];
    compound[5].intFormula[7] = compound[0].intFormula[7]+2;
    compound[5].intFormula[8] = compound[0].intFormula[8];
    compound[5].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a tri-oxo-metabolite*/
    compound[6].intFormula[0] = compound[0].intFormula[0];
    compound[6].intFormula[1] = compound[0].intFormula[1]-6;
    compound[6].intFormula[2] = compound[0].intFormula[2];
    compound[6].intFormula[3] = compound[0].intFormula[3];
    compound[6].intFormula[4] = compound[0].intFormula[4];
    compound[6].intFormula[5] = compound[0].intFormula[5];
    compound[6].intFormula[6] = compound[0].intFormula[6];
    compound[6].intFormula[7] = compound[0].intFormula[7]+3;
    compound[6].intFormula[8] = compound[0].intFormula[8];
    compound[6].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a di-oxo-hydroxy-metabolite*/
    compound[7].intFormula[0] = compound[0].intFormula[0];
    compound[7].intFormula[1] = compound[0].intFormula[1]-4;
    compound[7].intFormula[2] = compound[0].intFormula[2];
    compound[7].intFormula[3] = compound[0].intFormula[3];
    compound[7].intFormula[4] = compound[0].intFormula[4];
    compound[7].intFormula[5] = compound[0].intFormula[5];
    compound[7].intFormula[6] = compound[0].intFormula[6];
    compound[7].intFormula[7] = compound[0].intFormula[7]+3;
    compound[7].intFormula[8] = compound[0].intFormula[8];
    compound[7].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for an oxo-di-hydroxy-metabolite*/
    compound[8].intFormula[0] = compound[0].intFormula[0];
    compound[8].intFormula[1] = compound[0].intFormula[1]-2;
    compound[8].intFormula[2] = compound[0].intFormula[2];
    compound[8].intFormula[3] = compound[0].intFormula[3];
    compound[8].intFormula[4] = compound[0].intFormula[4];
    compound[8].intFormula[5] = compound[0].intFormula[5];
    compound[8].intFormula[6] = compound[0].intFormula[6];
    compound[8].intFormula[7] = compound[0].intFormula[7]+3;
    compound[8].intFormula[8] = compound[0].intFormula[8];
    compound[8].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a tri-hydroxy-metabolite*/
    compound[9].intFormula[0] = compound[0].intFormula[0];
    compound[9].intFormula[1] = compound[0].intFormula[1];
    compound[9].intFormula[2] = compound[0].intFormula[2];
    compound[9].intFormula[3] = compound[0].intFormula[3];
    compound[9].intFormula[4] = compound[0].intFormula[4];
    compound[9].intFormula[5] = compound[0].intFormula[5];
    compound[9].intFormula[6] = compound[0].intFormula[6];
    compound[9].intFormula[7] = compound[0].intFormula[7]+3;
    compound[9].intFormula[8] = compound[0].intFormula[8];
    compound[9].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a hydroxy-glucuronide-metabolite*/
    compound[10].intFormula[0] = compound[0].intFormula[0]+6;
    compound[10].intFormula[1] = compound[0].intFormula[1]+8;
    compound[10].intFormula[2] = compound[0].intFormula[2];
    compound[10].intFormula[3] = compound[0].intFormula[3];
    compound[10].intFormula[4] = compound[0].intFormula[4];
    compound[10].intFormula[5] = compound[0].intFormula[5];
    compound[10].intFormula[6] = compound[0].intFormula[6];
    compound[10].intFormula[7] = compound[0].intFormula[7]+7;
    compound[10].intFormula[8] = compound[0].intFormula[8];
    compound[10].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for an oxo-hydroxy-glucuronide-metabolite*/
    compound[11].intFormula[0] = compound[0].intFormula[0]+6;
    compound[11].intFormula[1] = compound[0].intFormula[1]+6;
    compound[11].intFormula[2] = compound[0].intFormula[2];
    compound[11].intFormula[3] = compound[0].intFormula[3];
    compound[11].intFormula[4] = compound[0].intFormula[4];
    compound[11].intFormula[5] = compound[0].intFormula[5];
    compound[11].intFormula[6] = compound[0].intFormula[6];
    compound[11].intFormula[7] = compound[0].intFormula[7]+8;
    compound[11].intFormula[8] = compound[0].intFormula[8];
    compound[11].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a di-hydroxy-glucuronide-metabolite*/
    compound[12].intFormula[0] = compound[0].intFormula[0]+6;
    compound[12].intFormula[1] = compound[0].intFormula[1]+8;
    compound[12].intFormula[2] = compound[0].intFormula[2];
    compound[12].intFormula[3] = compound[0].intFormula[3];
    compound[12].intFormula[4] = compound[0].intFormula[4];
    compound[12].intFormula[5] = compound[0].intFormula[5];
    compound[12].intFormula[6] = compound[0].intFormula[6];
    compound[12].intFormula[7] = compound[0].intFormula[7]+8;
    compound[12].intFormula[8] = compound[0].intFormula[8];
    compound[12].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a di-oxo-hydroxy-glucuronide-metabolite*/
    compound[13].intFormula[0] = compound[0].intFormula[0]+6;
    compound[13].intFormula[1] = compound[0].intFormula[1]+4;
    compound[13].intFormula[2] = compound[0].intFormula[2];
    compound[13].intFormula[3] = compound[0].intFormula[3];
    compound[13].intFormula[4] = compound[0].intFormula[4];
    compound[13].intFormula[5] = compound[0].intFormula[5];
    compound[13].intFormula[6] = compound[0].intFormula[6];
    compound[13].intFormula[7] = compound[0].intFormula[7]+9;
    compound[13].intFormula[8] = compound[0].intFormula[8];
    compound[13].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for an oxo-di-hydroxy-glucuronide-metabolite*/
    compound[14].intFormula[0] = compound[0].intFormula[0]+6;
    compound[14].intFormula[1] = compound[0].intFormula[1]+6;
    compound[14].intFormula[2] = compound[0].intFormula[2];
    compound[14].intFormula[3] = compound[0].intFormula[3];
    compound[14].intFormula[4] = compound[0].intFormula[4];
    compound[14].intFormula[5] = compound[0].intFormula[5];
    compound[14].intFormula[6] = compound[0].intFormula[6];
    compound[14].intFormula[7] = compound[0].intFormula[7]+9;
    compound[14].intFormula[8] = compound[0].intFormula[8];
    compound[14].intFormula[9] = compound[0].intFormula[9];

    /*Alteration of the native formula for a tri-hydroxy-glucuronide-metabolite*/
    compound[15].intFormula[0] = compound[0].intFormula[0]+6;
    compound[15].intFormula[1] = compound[0].intFormula[1]+8;
    compound[15].intFormula[2] = compound[0].intFormula[2];
    compound[15].intFormula[3] = compound[0].intFormula[3];
    compound[15].intFormula[4] = compound[0].intFormula[4];
    compound[15].intFormula[5] = compound[0].intFormula[5];
    compound[15].intFormula[6] = compound[0].intFormula[6];
    compound[15].intFormula[7] = compound[0].intFormula[7]+9;
    compound[15].intFormula[8] = compound[0].intFormula[8];
    compound[15].intFormula[9] = compound[0].intFormula[9];
}
