#include <stdio.h>
int n, a[100], b[100];

void merge(int low, int m, int high)
{
    int p;
    int j = m + 1;
    int i = low;
    int k = low;

    while (i <= m && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > m)
    {
        for (p = j; p <= high; p++)
            b[k++] = a[p];
    }
    else
    {
        for (p = i; p <= m; p++)
            b[k++] = a[p];
    }

    for (p = low; p <= high; p++)
        a[p] = b[p];
}

void sort(int p, int q)
{
    int m;
    if (p < q)
    {
        m = (p + q) / 2;
        sort(p, m);
        sort(m + 1, q);
        merge(p, m, q);
    }
}

void main()
{
    int low, high;
    printf("enter the number of elements in the list : ");
    scanf("%d", &n);
    printf("enter the elements one by one :");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    low = 0;
    high = n - 1;

    sort(low, high);

    printf(" The list is: \n");
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}