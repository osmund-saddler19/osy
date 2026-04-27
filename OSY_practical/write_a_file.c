#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    // Creating file using fopen()
    fptr = fopen("file1.txt", "w");

    if (fptr == NULL)
    {
        printf("The file is not opened. The program will exit now");
        exit(0);
    }

    printf("The file is created successfully");

    fprintf(fptr, "\nSome text 3");

    fclose(fptr);
    return 0;
}
