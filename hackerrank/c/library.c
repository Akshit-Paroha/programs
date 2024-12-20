#include <stdio.h>
#include <stdlib.h>

int* total_number_of_books;
int** total_number_of_pages;

int main() {
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    total_number_of_books = (int*)malloc(total_number_of_shelves * sizeof(int));
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));

    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_books[i] = 0; // Initialize book count for each shelf
        total_number_of_pages[i] = (int*)malloc(100 * sizeof(int)); // Assume a max of 100 books per shelf
    }

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_pages[x][total_number_of_books[x]] = y; // Add pages to the shelf
            total_number_of_books[x]++; // Increment the book count for that shelf
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", total_number_of_pages[x][y]); // Print pages of the book
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", total_number_of_books[x]); // Print number of books on the shelf
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (total_number_of_pages[i]) {
            free(total_number_of_pages[i]);
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
