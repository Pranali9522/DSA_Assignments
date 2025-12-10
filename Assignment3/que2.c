//2. Create an array of integers. Reverse the array using stack
#include<stdio.h>
#define SIZE 20   // maximum array size

// Stack structure
typedef struct stack {
    int arr[SIZE];
    int top;
} stack;

// Stack functions
void init(stack *ps) {
    ps->top = -1;
}

int stack_full(stack *ps) {
    return ps->top == SIZE - 1;
}

int stack_empty(stack *ps) {
    return ps->top == -1;
}

void push(stack *ps, int data) {
    ps->arr[++ps->top] = data;
}

int pop(stack *ps) {
    return ps->arr[ps->top--];
}

// Main logic: reverse array
int main() {
    int n;
    int arr[SIZE];
    stack S;

    init(&S);

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Push all elements into stack
    for(int i = 0; i < n; i++)
        push(&S, arr[i]);

    // Pop back into array (reversed)
    for(int i = 0; i < n; i++)
        arr[i] = pop(&S);

    // Output reversed array
    printf("\nReversed Array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

