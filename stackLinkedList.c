#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* push(int val, struct node* head) {
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

struct node* pop(struct node* head) {
    if (head == NULL) {
        printf("UnderFlow\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}

void traverse(struct node* head) {
    if (head == NULL) {
        printf("List is empty!!!\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d, ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int peek(struct node* head) {
    if (head == NULL) {
        printf("UnderFlow\n");
        return -1;
    }
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    return temp->data;
}

int main() {
    struct node* head = NULL;
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value push: ");
                scanf("%d", &val);
                head = push(val, head);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                val = peek(head);
                if (val != -1) {
                    printf("Peek: %d\n", val);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}