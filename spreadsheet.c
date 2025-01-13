#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordering.c"
#include "data.c"
#include "calc.c"
#include "spreadsheet.h"
//gcc ordering.c ordering.h data.c data.h calc.c calc.h spreadsheet.c spreadsheet.h

int checkExit = 0; //Variable to check if program should exit
int selection; //Variable to store main menu user selection


//Display main menu and return user selection
int displayMenu(){
    selection = -1; //Set main menu selection variable to invalid option
    //Main menu display
    printf("Speadsheet Menu\n---------------\n1. Display Spreadsheet\n2. Display Histogram\n3. Set sort column\n4. Update Last Name\n5. Update Exam Grade\n6. Update Grade Mapping\n7. Delete Student\n8. Exit\n\nSelection: ");
    while ((selection<1)||(selection>8)){ //Input validation
        scanf("%d", &selection); //Set selection to user input
        if ((selection<1)||(selection>8)){ //Input validation
            printf("\nInvalid input, selection must be an integer between 1 and 8\nSelection: ");
        }
    }
    return selection;
}


//Display Spreadsheet
void display1(){
    printf("COMP 348 GRADE SHEET\n\n");
    printf("ID\tLast         First        A1\tA2\tA3\tMidterm\t\tExam\tTotal\tGrade\n");
    printf("--\t----         -----        --\t--\t--\t-------\t\t----\t-----\t-----\n");
    for (int i = 0; i<studentAmount; i++){
        printf("%d\t%s %s %d\t%d\t%d\t%d\t\t%d\t%.2f\t%c\n", studentArray[i]->id,studentArray[i]->lname,studentArray[i]->fname,studentArray[i]->a1,studentArray[i]->a2,studentArray[i]->a3,studentArray[i]->midterm,studentArray[i]->exam,studentArray[i]->total, letterGrade(studentArray[i]->total));
    }
    proceedBuffer();
}

//Display grade histogram
void display2(){
    printf("COMP 348 Grade Distribution\n\n");

    int Anum = 0;
    int Bnum = 0;
    int Cnum = 0;
    int Dnum = 0;
    int Fnum = 0;

    for (int i = 0; i<studentAmount; i++){
        switch (letterGrade(studentArray[i]->total)){
            case 'A':
            Anum++;
            break;
            case 'B':
            Bnum++;
            break;
            case 'C':
            Cnum++;
            break;
            case 'D':
            Dnum++;
            break;
            case 'F':
            Fnum++;
            break;
            default:
            break;
        }
    }

    printf("A: ");
    for (int i = 0; i<Anum; i++){
        printf("*");
    }
    printf("\nB: ");
    for (int i = 0; i<Bnum; i++){
        printf("*");
    }
    printf("\nC: ");
    for (int i = 0; i<Cnum; i++){
        printf("*");
    }
    printf("\nD: ");
    for (int i = 0; i<Dnum; i++){
        printf("*");
    }
    printf("\nF: ");
    for (int i = 0; i<Fnum; i++){
        printf("*");
    }

    proceedBuffer();
}

//Display sort options
void display3(){
    printf("Column options\n");
    printf("--------------\n");
    printf("1. Student ID\n");
    printf("2. Last name\n");
    printf("3. Exam\n");
    printf("4. Total\n");
    int tempSelection = -1;
    printf("Sort Column: ");
    scanf("%d", &tempSelection);
    switch (tempSelection){
        case 1:
        qsort(studentArray, studentAmount, sizeof(struct student*), compareID);
        printf("\nSort Column updated\n");
        break;
        case 2:
        qsort(studentArray, studentAmount, sizeof(struct student*), compareLname);
        printf("\nSort Column updated\n");
        break;
        case 3:
        qsort(studentArray, studentAmount, sizeof(struct student*), compareExam);
        printf("\nSort Column updated\n");
        break;
        case 4:
        qsort(studentArray, studentAmount, sizeof(struct student*), compareTotal);
        printf("\nSort Column updated");
        break;
        default:
        printf("\nInvalid sort selection");
        break;
    }


    proceedBuffer();
}

//Function to update student last name
void display4(){
    printf("COMP 348 GRADE SHEET\n\n");
    printf("ID\tLast         First        A1\tA2\tA3\tMidterm\t\tExam\tTotal\tGrade\n");
    printf("--\t----         -----        --\t--\t--\t-------\t\t----\t-----\t-----\n");
    for (int i = 0; i<studentAmount; i++){
        printf("%d\t%s %s %d\t%d\t%d\t%d\t\t%d\t%.2f\t%c\n", studentArray[i]->id,studentArray[i]->lname,studentArray[i]->fname,studentArray[i]->a1,studentArray[i]->a2,studentArray[i]->a3,studentArray[i]->midterm,studentArray[i]->exam,studentArray[i]->total, letterGrade(studentArray[i]->total));
    }

    int inputID;
    char *inputLname = malloc(13);

    printf("\nEnter Student ID: ");
    scanf("%d", &inputID);

    int studentIndex = findStudent(inputID);

    if (studentIndex >= 0){
        printf("\nEnter updated last name: ");
        scanf("%s", inputLname);
        memset(studentArray[studentIndex]->lname, ' ', 12); //Fill fname with whitespace
        for (int i = 0; i<strlen(inputLname); i++){ //Replace whitespace characters with inputted string
            studentArray[studentIndex]->lname[i] = inputLname[i];
        }
        printf("Last name updated");
    }
    else{
        printf("\nInvalid student ID");
    }
    free(inputLname);

    proceedBuffer();
}

void display5(){
    printf("COMP 348 GRADE SHEET\n\n");
    printf("ID\tLast         First        A1\tA2\tA3\tMidterm\t\tExam\tTotal\tGrade\n");
    printf("--\t----         -----        --\t--\t--\t-------\t\t----\t-----\t-----\n");
    for (int i = 0; i<studentAmount; i++){
        printf("%d\t%s %s %d\t%d\t%d\t%d\t\t%d\t%.2f\t%c\n", studentArray[i]->id,studentArray[i]->lname,studentArray[i]->fname,studentArray[i]->a1,studentArray[i]->a2,studentArray[i]->a3,studentArray[i]->midterm,studentArray[i]->exam,studentArray[i]->total, letterGrade(studentArray[i]->total));
    }

    int inputID;
    int inputExam;

    printf("\nEnter Student ID: ");
    scanf("%d", &inputID);

    int studentIndex = findStudent(inputID);

    if (studentIndex >= 0){
        printf("\nEnter updated exam grade: ");
        scanf("%d", &inputExam);
        if (inputExam>=0&&inputExam<=40){
            studentArray[studentIndex]->exam = inputExam;
            printf("Exam grade updated");
            studentArray[studentIndex]->total = (((double)(studentArray[studentIndex]->a1+studentArray[studentIndex]->a2+studentArray[studentIndex]->a3)/120)*25)+studentArray[studentIndex]->midterm+(((double)studentArray[studentIndex]->exam/40)*50);
        }
        else{
            printf("Invalid exam grade (must be between 0 and 40)");
        }
    }

    else{
        printf("\nInvalid student ID");
    }   

    proceedBuffer();
}

void display6(){
    printf("Current Mapping:\n");
    printf("A: >= %d\n", Abaseline);
    printf("B: >= %d\n", Bbaseline);
    printf("C: >= %d\n", Cbaseline);
    printf("D: >= %d\n", Dbaseline);
    printf("F:  < %d\n", Dbaseline);

    printf("\nEnter new A baseline: ");
    scanf("%d", &Abaseline);
    printf("Enter new B baseline: ");
    scanf("%d", &Bbaseline);
    printf("Enter new C baseline: ");
    scanf("%d", &Cbaseline);
    printf("Enter new D baseline: ");
    scanf("%d", &Dbaseline);

    printf("\nNew Mapping:\n");
    printf("A: >= %d\n", Abaseline);
    printf("B: >= %d\n", Bbaseline);
    printf("C: >= %d\n", Cbaseline);
    printf("D: >= %d\n", Dbaseline);
    printf("F:  < %d\n", Dbaseline);

    proceedBuffer();
}

void display7(){
    printf("COMP 348 GRADE SHEET\n\n");
    printf("ID\tLast         First        A1\tA2\tA3\tMidterm\t\tExam\tTotal\tGrade\n");
    printf("--\t----         -----        --\t--\t--\t-------\t\t----\t-----\t-----\n");
    for (int i = 0; i<studentAmount; i++){
        printf("%d\t%s %s %d\t%d\t%d\t%d\t\t%d\t%.2f\t%c\n", studentArray[i]->id,studentArray[i]->lname,studentArray[i]->fname,studentArray[i]->a1,studentArray[i]->a2,studentArray[i]->a3,studentArray[i]->midterm,studentArray[i]->exam,studentArray[i]->total, letterGrade(studentArray[i]->total));
    }

    int inputID;

    printf("\nEnter Student ID: ");
    scanf("%d", &inputID);

    int studentIndex = findStudent(inputID);
    
    if (studentIndex >=0){
            free(studentArray[studentIndex]);

            for (int j = studentIndex; j < studentAmount - 1; j++) {
                studentArray[j] = studentArray[j + 1];
            }

            studentAmount--;
            printf("Student sucessfully deleted\n");
    }
    else{
        printf("Invalid student ID\n");
    }

    proceedBuffer();
}

//Method to keep the current screen until c is inputted
void proceedBuffer(){
    char proceed; //Define proceed char variable
    printf("\n"); //Formatting
    printf("\nPress 'c' or 'C' to continue ");
    do{
        scanf("%c", &proceed); //Replace proceed with user input
    } while ( (proceed != 'c') && (proceed != 'C')); //Check if correct user input, repeat if not
}


void main(){

    studentAmount = findAmount();
    studentArray = create_student_array(studentAmount); //Initialize student array from text file
    qsort(studentArray, studentAmount, sizeof(struct student*), compareID); //Initially sort by ID
    


    while(checkExit==0){ //Quit program if exit condition is satisfied
        system("clear");
        displayMenu(); //Display main menu
        system("clear");
        switch(selection){ //User selection logic
            case 1 :
            display1();
            break;
            case 2 :
            display2();
            break;
            case 3 :
            display3();
            break;
            case 4 :
            display4();
            break;
            case 5 :
            display5();
            break;
            case 6 :
            display6();
            break;
            case 7 :
            display7();
            break;
            case 8 :
            for (int i = 0; i<studentAmount; i++){
                free(studentArray[i]);
            }
            free(studentArray);
            printf("Exiting program\n");
            checkExit = 1;
            break;
            default :
            printf("Invalid selection");
        }
    } 
}