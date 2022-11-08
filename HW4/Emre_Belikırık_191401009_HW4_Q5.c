#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void minimum(int *ptr);
void maximum(int *ptr);
void average(int *ptr);
void printArray(int *ptr);


int main(void) {
    int *ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
    int *processGrades[5] = {ptr1,ptr2,ptr3,ptr4,ptr5};

    int choice;
    printf("Enter a choice:\n0 Print the array\n1 Find the minimum grade\n2 Find the maximum grade\n");
    printf("3 Print the average on all tests for each student \n4 Print the modified average on all tests for each student \n");
    printf("5 End program");
    printf("\nChoice: ");
    scanf("%d",&choice);

    
    int studentGrades[STUDENTS][EXAMS] = { { 77, 68, 86, 73 },
                                        { 96, 87, 89, 78 },
                                        { 70, 90, 86, 81 } };

    
    if(choice == 5) {
        printf("Program ended.");
    } else if(choice == 0) { 
        processGrades[0] = studentGrades;
        printArray(processGrades[0]);
    } else if(choice == 1) {
        processGrades[1] = studentGrades;
        maximum(processGrades[1]);
    } else if(choice == 2) {
        processGrades[2] = studentGrades;
        minimum(processGrades[2]);
    } else if(choice == 3) {
        processGrades[3] = studentGrades;
        average(processGrades[3]);
    } else if(choice == 4) {
        processGrades[4] = studentGrades;
        modifiedAverage(processGrades[4]);
    }
    return 0;
}  

void modifiedAverage(int *ptr)  {
    int total;
    int min;
    int max;
    for (int i = 0; i < STUDENTS; ++i) {
        total = 0;
        min = 100;
        max = 0;

        for (int j = 0; j < EXAMS; ++j) {
            if (*(ptr+EXAMS*i+j) < min) {
                min = *(ptr+EXAMS*i+j);
            } 
            if(*(ptr+EXAMS*i+j) > max) {
                max = *(ptr+EXAMS*i+j);
            }
        }
        total += (min+max);
        
        printf("\nmodifiedAverage of student %d is %d.",i+1,total/2);
    }
}

void minimum(int *ptr) {
    int lowGrade = 100; // initialize to highest possible grade

    for (int i = 0; i < STUDENTS; ++i) {

        for (int j = 0; j < EXAMS; ++j) {

            if (*(ptr+EXAMS*i+j) < lowGrade) {
                lowGrade = *(ptr+EXAMS*i+j);
            }
        }
    }
    printf("\nMinimum grade is %d\n",lowGrade);
} 

void maximum(int *ptr){
    int highGrade = 0; 
        for (int i = 0; i < STUDENTS; ++i) {
            for (int j = 0; j < EXAMS; ++j) {

                if (*(ptr+EXAMS*i+j) > highGrade) {
                    highGrade = *(ptr+EXAMS*i+j);
                }
            }
        }
    printf("\nMaximum grade is %d\n",highGrade);

}

void average(int *ptr) {
    int total;
    for (int i = 0; i < STUDENTS; ++i) {
        total = 0;
        for(int j = 0; j < EXAMS; j++) {
            total+= *(ptr+EXAMS*i+j);
        }
        printf("\nAverage of student %d is %d.",i+1,total/EXAMS);
    }
}

void printArray(int *ptr){
    for (int i = 0; i < STUDENTS; ++i) {
        printf("\nstudentGrades[%u] ", i);

        for (int j = 0; j < EXAMS; ++j) {
            printf("%d ", *(ptr+EXAMS*i+j));
        }
    }
}
