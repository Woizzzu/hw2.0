#include <stdio.h>
#include <string.h>

#define journal_number 5

double calculate_average(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr [i];
    }
    return sum / size;
}
int find_min(int arr [], int size){
    int min = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int find_max(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
int count_retakes(int arr[], int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == 2) count++;
    }
    return count;
}
int main (){
    const int N = 5 + (journal_number %5);
    char student_name[100];
    int grades[N];

    printf("Grade Journal (Number of grades N = %d)\n", N);
    
    printf("Enter student name: ");
    if (fgets(student_name, sizeof(student_name), stdin) != NULL) {
        student_name[strcspn(student_name, "\n")] = '\0';
    }

    printf("Enter %d grades (from 2 to 5):\n", N);
    for (int i = 0; i < N; i++) {
        while (1) {
            printf("Grade %d: ", i + 1);
            if (scanf("%d", &grades[i]) == 1 && grades[i] >= 2 && grades[i] <= 5) {
                break; 
            }
            printf("Error! Grade must be between 2 and 5. Try again.\n");
            while (getchar() != '\n'); 
        }
    }

    // Вывод результатов
    printf("\n=== Results for student: %s ===\n", student_name);
    printf("Average grade: %.2f\n", calculate_average(grades, N));
    printf("Minimum grade: %d\n", find_min(grades, N));
    printf("Maximum grade: %d\n", find_max(grades, N));
    printf("Number of retakes (grades equal to 2): %d\n", count_retakes(grades, N));
    return 0;
}