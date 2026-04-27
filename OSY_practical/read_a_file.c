// Read a file
// C program to create a file

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // File pointer
    FILE *fptr;

    // Creating file using fopen() access mode "w"
    fptr = fopen("E:\\file1.txt", "w");

    // Checking if the file is created
    if (fptr == NULL)
    {
        printf("The file is not opened. The program will exit now");
        exit(0);
    }
    else
    {
        printf("The file is created successfully.");
    }

    char myString[100];   // array of chars (string)

    // Read the content and store it inside the string
    char c = fgetc(fptr);
    printf("%c", c);

    // fgets(myString, 100, fptr);

    // Print the file content
    // printf("%s", myString);

    fclose(fptr);
    return 0;
}
