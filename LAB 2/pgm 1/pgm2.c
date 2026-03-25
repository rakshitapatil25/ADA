#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int *a;
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    // generate random numbers
    srand(time(0));

    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 100000;
    }

    printf("\nRandom numbers generated.\n");

    start = clock();

    quicksort(a, 0, n - 1);

    end = clock();

    printf("\nSorted array (first 20 elements):\n");

    for(i = 0; i < 20 && i < n; i++)
    {
        printf("%d ", a[i]);
    }

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken = %f seconds\n", time_taken);

    free(a);

    return 0;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}
 