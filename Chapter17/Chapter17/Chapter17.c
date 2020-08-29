// Chapter17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TSIZE 45

struct movie {
	char title[TSIZE];
	float rating;
	struct movie* next;
};

typedef struct movie* p_movie;

int input_int();
int input_menu();
void read_file(p_movie *p_head);

int main()
{
    p_movie movie_list = NULL;
    
    read_file(&movie_list);

    int s = input_menu();

    switch (s)
    {
    case 1:
        //print_all_items(movie_list);
        break;
    default:
        printf("%d is not implemented. Please try again.\n", s);
        break;
    }
	return 0;
}

int input_int()
{
    int input;
    while (1)
    {
        printf(">> ");
        if ((scanf("%d%*c", &input)) == 1)
            return input;
        else
        {
            printf("Please insert an integer number. Try again.\n");
            while (getchar() != '\n')
                continue;
        }
    }
}
int input_menu()
{
    while (1)
    {
        printf("\n");
        printf("Please select a menu and press Enter.\n\n");
        printf("1. print all items    2. print an item\n");
        printf("3. edit an item       4. add an item\n");
        printf("5. insert an item     6. delete an item\n");
        printf("7. delete all items   8. save to file\n");
        printf("9. searcy by name     10. quit\n");
        int index = input_int();
        if (index >= 1 && index <= 5)
            return index;
        else
        {
            printf("Please input a valid number. try again.\n");
        }
    }
}
void read_file(p_movie* p_head)
{
    char filename[TSIZE] = { 0, };
    printf("Please input filename to read and press Enter.\n");
    if ((scanf("%[^\n]%*c", filename)) != 1)
    {
        printf("Wrong input. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    FILE* file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    int n_items;
    fscanf(file, "%d%*c", &n_items);
    
    p_movie pmovie = malloc(sizeof(struct movie) * n_items);
    p_movie pnode = *p_head;
    int count = 0;
    while (pnode != NULL)
    {
        fscanf(file, "%[^\n]%*c", pnode->title);
        fscanf(file, "%f%*c", pnode->rating);
        pnode = pnode->next;
        count++;
    }
    assert(n_items == count);

    printf("%d items have been read from file.\n", count);
    fclose(file);
    free(pmovie);
}