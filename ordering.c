#ifndef ORDERING_DOT_C
#define ORDERING_DOT_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.c"
//Compare function for ascending ID
int compareID(const void* a, const void* b){
    const struct student* studentA = *(const struct student**)a;
    const struct student* studentB = *(const struct student**)b;
    return studentA->id - studentB->id;
}

//Compare function for ascending last name
int compareLname(const void* a, const void* b) {
    const struct student* studentA = *(const struct student**)a;
    const struct student* studentB = *(const struct student**)b;
    return strcmp(studentA->lname, studentB->lname);
}

//Compare function for descending exam grade
int compareExam(const void* a, const void* b){
    const struct student* studentA = *(const struct student**)a;
    const struct student* studentB = *(const struct student**)b;
    return studentB->exam - studentA->exam;
}

//Compare function for descending total grade
int compareTotal(const void* a, const void* b){
    const struct student* studentA = *(const struct student**)a;
    const struct student* studentB = *(const struct student**)b;
    return studentB->total - studentA->total;
}
#endif