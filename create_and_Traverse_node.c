#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;
 void creation( int n)
 {
    int i,d;
     struct node *newNode,*temp;
     head=(struct node *)malloc(sizeof(struct node));
     if(head==NULL)
     {
        printf("Unable to allocate memory");
        exit(0);
     }
     printf("Enter the first element:");
      scanf("%d",&d);
      head->data=d;
      head->next=NULL;
      temp =head;
    for(i=2;i<=n;i++)
    {
        newNode=(struct node *)malloc(sizeof(struct node));
        if(newNode== NULL)
        {
            printf("Unable to allocate memory");
            break;
        }
        printf("Value:");
        scanf("%d",&d);
        newNode->data=d;
        newNode->next=NULL;
        temp->next=newNode;
    }
 }
 void traverse() {
    struct node *temp;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    printf("\n"); 
}

 int main()
 {
    int n;
    printf("enter the size of linked list:");
    scanf("%d",&n);
    creation(n);
    traverse();
    return 0;
 }
