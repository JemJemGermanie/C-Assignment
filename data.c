#ifndef DATA_DOT_C
#define DATA_DOT_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
//Function to find number of students
int findAmount(){
    int amount = 0;
    FILE* file_ptr = fopen("students.txt", "r");
    char current_row[256];
    while (fgets(current_row, 256, file_ptr) != NULL){
        amount++;
    }
    return amount;
}

//Function to initialize student array
struct student* *create_student_array(int amount){

    FILE* file_ptr = fopen("students.txt", "r"); //Create pointer to file
    char current_row[256]; //Initialize string to hold the current row
	struct student* *new_array = malloc(amount * sizeof(struct student*)); //Reserve space for pointer array
    int i = 0; //Counter

    while (fgets(current_row, 256, file_ptr) != NULL){ //Do while there is a next line
        new_array[i] = createStudent(current_row); //Create student and place pointer in array
        i++;
    }
	
	return new_array;
}

//Function to create a student struct when passed the current row in the file
struct student *createStudent(char* current_row){

    struct student *s = malloc(sizeof(struct student)); //Allocate memory for struct

    s->id = atoi(strtok(current_row, "|"));

    char *parsedLname = strtok(NULL, "|");
    memset(s->lname, ' ', 12); //Fill fname with whitespace
    for (int i = 0; i<strlen(parsedLname); i++){ //Replace whitespace characters with inputted string
        s->lname[i] = parsedLname[i];
    }

        char *parsedFname = strtok(NULL, "|");
    memset(s->fname, ' ', 12); //Fill fname with whitespace
    for (int i = 0; i<strlen(parsedFname); i++){ //Replace whitespace characters with inputted string
        s->fname[i] = parsedFname[i];
    }

    s->a1 = atoi(strtok(NULL, "|"));

    s->a2 = atoi(strtok(NULL, "|"));

    s->a3 = atoi(strtok(NULL, "|"));

    s->midterm = atoi(strtok(NULL, "|"));

    s->exam = atoi(strtok(NULL, "|"));

    //Calculate total grade
    s->total = (((double)(s->a1+s->a2+s->a3)/120)*25)+s->midterm+(((double)s->exam/40)*50);

    return s;
}
#endif