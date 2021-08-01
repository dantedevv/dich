#include <stdio.h>

void decalc(int a, int b, int *summ, int *diff, int *mult, int *div);

int main(void)
{
    int summ=0, diff=0, mult=0, div=0;
    int num1, num2;

    printf ("Введите 2 числа:\n");
    scanf("%d %d", &num1 ,&num2);
    decalc(num1, num2, &summ, &diff, &mult, &div);
    printf(" Сумма = %d \n Разность = %d \n Произведение = %d \n Частное = %d \n", summ, diff, mult, div);
   
}

void decalc(int a, int b, int *summ, int *diff, int *mult, int *div)
{
    *summ = a + b;
    *diff = a - b;
    *mult = a * b;
    *div = a / b;
}