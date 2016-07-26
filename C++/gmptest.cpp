#include <cstdio>
#include <gmp.h>
#include <gmpxx.h>
#include <cstdarg>

int main(){
    mpz_t num;
    mpz_t sum;
    mpz_t tmp;
    mpz_init(sum);
    mpz_init(sum);
    unsigned long int base = 2;
    unsigned long int index = 1000;
    mpz_ui_pow_ui(num,base,index);
    mpz_init(sum);
    while(mpz_sgn(num)){
        mpz_init(tmp);
        mpz_mod_ui(tmp, num, 10);
        mpz_add(sum,sum,tmp);
        mpz_div_ui(num,num,10);
    }
    gmp_printf("Sum : %Zd",sum);
    return 0;

}
