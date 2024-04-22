#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
     int i,a=0,b=1,r=0,n;
    scanf("%d",&n);
    if(n>40||n<1){exit(0);}
    for(i=1;i<=n;i++)
    {
        a=b;
        b=r;
        r=a+b;
    }
    printf("%d",b);
    return 0;
}
