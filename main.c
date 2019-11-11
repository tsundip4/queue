#include <stdio.h>
#include <stdlib.h>

//#define size 5
//
//int queue[5];
//
//int front=0, rear = 0;
//int main()
//{
//    int choice;
//
//    while(1){
//        printf("press 1 for queue in\n");
//        printf("press 2 for queue out\n");
//        printf("press 3 for traverse queue\n");
//
//        scanf("%d", &choice);
//
//        switch(choice)
//        {
//        case 1:
//            queuein();
//            break;
//
//        case 2:
//            queueout();
//            break;
//
//        case 3:
//            traverse();
//            break;
//
//        case 4:
//            exit(0);
//        }
//    }
//}
//
//void queuein()
//{
//    if(rear == size){
//        printf("queue is full\n");
//    }
//    printf("enter the data please\n");
//    scanf("%d", &queue[rear]);
//
//    rear++;
//}
//
//void queueout()
//{
//    int i;
//    if(front == rear){
//        printf("queue is empty\n");
//    }
//    else {
//    printf("the deleted value is %d\n", queue[front]);
//
//    for(i=0; i<rear-1; i++){
//        queue[i]=queue[i+1];
//    }
//    }
//
//    rear--;
//
//    printf("\n");
//}
//
//void traverse()
//{
//    int i;
//
//    for(i=front ; i<rear; i++){
//        printf("%d--", queue[i]);
//    }
//    printf("\n");
//}
//

/* queue using linked list*/
//
//struct node{
//    int data;
//    struct node* next;
//};
//struct node* Head;
//
//void insert()
//{
//    struct node* temp1;
//    struct node* temp2;
//
//    temp1 = (struct node*)malloc(sizeof(struct node));
//    printf("take the data\n");
//    scanf("%d", &temp1->data);
//    temp1->next = NULL;
//    if(Head==NULL){
//        Head = temp1;
//    }
//    else{
//        temp2 = Head;
//
//        while(temp2->next!= NULL){
//            temp2 = temp2->next;
//        }
//        temp2->next = temp1;
//    }
//}
//
//void queueout()
//{
//    struct node* qout;
//    if(Head == NULL){
//        printf("queue is empty\n");
//    }
//    else
//    {qout = Head;
//    printf("the deleted value is %d\n", Head->data);
//    Head = qout->next;
//
//    free(qout);
//    }
//
//}
//
//void traverse()
//{
//    struct node* temp;
//
//    temp = Head;
//
//    while(temp != NULL){
//        printf("-->%d", temp->data);
//        temp = temp->next;
//    }
//}
//
//int main()
//{
//    int choice;
//    while(1){
//
//    printf("press 1 for insert\n");
//    printf("press 2 for traverse\n");
//    scanf("%d", &choice);
//    switch(choice){
//    case 1:
//        insert();
//        break;
//
//    case 2:
//        traverse();
//        break;
//
//    case 3:
//        queueout();
//        break;
//
//    }
//    }
//}


/* queue using linked list*/
//
//struct node{
//    int data;
//    struct node* next;
//};
//struct node* front = NULL;
//struct node* rear = NULL;
//
//void queuein()
//{
//    struct node* newnode;
//    newnode =(struct node*)malloc(sizeof(struct node));
//    newnode->next = NULL;
//
//    printf("enter the data please\n");
//    scanf("%d", &newnode->data);
//
//    if(rear == NULL){
//        rear = newnode;
//        front = newnode;
//    }
//
//    else
//    {
//        rear->next =newnode;
//        rear =rear->next;
//    }
//
//
//}
//
//void queueout()
//{
//    struct node* freee = NULL;
//
//
//    if(front==NULL){
//        printf("queue is empty\n");
//    }
//
//    else{
//        printf("the deleted value is %d", front->data);
//        freee = front;
//        front = front->next;
//    }
//    free(freee);// this will free the node which freee pointed so that no memory will be free
//
//    printf("\n");
//
//
//}
//
//void traverse()
//{
//    struct node* temp;
//    temp = front;
//
//    while(temp != NULL){
//        printf("-->%d", temp->data);
//        temp = temp->next;
//    }
//    printf("\n");
//}
//
//int main()
//{
//    int choice;
//
//    while(1){
//        printf("choose 1 for queue add\n");
//        printf("choose 2 for queue remove\n");
//        printf("choose 3 for traverse\n");
//
//        scanf("%d", &choice);
//
//        switch(choice){
//        case 1:
//            queuein();
//            break;
//
//        case 2:
//            queueout();
//            break;
//
//        case 3:
//            traverse();
//            break;
//
//        }
//    }
//}


/* Circular queue using array*/

#define size 5

int cqueue[size];
int front=-1, rear = -1;

void cqueueinsert(int x)
{
  if(rear==-1 && front == -1){
    front = rear =0;
    cqueue[rear] = x;
  }

  else if((rear+1)%size == front){
    printf("the queue is full\n");
  }

  else{
    rear = (rear+1)%size;
    cqueue[rear] = x;
  }
}


void cqueueout()
{
    if(front==-1 && rear==-1){
        printf("the queue value is empty\n");
    }

    else if(front == rear){
        printf("the last qout is %d\n", cqueue[front]);
        front = rear =-1;
    }

    else {
        printf("the qout value is %d\n", cqueue[front]);
         front = (front+1)%size;
    }
}
void display(){
    int i = front;

    while(i != rear){
        printf("--%d", cqueue[i]);
        i = (i+1)%size;
    }
    printf("--%d", cqueue[rear]);

    printf("\n");
}
int main()
{
    int choice, x;

    while(1){

    printf("press 1 for insert\n");
    printf("press 2 for qout\n");
    printf("press 3 for display\n");

    scanf("%d", &choice);

    switch(choice){
    case 1:
        printf("take the data please\n");
        scanf("%d", &x);
        cqueueinsert(x);
        break;

    case 2:
        cqueueout();
        break;


    case 3:
        display();
        break;

    }
    }
}
