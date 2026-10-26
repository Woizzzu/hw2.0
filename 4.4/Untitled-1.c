#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define journal_number 5

typedef struct {
    char name [50];
    int age;
    double grade;
} Student;

int main () {
    setlocale(LC_ALL, "Rus");
    const int N = 3 + (journal_number % 3 );
    printf("Student Directory (N = %d)\n\n", N);
    Student *students = (Student *) malloc(N * sizeof(Student));

    if (students == NULL) {
        printf("Error: memory allocation failed\n");
        return 1;
    }
    strcpy((students + 0) ->name, "Thomas");
    (students +0)-> age = 20;
    (students +0)->grade = 4.8;

    if (N > 1) {
    strcpy((students + 1)->name, "Anna");
    (students + 1)->age = 19;
    (students + 1)->grade = 4.2;
    }
    if (N > 2) {
    strcpy((students + 2)->name, "Dmitry");
    (students + 2)->age = 18;
    (students + 2)->grade = 3.7;
    }
    if (N > 3){
    strcpy((students + 3)->name, "Elena");
    (students + 3)->age = 22;
    (students + 3)->grade = 4.9;
    }
    if (N > 4){
    strcpy((students + 4)->name, "Pavel");
    (students + 4)->age = 19;
    (students + 4)->grade = 4.5;
    }
    (students + 1)->grade = 5.0;
    double sum = 0;
    Student *best_student = students;

    printf("Student List:\n");
    for (int i = 0; i < N; i++){
        Student *ptr = students + i;
        printf("- %s (Age: %d, Grade: %.1f)\n", ptr->name, ptr->age, ptr->grade);

        sum += ptr->grade;

        if (ptr->grade > best_student -> grade) {
            best_student = ptr;
        }
    }

    double average = sum / N;

    printf("\n=== Analysis Results ===\n");
    printf("Average grade of the group: %.2f\n", average);
    printf("Student with the highest grade: %s (Grade: %.1f)\n", best_student->name, best_student->grade);

    free (students);
    students = NULL;

    return 0;
}
