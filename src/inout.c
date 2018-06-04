/*
        Functions in this file:
        - void parseFormula (char charFormula[33], int intFormula[10])
        - void assembleFormula (int intFormula[10], char charFormula[33])
        - void displayTable (chemical *output, int size)
        - void exportTable (chemical *table, int size)
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "inout.h"

/*Import chemical struct*/
extern chemical compound;

/*Function to enter a molecular formula and return the atom numbers as an integer array
 * Atoms are sorted by IUPAC guidelines, other orders that are entered are also supported
 * Currently this function supports C, H, Br, Cl, F, I, N, O, P, S*/
void
parseFormula (char charFormula[33],
              int  intFormula[10])
{
        /*Initialise buffer and index intergers*/
        char buffer[3];
        int a, i;

        /*Zero the integer array*/
        for (a = 0; a < 10; a++)
        intFormula[a] = 0;

        /*Loop that processes every element of the char array*/
        for (i = 0; i < 33; i++) {

                /*Check if the array element is a "C" declaring a carbon atom*/
                if(charFormula[i] == 'C') {

                        /*Go one element further in the array*/
                        i++;

                        /*Check if the next element of the array is an "l" declaring a chlorine atom*/
                        if (charFormula[i] == 'l') {

                                /*Check if the next element is another char element or the end of the input*/
                                if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {

                                        /*If so record one chlorine atom in the intFormula */
                                        intFormula[3] = 1;
                                }
                                else {
                                        /*If not char, then copy to the buffer*/
                                        buffer[0] = charFormula[i];

                                        /*Check if the next element of the array is also not a char,
                                         * if so copy to buffer*/
                                        ++i;
                                        if(isdigit(charFormula[i]) == 0) {
                                                buffer[1] = '\0';
                                        }

                                        /*If not, append "\0" to indicate the end of the buffer*/
                                        else {
                                                buffer[1] = charFormula[i];
                                                buffer[2] = '\0';
                                        }

                                        /*Convert the char digits to an integer and write it to the intFormula*/
                                        intFormula[3] = atoi(buffer);
                                }
                        }


                        /*If the next element is not an "l" check if it is a char or a "\0"*/
                        else if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                /*If so record one carbon atom*/
                                intFormula[0] = 1;
                        }

                        /*If it is not an "l" and not a char*/
                        else if (charFormula[i] != 'l'){

                                /*Write element to buffer*/
                                buffer[0] = charFormula[i];

                                /*Proceed with next element*/
                                ++i;

                                /*Check if the next element is a char*/
                                if(isdigit(charFormula[i]) == 0) {

                                        /*If so write "\0" to the buffer*/
                                        buffer[1] = '\0';
                                }

                                /*If not write also the next digit to the buffer*/
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }

                                /*Convert digits to integer*/
                                intFormula[0] = atoi(buffer);
                        }

                        /*Revert to the previous element of the array*/
                        --i;
                }


                else if(charFormula[i] == 'H') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[1] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[1] = atoi(buffer);
                        }
                        --i;
                }

                else if ((charFormula[i] == 'B') && (charFormula[++i] == 'r')) {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[2] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[2] = atoi(buffer);
                        }
                        --i;
                }

                else if(charFormula[i] == 'F') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[4] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[4] = atoi(buffer);
                        }
                        --i;
                }

                else if(charFormula[i] == 'I') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[5] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[5] = atoi(buffer);
                        }
                        --i;
                }

                else if(charFormula[i] == 'N') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[6] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[6] = atoi(buffer);
                        }
                        --i;
                }

                else if(charFormula[i] == 'O') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[7] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[7] = atoi(buffer);
                        }
                        --i;
                }

                else if(charFormula[i] == 'P') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[8] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[8] = atoi(buffer);
                        }
                        --i;
                }

                else if(charFormula[i] == 'S') {
                        ++i;
                        if((isdigit(charFormula[i]) == 0) || (charFormula[i] == '\0')) {
                                intFormula[9] = 1;
                        }
                        else {
                                buffer[0] = charFormula[i];
                                ++i;
                                if(isdigit(charFormula[i]) == 0) {
                                        buffer[1] = '\0';
                                }
                                else {
                                        buffer[1] = charFormula[i];
                                        buffer[2] = '\0';
                                }
                                intFormula[9] = atoi(buffer);
                        }
                        --i;
                }

                else if (charFormula[i] == '\0') {
                    break;
                }
        }
}

/*Function to assemble a molecular formula string from the atom numbers*/
void
assembleFormula(int  intFormula[10],
                char charFormula[33])
{
        /*Initialize index variables and buffer array*/
        int a, i, intbuffer;
        char charbuffer[2];

        /*Set every element of the char array to "x"*/
        for(a = 0; a < 33; a++) {
                charFormula[a] = 'x';
        }

        /*For loop to process every element of the char array*/
        for(i = 0; i < 33; i++) {

                /*Check if the element is an "x". If not, continue.*/
                if(charFormula[i] != 'x') {
                        continue;
                }

                /*If so continue to assemble the readable sum formula*/
                else {
                        /*Check if element from intFormula is 0. If so skip it.*/
                        if(intFormula[0] == 0){
                                break;
                        }

                        /*If the first element is a 1, then merely write a C and continue with next element*/
                        else if(intFormula[0] == 1){
                                charFormula[i] = 'C';
                                break;
                        }

                        /*If it is not 1, then write "C" and append number*/
                        else{
                                charFormula[i] = 'C';

                                /*If number is less than 10 append it*/
                                if(intFormula[0] < 10){
                                        charFormula[++i] = intFormula[0] + '0';
                                }

                                /*If number is equal 10 write 1 and 0 to the following elements*/
                                else if(intFormula[0] == 10){
                                        charFormula[++i] = '1';
                                        charFormula[++i] = '0';
                                }

                                /*If number is something else write it to the intbuffer,
                                 * divide it by 10 and write the rest to the charbuffer.
                                 * At last write the charbuffer recursively to the char array of the sum formula*/
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

        /*Append "\0" to mark end of the string*/
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
void displayTable(chemical *output,
                  int       size)
{
        int i;

        printf("Name                      Formula        Average mass   Monoisotopic mass");
        printf("\n");

        for(i=0; i < size; i++) {
                printf("%-26s%-15s%-15d%-12.4f\n", output[i].name,
                                                   output[i].charFormula,
                                                   output[i].averageMass,
                                                   output[i].monoisotopicMass);
        }
        printf("\n");
}

/*Functinon to export the result table into a .csv file*/
void
exportTable(chemical *table,
            int       size)
{
        int i;
        char yn;

        do {
                printf("Do you like to export the table into a .csv file? (y/n)\n");
                scanf(" %c", &yn);
        }
        while(yn != 'y' && yn != 'n');

        if(yn == 'y') {
                FILE *fp;
                fp = fopen("Metabolites.csv", "w");

                fprintf(fp, "Name,Formula,Nominalmass,Exactmass\n");
                for(i = 0; i < size; i++) {
                        fprintf(fp, "%s,%s,%d,%.4f\n", table[i].name,
                                                       table[i].charFormula,
                                                       table[i].averageMass,
                                                       table[i].monoisotopicMass);
                }
                fclose(fp);
        }
}
