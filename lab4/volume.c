// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void copyheader(FILE *input, FILE *output);
void setvolume(FILE *input, FILE *output, float factor);

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    copyheader(input, output);
    // Read samples from input file and write updated data to output file
    setvolume(input, output, factor);
    // Close files
    fclose(input);
    fclose(output);
}

void copyheader(FILE *input, FILE *output)
{
    uint8_t header[HEADER_SIZE];

    fread(header, HEADER_SIZE, sizeof(uint8_t), input);
    fwrite(header, HEADER_SIZE, sizeof(uint8_t), output);
}

void setvolume(FILE *input, FILE *output, float factor)
{
    int16_t buffer;

    while (fread(&buffer, 1, sizeof(int16_t), input))
    {
        buffer *= factor;
        fwrite(&buffer, 1, sizeof(int16_t), output);
    }
}
