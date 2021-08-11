#include <stdio.h>
#include <string.h>

// Реализовать функцию, которая возвращает сумму цифр в переданной ей строке. str_sum_digits(const char *cs)

int str_sum_digits(const char *cs);


int main(void)
{
    char str[100] = { 0 };

    scanf("%s", str);
    printf("Summ of digits in string is %d\n", str_sum_digits(str));

    return 0;
}

int str_sum_digits(const char *cs)
{
    char num;
    int summ;
    int n = strlen(cs);
    
    for (int i = 0; i < n; i++) {
       if ((cs[i] >= '0') && (cs[i] <= '9')) { 
            num = cs[i];
            summ += num - '0';
        }
        else num = 0;
    }

    return summ;
}