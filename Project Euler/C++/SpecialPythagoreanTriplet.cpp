#include <iostream>

int main(){
    int sum = 1000;
    int product = 1;
    for(int c = 415; c < 500; ++c)
        for(int b = 332; b < (c > 400 ? 400 : c); ++b)
         for(int a = 100; a < 253; ++a)
            if((a+b+c) == 1000 && c*c == a*a + b*b) 
                std::cout << "A : " << a << ", B : " << b << ", C : " << c << std::endl << a*b*c << std::endl;
    return 0;
}