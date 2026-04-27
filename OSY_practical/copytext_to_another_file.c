#include <stdio.h>
#include <stdlib.h>  // For exit()

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading:\n");
    scanf("%s", filename);

    // Open file for reading
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    // Open another file for writing
    fptr2 = fopen("copy.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file for writing\n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("\nContents copied to copy.txt");

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}
