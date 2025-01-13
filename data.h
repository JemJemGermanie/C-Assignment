#ifndef DATA_DOT_H
#define DATA_DOT_H
struct student{
    int id;
    char fname[13];
    char lname[13];
    int a1;
    int a2;
    int a3;
    int midterm;
    int exam;
    double total;
};

struct student *createStudent(char* current_row);
struct student* *create_student_array(int size);
int findAmount();
#endif