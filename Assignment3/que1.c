//1. Implement descending stack (Initialize top = SIZE)

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stack{
    int arr[SIZE];
    int top;
}stack_t;

void init_stack(stack_t *ps);
void push(int data,stack_t *ps);
void pop(stack_t *ps);
int peek(stack_t *ps);
int stack_full(stack_t *ps);
int stack_empty(stack_t *ps);
void display(stack_t *ps);

int main()
{
    stack_t s;
    init_stack(&s);
    int choice;

    do{
        
        printf("0.exit\n1.push\n2.pop\n3.peek\n4.display\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                exit(0);

            case 1: // push
                if(stack_full(&s)) {
                    printf("Stack is FULL!\n");
                } 
                else {
                    int data;
                    printf("Enter data to push: ");
                    scanf("%d", &data);
                    push(data, &s);
                    printf("Pushed = %d\n", data);
                }
                break;

            case 2: // pop
                if(stack_empty(&s)) {
                    printf("Stack is EMPTY!\n");
                } 
                else 
                {
                    int val = peek(&s);
                    pop(&s);
                    printf("Popped = %d\n", val);
                }
                break;

            case 3: // peek
                if(stack_empty(&s)) {
                    printf("Stack is empty! Peek not possible.\n");
                } 
                else 
                {
                    printf("Top element = %d\n", peek(&s));
                }
                break;

            case 4:
                display(&s);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice !=0);

    return 0;
}

void init_stack(stack_t *ps)
{
    ps->top = SIZE;
}
void push(int data,stack_t *ps)
{
    //decrement top because descending
    
    ps->top--;

    //insert data 
    ps->arr[ps->top] = data;
}
void pop(stack_t *ps)
{
    ps->arr[ps->top] = 0;
    ps->top++;
    //ps->arr[ps->top] =0;
   // ps->top--;
}
int peek(stack_t *ps)
{
    return ps->arr[ps->top];
}
int stack_full(stack_t *ps)
{
    return ps->top == 0;
}
int stack_empty(stack_t *ps)
{
    return ps->top == SIZE;
}
void display(stack_t *ps) 
{
    if(stack_empty(ps)) 
    {
        printf("Stack is EMPTY! Nothing to display.\n");
        return;
    }

    printf("\n--- STACK CONTENT (Top to Bottom) ---\n");

    for(int i = ps->top; i < SIZE; i++) {
        printf("%d ", ps->arr[i]);
    }

    printf("\n--------------------------------------\n");

    printf("Top element (Peaked) = %d\n", ps->arr[ps->top]);
    printf("Total elements pushed = %d\n", SIZE - ps->top);
}
