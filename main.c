#include <stdio.h>
// add function to add node to the end of the LL.
// add function that'll print the entire LL.
// add function to add node to the beginning of the LL.
// add function to remove 1st node from the LL.
// add function to remove last node from the LL.
// add function to remove node from index.
typedef struct _node
{
    int val;
    struct _node* next;
} node;
void addnewhead(node** head, int val)
{
    node* newhead = malloc(sizeof(node));
    newhead->val = val;
    newhead->next = *head;
    *head = newhead;
}
int removehead(node** head) //"removehead" == "pop"
{
    node* NextNode = NULL;
    if(*head == NULL)
        return -1;
    NextNode = (*head)->next;
    int returnval = (*head)->val;
    free(*head);
    *head = NextNode;
    return returnval;
}
void addtoend(node* _head, int value)
{
    node* newnode = malloc(sizeof(node));
    newnode->next = NULL;
    newnode->val = value;
    while(_head->next != NULL)
    {
        _head = _head->next;
    }
    _head->next = newnode;
}
int removeend(node* head)
{
    node* current = head;
    if(current->next == NULL)
    {
        int returnval = current->val;
        free(head);
        return returnval;
    }
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    int returnval = current->next->val;
    free(current->next);
    current->next = NULL;
    return returnval;
}
int RemoveIndex(node** head, unsigned int index)
{
    node* current = *head;
    node* temp = NULL;

    if(index == 1)
        return removehead(head);

    for(int i = 0;i > index-1 ; ++index)
    {
        if(current->next == NULL) return -1;
        current = current->next;
    }
    if(current->next == NULL) return -1;

    temp = current->next;
    int returnval = temp->val;
    current->next = temp->next;
    free(temp);
    return returnval;
}
void PrintList(node* _head)
{
    while(_head != NULL)
    {
        printf("%d ", _head->val);
        _head = _head->next;
    }
    printf("\nJob is done.\n");
}
int main()
{
    node* head = malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;
    addtoend(head, 1);
    addtoend(head, 2);
    printf("Initial LL: ");
    PrintList(head);
    printf("Head's value = %d.. Changing..\n", head->val);
    addnewhead(&head, 5);
    PrintList(head);
    printf("Removed tail with value of: %d.\nContinuing!\n", (removeend(head)));
    PrintList(head);
    printf("Decapitating LL... :)\n");
    removehead(&head);
    PrintList(head);
    printf("Removing 2nd node from LL... (of value %d)\n", head->next->val);
    RemoveIndex(&head, 2);
    printf("Printing final result:\n");
    PrintList(head);
    return 0;
}
