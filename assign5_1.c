#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct NODE{
    int data;
    struct NODE *prev, *next;
}NODE;

NODE* head = NULL;

void insertEnd(int data)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    NODE *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

NODE *insertBeg(int data)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->next = head;
    return newNode;
}

void insertBet(int data, int pos)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (pos == 1)
    {
        head = insertBeg(data);
        return;
    }
    

    NODE *temp = head;
    for(int i = 0; i < pos-2 && (temp != NULL); i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Can't add %d to the Linked List\n", data);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int delBeg()
{
    if (head == NULL) return -1;
    else if (head->next == NULL)
    {
        int data = head->data;
        free(head);
        return data;
    }
    
    
    NODE *ptr = head;
    head = head->next;
    ptr->next = NULL;
    int data = ptr->data;
    free(ptr);
    return data;
}

int delEnd()
{
    if (head == NULL) return -1;
    else if (head->next == NULL)
    {
        int data = head->data;
        free(head);
        return data;
    }
    NODE *ptr = head, *p;
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    ptr->prev = NULL;
    int data = ptr->data;
    free(ptr);
    return data;
}

int delBet(int pos)
{
    if (head == NULL) {
        printf("The list is empty\n");
        return -1;
    }
    else if (head->next == NULL)
    {
        int data = head->data;
        free(head);
        return data;
    }
    if (pos == 1) return delBeg();    
    
    NODE *ptr = head, *p;
    for (int i = 0; i < pos-1 && (ptr != NULL); i++)
    {
        p = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("Can't delete from %dth position\n", pos);
            return -1;
        }
    }
    p->next = ptr->next;
    ptr->next = NULL;
    ptr->prev = NULL;
    int data = ptr->data;
    free(ptr);
    return data;
}

NODE *reverseList()
{
    if(head == NULL || head->next == NULL) return head;

    NODE *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;  
    }
    return prev;
}

void printList()
{
    if(head == NULL) return;

    NODE *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void main(){
    
    int option, data, pos;
    do
    {
        printf("\n************************\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in between\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete in between\n");
        printf("7. Reverse the List\n");
        printf("0. Exit\n");
        printf("************************\n");
        printf("Enter Your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 0:
                break;
            
            case 1:
                printf("Enter the data you want to insert: ");
                scanf("%d", &data);
                head = insertBeg(data);
                break;
            
            case 2:
                printf("Enter the data you want to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            
            case 3:
                printf("Enter the data you want to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert the data: ");
                scanf("%d", &pos);
                insertBet(data, pos);
                break;

            case 4:
                data = delBeg();
                (data != -1)? printf("The deleted element is %d\n", data) : printf("");
                break;

            case 5:
                data = delEnd();
                (data != -1)? printf("The deleted element is %d\n", data) : printf("");
                break;

            case 6:
                printf("Enter the position to delete element: ");
                scanf("%d", &pos);
                data = delBet(pos);
                (data != -1)? printf("The deleted element is %d\n", data) : printf("");
                break;

            case 7:
                head = reverseList();
                break;
            
            default:
                printf("Invalid Option\n");
                break;
        }
        printf("\nYour List looks like this: \n");
        printList();
    } while (option != 0);   
}