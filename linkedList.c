#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insertAtBeg(int val, struct node* head)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return head;
}

struct node* deleteAtBeg(struct node* head)
{
    if (head == NULL)
    {
        printf("UnderFlow\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* insertAtEnd(int val, struct node* head)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* deleteAtEnd(struct node* head)
{
    if (head == NULL)
    {
        printf("UnderFlow\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

struct node* insertAtPos(int val, int pos, struct node* head)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    struct node* temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (i == pos - 1 && temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Position out of bounds\n");
        free(newNode);
    }
    return head;
}

struct node* deleteAtPos(int pos, struct node* head)
{
    if (head == NULL)
    {
        printf("UnderFlow\n");
        return NULL;
    }
    if (pos == 1)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    int i;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (i == pos && temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Position out of bounds\n");
    }
    return head;
}

void traverse(struct node* head)
{
    if (head == NULL)
    {
        printf("List is empty!!!\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to reverse.\n");
        return head;
    }

    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int countNodes(struct node* head)
{
    int count = 0;
    struct node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}`
int main()
{
    struct node* head = NULL;
    int choice, value, pos;
    char cont;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete at end\n");
        printf("5. Insert at position\n");
        printf("6. Delete at position\n");
        printf("7. Traverse\n");
        printf("8. Reverse the list\n");
        printf("9. Count nodes\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            head = insertAtBeg(value, head);
            break;

        case 2:
            head = deleteAtBeg(head);
            break;

        case 3:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            head = insertAtEnd(value, head);
            break;

        case 4:
            head = deleteAtEnd(head);
            break;

        case 5:
            printf("Enter value to insert and position: ");
            scanf("%d %d", &value, &pos);
            head = insertAtPos(value, pos, head);
            break;

        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            head = deleteAtPos(pos, head);
            break;

        case 7:
            printf("List: ");
            traverse(head);
            break;

        case 8:
            head = reverse(head);
            printf("List reversed successfully.\n");
            break;

        case 9:
            printf("Number of nodes: %d\n", countNodes(head));
            break;

        case 10:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }

        printf("Do you wish to continue? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    return 0;
}