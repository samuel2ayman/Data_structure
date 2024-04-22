#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
adv of this way comparing to array implementation
1-time complexity is better in stack implementation using linked list
2-the stack won't be full we can add elements until memory full
dis adv
1-clear stack is more complex as we should traverse stack to free every node O(N)
2-take 50% additional memory than array implementation as every element have pointer(next)

*/
struct node
{
    int data;
    struct node *next;
};


struct stack
{
    struct node *top;
    int size;
};


void init(struct stack* stack_a)
{
    stack_a->top=NULL;
    stack_a->size=0;
}


void push(struct stack* stack_a,int Data)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=Data;
    newnode->next=stack_a->top;
    stack_a->top=newnode;
    stack_a->size++;

}


void pop(struct stack* stack_a,int* x)
{
    struct node *temp;
    *x=stack_a->top->data;
    temp=stack_a->top;
    stack_a->top=stack_a->top->next;
    free(temp);
    stack_a->size--;
}


int is_empty(struct stack *stack_a)
{
    return stack_a->top==NULL;
}


int size_s(struct stack* stack_a)
{
    return stack_a->size;
}


void peek(struct stack* stack_a)
{
    printf("%d",stack_a->top->data);
}



void print(struct stack* stack_a)
{
    if(is_empty(stack_a))
    {
        printf("[]");
    }
    else
    {
     struct node *current;
     current=stack_a->top;
        printf("[");
     while(current!=NULL)
     {
         if(current->next == NULL)
                printf("%d",current->data);
            else
                printf("%d, ",current->data);
            current = current->next;
    }
                printf("]");

}
}

void clear(struct stack *stack_a)
{
struct node *current;
current=stack_a->top;
while(current)
   {
      current=stack_a->top->next;
      free(stack_a->top);
       stack_a->top=current;
   }
   stack_a->size=0;
}
void StgTo_stack(char stg[100], struct stack* stack_a)
{
    int x, i = 0;
    int num = 0, sign = 1;
    if(!(strcmp(stg,"[]\n")))
        return;
    else {
        struct stack temp;
        init(&temp);
        while (stg[i] != '\n')
        {
            if ((stg[i] == ' ')||(stg[i] == '[')){
                i++;
                continue;
            }
            else if (stg[i] == '-')
                sign = -1;
            else if ((stg[i] == ',')||(stg[i] == ']'))
            {
                x = sign * num;
                push(&temp,x);
                sign = 1;
                num = 0;
            }
            else
                num = num * 10 + (stg[i] - '0');
            i++;
        }
        while(!(is_empty(&temp)))
        {
            pop(&temp, &x);
            push(stack_a, x);
        }
    }
}



int main() {
    char stg[100],Do[10];
    int x;
    struct stack s;
    fgets(stg,100,stdin);
    scanf("%s",Do);
    init(&s);
     StgTo_stack(stg,&s);

    if(!(strcmp(Do,"push")))
    {
       scanf("%d",&x);
       push(&s,x);
        print(&s);
    }
    else if(!(strcmp(Do,"peek")))
    {

        if(is_empty(&s))
           {
               printf("Error");
           }
           else
           {
               peek(&s);
           }


    }
    else if(!(strcmp(Do,"pop")))
    {
        if(is_empty(&s))
           {
               printf("Error");
           }
           else
           {
              pop(&s,&x);
              print(&s);
           }

        }

    else if(!(strcmp(Do,"isEmpty")))
    {
        if(is_empty(&s))
           {
               printf("True");
           }
        else
           {
               printf("False");
           }
    }
    else if(!(strcmp(Do,"size")))
    {
      printf("%d",size_s(&s)) ;
    }
    else
        printf("Error");

    return 0;
}
