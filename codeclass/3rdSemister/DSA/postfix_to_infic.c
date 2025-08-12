#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct stack
{
    char *arr[MAX];
    int top;
} stack;

void push(stack *s, char *str)
{
    if (s->top < MAX - 1)
    {
        s->arr[++(s->top)] = str;
    }
}
char *pop(stack *s)
{
    if (s->top != -1)
    {
        return s->arr[(s->top)--];
    }
    return NULL;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

char *postfix_to_infix(char *postfix)
{
    stack s;
    s.top = -1;
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            char *op = (char *)malloc(2 * sizeof(char));
            op[0] = postfix[i];
            op[1] = '\0';
            push(&s, op);
        }
        else // Operator
        {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(expr, "(%s%c%s)", op2, postfix[i], op1);

            push(&s, expr);
        }
    }
    return pop(&s);
}

int main()
{
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    char *infix = postfix_to_infix(postfix);
    printf("Infix expression: %s\n", infix);

    free(infix);
    return 0;
}