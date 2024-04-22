#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
adv of this way comparing to linked list implementation
1-the complexity of clearing stack is better than linked list implementation O(1)
2-take less memory by 50% as we don't use pointer (next)
dis adv
1-time complexity is better in stack implementation using linked list
2-stack will be full if reached max length of array

*/
int arr[100],arr2[100];
int j=0,siz=0;
int top =-1,s=1;
//------------------------------------------------
void push (int data)
{
    top++;
    siz++;
    arr2[top]=data;
}
void StgTo_array(char stg[100]){
    int i = 1;
    int num = 0, sign = 0;
    while (stg[i] != ']'){

        if (stg[i] == ' '){
            i++;
            continue;}
        else if (stg[i] == '-')
        {
          sign = 1;
        }
        else if (stg[i] == ',')
        {
            if(sign==1)
            {
                 arr[j]=-1*num;
            }
            else
            {
                  arr[j]=num  ;
            }
            num=0;
            j++;
            s++;
            sign=0;
        }

        else
        {
            num = num * 10 + (stg[i] - '0');


        }
        i++;

    if(sign==1)
    {
        arr[j]=-num;
    }
    else
    {
        arr[j]=num;
    }
    }

    for(int k=s-1;k>=0;k--)
    {
    int c=0;
    c=arr[k];
    push(c);
    }

}
void print()
{
    int i;
    printf("[");
    for(i=top;i>0;i--)
    {
    printf("%d, ",arr2[i]);
    }
    printf("%d",arr2[0]);
     printf("]");
}
//-------------------------------------------------------------------------


void pop()
{
    if(top==-1)
    {
        printf("Error");
    }
    else if(top==0)
    {printf("[]");}
    else
    {
    top--;
     print();
    }

}
//----------------------------------
void peek()
{
    if(top==-1)
    {
        printf("Error");
    }
    else
    {
    printf("%d",arr2[top]);
    }

}
//---------------------------------------------
void is_empty()
{
    if(top==-1)
    {
    printf("True");
    }
    else
    printf("False");
}
//----------------------------

void size()
{
int l;
l=siz;
printf("%d",l);
}

int main() {
    int  In;
    char str[100];
    char Do[20];
    scanf("%[^\n]",str);
    scanf("%s",Do);
    if(str[1]==']'){s=-1;}
    StgTo_array(str);
  if(!(strcmp(Do,"push"))){
       scanf("%d",&In);
              push(In);
      if(top==siz)
    {
        printf("Error");
    }
             print();
    }
    else if(!(strcmp(Do,"peek"))){
        peek();
    }
    else if(!(strcmp(Do,"pop"))){
        pop();
        }

    else if(!(strcmp(Do,"isEmpty"))){
        is_empty();
    }
    else if(!(strcmp(Do,"size"))){
       size();
    }
    else
        printf("Error");

    return 0;
}
