#include<stdio.h>
#define STACK_MAX 100

typedef struct {
    int top;
    int data[STACK_MAX];
} Stack;

void push (Stack *s, int item) {
    if (s->top < STACK_MAX) {
        s->data[s->top] = item;
        s->top++;
    } else {
        printf("Stack is full!\n");
    }
}

int pop (Stack *s) {
    if(s->top == 0) {
        printf("Stack is emplty!\n");
        return -1;
    } else {
        s->top--;
        return s->data[s->top];
    }
}
void show(Stack *s) {
    int i;
    printf("\nStack : ");
    for (i = s->top - 1; i >= 0; i--) {
        printf("%d ",s->data[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    Stack my_stack;
    my_stack.top = 0;
    
    push(&my_stack, 1);
    push(&my_stack, 7);
    push(&my_stack, 3);
    push(&my_stack, 5);

    show(&my_stack);

    printf("\nPop: %d", pop(&my_stack));
    printf("\nPop: %d", pop(&my_stack));
    printf("\nPop: %d", pop(&my_stack));
    printf("\nPop: %d", pop(&my_stack));
    printf("\n");

    return 0;
}
