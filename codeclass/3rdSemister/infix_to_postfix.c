#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct stack
{
    char arr[MAX];
    int top;
} stack;

void push(stack *s, char ch)
{
    if (s->top < MAX - 1)
    {
        s->arr[++(s->top)] = ch;
    }
}

char pop(stack *s)
{
    if (s->top != -1)
    {
        return s->arr[(s->top)--];
    }
    return -1;
}

char peek(stack *s)
{
    if (s->top != -1)
    {
        return s->arr[s->top];
    }
    return -1;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

char *infix_to_postfix(char *infix)
{
    int len = strlen(infix);
    char *postfix = (char *)malloc(len + 1);
    stack s;
    s.top = -1;
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        else
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    char *postfix = infix_to_postfix(infix);
    printf("Postfix expression: %s\n", postfix);

    free(postfix);
    return 0;
}