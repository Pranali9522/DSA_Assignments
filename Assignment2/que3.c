#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct queue{
    int front;
    int rear;
    int arr[SIZE];
    int count;

}queue_t;

void init_queue(queue_t *pq);
void enqueue(int data,queue_t *pq);
void dequeue(queue_t *pq);
int peek(queue_t *pq);
int queue_full(queue_t *pq);
int queue_empty(queue_t *pq);

int main()
{
    queue_t q;
    init_queue(&q);

    int choice;
    do{
        printf("0.exit\n1.enqueue\n2.dequeue\n3.peek\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                    exit(0);
            
            case 1://enqueue
                    if(queue_full(&q))
                    {
                        printf("queue is full\n");
                    }
                    else
                    {
                        int data;
                        printf("enter data:");
                        scanf("%d",&data);
                        enqueue(data,&q);
                        printf("ENtered data is %d\n",data);
                    }
                    break;

            case 2://dequeue
                    if(queue_empty(&q))
                    {
                        printf("queue empty\n");
                    }
                    else
                    {
                        int val = peek(&q);
                        dequeue(&q);
                        printf("deleted data:%d\n",val);
                    }
                    break;

            case 3://peek
                    if(queue_empty(&q))
                        printf("queue empty.. no peek\n");

                    else
                        printf("front most element:%d\n",peek(&q));

                    break;

            default:
                    printf("invalid choice\n");
        }


    }while(choice !=0);
    return 0;
}

void init_queue(queue_t *pq)
{
    pq->front=0;
    pq->rear=0;
    pq->count=0;
}

void enqueue(int data,queue_t *pq)
{
    //increment rear
    pq->rear = (pq->rear +1) %SIZE;

    //insert data
    pq->arr[pq->rear] = data;

    pq->count++;//increase count

}

void dequeue(queue_t *pq)
{
    pq->front=(pq->front +1)%SIZE;
    pq->count--;

}

int peek(queue_t *pq)
{
    return pq->arr[pq->front];

}

int queue_full(queue_t *pq)
{
   return (pq->count==SIZE-1);
}

int queue_empty(queue_t *pq)
{
    return (pq->count==0);
    
}


