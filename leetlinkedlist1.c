#include<stdio.h>
#include<stdlib.h>
 struct ListNode {
        int val;
    struct ListNode *next;
};
typedef struct ListNode s;
void printList(s *n)
{
  while (n != NULL)
  {
    printf(" %d ", n->val);
    n = n->next;
  }

}
void insert(s **head, int val) {
    s *newNode = (s *)malloc(sizeof(s));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}
s *addTwoNumbers(s* l1, s* l2) {
    s *dummy = (s *)malloc(sizeof(s)); 
    s *temp = dummy; 
    int sum_carry = 0;

    while (l1 != NULL || l2 != NULL || sum_carry) {
        int sum = 0;

        if (l1 != NULL) {
            sum += l1->val; 
            l1 = l1->next; 
        }

        if (l2 != NULL) {
            sum += l2->val; 
            l2 = l2->next; 
        }

        sum += sum_carry; 
        sum_carry = sum / 10; 

        s *node = (s *)malloc(sizeof(s)); 
        node->val = sum % 10;
        node->next = NULL;
        temp->next = node; 
        temp = temp->next; 
    }

    s *result = dummy->next;
    //free(dummy); // Freeing dummy after extracting the result
   return result;
   free(dummy); 
}

    int main() {
    s *list1 = NULL;
    s *list2 = NULL;

    int n, val;

    // Taking input for the first linked list
    printf("Enter the number of elements for the first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&list1, val);
    }

    // Taking input for the second linked list
    printf("Enter the number of elements for the second linked list: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&list2, val);
    }

     s *result = addTwoNumbers(list1,list2);
     printf("Result: ");
     printList(result);
      //free(dummy);

     return 0;
    }

