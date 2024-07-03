
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[100], b[100], c[100];
int n;

int smallest(int i, int n, int pos)
{
    int small;
    small = b[i];
    pos = i;
    for (int j = i + 1; j < n; j++)
    {
        if (small > b[j])
        {
            small = b[j];
            pos = j;
        }
    }
    return pos;
}

void selection()
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    int pos = 0, temp;
    for (int i = 0; i <= n - 1; i++)
    {
        pos = smallest(i, n, pos);
        temp = b[i];
        b[i] = b[pos];
        b[pos] = temp;
    }
}

int partition(int p, int r)
{
    int pivot = c[p];
    int left = p + 1;
    int right = r;

    while (left <= right)
    {
        while (left <= r && c[left] <= pivot)
        {
            left++;
        }
        while (right >= p && c[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            int temp = c[left];
            c[left] = c[right];
            c[right] = temp;
        }
    }
    int temp = c[p];
    c[p] = c[right];
    c[right] = temp;

    return right;
}

void quick(int pivot, int right)
{
    
    if (pivot < right)
    {
        int q = partition(pivot, right);
        quick(pivot, q - 1);
        quick(q + 1, right);
    }
}

void main()
{
    int ch;
    printf("Enter no: of elements: ");
    scanf("%d", &n);
    printf("Enter each element one by one");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }


    printf("The List is:");
            for (int i = 0; i < n; i++)
            {
                printf("%d  ",a[i]);
            }
            printf("\n");


    while (1)
    {
        printf("Enter your choice:\n1.Selection Sort\n2.Quick Sort\n3.Exit: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            selection();
            printf("The List is:");
            for (int i = 0; i < n; i++)
            {
                printf("%d  ", b[i]);
            }
            printf("\n");
        }
        else if (ch == 2)
        {
            for (int i = 0; i < n; i++)
            c[i] = a[i];
            quick(0, n - 1);

            printf("The List is:");
            for (int i = 0; i < n; i++)
            {
                printf("%d  ", c[i]);
            }
            printf("\n");
        }
        else
            break;
    }
}