#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main()
{
   int j=1,i=0,n=0,c=1,integ[100];
   char arr[100],arr2[100];
    fgets(arr,100,stdin);
    int l=strlen(arr);
    if(l==2){
             printf("[]");
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
    printf("[");
  for(i=c-2;i>0;i--)
  {
      printf("%d, ",integ[i]);

  }
    printf("%d",integ[0]);
     printf("]");
    return 0;
}
