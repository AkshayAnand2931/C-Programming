#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void inf_to_pre(char prefix[MAX],char infix[MAX] ,int size);
int evaluate_pre(char prefix[MAX], int size);
int prec(char top, char curr);

int main()
{
    char infix[MAX], prefix[MAX];
    int size;

    scanf("%d",&size);
    scanf("%s",infix);

    inf_to_pre(prefix,infix,size);
    int result = evaluate_pre(prefix,strlen(prefix));

    printf("%s %d\n",prefix,result);
    return 0;
}

int evaluate_pre(char prefix[MAX], int size)
{
    if(size == 0) return 0;
    int oprstack[MAX];
    int top = -1;
    for(int i = size - 1; i >-1 ; i--)
    {
        char ch = prefix[i];
        if(ch>='0' && ch<='9')
        {   
            oprstack[++top] = ch-'0';
        }
        else
        {   
            int opr1 = oprstack[top--];
            int opr2 = oprstack[top--];
            int res;
            switch(ch)
            {
                case '^':
                {
                    res = 1;
                    for(;opr2 != 0; opr2--)
                    {
                        res = res * opr1;
                    }
                    oprstack[++top] = res;
                    break;
                }
                case '*':
                {
                    res = opr1 * opr2;
                    oprstack[++top] = res;
                    break;
                }
                case '/':
                {
                    res = opr1/opr2;
                    oprstack[++top] = res;
                    break;
                }
                case '+':
                {
                    res = opr1 + opr2;
                    oprstack[++top] = res;
                    break;
                }
                case '-':
                {
                    res = opr1 - opr2;
                    oprstack[++top] = res;
                    break;
                }
            }
        }
    }
    return oprstack[top--];
}

void inf_to_pre(char prefix[MAX],char infix[MAX] ,int size)
{
    char stack[MAX];
    int top = -1;
    int j = 0;
    char postfix[MAX];
    char ch;
    for(int i = size - 1; i>-1 ; i--)
    {
        ch = infix[i];
        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else
        {
            while(top != -1 && prec(stack[top],ch))
            {
                postfix[j++] = stack[top--];
            }
            if(ch == '(')
            {
                top--;
            }
            else
            {
                stack[++top] = ch;
            }
        }

    }
    while(top != -1)
    {
        postfix[j++] = stack[top--];
    }
    int l,k;
    for(k = (strlen(postfix) - 1),l = 0; k > -1 ; k--,l++)
    {
        prefix[l] = postfix[k];
    }
    prefix[l] = '\0';
}

int prec(char top, char curr)
{
    switch(curr)
    {
        case ')':
        {
            return 0;
        }
        case '(':
        {
            if(top==')') return 0;
            return 1;
        }
        case '^':
        {
            if(top == '^') return 1;
            return 0;
        }
        case '*':
        case '/':
        {
            if(top == '^') return 1;
            return 0;
        }
        case '+':
        case '-':
        {
            if(top == '^' || top == '*' || top == '/') return 1;
            return 0;
        }
    }
}