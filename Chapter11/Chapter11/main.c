
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
int main()
{
    //char msg[] = "Just,"" do it!";
    //puts(msg);
    //printf("Length %d\n", strlen(msg));
    //fit_str(msg, 4);
    //puts(msg);
    //printf("Length %d\n", strlen(msg));

    /*
        strcat() and strncat() : string concatenation
    */

    //char str1[100] = "First string";
    //char str2[] = "Second string";

    ////strcat(str1, ", ");
    ////strcat(str1, str2);
    //strncat(str1, str2, 2); // Append 2 characters
    //puts(str1);

    //TODO: implement my_strcat() function!

    /*
        strcmp() and strncmp() : compare strings (not characters)
    */

    printf("%d\n", strcmp("A", "A"));
    printf("%d\n", strcmp("A", "B"));
    //TODO: implement strcmp!

    /*
        strcpy() and strncpy()
    */

    char dest[100] = "";
    char source[] = "Start programming!";
    //dest = source; // Error
    //dest = "Start something";   // Error
    strcpy(dest, source);
    strncpy(dest, source, 5);   // '\0' is NOT added
    puts(dest);

    return 0;
}
void fit_str(char* str, unsigned int size)
{
    if (strlen(str) > size)
    {
        str[size] = '\0';
    }
}