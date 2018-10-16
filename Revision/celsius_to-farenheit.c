#include <stdio.h>
int main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step  = 20;
    celsius = lower;
    printf("Celsius  Fahrenheit\n");
    while(celsius <= upper){
        fahr = 9.0/5.0 * celsius + 32.0;
        printf("%6.1f  %6.0f \n",celsius,fahr);
        celsius += step;
    }
    return 0;
}
