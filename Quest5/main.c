#include <stdio.h>

int sc_func(void);
int print_counter(int num);
_Bool s_num(int n);

int main(int argc, char **argv)
{
    int num = sc_func();
    print_counter(num);
    
    return 0;
}

int sc_func(void)
{
    int num;

    printf("Would you kindly enter your number: \n");
    scanf("%u", &num);

    return num;
}

int print_counter(int num)
{
    int i=2;

    while (i<num){
        if (s_num(i)) 
            printf ("%d ",i);
        
    i++;
    }
       printf ("\n"); 

    return i;   
}

_Bool s_num(int n)
{
    for (int i = 2; i <= n / 2; i++) 
    if ((n%i) == 0) 
        return 0;

    return 1;
}