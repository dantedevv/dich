#include <stdio.h>

void rev_array(int array[],int n);
void print_array(int array[], int n);

int main(void)
{
    int tmp, ctr;
    int array[5];

    printf("Enter 5 numbers of the array:\n");
    
    for (ctr = 0; ctr < 5; ctr++) scanf("%d", &array[ctr]);  
    
    rev_array(array,5);
    printf("\n");

    return 0;
}

void rev_array(int array[],int n)
{
    int tmp;
    for(int ctr = 0; ctr<n/2;ctr++) {
    tmp = array[ctr];
    array[ctr] = array[n-ctr-1]; 
    array[n-ctr-1] = tmp;
    }

    print_array(array, 5);
}

void print_array(int array[], int n)
{
    for (int ctr = 0; ctr < n; ctr++) {
        printf("%d ", array[ctr]);
    }
}
