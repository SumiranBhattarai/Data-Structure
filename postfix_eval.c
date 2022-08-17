// Write algorithm

/*
step1 Start
step2 Declare a stack of size 50
step3 Declare int top=-1 and ch;
step4 Write push function to insert element in stacks
step5 write pop function to delete element from stacks
step6 write display function to print the elements in stacks
step7 enter postfix
step8 for i=0 till i<= length of postfix, increment i
        element = postfix[i]
        if element is a digit then push the element
        else pop 2 elements, check the operator and perform operations, and push the result
        display stacks
        display result
step9 stop

*/

// Write source code

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 50
int s[SIZE];
int top=-1;
int ch;

void push(int);
int pop();
void display();

void push(int x)
{	 	  	   	   	  		  	 	
    s[++top] = x;
}

int pop()
{
    return s[top--];
}


void display()
{
	int i;
	printf("\n Stack: ");
	for(i=0;i<=top;i++)
	{
		printf(" | %d",s[i]);
	}
}
int main()
{
	char postfix[SIZE],ele;
	int i,n1,n2,res;
	printf("\nEnter postfix Expression: ");
	gets(postfix);
	printf("\n Postfix Expression: ");
	puts(postfix);
	for(i=0;i<=strlen(postfix);i++)
	{
		ele=postfix[i];
		if(isdigit(ele))
		{
			push(ele-'0');
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(ele)
			{	 	  	   	   	  		  	 	
				case '^': res= pow(n2,n1);
				break;
				case '/': res= n2/n1;
				break;
				case '*': res= n2*n1;
				break;
				case '+': res= n2+n1;
				break;
				case '-': res= n2-n1;
				break;
			}
			push(res);
		}
		display();
	}
	printf("\n Answer = %d",pop());
	return 0;
}

