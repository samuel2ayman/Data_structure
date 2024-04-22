#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxQueue 100

struct node{
    int data;
    struct node *next;
};

struct stack{
    struct node *top;
    int size;
};

void InitializeStack(struct stack* pStack){
    pStack->top = NULL;
    pStack->size = 0;
}

void push(struct stack* pStack ,int x){
    struct node* pNewNode = malloc(sizeof(struct node));
    pNewNode ->data = x;
    pNewNode ->next = pStack->top;
    pStack->top = pNewNode ;
    pStack->size++;
}

void pop(struct stack* pStack ,int* x){
    struct node* current;
    *x = pStack->top->data;
    current = pStack->top;
    pStack->top = pStack->top->next;
    free(current);
    pStack->size--;
}

int isEmptyStack(struct stack* pStack){
    return pStack->top==NULL;
}

struct queue{
    int front;
    int rare;
    int size;
    int data[MaxQueue];
};

void InitializeQueue(struct queue *pQueue){
    pQueue->front = 0;
    pQueue->rare = -1;
    pQueue->size = 0;
}

int size(struct queue *pQueue){
    return pQueue->size;
}

int isEmpty(struct queue *pQueue){
    return !pQueue->size;
}

int isFull(struct queue *pQueue){
    return (pQueue->size == MaxQueue);
}

void append(struct queue *pQueue , int x){
    pQueue->rare = (pQueue->rare + 1) % MaxQueue;
    pQueue->data[pQueue->rare] = x;
    pQueue->size++;
}

void serve(struct queue *pQueue , int *x){
    *x = pQueue->data[pQueue->front];
    pQueue->front = (pQueue->front + 1) % MaxQueue;
    pQueue->size--;
}

void front (struct queue *pQueue , int *x){
    *x = pQueue->data[pQueue->front];
}

void printQueue(struct queue *pQueue){
    int pos = pQueue->rare;
    int i;
    printf("[");
    for(i=0;i<pQueue->size;i++){
        if(pos == pQueue->front)
            printf("%d",pQueue->data[pos]);
        else
            printf("%d, ",pQueue->data[pos]);
        pos = (pos - 1) % MaxQueue;
    }
    printf("]");
}

void StgToQueue(char stg[100], struct queue *pQueueA){
    int x, i = 0;
    int num = 0, sign = 1, flag = 0;
    struct stack temp;
    InitializeStack(&temp);
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
                push(&temp, x);
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
    while(!isEmptyStack(&temp)){
        pop(&temp, &x);
        append(pQueueA, x);
    }
}

int main(){
    char stg[100];
    char operation[20];
    int x;
    fgets(stg,100,stdin);
    struct queue queueA;
    InitializeQueue(&queueA);
    StgToQueue(stg,&queueA);
    scanf ("%s", operation);
    if(!(strcmp(operation,"print"))){
        printQueue(&queueA);
    }
    else if(!(strcmp(operation,"enqueue"))){
        scanf("%d",&x);
        if (isFull(&queueA))
            printf("Error");
        else{
            append(&queueA,x);
            printQueue(&queueA);
        }
    }
    else if(!(strcmp(operation,"dequeue"))){
        if (isEmpty(&queueA))
            printf("Error");
        else{
            serve(&queueA,&x);
            printQueue(&queueA);
        }
    }
    else if(!(strcmp(operation,"front"))){
        if (isEmpty(&queueA))
            printf("Error");
        else{
            front(&queueA,&x);
            printf("%d",x);
        }
    }
    else if(!(strcmp(operation,"isEmpty"))){
        if(isEmpty(&queueA))
            printf("True");
        else
            printf("False");
    }
    else if(!(strcmp(operation,"size"))){
        printf("%d",size(&queueA));
    }
    else
        printf("Error");
    return 0;
}
