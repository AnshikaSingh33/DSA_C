#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* enqueue(int val, struct node* head) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

struct node* dequeue(struct node* head)
{
    if (head == NULL)
    {
        printf("UnderFlow\n");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    struct node* tail = head;
    while (tail->next != head)
        tail = tail->next;
    head = head->next;
    tail->next = head;
    free(temp);
    return head;
}

void traverse(struct node* head) {
    if (head == NULL) {
        printf("Queue is empty!!!\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d, ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                head = enqueue(val, head);
                break;
            case 2:
                head = dequeue(head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}