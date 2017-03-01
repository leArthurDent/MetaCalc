#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double monoisotopicMassAtoms[10] = {12, 1.007825037, 78.9183, 34.9689, 18.9984, 126.9045, 14.003074, 15.99491464, 30.973763, 31.9721};
int nominalMassAtoms[10] = {12, 1, 79, 35, 19, 127, 14, 16, 31, 32};

typedef struct{
    char name[20];
    int intFormula[10];
    char charFormula [33];
    int nominalMass;
    double exactMass;
}chemical;

/*Definition of the banner*/
void banner()
{
    printf("******************************************\n");
    printf("*                                        *\n");
    printf("*               MetaCalc v0.2            *\n");
    printf("*                                        *\n");
    printf("******************************************\n");
    printf("\n");
}

/*Function to enter a molecular formula and return the atom numbers as an integer array
Atoms are sorted by IUPAC guidelines, other orders that are entered are also supported
Currently this function supports C, H, Br, F, I, N, O, P, S*/
void chemscanf (int formula[10])
{
    char input[33], bufferflush, buffer[3];
    int a, i;

    for(a = 0; a < 10; a++) {
        formula[a] = 0;
    }
    scanf("%33s", input);

    do{
        bufferflush = getchar();
    }
    while(bufferflush != '\n' && bufferflush != EOF);

    for(i = 0; i < sizeof(input) / sizeof(char); i++){

        if(input[i] == 'C'){
            i++;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[0] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[0] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'H') {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[1] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[1] = atoi(buffer);
            }
            --i;
        }

        else if((input[i] == 'B') && (input[++i] == 'r')) {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[2] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[2] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'F') {
                ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[4] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[4] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'I') {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[5] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[5] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'N') {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[6] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[6] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'O') {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[7] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[7] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'P') {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[8] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[8] = atoi(buffer);
            }
            --i;
        }

        else if(input[i] == 'S') {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[9] = 1;
            }
            else {
                buffer[0] = input[i];
                ++i;
                if(isdigit(input[i]) == 0) {
                    buffer[1] = '\0';
                }
                else {
                    buffer[1] = input[i];
                    buffer[2] = '\0';
                }
                formula[9] = atoi(buffer);
            }
            --i;
        }

        else if (input[i] == '\0') {
            break;
        }
    }
}

/*Function to assemble a molecular formula string from the atom numbers*/
void assembleFormula(int intFormula[10], char charFormula[33])
{
    int a, i, intbuffer;
    char charbuffer[2];

    for(a = 0; a < 33; a++) {
        charFormula[a] = 'x';
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[0] == 0){
                break;
            }
            else if(intFormula[0] == 1){
                charFormula[i] = 'C';
                break;
            }
            else{
                charFormula[i] = 'C';
                if(intFormula[0] < 10){
                    charFormula[++i] = intFormula[0] + '0';
                }
                else if(intFormula[0] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[0];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[1] == 0){
            break;
            }
            else if(intFormula[1] == 1){
                charFormula[i] = 'H';
                break;
            }
            else{
                charFormula[i] = 'H';
                if(intFormula[1] < 10){
                    charFormula[++i] = intFormula[1] + '0';
                }
                else if(intFormula[1] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[1];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[2] == 0){
                break;
            }
            else if(intFormula[2] == 1){
                charFormula[i] = 'B';
                charFormula[++i] = 'r';
                break;
            }
            else{
                charFormula[i] = 'B';
                charFormula[++i] = 'r';
                if(intFormula[2] < 10){
                    charFormula[++i] = intFormula[2] + '0';
                }
                else if(intFormula[2] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[2];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[3] == 0){
                break;
            }
            else if(intFormula[3] == 1){
                charFormula[i] = 'C';
                charFormula[++i] = 'l';
                break;
            }
            else{
                charFormula[i] = 'C';
                charFormula[++i] = 'l';
                if(intFormula[3] < 10){
                    charFormula[++i] = intFormula[3] + '0';
                }
                else if(intFormula[3] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[3];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[4] == 0){
                break;
            }
            else if(intFormula[4] == 1){
                charFormula[i] = 'F';
                break;
            }
            else{
                charFormula[i] = 'F';
                if(intFormula[4] < 10){
                    charFormula[++i] = intFormula[4] + '0';
                }
                else if(intFormula[4] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[4];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[5] == 0){
                break;
            }
            else if(intFormula[5] == 1){
                charFormula[i] = 'I';
                break;
            }
            else{
                charFormula[i] = 'I';
                if(intFormula[5] < 10){
                    charFormula[++i] = intFormula[5] + '0';
                }
                else if(intFormula[5] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[5];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[6] == 0){
                break;
            }
            else if(intFormula[6] == 1){
                charFormula[i] = 'N';
                break;
            }
            else{
                charFormula[i] = 'N';
                if(intFormula[6] < 10){
                    charFormula[++i] = intFormula[6] + '0';
                }
                else if(intFormula[6] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[6];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[7] == 0){
                break;
            }
            else if(intFormula[7] == 1){
                charFormula[i] = 'O';
                break;
            }
            else if(intFormula[7] == 1){
                charFormula[i] = 'C';
                break;
            }
            else{
                charFormula[i] = 'O';
                if(intFormula[7] < 10){
                    charFormula[++i] = intFormula[7] + '0';
                }
                else if(intFormula[7] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[7];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
                if(intFormula[8] == 0){
                break;
            }
            else if(intFormula[8] == 1){
                charFormula[i] = 'P';
                break;
            }
            else{
                charFormula[i] = 'P';
                if(intFormula[8] < 10){
                    charFormula[++i] = intFormula[8] + '0';
                }
                else if(intFormula[8] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[8];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else {
            if(intFormula[9] == 0){
                break;
            }
            else if(intFormula[9] == 1){
                charFormula[i] = 'S';
                break;
            }
            else{
                charFormula[i] = 'S';
                if(intFormula[9] < 10){
                    charFormula[++i] = intFormula[9] + '0';
                }
                else if(intFormula[9] == 10){
                    charFormula[++i] = '1';
                    charFormula[++i] = '0';
                }
                else{
                    intbuffer = intFormula[9];
                    charbuffer[0] = (intbuffer % 10) + '0';
                    intbuffer /= 10;
                    charbuffer[1] = (intbuffer % 10) + '0';
                    charFormula[++i] = charbuffer[1];
                    charFormula[++i] = charbuffer[0];
                }
            }
            break;
        }
    }

    for(i = 0; i < 33; i++) {
        if(charFormula[i] != 'x') {
            continue;
        }
        else{
            charFormula[i] = '\0';
        }
    }
}

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

/*Function to calculate exact masses*/
double exactMass(int intFormula[10])
{
    int i;
    double exactMass = 0;

    for(i = 0; i < 11; i++)
    {
        exactMass = exactMass + intFormula[i] * monoisotopicMassAtoms[i];
    }
    return exactMass;
}


/*Function to calculate nominal masses*/
int nominalMass(int intFormula[10])
{
    int i;
    int nominalMass = 0;

    for(i = 0; i < 11; i++)
    {
        nominalMass = nominalMass + intFormula[i] * nominalMassAtoms[i];
    }
    return nominalMass;
}

/*Function to display the result table*/
void outputTable(chemical *output, int size)
{
    int i;

    printf("Name           Formula        Nominalmass    Exactmass");
    printf("\n");
    for(i=0; i < size; i++)
    {
        printf("%-15s%-15s%-15d%-12.4f\n", output[i].name, output[i].charFormula, output[i].nominalMass, output[i].exactMass);
    }
}

/*Functino to export the result table into a .csv file*/
void exportTable(chemical *table, int size)
{
    int i;
    char yn;

    do {
    printf("Do you like to export the table into a .csv file? (y/n)\n");
    scanf(" %c", &yn);
    }
    while(yn != 'y' && yn != 'n');

    if(yn == 'y')
    {

        FILE *fp;
        fp = fopen("Metabolites.csv", "w");

        fprintf(fp, "Name,Formula,Nominalmass,Exactmass\n");

        for(i = 0; i < size; i++)
            fprintf(fp, "%s,%s,%d,%.4f\n", table[i].name, table[i].charFormula, table[i].nominalMass, table[i].exactMass);

        fclose(fp);
    }
}

int main()
{
    chemical compound[16];
    int i, choice;
    char correction = 'y';

    banner();

    do {
        printf("Calculate metabolites: 1    About: 2    Exit: 0\n");

        do {
        scanf(" %d", &choice);
        }
        while(choice != 0 && choice != 1 && choice != 2);

        if(choice == 1){
            /*Input dialogue with the possibility of correction*/
            do
            {
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

            /*Metabolising of the molecular formula*/
            metabolise(compound);

            /*Calculation of the nominal masses*/
            for(i = 0; i < (sizeof(compound)/sizeof(chemical)); i++)
                compound[i].nominalMass = nominalMass(compound[i].intFormula);

            /*Calculation of the exact masses*/
            for(i = 0; i < (sizeof(compound)/sizeof(chemical)); i++)
                compound[i].exactMass = exactMass(compound[i].intFormula);

            /*Generating molecular formula strings of metabolitea*/
            for(i = 0; i < (sizeof(compound)/sizeof(chemical)); i++)
                assembleFormula(compound[i].intFormula, compound[i].charFormula);

            /*Output of the result table*/
            outputTable(compound, (sizeof(compound)/sizeof(chemical)));

            /*Export of the result table into a .csv file*/
            exportTable(compound, (sizeof(compound)/sizeof(chemical)));

        }

        if(choice == 2){
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

        if(choice == 0){
            printf("Good luck!\n");
            return 0;
        }

    }
    while(choice != 0);
}
