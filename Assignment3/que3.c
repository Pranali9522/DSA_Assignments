#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Display(struct Node* first)
{
    while(first != NULL)
    {
        printf("| %d |-> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

void DisplayReverse(struct Node* first)
{
    if(first == NULL)          // base condition
        return;

    DisplayReverse(first->next);   // recursive call (go to last node)
    printf("| %d |-> ", first->data);  // print while coming back
}

void InsertFirst(struct Node** first, int no)
{
    struct Node* newn = (struct Node*)malloc(sizeof(struct Node));
    newn->data = no;
    newn->next = *first;

    *first = newn;
}

int main()
{
    struct Node* head = NULL;

    InsertFirst(&head, 30);
    InsertFirst(&head, 20);
    InsertFirst(&head, 10);

    printf("Original Linked List:\n");
    Display(head);

    printf("\nReverse Order Display:\n");
    DisplayReverse(head);
    printf("NULL\n");

    return 0;
}
