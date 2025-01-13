#ifndef CALC_DOT_C
#define CALC_DOT_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.c"
#include "calc.h"
#include "spreadsheet.h"
int Abaseline = 80;
int Bbaseline = 70;
int Cbaseline = 60;
int Dbaseline = 50;

//Function to calculate student letter grade
char letterGrade(int total){
    if (total>=Abaseline){
        return 'A';
    }
    else if (total>=Bbaseline){
        return 'B';
    }
    else if (total>=Cbaseline){
        return 'C';
    }
    else if (total>=Dbaseline){
        return 'D';
    }
    else{
        return 'F';
    }
}

int findStudent(int id){
    int location = -1;
    for (int i = 0; i<studentAmount; i++){
        if (studentArray[i]->id == id){
            location = i;
        }
    }
    return location;
}

#endif