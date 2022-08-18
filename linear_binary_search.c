// Write Linear Search and Binary Search ALgorithm
/*
1: Start
2: Declare array arr[] and other integer variables i,n,num and srch
3: Enter size n
4: for(i = 0; i<n ;i++ ) enter the elements into the array arr[i]
5: Enter num
6: Enter and select 1.Linear Search 2.Binary Search
    case 1: for(i =0; i<n; i++) if arr[i] == num print the index
    case 2: Initialize variable low=0 and high= n - 1
            while(low<=high) initialize mid = (low+high)/2
            if arr[mid]= num then print the index
            if arr[mid]<num set low as mid+1
            else set high as mid-1
*/


// Write Program to implement the above two
#include<stdio.h>
void linearSearch(int a[],int num,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            printf("%d is located at index %d",num,i+1);
        }
    }
}
void binarySearch(int a[],int num,int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high){
        mid = (low + high)/2;
        if(a[mid] == num){	 	  	   	   	  		  	 	
            printf("\n%d is located at index %d",num,mid+1);
        }
        if(a[mid]<num){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
}

void main()
{
    int arr[100], n, num, srch, i;
    printf("\nEnter array size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the number to search: ");
    scanf("%d",&num);
    printf("\nEnter the search method: \n1.Linear Search\n2.Binary Search: ");
    scanf("%d",&srch);
    switch(srch)
    {
        case 1:linearSearch(arr,num,n);
        break;
        case 2:binarySearch(arr,num,n);
        break;
        default:printf("\nYou have entered the incorrect choice");
    }
}	 	  	   	   	  		  	 	
