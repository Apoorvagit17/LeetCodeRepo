#include<stdio.h>
#include<string.h>

#define MAX 100

char stk[MAX];
int top = -1;

void push(char c);
char pop();

int isValid(char* s) {
    char exp[MAX], temp;
    int i, flag = 1;

    printf("Enter an expression : ");
    gets(exp);

    for(i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1)
                flag = 0;
            else {
                temp = pop();
                if((exp[i] == ')' && (temp == '{' || temp == '[')) ||
                   (exp[i] == '}' && (temp == '(' || temp == '[')) ||
                   (exp[i] == ']' && (temp == '(' || temp == '{')))
                    flag = 0;
            }
        }
    }

    if(top >= 0)
        flag = 0;

    if(flag == 1)
        printf("\n Valid expression");
    else
        printf("\n Invalid expression");

    return flag;
}

void push(char c) {
    if(top == (MAX - 1))
        printf("Stack Overflow\n");
    else {
        top++;
        stk[top] = c;
    }
}

char pop() {
    if(top == -1) {
        printf("\n Stack Underflow");
        return '\0';
    } else {
        return stk[top--];
    }
}

int main() {
    isValid(NULL);  // You can call the function with a NULL parameter or any other string you want.
    return 0;
}