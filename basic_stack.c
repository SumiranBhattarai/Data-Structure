/*
step1: start
step2: Declare an integer stack of size 5
step3: Initialize top=-1
step4: Write isFull function
            if top= size - 1 then return 1
                else return 0

step5: Write Push function
        if stack isFull then Display Stack is Full
            else increment top, stack[top]=expression

step6: Write isEmpty function
            if top= -1 then return 1
                else return 0

step7: Write Pop function
        if stack isEmpty then display stack is empty
            else display stack[top], then decrement top

step8: Write peek function
        if stack isEmpty then display stack is empty
            else display stack[top]

step9: initialize q=1 to run the while loop
step10: while q!=0 then run loop
            Display 1.push, 2.Pop, 3.peek, 4.quit

step11: Enter choice
step12: switch(choice)
            case 1 push()
            case 2 pop()
            case 3 peek()
            case 4 q=0
step13: Repeat from step 9 untill the value of q becomes 0
step14: stop
*/
#include<stdio.h>
#define SIZE 5
//Stack and Top made global
int stack[SIZE],top=-1;

//Function Declarations
int isFull();
int isEmpty();
void push();
void pop();
void peek();

int main()
{
	int choice, i, size, ele,q=1;
	while(q!=0){
		printf("\n\nEnter Choice");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Quit\n-->");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1: push(ele);
				break;
			case 2: pop();
				break;
			case 3: peek();
				break;
            case 4: q=0;
                break;
			default: printf("!!!---Invalid choice---!!!");
		}
	}
return 0;
}

void push ()
{
    int ele;
	if(isFull())
		printf("Stack is full!");
	else // stack is not full
		{
		printf("\nEnter an Element: ");
        scanf("%d",&ele);
        top++;
		stack[top]=ele;
		printf("%d is pushed into the stacks", ele);
		}
}

int isFull()
{
	if(top == SIZE-1)
		return 1;
	else
		return 0;
}
void pop()
{
	 int ele;
	if (isEmpty())
		printf("The stack is Empty");
	else
        {
		ele = stack[top];
		top--;
		printf("\n%d popped out of the stack",ele);
		};
}
int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

void peek()// displays only the top element of your stack
{
	if(isEmpty())
		printf("\nThe stack is Empty");
	else
        {
		printf("\nThe top of the stack is %d",stack[top]);
        }
}
