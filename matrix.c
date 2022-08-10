#include <stdio.h>

/* To take input of two matrices and perform various matrix operations */

void init(int mat1[100][100], int ordx,int ordy);
void add(int mat1[100][100], int mat2[100][100],int mat3[100][100],int ordx,int ordy);
void sub(int mat1[100][100], int mat2[100][100],int mat3[100][100],int ordx,int ordy);
void mult(int mat1[100][100], int mat2[100][100],int mat3[100][100],int ord1x,int ord1y,int ord2x,int ord2y);
void disp(int mat3[100][100], int ordx, int ordy);

int main()
{
    int ord1x, ord2x, ord1y, ord2y, ord3x, ord3y;
    int choice;
    int mat1[100][100];
    int mat2[100][100];
    int mat3[100][100];

    printf("Enter the order of the first matrix: \n");
    scanf("%d %d",&ord1x, &ord1y);
    printf("Enter the order of the second matrix: \n");
    scanf("%d",&ord2x, &ord2y);

    printf("Enter the details of the first matrix: ");
    init(mat1,ord1x,ord1y);
    printf("Enter the details of the second matrix: ");
    init(mat2,ord2x,ord2y);

    printf("Choose the operations you want to perform: \n");
    printf("1.Add \n2.Subtract \n3.Multiply \n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            if((ord1x == ord2x) && (ord1y == ord2y))
            {
                add(mat1,mat2,mat3,ord1x,ord1y);
                ord3x = ord1x; ord3y = ord1y;
            } 
            else 
                printf("Not compatible for addition.\n");
            break;
        }
        case 2:
        {
            if((ord1x == ord2x) && (ord1y == ord2y)) 
            {
                sub(mat1,mat2,mat3,ord1x,ord1y);
                ord3x = ord1x; ord3y = ord1y;
            }  
            else 
                printf("Not compatible for subtraction.\n");
            break;
        } 
        case 3:
        {
            if(ord1y == ord2x)
            {
                mult(mat1,mat2,mat3,ord1x,ord1y,ord2x,ord2y);
                ord3x = ord1x; ord3y = ord2y;
            }
            else
                printf("Not compatible for multiplication.\n");
            break;
        } 
    }

    printf("The resultant matrix is: \n");
    disp(mat3,ord3x,ord3y);
}

void init(int mat[100][100], int ordx , int ordy)
{
    for(int i = 0; i < ordx; i++)
    {
        for(int j = 0; j < ordy; j++)
        {
            printf("\nEnter the [%d][%d] element: ",i,j);
            scanf("%d",&(mat[i][j]));
        }
    } 
}

void add(int mat1[100][100], int mat2[100][100],int mat3[100][100],int ordx,int ordy)
{
    for(int i = 0; i < ordx; i++)
    {
        for(int j = 0; j < ordy; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void sub(int mat1[100][100], int mat2[100][100],int mat3[100][100],int ordx,int ordy)
{
    for(int i = 0; i < ordx; i++)
    {
        for(int j = 0; j < ordy; j++)
        {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void mult(int mat1[100][100], int mat2[100][100],int mat3[100][100],int ord1x,int ord1y,int ord2x,int ord2y)
{
    for(int i = 0; i< ord1x ;i++)
    {

        for(int j = 0; j < ord2y; j++)
        {
            int sum = 0;
            for(int x = 0; x < ord1y; x++)
            {
                sum = sum + (mat1[i][x] * mat2[x][j]);
            }
            mat3[i][j] = sum;
        }
        
    }
}

void disp(int mat3[100][100],int ordx,int ordy)
{
    for(int i = 0; i < ordx; i++)
    {
        printf("\n");
        for(int j = 0; j < ordy; j++)
        {
            printf("%d", mat3[i][j]);
        }
    }
}