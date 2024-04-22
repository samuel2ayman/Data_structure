#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main()
{
   int j=1,i=0,n=0,c=1,integ[100],s=0,count=0;
   char arr[100],arr2[100];
    fgets(arr,100,stdin);
    if(arr[0]=='['&&arr[1]==']'){
             printf("[]");
             exit(0);
           }
    scanf("%d",&s);
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

  for(i=0;i<c-1;i++)
  { if(integ[i]!=s)
      {
      integ[count]=integ[i];
      count++;
      }
  }
    printf("[");
    for(i=count;i<c-1;i++)
    {integ[i]=s;}
        for(i=0;i<c-2;i++)
        {printf("%d, ",integ[i]);}
    printf("%d",integ[c-2]);
     printf("]");

    return 0;
}
