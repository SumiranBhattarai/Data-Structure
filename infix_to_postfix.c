/*
step1: start
step2: Declare a character stack of size 30
step3: Initialize top=-1
step4: Write Push function
        if stack is not full then increment top, stack[top]=expression

step5: Write Pop function
        if stack is not empty then display expression, then decrement top

step6: write operatorPriority function
        if symbol = ^ return 3
        else if symbol = * or / return 2
        else if symbol = + or - return 1

step7: Write infix to postfix function
        for i=0 till i< length of expression
            if expression[i] = ( then push
            else if expression[i] is ^ or * or / or -
                if priority of stack[top] >= expression[i] then pop stack[top] and push expression[i]
                else push expression[i]
            else if expression[i] = ) then pop every elements till when stack[top]= (
            else display the operand

step8: for i=top till i>=0 pop stack[top]
step9: Enter expression
step10: convert the expression from infix to postfix
step11: stop
*/

#include<stdio.h>
#include<string.h>
#define SIZE 30
char stack[SIZE];
int top=-1;

int operatorPriority(char);
void push(char);
void pop();
int isEmpty();
int isFull();
int infx2pstfx();

int main()
{
    char exp[SIZE];
    int i;
    printf("\nEnter an Expression: ");
    gets(exp);
    printf("\nInfix Form: ");
    puts(exp);
    printf("\nPostfix Form: ");
    infx2pstfx(exp);
    return 0;
}

void push(char exp)
{
    if(isFull())
    {
        printf("\nStack is Full");
    }
    else
    {
        top++;
        stack[top]=exp;
        // printf("\n%c is pushed",exp);
    }
}

void pop()
{
    char del;
    if(isEmpty())
    {
        printf("\nStack is Empty");
    }
    else
    {
        del=stack[top];
        top--;
        if(del!=')'&&del!='(')
            printf("%c",del);
    }
}

int isFull()
{
    if(top==SIZE-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int operatorPriority(char opp)
{
    if(opp=='^')
        return 3;
    else if(opp=='*'||opp=='/')
        return 2;
    else if(opp=='+'||opp=='-')
        return 1;
}
int infx2pstfx(char exp[SIZE])
{
    int i;
    for(i=0; i<strlen(exp); i++)
    {
        if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]=='^'||exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-')
        {
            while((operatorPriority(exp[i])<=operatorPriority(stack[top]))
                    &&(stack[top]!='(')
                    &&(stack[top]!=-1))
            {
                pop(stack[top]);
                //push(exp[i]);
            }
            push(exp[i]);
            /*         else
                         {
                             push(exp[i]);
                         }
            */
        }
        else if(exp[i]==')')
        {
           // while(stack[top]!='('&&top!=-1)
            while(top!=-1)
            {
                if(stack[top]!='(')
                pop(stack[top]);
                else if(stack[top]=='(')
                {
                    pop(stack[top]);
                    break;
                }
            }
        }
        else
        {
            printf("%c",exp[i]);
        }
    }
    for(i=top; i>=0; i--)
    {
        pop(stack[top]);
    }
}
