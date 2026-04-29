#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char c;

    // Open file in read mode
    fptr = fopen("E:\\file1.txt", "r");

    // Check if file exists
    if (fptr == NULL)
    {
        printf("Error! File cannot be opened.\n");
        exit(0);
    }

    printf("File opened successfully.\n\n");

    // Read file character by character
    while ((c = fgetc(fptr)) != EOF)
    {
        printf("%c", c);
    }

    // Close file
    fclose(fptr);

    return 0;
}
