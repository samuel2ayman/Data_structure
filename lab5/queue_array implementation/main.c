#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
 typedef struct queue
 {
     struct node *front;
     struct node *rear;
     int size;
 } Queue;


 void init (Queue * pqueue)
 {
     pqueue->front=NULL;
     pqueue->rear=NULL;
     pqueue->size=0;
 }

 void enqueue(Queue * pqueue,int x)
 {
     struct node* newnode=malloc(sizeof(struct node));
     newnode->next=NULL;
     newnode->data=x;
     if(!pqueue->rear)
     {
         pqueue->front=newnode;
     }
     else
    {
        pqueue->rear->next=newnode;
        pqueue->rear=newnode;
        pqueue->size++;
    }
 }
int size(Queue * pqueue)
{
    return pqueue->size;
}
int isEmpty(Queue * pqueue)
{
    return !pqueue->size;
}


void print (Queue * pqueue)
{
    if(isEmpty( pqueue))
    {
        printf("[]");
    }
    else
    {
     struct node *current;
     current=pqueue->front;
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



 void dequeue(Queue * pqueue,int*x)
 {
     struct node* temp;
     temp=pqueue->front;
     *x=pqueue->front->data;
     pqueue->front=pqueue->front->next;
     free(temp);
     if(pqueue->front==NULL)
     {
       pqueue->rear=NULL;
     }
     pqueue->size--;
 }
void StgToQueue(char stg[100], struct queue *pqueue){
    int x, i = 0;
    int num = 0, sign = 1, flag = 0;
    while (stg[i] != '\0'){
        if ((stg[i] == ' ')||(stg[i] == '[')){
            i++;
            continue;
        }
        if (stg[i] == '-')
            sign = -1;
        else if ((stg[i] == ',')||(stg[i] == ']')){
            if(flag){
                x = sign * num;
                enqueue(pqueue, x);
                sign = 1;
                num = 0;
                flag = 0;
            }
        }
        else{
            num = num * 10 + (stg[i] - '0');
            flag = 1;
        }
        i++;
    }
}
 int main()
{
    int In,x;
    Queue q;
    char stg[100];
    char Do[20];
    init(&q);
    fgets(stg,100,stdin);
    scanf("%s",Do);
    StgToQueue(stg,&q);
  if(!(strcmp(Do,"enqueue"))){
       scanf("%d",&In);
        enqueue(&q,In);
        print(&q);

    }
    else if(!(strcmp(Do,"dequeue"))){
        if(isEmpty(&q))
        {
            printf("Error");
        }
        else
        {
           dequeue(&q,&x);
        print(&q);
        }

        }

    else if(!(strcmp(Do,"isEmpty"))){
        if(isEmpty(&q))
        {
            printf("True");
        }
        else
        {
            printf("False");
        }
    }
    else if(!(strcmp(Do,"size"))){
      printf("%d",size(&q));
    }
    else
    { printf("Error");}


    return 0;
}
