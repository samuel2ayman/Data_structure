#include <stdio.h>
#include <stdlib.h>
char c[100],a[100],b[100];
int k,h=0,j=0,x=0,y=0,i,n;
float z=0;

int main()
{
    fgets(c,100,stdin);
    for(i=0;i<100;i++)
    {
        if ((c[i]=='+')||(c[i]=='/'))
        {
          j=i;
          n=c[j];
        }
    }
      for( k=0;k<j;k++)
        {
            a[k]=c[k];
        }

        while(h<100)
        {
        b[h]=c[h+j+1];
        h++;
        if(c[j+h+1]!='\n'){continue;}

        }
        x=atoi(a);
        y=atoi(b);
        if(x<=-1048576||x>1048576||y<=-1048576||y>1048576)
    {
        printf("Error");
        exit(0);
    }

    switch(n)
    {
       case'+':
        printf("%d",x+y) ;
        break;
       case'/':
           if(y==0)
    {
        printf("Error");
        exit(0);
    }
        z=(float)x/y;
        printf("%0.1f",z) ;
        break;
    }

    return 0;
}
