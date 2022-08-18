/*
Step1: Start
Step2: Create an header file containing functions to:
        insert an element in the array
        delete an element from the array
        search an element in the array
        reverse the array elements
        move the zeros to the end of the array
step3: Enter the size of the array
step4: Enter the elements in the array
step5: Enter the choice
        case 1:insert an element in the array and display
        case 2:delete an element from the array and display
        case 3:search an element in the array and display
        case 4:reverse the array elements and display
        case 5:move the zeros to the end of the array and display
case6: Stop
*/

#include<stdio.h>
#include "myheader.h"
void main()
{
    int choice,pos,a[100],size,i,num,res;
    printf("\nEnter Array Size: ");
    scanf("%d",&size);
    printf("\nEnter Array Elements:\n");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("\nChoose the required operation on the array:\n1.Insert an Element at a given index\n2.Delete an Element from a given index");
    printf("\n3.Search an element\n4.Reverse the array\n5.Move all the zeros at the end of the array\nEnter your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\nEnter the position: ");
        scanf("%d",&pos);
        if(pos>size)
            {	 	  	   	   	  		  	 	
                printf("\nWrong Position specified");
                break;
            }
        printf("\nEnter the element: ");
        scanf("%d",&num);
        insert(a,num,pos);
        printf("\nElement successfully inserted:\n");
        for(i=0;i<size;i++)
            printf("\t%d",a[i]);
        break;
    case 2:
        printf("\nEnter the position: ");
        scanf("%d",&pos);
        if(pos>size)
            {
                printf("\nWrong Position specified");
                break;
            }
        delete(a,pos);
        printf("\nElement successfully deleted:\n");
        for(i=0;i<size;i++)
            printf("\t%d",a[i]);
        break;
    case 3:
        printf("\nEnter the element to search: ");
        scanf("%d",&num);
        res=search(a,num,size);
        if(res!=-1)
            printf("\nElement %d found in location %d",num,res);
        else
            printf("\nElement %d cannot be found",num);
        break;
    case 4:
        printf("\nReversed Array: ");
        reverse(a,size);
        for(i=0;i<size;i++)
            printf("\t%d",a[i]);
        break;
    case 5:
        printf("\nFinal Array: ");
        endzero(a,size);
        for(i=0;i<size;i++)
            printf("\t%d",a[i]);
        break;
    default:printf("\nPlease select the appropriate choice: ");
    }	 	  	   	   	  		  	 	
}