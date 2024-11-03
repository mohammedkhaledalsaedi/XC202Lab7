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
            // Shift bits to the left and add the new bit at the LSB position
            byte = (byte >> 1) | ((bit - '0') << 7);
            bitCount++;

            // When we have 8 bits, write to the output file
            if (bitCount == BYTE_SIZE) {
                fprintf(outputFile, "%02X\n", byte);
                byte = 0; // Reset byte for the next set of bits
                bitCount = 0; // Reset bit count
            }
        }
    }

    // Handle any remaining bits (if total bits is not a multiple of 8)
    if (bitCount > 0) {
        byte >>= (BYTE_SIZE - bitCount); // Shift to fill remaining bits
        fprintf(outputFile, "%02X\n", byte);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete! Hex output written to bitstream1.hex\n");

    return 0;
}

