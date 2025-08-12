#include <stdio.h>

// Structure for date
struct Date {
    int day;
    int month;
    int year;
};

// Structure for employee
struct Employee {
    int code;
    float salary;
    int dept;
    struct Date joining_date;
};

// Function signatures
void displayMinMaxEmployees(struct Employee emp[], int n);
void searchByEmployeeCode(struct Employee emp[], int n, int code);

int main() {
    int n, choice, code;
    
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    struct Employee emp[n];
    
    // Input employee details
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i+1);
        printf("Employee code: ");
        scanf("%d", &emp[i].code);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        printf("Department number: ");
        scanf("%d", &emp[i].dept);
        printf("Date of joining (dd mm yyyy): ");
        scanf("%d %d %d", &emp[i].joining_date.day, 
                          &emp[i].joining_date.month, 
                          &emp[i].joining_date.year);
    }
    
    // Menu
    do {
        printf("\nMenu:\n");
        printf("1. Display employees with max and min salary\n");
        printf("2. Search employee by code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayMinMaxEmployees(emp, n);
                break;
            case 2:
                printf("Enter employee code to search: ");
                scanf("%d", &code);
                searchByEmployeeCode(emp, n, code);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}

// Function to display employees with max and min salary
void displayMinMaxEmployees(struct Employee emp[], int n) {
    if(n == 0) {
        printf("No employees to display!\n");
        return;
    }
    
    float max_salary = emp[0].salary;
    float min_salary = emp[0].salary;
    int max_index = 0, min_index = 0;
    
    for(int i = 1; i < n; i++) {
        if(emp[i].salary > max_salary) {
            max_salary = emp[i].salary;
            max_index = i;
        }
        if(emp[i].salary < min_salary) {
            min_salary = emp[i].salary;
            min_index = i;
        }
    }
    
    printf("\nEmployee with maximum salary:\n");
    printf("Code: %d, Salary: %.2f, Dept: %d, Joining Date: %d/%d/%d\n", 
           emp[max_index].code, emp[max_index].salary, emp[max_index].dept,
           emp[max_index].joining_date.day, emp[max_index].joining_date.month, 
           emp[max_index].joining_date.year);
    
    printf("\nEmployee with minimum salary:\n");
    printf("Code: %d, Salary: %.2f, Dept: %d, Joining Date: %d/%d/%d\n", 
           emp[min_index].code, emp[min_index].salary, emp[min_index].dept,
           emp[min_index].joining_date.day, emp[min_index].joining_date.month, 
           emp[min_index].joining_date.year);
}

// Function to search employee by code
void searchByEmployeeCode(struct Employee emp[], int n, int code) {
    int found = 0;
    
    for(int i = 0; i < n; i++) {
        if(emp[i].code == code) {
            printf("\nEmployee found:\n");
            printf("Code: %d, Salary: %.2f, Dept: %d, Joining Date: %d/%d/%d\n", 
                   emp[i].code, emp[i].salary, emp[i].dept,
                   emp[i].joining_date.day, emp[i].joining_date.month, 
                   emp[i].joining_date.year);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Employee with code %d not found!\n", code);
    }
}