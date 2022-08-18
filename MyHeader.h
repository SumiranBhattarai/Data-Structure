void insert(int a[],int num,int pos)
{
    a[pos-1]=num;
}

void delete(int a[],int pos)
{
    a[pos-1]=0;
}

int search(int a[],int num,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]==num)
            return i+1;
    }
    return -1;
}
void reverse(int a[],int size)
{
    int rear,front,temp;
    rear=size-1;
    front=0;
    while(rear>front)
    {
        temp=a[rear];
        a[rear]=a[front];
        a[front]=temp;
        front++;
        rear--;
    }
}
void endzero(int a[],int size)
{
    int rear,front,temp;
    rear=size-1;
    front=0;
    while(rear>front)
    {	 	  	   	   	  		  	 	
        if(a[front]==0&&a[rear]!=0)
        {
            temp=a[rear];
            a[rear]=a[front];
            a[front]=temp;
            front++;
            rear--;
        }
        if(a[front]==0&&a[rear]==0)
        {
            rear--;
        }
        if(a[front]!=0)
        {
            front++;
        }
    }
}
