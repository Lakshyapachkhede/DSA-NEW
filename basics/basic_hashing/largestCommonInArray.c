#include <stdio.h>

#define MAX 10

int largestCommonElement(int a[], int b[], int na, int nb)
{
    int map[MAX] = {0};

    for(int i = 0; i < na; i++)
        map[a[i]] = 1;

    
    int largest = -1;

    for(int i = 0; i < nb; i++)
    {
        if(map[b[i]] && b[i] > largest)
            largest = b[i];
    }


    return largest;
}

int main(){
    int a[] = {5, 8 , 1, 6, 5, 9};
    int b[] = {3, 3 , 9, 6, 7, 1, 3 , 4, 5};

    int na = sizeof(a) / sizeof(int);
    int nb = sizeof(b) / sizeof(int);

    printf("%d", largestCommonElement(a, b, na, nb));

    return 0;
}
