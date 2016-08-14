/*

Author : JAGANI VATSAL
            Computer Engineering
            DDIT,2014-18

 singly linked list with the features of
add at the beginning
            end
            after some data
            before some data
            at position
delete at particular position
            particular data
sort in ascending
        descending order   ....  sorting must be of node not of only data  oh!!!! but by
make reverse link list

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}node;

node *head;
int length;

void print_main_menu();
void print();
void insert();
void insert_beginning(node *n);
void insert_end(node *n);
void insert_position(node *n,int position);
void insert_after(node *n);
void insert_before(node *n);
void delete();
void delete_beginning();

main()
{
    head=NULL;
    length=0;
    int choice=1;
    do{
        print_main_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();break;
            case 2:print();break;
            case 3:{
                if(length<1){
                    printf("Empty List\n");
                }
                else{
                    delete();
                }
                break;
            }
            case 4:sort();break;
            case 0:break;
            default:printf("INVALID CHOICE\n");
                    print();
                    break;
        }
    }while(choice!=0);

}



void print_main_menu()
{
    printf("Enter your choice\n");
    printf("1. Add value\n");
    printf("2. Print list\n");
    printf("3. Delete value\n");
    printf("4. sort list\n");
    printf("0. exit\n");
}

void print()
{
    node *temp=head;
    printf("Length of List : %d\n",length);
    while(temp!=NULL)
    {
        printf("-> %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert()
{
    int choice=2;
    printf("1. insert at beginning\n");
    printf("2. insert at end\n");
    printf("3. insert at position\n");
    printf("4. insert after some element\n");
    printf("5. insert before some element\n");

    scanf("%d",&choice);

    node *n=(node *)malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&n->data);
    length++;

    if(head==NULL)
    {
        head=n;
        n->next=NULL;
        return;
    }

    switch(choice)
    {
        case 1:{
            insert_beginning(n);
            break;
        }
        case 2:{
            insert_end(n);
            break;
        }
        case 3:{
            int position=0;
            printf("Enter position(total length - %d ): ",length-1);
            scanf("%d",&position);
            if(position>length+1 || position<1)
            {
                printf("Invalid POSITION\n");
                break;
            }
            if(position==1)
            {
                insert_beginning(n);
                break;
            }else if(position==length+1)
            {
                insert_end(n);
            }
            else{
                insert_position(n,position);
            }
            break;
        }
        case 4:{
            insert_after(n);
            break;
        }
        case 5:{
            insert_before(n);
            break;
        }
    }
}

void insert_beginning(node *n)
{
    n->next=head;
    head=n;
}

void insert_end(node *n)
{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    n->next=NULL;
    temp->next=n;
    return;
}

insert_position(node *n,int position)
{
    int i=1;
    node *temp=head;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    n->next=temp->next;
    temp->next=n;
}

insert_after(node *n)
{
    int data;
    printf("Enter element data : ");
    scanf("%d",&data);
    node *temp=head;
    while(temp->data!=data)
    {
        temp=temp->next;
         if(temp==NULL)
         {
            printf("Data not found\n");
            length--;
            return;
         }
    }
    n->next=temp->next;
    temp->next=n;
    return;
}

insert_before(node *n)
{
    int data;
    printf("Enter element data : ");
    scanf("%d",&data);
    node *temp=head;
    if(head->next==NULL)
    {
        insert_beginning(n);
    }
    else
    {
        while(temp->next->data!=data)
        {
            temp=temp->next;
            if(temp->next==NULL)
            {
                printf("Data not found\n");
                length--;
                return;
            }
        }
        n->next=temp->next;
        temp->next=n;
    }
}


void delete()
{
    int option;
    length--;
    printf("Enter your choice : \n");
    printf("1. Position\n2. Data\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:{
            int position;
            printf("Enter position to be deleted : ");
            scanf("%d",&position);
            if(position>length+1 || position<1)
            {
                printf("Invalid POSITION\n");
                length++;
                break;
            }
            if(position==1)
            {
                delete_beginning();
                break;
            }
            int i=1;
            node *temp=head;
            while(i<position-1)
            {
                temp=temp->next;
                i++;
            }
            node *t=temp->next;
            temp->next=temp->next->next;
            free(t);
            break;
        }
        case 2:{
            int data;
            printf("Enter data to be deleted : ",&data);
            scanf("%d",&data);
            if(head->data==data)
            {
                delete_beginning();
                break;
            }
            node *temp=head;
            if(temp->next==NULL)
            {
                printf("Data not found\n");
                length++;
                break;
            }
            while(temp->next->data!=data)
            {
                temp=temp->next;
                if(temp->next==NULL)
                {
                    printf("Data not found\n");
                    length++;
                    break;
                }
            }
            node *t=temp->next;
            temp->next=temp->next->next;
            free(t);
            break;
        }
    }
}

void delete_beginning()
{
    node *t=head;
    head=head->next;
    free(t);
}


void sort()
{
    int counter;
node *current = head;
node *previous = (node*) malloc(sizeof(node));
node *next = (node*) malloc(sizeof(node));

for (counter = 0; counter < length; counter++){
    current = head;
    next = current->next;

    while(next != NULL){
        if (current->data > next->data){
            if (current == head){
                head = next;
            }
            previous->next = next;
            current->next = next->next;
            next->next = current;

            previous = next;
            next = current->next;
        }
        else {
            previous = current;
            current = current->next;
            next = current->next;
        }
    }
}
}




