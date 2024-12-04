#include <stdio.h>
int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int low = 0;
    int high = 5-1;
    int pos = -1;
    int key;
    printf("Enter the element to be searched:");
    scanf("%d", &key);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            pos = mid;
            printf("Element found at %d", pos + 1);
            break;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (pos == -1)
    {
        printf("Element not found");
    }
    return 0;
}