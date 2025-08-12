#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

typedef struct stack
{
	char arr[MAX];
	int top;
}stack;

void push(stack *s,char ch)
{
	if(s->top<MAX-1)
	{
		s->arr[++(s->top)]=ch;
	}
}

char pop(stack *s)
{
	if(s->top!=-1)
	{
		return(s->arr[(s->top)--]);
	}
	return -1;
}

char peek(stack *s)
{
	if(s->top!=-1)
	{
		return(s->arr[s->top]);
	}
	return -1;
}

int isEmpty(stack *s)
{
	return (s->top==-1);
}

int precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
	}
}

char *infix_to_postfix(char *infix)
{
	int len=strlen(infix);
	char *post=(char *)malloc(sizeof(char)*(len+1));
	stack s;
	s.top=-1;
	int i,j=0;
	char x;
	for(i=0;i<len;i++)
	{
		if(isalnum(infix[i]))
		{
			post[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			push(&s,infix[i]);
		}
		else if(infix[i]==')')
		{
			while(!isEmpty(&s)&&(x=pop(&s))!='(')
			{
				post[j++]=x;
			}
		}
		else
		{
			while(!isEmpty(&s)&&precedence(peek(&s))>=precedence(infix[i]))
			{
				post[j++]=pop(&s);
			}
			push(&s,infix[i]);
		}
	}
	while(!isEmpty(&s))
	{
		post[j++]=pop(&s);
	}
	post[j]='\0';
	return post;
}
int evaluate_postfix(char *expr)
{
	stack s;
	s.top=-1;
	int i;
	for(i=0;expr[i]!='\0';i++)
	{
		if(isdigit(expr[i]))
		{
			push(&s,expr[i]-'0');
		}
		else
		{
			int op1=pop(&s);
			int op2=pop(&s);
			switch(expr[i])
			{
				case '+':
					push(&s,op2+op1);
					break;
				case '-':
					push(&s,op2-op1);
					break;
				case '*':
					push(&s,op2*op1);
					break;
				case '/':
					push(&s,op2/op1);
			}
		}
	}
	return (pop(&s));
}
int main()
{
	char infix[MAX];
	printf("Enter in infix expression:");
	scanf("%s",infix);
	char *postfix=infix_to_postfix(infix);
	printf("postfix expression: %s\n",postfix);
	int result=evaluate_postfix(postfix);
	printf("Result= %d",result);
	return 0;
}