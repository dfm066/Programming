//
//  main.c
//  Operators
//
//  Created by Itachi on 06/09/16.
//  Copyright © 2016 Itachi. All rights reserved.
//

#include <stdio.h>
int getbits(int x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}
//int setbits(int x)
int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    int n,p;
    scanf("%d %d %d",&x,&p,&n);
    printf("%d\n",getbits(x,p,n));
    return 0;
}
