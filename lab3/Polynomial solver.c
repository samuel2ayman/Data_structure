#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int coeff;
    int expo;
    struct node *next;
};
struct list{
    struct node *head;
    int size;
};
int size (struct list *list){
    return (list->size);
}
int isEmpty (struct list *list){
    return(list->size==0);
}
void addtolist (struct list *list ,int x){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->coeff = x;
    newnode->expo = 0;
    if(list->head == NULL){
        list->head = newnode;
    }
    else{
        struct node *current;
        current = list->head;
        while(current->next != NULL){
            current->expo ++;
            current = current->next;
        }
        current->expo ++;
        current->next = newnode;
    }
    list->size++;
}
void addexpo(struct list *list ,int x,int y){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->coeff = x;
    newnode->expo = y;
    if(list->head == NULL){
        list->head = newnode;
    }
    else{
        struct node *current;
        current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
    list->size++;
}
void StgTolist(char stg[50], struct list* list){
    int x;
    int i = 1;
    int num = 0, sign = 1;
    while (stg[i] != ']'){
        if (stg[i] == ' '){
            i++;
            continue;}
        else if (stg[i] == '-')
            sign = -1;
        else if (stg[i] == ','){
            x = sign * num;
            addtolist(list,x);
            sign = 1;
            num = 0;}
        else
            num = num * 10 + (stg[i] - '0');
        i++;
    }
    x = sign * num;
    addtolist(list,x);
}
void print(struct list* list){
    if(isEmpty(list)){
        printf("Error");
        exit(0);
    }
    else{
        struct node *current = list->head;
        while(current != NULL)
        {
            if(current->coeff==0){
                printf("");
            }
            else if(current->coeff<0){
                printf("%d",current->coeff);
                if(current->expo==0)
                    printf("");
                else
                    printf("x");
                if(current->expo==0||current->expo==1)
                    printf("");
                else
                    printf("^%d",current->expo);
            }
            else if(current->coeff>0){
                if (current->coeff==1){
                    if(list->size==1)
                        printf("1");
                    else if(current->expo==0)
                        printf("+1");
                    else if(current->expo==list->size-1)
                        printf("");
                    else
                        printf("+");
                }
                else {
                    if(current->expo==list->size-1)
                        printf("%d",current->coeff);
                    else
                        printf("+%d",current->coeff);
                }
                if(current->expo==0)
                    printf("");
                else
                    printf("x");
                if(current->expo==0||current->expo==1)
                    printf("");
                else
                    printf("^%d",current->expo);
            }
        current = current->next;
        }
        printf("\n");
    }
}
void eval(struct list *list, int x){
    if(isEmpty(list)){
        printf("Error");
        exit(0);
    }
    else{
        int sum = 0;
        struct node *current;
        current = list->head;
        while(current != NULL){
            sum += current->coeff * pow( x, current->expo);
            current = current->next;
        }
        printf("%d",sum);
    }
}
int clear(struct list* list){
    if(isEmpty(list)){
        return -1;
    }
    else{
        struct node *current, *temp;
        current = list->head;
        while(current->next != NULL){
          temp = current;
          current = current->next;
          free(temp);
        }
    list->head = NULL;
    list->size = 0;
    return 1;
    }
}
void add (struct list* list1 , struct list* list2){
     struct node* current1=list1->head;
     struct node* current2=list2->head;
     struct list listR;
     listR.head = NULL;
     listR.size=0;
     if(isEmpty(list1)||isEmpty(list2)){
        printf("Error");
        exit(0);
     }
     else{
         while(current1!=NULL || current2!=NULL){
             if(current1->expo==current2->expo)
             {
                 addtolist(&listR,(current1->coeff + current2->coeff));
                 current1=current1->next;
                 current2=current2->next;
             }
             else if(current1->expo>current2->expo)
             {
                 addtolist(&listR,current1->coeff);
                 current1=current1->next;
             }
             else if(current1->expo < current2->expo)
             {
                addtolist(&listR,current2->coeff);
                 current2=current2->next;
             }
         }
         print(&listR);
     }
}
void sub (struct list* list1 , struct list* list2){
    struct node* current1=list1->head;
    struct node* current2=list2->head;
    struct list listR;
    listR.head = NULL;
    listR.size=0;
    if(isEmpty(list1)||isEmpty(list2)){
        printf("Error");
        exit(0);
    }
    else{
    while(current1!=NULL || current2!=NULL){
         if(current1->expo==current2->expo)
         {
             addtolist(&listR,(current1->coeff - current2->coeff));
             current1=current1->next;
             current2=current2->next;
         }
         else if(current1->expo>current2->expo)
         {
             addtolist(&listR,current1->coeff);
             current1=current1->next;
         }
         else if(current1->expo < current2->expo)
         {
            addtolist(&listR,-current2->coeff);
             current2=current2->next;
         }
     }
     print(&listR);
    }
}
void mult (struct list* list1 , struct list* list2){
    int expo,coeff ;
    struct list listR;
    listR.head = NULL;
    listR.size = 0;
    struct node* current=list1->head;
    struct node* temp=list2->head;
    struct node* pre_temp;

    if(isEmpty(list1)||isEmpty(list2)){
        exit(0);
    }
    else{
        while(current!=NULL){
            while(temp!=NULL){
                expo = current->expo + temp->expo;
                coeff = current->coeff * temp->coeff;
                addexpo(&listR,coeff,expo);
                temp=temp->next;
            }
            temp = list2->head;
            current = current->next;
        }
        current = listR.head;
        while (current->next!=NULL){
            pre_temp = current;
            temp = current->next;
            while (temp != NULL){
                if (current->expo == temp->expo){
                    current->coeff += temp->coeff;
                    pre_temp->next = temp->next;
                    free(temp);
                    temp = pre_temp->next;
                    listR.size--;
                }
                pre_temp = temp;
                temp = temp->next;
            }
            current = current->next;
        }
    }
    print(&listR);
}
int main(){
    struct list listA;
    struct list listB;
    struct list listC;
    struct list listR;
    listA.head = listB.head = listC.head = listR.head = NULL;
    listA.size = listB.size = listC.size = listR.size = 0;
    char stg[20];
    char stg1[20];
    int x;
    while(1){
       fgets(stg,20,stdin);
       if(!(strcmp(stg,"set\n"))){
            fgets(stg,20,stdin);
            if (!(strcmp(stg,"A"))||!(strcmp(stg,"A\n"))){
                clear(&listA);
                fgets(stg1,20,stdin);
                if(stg1[1]!=']')
                    StgTolist(stg1,&listA);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"B"))||!(strcmp(stg,"B\n"))){
                clear(&listB);
                fgets(stg1,20,stdin);
                if(stg1[1]!=']')
                    StgTolist(stg1,&listB);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"C"))||!(strcmp(stg,"C\n"))){
                clear(&listC);
                fgets(stg1,20,stdin);
                if(stg1[1]!=']')
                    StgTolist(stg1,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else{
                printf("Error");
                exit(0);
            }
        }
        else if (!(strcmp(stg,"print\n"))){
            fgets(stg,20,stdin);
            if (!(strcmp(stg,"A"))||!(strcmp(stg,"A\n")))
                print(&listA);
            else if (!(strcmp(stg,"B"))||!(strcmp(stg,"B\n")))
                print(&listB);
            else if (!(strcmp(stg,"C"))||!(strcmp(stg,"C\n")))
                print(&listC);
            else{
                printf("Error");
                exit(0);
            }
        }
        else if (!(strcmp(stg,"eval\n"))){
            fgets(stg,20,stdin);
            scanf("%d",&x);
            if (!(strcmp(stg,"A"))||!(strcmp(stg,"A\n")))
                eval(&listA,x);
            else if (!(strcmp(stg,"B"))||!(strcmp(stg,"B\n")))
                eval(&listB,x);
            else if (!(strcmp(stg,"C"))||!(strcmp(stg,"C\n")))
                eval(&listC,x);
            else{
                printf("Error");
                exit(0);
            }
        }
        else if (!(strcmp(stg,"clear\n"))){
            fgets(stg,20,stdin);
            if (!(strcmp(stg,"A"))||!(strcmp(stg,"A\n"))){
                if(clear(&listA) == -1)
                    printf("Error");
                else
                    printf("[]");
            }
            else if (!(strcmp(stg,"B"))||!(strcmp(stg,"B\n"))){
                if(clear(&listB) == -1)
                    printf("Error");
                else
                    printf("[]");
            }
            else if (!(strcmp(stg,"C"))||!(strcmp(stg,"C\n"))){
                if(clear(&listC) == -1)
                    printf("Error");
                else
                    printf("[]");
            }
            else{
                printf("Error");
                exit(0);
            }
        }
        else if (!(strcmp(stg,"add\n"))){
            fgets(stg,20,stdin);
            fgets(stg1,20,stdin);
            if (!(strcmp(stg,"A\n"))){
                if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    add(&listA,&listA);
                else if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    add(&listA,&listB);
                else if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    add(&listA,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"B\n"))){
                if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    add(&listB,&listB);
                else if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    add(&listA,&listB);
                else if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    add(&listB,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"C\n"))){
                if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    add(&listC,&listC);
                else if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    add(&listC,&listB);
                else if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    add(&listA,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else{
                printf("Error");
                exit(0);
            }
        }
        else if (!(strcmp(stg,"sub\n"))){
            fgets(stg,20,stdin);
            fgets(stg1,20,stdin);
            if (!(strcmp(stg,"A\n"))){
                if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    sub(&listA,&listA);
                else if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    sub(&listA,&listB);
                else if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    sub(&listA,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"B\n"))){
                if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    sub(&listB,&listB);
                else if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    sub(&listB,&listA);
                else if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    sub(&listB,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"C\n"))){
                if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    sub(&listC,&listC);
                else if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    sub(&listC,&listB);
                else if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    sub(&listC,&listB);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else{
                    printf("Error");
                 exit(0);
            }
        }
        else if (!(strcmp(stg,"mult\n"))){
            fgets(stg,20,stdin);
            fgets(stg1,20,stdin);
            if (!(strcmp(stg,"A\n"))){
                if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    mult(&listA,&listA);
                else if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    mult(&listA,&listB);
                else if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    mult(&listA,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"B\n"))){
                if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    mult(&listB,&listB);
                else if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    mult(&listA,&listB);
                else if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    mult(&listB,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else if (!(strcmp(stg,"C\n"))){
                if (!(strcmp(stg1,"C"))||!(strcmp(stg1,"C\n")))
                    mult(&listC,&listC);
                else if (!(strcmp(stg1,"B"))||!(strcmp(stg1,"B\n")))
                    mult(&listC,&listB);
                else if (!(strcmp(stg1,"A"))||!(strcmp(stg1,"A\n")))
                    mult(&listA,&listC);
                else{
                    printf("Error");
                    exit(0);
                }
            }
            else{
                printf("Error");
                exit(0);
            }
        }
        else if ((!(strcmp(stg,"\n")))||(!(strcmp(stg,"end"))))
            break;
        else{
            printf("Error");
            exit(0);
        }
        strcpy(stg,"end");
    }
    return 0;
}
