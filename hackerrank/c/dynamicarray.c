#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_shelves, num_requests;
    scanf("%d %d", &num_shelves, &num_requests);

    int *total_number_of_books = (int *)calloc(num_shelves, sizeof(int));
    int **total_number_of_pages = (int **)malloc(num_shelves * sizeof(int *));

    for (int i = 0; i < num_shelves; i++)
    {
        total_number_of_pages[i] = NULL;
    }

    while (num_requests--)
    {
        int query_type;
        scanf("%d", &query_type);

        if (query_type == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            int current_books = total_number_of_books[x];
            total_number_of_books[x]++;
            total_number_of_pages[x] = (int *)realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            total_number_of_pages[x][current_books] = y;
        }
        else if (query_type == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", total_number_of_pages[x][y]);
        }
        else if (query_type == 3)
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", total_number_of_books[x]);
        }
    }

    for (int i = 0; i < num_shelves; i++)
    {
        free(total_number_of_pages[i]);
    }
    free(total_number_of_pages);
    free(total_number_of_books);

    return 0;
}
