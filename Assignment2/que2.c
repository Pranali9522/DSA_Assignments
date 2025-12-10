//2. Write program to implement linear queue in which front and rear starts at 0.


#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int arr[SIZE];
    int rear;
    int front;
};

void init_queue(struct queue *pq);
void enqueue(int data,struct queue *pq);
void dequeue(struct queue *pq);
int peek(struct queue *pq);
int queue_full(struct queue *pq);
int queue_empty(struct queue *pq);

int main()
{
    struct queue q;
    init_queue(&q);

   /* int data;
    for(int i=0;i<SIZE;i++)
    {
    printf("enter the data to insert in the q:");
    scanf("%d",&data);
    enqueue(data,&q);
    printf("data entered:%d\n",data);
    }
    */

    int choice;
    do{
        printf("/n 0.exit\n1.enqueue\n2.dequeue\n3.peek\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                    exit(0);
            
            case 1://enqueue
                    if(queue_full(&q))
                    {
                        printf("queue is full..\n");
                    }
                    else
                    {
                        int data;
                        printf("Enter data to be inserted:");
                        scanf("%d",&data);
                        enqueue(data,&q);
                        printf("data entered:%d\n",data);
                    }
                    break;
            
            case 2://dequeue
                    if(queue_empty(&q))
                    {
                        printf("queue empty..\n");
                    }
                    else
                    {
                        int val = peek(&q);
                        dequeue(&q);
                        printf("value deleted:%d\n",val);
                    }
                    break;
                
            case 3://peek
                    if(queue_empty(&q))
                    {
                        printf("queue empty..cannot peek\n");
                    }
                    else
                    {
                        int val=peek(&q);
                        printf("frontmost element=%d\n",val);
                    }
                    break;

            default: 
                    printf("invalid choice");
        }

    }while(choice !=0);
    
    return 0;

}

void init_queue(struct queue *pq)
{
    pq->rear=0;
    pq->front=0;
}

void enqueue(int data,struct queue *pq)
{
    if(queue_full(pq))
    {
        printf("queue is full..\n");
    }
    //increment the rear
    pq->rear++;

    //2.data insert at the rear index
    pq->arr[pq->rear]=data;

    //if front is at -1 then bring to 0
    //if(pq->front == -1)
        //pq->front = 0;
}

void dequeue(struct queue *pq)
{
    if(queue_empty(pq))
    {
        printf("queue is empty..!cannot delete\n");
        return;
    }
    printf("deleted:%d\n",pq->arr[pq->front]);
    pq->front++;
}

int peek(struct queue *pq)
{
    if(queue_empty(pq))
    {
        printf("queue is empty...cannot peek\n");
        return -1;
    }
    return pq->arr[pq->front];
}

int queue_full(struct queue *pq)
{
    if(pq->rear==SIZE-1)
        return 1;
    else
        return 0;

}

int queue_empty(struct queue *pq)
{
    if(pq->rear == 0 || pq->front > pq->rear)
        return 1;
    
    else
        return 0;
}