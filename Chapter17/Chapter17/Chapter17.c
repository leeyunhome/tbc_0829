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
unsigned int count_items(const p_movie head);
void read_file(p_movie *p_head);
void print_all_items(p_movie head);
void print_an_item(p_movie head);
void edit_an_item(p_movie *p_head);

void write_file(p_movie head);

int main()
{
    p_movie movie_list = NULL;
    
    read_file(&movie_list);

    while (1)
    {
        int s = input_menu();

        switch (s)
        {
        case 1:
            print_all_items(movie_list);
            break;
        case 2:
            print_an_item(movie_list);
            break;
        case 3:
            edit_an_item(&movie_list);
            break;
        case 8:
            write_file(movie_list);
            break;
        case 10:
            printf("Good-bye\n");
            exit(EXIT_SUCCESS);
        default:
            printf("%d is not implemented. Please try again.\n", s);
            break;
        }
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
            printf("Please insert an integer and press enter. Try again.\n");
            while (getchar() != '\n')
                continue;
        }
    }
}
int input_menu()
{
    while (1)
    {
        printf("Please select a menu and press Enter.\n");
        printf("1. Print all items    2. Print an item\n");
        printf("3. Edit an item       4. Add an item\n");
        printf("5. Insert an item     6. Delete an item\n");
        printf("7. Delete all items   8. Save to file\n");
        printf("9. Searcy by name     10. Quit\n");

        int input = input_int();

        if (input >= 1 && input <= 10)
            return input;
        else
        {
            printf("%d is invalid. Please try again.\n", input);
        }
    }
}

void write_file(p_movie head)
{
    char filename[TSIZE] = { 0, };

    printf("Please input filename to write and press Enter.\n");
    printf(">> ");
    if (scanf("%[^\n]%*c", filename) != 1)
    {
        printf("Wrong input. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    FILE* file;

    if ((file = fopen(filename, "w")) == NULL)
    {
        printf("ERROR: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    fprintf(file, "%d\n", (int)count_items(head));

    p_movie pnode = head;   /* set to start of list */

    while (pnode != NULL)
    {
        fprintf(file, "%s\n%.1f\n", pnode->title, pnode->rating);

        pnode = pnode->next;

        count++;
    }

    if (fclose(file) != 0)
    {
        printf("ERROR: Cannot close file.\n");
        exit(EXIT_FAILURE);
    }

    assert(count == (int)count_items(head));

    printf("%d items have been saved to the file.\n", count);
}
unsigned int count_items(const p_movie head)
{
    unsigned int count = 0;
    p_movie pnode = head;
    while (pnode != NULL)
    {
        count += 1;
        pnode = pnode->next;
    }

    return count;
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
    if (fscanf(file, "%d%*c", &n_items) != 1)
    {
        printf("ERROR: Wrong file format.\n");
        exit(EXIT_FAILURE);
    }
    
    p_movie prev = *p_head;
    int count = 0;
    fprintf(stderr, "%d=%s, \n", __LINE__, __FUNCTION__);
    for (int i = 0; i < n_items; ++i)
    {
        p_movie new_movie = (p_movie)malloc(sizeof(struct movie));
        if (new_movie == NULL)
        {
            printf("ERROR: malloc() failed.\n");
            exit(EXIT_FAILURE);
        }
        new_movie->next = NULL;
        if (fscanf(file, "%[^\n]%*c", new_movie->title) != 1 ||
            fscanf(file, "%f%*c", &new_movie->rating) != 1)
        {
            printf("ERROR: Wrong file format.\n");
            exit(EXIT_FAILURE);
        }
        if (prev == NULL)
        {
            *p_head = new_movie;
            prev = new_movie;
        }
        {
            // Insert front
            //p_movie temp = (*head)->next;
            //(*head)->next = new_movie;
            // new_movie->next = temp;

            // add at the end
            prev->next = new_movie;
            prev = new_movie;
        }
        count++;
        //free(new_movie);
        //new_movie = NULL;
    }

    assert(n_items == count);

    printf("%d items have been read from the file.\n", count);
    fclose(file);
}
void print_all_items(p_movie head)
{
    p_movie pnode = head;   /* set to start of list */

    int count = 0;
    while (pnode != NULL)
    {
        printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rating);
        pnode = pnode->next;
        count++;
    }
}
void print_an_item(p_movie head)
{
    printf("Input the index of item to print.\n");
    int index = input_int();

    p_movie pnode = head;   /* set to start of list */
    int count = 0;
    while (pnode != NULL)
    {
        if (index == count) break;
        else
        {
            pnode = pnode->next;
            count++;
        }
    }

    if (pnode != NULL)
        printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rating);
    else
        printf("Invalid item.\n");
}
void edit_an_item(p_movie* p_head)
{

}
