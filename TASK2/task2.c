#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char data[100];
    int characters = 0, words = 0, lines = 0;
    int FLAG = 0;

    
    file = fopen("task2test.txt", "r");
    if (file == NULL) {
        printf("Error! Could not open file.\n");
        return 1;
    }

    
    while (fgets(data, 100, file) != NULL) {
        lines = lines+1;  

        for (int i = 0; data[i] != '\0'; i++) {
            characters = characters+1;  

            
            if (isspace(data[i])) {
                if (FLAG) {
                    words = words+1;  
                    FLAG = 0;
                }
            } else {
                FLAG = 1;  
            }
        }

        
        if (FLAG) {
            words = words+1;
            FLAG = 0;
        }
    }

    fclose(file);

    
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}


