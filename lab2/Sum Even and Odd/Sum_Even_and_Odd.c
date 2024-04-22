#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int j=1,i=0,n=0,c=1,integ[100];
int o=0,e=0;
char arr[100],arr2[100];
int main()
{

    fgets(arr,100,stdin);
    int l=strlen(arr);
    if(l==2){
             printf("[0, 0]");
             exit(0);
           }
    while(arr[j]!=']')
        {
        i=0;
        while(arr[j]!=']'&&arr[j]!=',')
        {
            arr2[i]=arr[j];
            j++;
            i++;
        }
           arr2[i]='\0';
           integ[n]=atoi(arr2);
           n++;
           j++;
           c++;

        if(arr[j-1]==']'){break;}
        }
    for(i=0;i<100;i++)
    {
        if (integ[i]%2==0)
        {e=integ[i]+e;}
        else
        {o=integ[i]+o;}
    }
      printf("[");
      printf("%d, ",e);
      printf("%d",o);
      printf("]");
    return 0;
}
