/*
    ---------------------------------------------------
    Implementation of double selection sort (iterative)
    ---------------------------------------------------

    Made by: landiluigi746
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 1024 //Constant for array size

//Functions prototypes
void fill(int *arr);
void sort(int *arr);
void swap(int *n1, int *n2);
void printIntArr(int *arr);
int smallestPos(int *arr, int arrStart, int arrEnd);
int largestPos(int *arr, int arrStart, int arrEnd);
bool isSorted(int *arr);

int main()
{
    int *array = (int*) malloc(SIZE * sizeof(int));
    clock_t start, end;
    double sortTime;
    
    printf("Filling array...\n");
    fill(array);

    printf("Array before sorting:\n");
    printIntArr(array);

    if( (!isSorted(array)) ) //Sorting only if the array isn't already sorted
    {
        start = clock(); //Sorting start time
        printf("Sorting array...\n");
        sort(array);
        end = clock(); //Sorting end time

        printf("Array after sorting:\n");
        printIntArr(array);

        sortTime = ((double) (end - start)) / (double) CLOCKS_PER_SEC;
        printf("Sorting time: %lf seconds.\n\n", sortTime);
    }
    else
        printf("The array is already sorted!!\n\n");

    free(array);

    getchar();
    return 0;
}

void fill(int *arr)
{
    int i;
    srand(time(NULL));

    for(i = 0; i < SIZE; i++)
        arr[i] = rand() % SIZE;
    
    return;
}

void sort(int *arr)
{
    int i, minPos, maxPos;

    for(i = 0; i < SIZE / 2; i++)
    {
        minPos = smallestPos(arr, i, SIZE - i);
        maxPos = largestPos(arr, i, SIZE - i);
        if(maxPos == i)
            maxPos = minPos;
        if(i != minPos)
            swap(&arr[i], &arr[minPos]);
        if(SIZE - i - 1 != maxPos)
            swap(&arr[SIZE - i - 1], &arr[maxPos]);
    }

    return;
}

void swap(int *n1, int *n2)
{
    *n1 = *n2 - *n1;
    *n2 = *n2 - *n1;
    *n1 = *n2 + *n1;

    return;
}

void printIntArr(int *arr)
{
    int i;

    for(i = 0; i < SIZE; i++)
        printf("Number no.%d: %d\n", i, arr[i]);

    return;
}

int smallestPos(int *arr, int arrStart, int arrEnd)
{
    int min = arr[arrStart], i, pos = arrStart;

    for(i = arrStart; i < arrEnd; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
            pos = i;
        }
    }

    return pos;
}

int largestPos(int *arr, int arrStart, int arrEnd)
{
    int max = arr[arrStart], i, pos = arrStart;

    for(i = arrStart; i < arrEnd; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            pos = i;
        }
    }

    return pos;
}

bool isSorted(int *arr)
{
    int i;

    for(i = 0; i < SIZE - 1; i++)
        if(arr[i] > arr[i + 1])
            return false;

    return true;
}