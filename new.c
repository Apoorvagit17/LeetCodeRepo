#include <stdio.h>
#include <stdlib.h>

struct node_st
{
    int data;
    struct node_st *next ;
};
int value = 10;
typedef struct node_st node;

node *start = NULL;
node* getnode();

void traverse_list();
void insert_at_start();
void insert_at_end();
void insert_after(int key);
void delete_at_start();
void delete_at_end();
void delete_node(int key);
void reverse_list();
void traverse_rec(node *n);
void reverse(node**start);

int main()
{

 insert_at_start(); // 10

 insert_at_start(); //20 10

 insert_at_start(); //30 20 10

 insert_at_end(); //30 20 10 40

 insert_after(20); //30 20 '50' 10 40

 insert_after(40); // 30 20 50 10 40 '60'

 insert_after(30); // 30 '70' 20 50 10 40 60
 traverse_list();

 reverse(&start);
 traverse_list();

return 0;
}

void traverse_list()
{
    node *temp = start;
    printf("The list:");
    while(temp !=NULL)
    {
    printf("%d ", temp->data);
    temp = temp->next;
    }
    printf("\n");

}

node* getnode()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    value = value+10;
    return temp;
}

void reverse(node**start){
     node* previous = NULL;
     node* current=*start;
     node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=previous;
        previous =current;
        current=next;
    }
    *start=previous;
 }


void insert_at_start()
{
    node *nn = getnode();
    nn->next = start;
    start = nn;
}

void insert_at_end()
{
    node *temp = start;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node *nn = getnode();
    temp->next = nn;

}

void insert_after(int key)
{
    node *temp = start;
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            node *nn = getnode();
            nn->next = temp->next;
            temp->next = nn;
            return;

        }
        temp = temp->next;
    }
    if(temp == NULL)
        printf("Key %d is not found in the list\n");
}


void delete_at_start()
{
    if(start!=NULL)
    {
        node *temp = start;
        start = start->next;
        free(temp);
    }
    else
        printf("List is empty\n");
}

void delete_at_end()
{
    node *cur = start;
    node *prev =  NULL;

    // Navigating to last node
    while(cur->next != NULL)
    {
        prev = cur;     // Updating prev node before moving to next node
        cur = cur->next;
    }
    free(cur); //Deleting the last node of list
    prev->next = NULL;

    //Spl case: Deleting the only node of list
    //    if(prev!=NULL)
    //        prev->next = NULL;
    //    else
    //        start = NULL;
}

void delete_node(int key)
{
    node *prev = NULL, *cur = start;
    while(cur != NULL)
    {
        if(cur->data == key)
        {
           prev->next = cur->next;
           free(cur);
           return;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("\nNode with data %d is not found!", key);
}

void reverse_list()
{
    node *prev = NULL, *next = NULL;
    node* cur = start;
    while(cur!=NULL)
    {
        // Update next pointer to node after current
        next = cur->next;
        // reverse conn for current node
        cur->next = prev;
        // Move pointers prev,cur forward
        prev = cur;
        cur = next;
    }
    // Set start pointer to last node
    start = prev;
}

void traverse_rec(node *n)
{
    if(n == NULL)
            return;
    else
    {
        printf("%d ", n->data);
        traverse_rec(n->next);

    }
}




 