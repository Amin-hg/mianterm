#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 10

typedef struct {
 char Name[50];
 double Dastmozd;
 double SahmBime;
} Employee;

void addEmployee(Employee *emp, int index) {printf("");
 printf("Enter details for employee %d\n", index + 1);
 printf("Name: ");
scanf("%s", emp[index].Name);
printf("Dastmozd: ");
scanf("%lf", &emp[index].Dastmozd);
printf("SahmBim: ");
scanf("%lf", &emp[index].SahmBime);
}

void saveToFile(Employee *emp, int count) {
 FILE *file = fopen("employees.txt", "w");
 if (file == NULL) {
 printf("File baraye naveshtan baz nemeshavad.\n");
 return;
 }
 
 for (int i = 0; i < count; i++) {
 fprintf(file, "Name: %s, Dastmozd: %.2lf, SahmBim: %.2lf\n",
 emp[i].Name, emp[i].Dastmozd, emp[i].SahmBime);
 }

 fclose(file);
 printf("Data saved to employees.txt\n");
}

void SahmBime(Employee *emp, int count) {
 printf("\nVaziyat Bime Karmandan:\n");
 for (int i = 0; i < count; i++) {
 printf("Name: %s, Dastmozd: %.2lf, SahmBime: %.2lf\n",
 emp[i].Name, emp[i].Dastmozd, emp[i].SahmBime);
 }
}

int main() {
 Employee employees[MAX_EMPLOYEES];
  int employeeCount = 0;

 for (employeeCount = 0; employeeCount < MAX_EMPLOYEES; employeeCount++) {
 addEmployee(employees, employeeCount);
 }

 SahmBime(employees, employeeCount);
 saveToFile(employees, employeeCount);

 return 0;
}