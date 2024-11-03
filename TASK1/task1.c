#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    int N;
    
    printf("Enter the number of students: ");
    scanf("%d", &N);
    
    struct student students[N];  
    
    for (int i = 0; i < N; i++) {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        
        printf("Enter GPA for student %d: ", i + 1);
        scanf("%f", &students[i].gpa);
    }
    
    printf("\nStudent Information:\n");
    for (int i = 0; i < N; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    return 0;
}

