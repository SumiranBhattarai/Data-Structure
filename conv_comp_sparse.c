#include<stdio.h>
int main()
{
    int comp[100][3],trans[3][100],i,j,nonzero;
    int sparse[0][0],srow,scol,sval;
    int choice;
    int maxrow=0,maxcol=0;
    printf("\nEnter the no of Non-Zero elements that will be in sparse matrix: ");
    scanf("%d",&nonzero);
    printf("\nFill the Compact Matrix:");
    for(i=0;i<nonzero;i++)
    {
        printf("\nNonzero no. %d",i+1);
        printf("\nEnter Sparse Matrix Row value and Column Value: ");
        scanf("%d%d",&comp[i][0],&comp[i][1]);
        printf("\nEnter Non-Zero Value: ");
        scanf("%d",&comp[i][2]);
    }
    printf("\n\n\n1.Convert the Entered Compact Matrix into Sparse Matrix Form");
    printf("\n2.Transpose the Entered Compact Matrix");
    printf("\n Enter the Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        for(i=0;i<nonzero;i++)
        {
            if(maxrow<comp[nonzero][0])
                maxrow=comp[nonzero][0];
            if(maxcol<comp[nonzero][1])
                maxcol=comp[nonzero][1];
        }
        int sparse[maxrow+1][maxcol+1];
        for(i=0;i<maxrow+1;i++)
        {
            for(j=0;j<maxcol+1;j++)
            {
                sparse[i][j]=0;
            }
        }
        for(i=0;i<nonzero;i++)
        {
            srow=comp[i][0];
            scol=comp[i][1];
            sval=comp[i][2];
            sparse[srow][scol]=sval;
        }
        break;
    case 2:
        printf("\n\nOriginal Form:");
        printf("\nRow\tColumn\tValue\n");
        for(i=0;i<nonzero;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",comp[i][j]);
            }
            printf("\n");
        }

        for(i=0;i<nonzero;i++)
        {
            for(j=0;j<3;j++)
            {
                trans[j][i]=comp[i][j];
            }
        }
        printf("\nTranspose Form:\n");
        for(i=0;i<3;i++)
        {
            if(i==0)
                printf("Row\t");
            if(i==1)
                printf("Column\t");
            if(i==2)
                printf("Value\t");
            for(j=0;j<nonzero;j++)
            {
                printf("%d\t",trans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
