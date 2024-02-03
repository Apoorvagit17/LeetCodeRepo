#include<stdio.h>
#include<stdlib.h>
#define MAX 30

int max_stack[MAX];
    int max_top=-1;
     int stack[MAX];
    int top=-1;

void push(int ele) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    top++;
    stack[top] = ele;

    if (max_top == -1 || ele >= max_stack[max_top]) {
        max_top++;
        max_stack[max_top] = ele;
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    }

    if (stack[top] == max_stack[max_top]) {
        max_top--;
    }

    top--;
}

int get_max() {
    if (max_top == -1) {
        printf("Stack is empty\n");
        return -1;  // You can return a sentinel value or handle it differently based on your requirements
    }

    return max_stack[max_top];
}


int main() {
    while (1) {
        int choice;
        printf("Enter your choice\n1. Push an element\n2. Pop an element\n3. Maximum element in the stack\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int ele;
                printf("Enter the element you want to push: ");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Maximum element in the stack: %d\n", get_max());
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong choice!!!\n");
        }
    }

    return 0;
}
