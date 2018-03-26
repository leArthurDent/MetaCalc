/*
    Functions in this file:
    - void chemscanf (int formula[10])
    - void assembleFormula(int intFormula[10], char charFormula[33])
    - void displayTable(chemical *output, int size)
    - void exportTable(chemical *table, int size)
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <inout.h>

extern chemical compound;

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

    /*if((input[i] == 'C') && (input[++i] == 'l')) {
            ++i;
            if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[3] = 1;
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
                formula[3] = atoi(buffer);
            }
            --i;
        }'*/
        
        if(input[i] == 'C'){
            i++;
       	    if (input[i] == 'l') {
            	if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[3] = 1;
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
                	formula[3] = atoi(buffer);
                }
            }
            else if((isdigit(input[i]) == 0) || (input[i] == '\0')) {
                formula[0] = 1;
            }
            
            else if (input[i] != 'l'){
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

/*Function to display the result table*/
void displayTable(chemical *output, int size)
{
    int i;

    printf("Name           Formula        Nominalmass    Exactmass");
    printf("\n");
    for(i=0; i < size; i++)
    {
        printf("%-15s%-15s%-15d%-12.4f\n", output[i].name, output[i].charFormula, output[i].nominalMass, output[i].exactMass);
    }
}

/*Functinon to export the result table into a .csv file*/
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
