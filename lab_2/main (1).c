#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct StringType { 
    char *string; 
    int length; 
} StringType; 

typedef struct Employee { 
    StringType *ename; 
    double salary; 
} Employee; 

Employee* createEmployees(char names[][50], double *salaries, int empCount) {
    Employee *ptr = malloc(empCount * sizeof(Employee));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < empCount; i++) {
        ptr[i].ename = malloc(sizeof(StringType));
        if (ptr[i].ename == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        int length = strlen(names[i])+1;
        ptr[i].ename->string = malloc(length * sizeof(char));
        strcpy(ptr[i].ename->string, names[i]);
        
        ptr[i].ename->length = length-1;
        
        ptr[i].salary = salaries[i];
    }

    return ptr;
    
}

int main() { 
    const int EMPLOYEE_COUNT = 4;
    //array of employees’ names 
    char nameList[][50] = {"Bill", "Mary", "Kevin", "Denise"}; 
    //array of salaries, where 15.80 is the salary of Bill, 13.50 is 
    // the salary of Mary, etc. 
    double salaries[] = {15.80, 13.5, 20.9, 12.99}; 
    Employee *pEmployees = createEmployees(nameList, salaries, EMPLOYEE_COUNT); 
    // Print Employees
    int e = 0;
    Employee *pEmployee = pEmployees;
    printf("\tEMPLOYEE NAME\t\tSALARY\n");
    for (e=0;e<EMPLOYEE_COUNT;++e) {
        printf("\t%s\t\t\t%.2lf\n",pEmployee->ename->string,pEmployee->salary);
        pEmployee++;
    }
    
    // Deallocate memory
    pEmployee = pEmployees;
    for (e=0;e<EMPLOYEE_COUNT;++e) {
        free(pEmployee->ename->string);
        pEmployee->ename->string = NULL;
        free(pEmployee->ename);
        pEmployee->ename = NULL;
        pEmployee++;
    }
    free(pEmployees);
    pEmployees = NULL;
    
    return 0; 
} 

//write a function createEmployees
//takes list of employee's names, list their salaries, length of list (empCount) as parameters
//returns pointer to a dynamically allocated array of Employee storing relevant info for empCount Employees



