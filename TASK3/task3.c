#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 8

int main() {
    FILE *inputFile, *outputFile;
    char bit;
    unsigned char byte = 0;
    int bitCount = 0;

    inputFile = fopen("bitstream1.bit", "r");
    if (inputFile == NULL) {
        printf("Error! Could not open input file.\n");
        return 1;
    }

    outputFile = fopen("bitstream1.hex", "w");
    if (outputFile == NULL) {
        printf("Error! Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while ((bit = fgetc(inputFile)) != EOF) {
        if (bit == '0' || bit == '1') {
            
            byte = (byte >> 1) | ((bit - '0') << 7);
            bitCount++;

            
            if (bitCount == BYTE_SIZE) {
                fprintf(outputFile, "%02X\n", byte);
                byte = 0; 
                bitCount = 0; 
            }
        }
    }

    
    if (bitCount > 0) {
        byte >>= (BYTE_SIZE - bitCount); 
        fprintf(outputFile, "%02X\n", byte);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete! Hex output written to bitstream1.hex\n");

    return 0;
}

