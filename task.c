#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <limits.h>


int main()
{
    
      int n=4, m=4, a=0, b=1;
    do { 
        printf("Enter (Input) n>3\n");
        scanf("%d", &n);
    } while (n<=3);
    
    do {
        printf("Enter (Input) m>3\n");
        scanf("%d", &m);
    } while (m<=3);
    
 
    printf("Enter (Input) a \n");
    scanf("%d", &a);
    
    do {
        printf("Enter (Input) b>a \n");
        scanf("%d",&b);
    } while(b<=a);
    
    srand(time(0));
    
    int lowerNum=a;
    int upperNum=b;
    int rows=n;
    int cols=m;
 
    long currentMultpValue = LONG_MIN;
    long maxMultpValue = LONG_MIN; 
    int matrix[rows][cols];
    
    // запълване на матрицата с данни
    for (int r = 0;  r < rows;  r++)
    {
        for(int c = 0; c<cols; c++)
        {
            int num = (rand() % (upperNum - lowerNum + 1)) + lowerNum; 
              matrix[r][c]=num;
        }
    }
    
    // изпечатване на въведената матрица
    for (int r = 0;  r < rows;  r++)
    {
        for(int c = 0; c < cols; c++)
        {
	        printf("%d ", matrix[r][c]);
        } 
        printf("\n");    
    }

    printf("\n");
    
    //setting initial values for indexes for maxMultpValue
    int rowForMaxValue=0;
    int colForMaxValue=0;
    int offsetType=0; //0 for rows, 1 for colums, 2 for diagLeftToRight, 3 for diagRightToLeft
    
    //iterating through rows
    
    for (int r = 0;  r < rows;  r++)
    {
        for(int c = 0; c<cols-3; c++)
        {
            currentMultpValue = matrix[r][c] * matrix[r][c+1] * matrix[r][c+2] * matrix[r][c+3];
            if(currentMultpValue > maxMultpValue ) {
               maxMultpValue =  currentMultpValue;
               rowForMaxValue = r;
               colForMaxValue = c;
               offsetType=0;
            } 
        }
    }
     
    //reset currentMultpValue to the lowet posible value for long
    currentMultpValue = LONG_MIN;
    
    //iterating through cols /  обхождане по колони
    
    for(int c = 0; c<cols; c++)
    {
        for (int r = 0;  r < rows-3;  r++)
        {
            currentMultpValue = matrix[r][c] * matrix[r+1][c] * matrix[r+2][c] * matrix[r+3][c]; 
            if(currentMultpValue > maxMultpValue ) {
               maxMultpValue =  currentMultpValue;
               rowForMaxValue = r;
               colForMaxValue = c;
               offsetType=1;
            }
        }
    }
 
    //reset currentMultpValue to the lowet posible value for long
    currentMultpValue = LONG_MIN;
    
    for (int r = 0;  r < rows-3;  r++)
    {
       for(int c = 0; c < cols-3; c++)
        {
            currentMultpValue = matrix[r][c] * matrix[r+1][c+1] * matrix[r+2][c+2] * matrix[r+3][c+3]; 
             if(currentMultpValue > maxMultpValue ) {
               maxMultpValue =  currentMultpValue;
               rowForMaxValue = r;
               colForMaxValue = c;
               offsetType=2;
            }
        }
    }
     
    //reset currentMultpValue to the lowet posible value for long 
    currentMultpValue = LONG_MIN;
    for (int r = 0;  r < rows - 3;  r++)
    {
        for(int c = cols -1; c >2; c--)
        {
           currentMultpValue = matrix[r][c] * matrix[r+1][c-1] * matrix[r+2][c-2]* matrix[r+3][c-3];
           
           if(currentMultpValue > maxMultpValue ) {
               maxMultpValue =  currentMultpValue;
               rowForMaxValue = r;
               colForMaxValue = c;
               offsetType=3;
            }  
        }
    }
     
    printf("Biggest multiplication value is: %ld. Numbers and their indexes are:", maxMultpValue);
    
    int r = rowForMaxValue;
    int c = colForMaxValue;

    switch(offsetType) 
    {
        case 0: {  
           printf("\n");
           printf("Number: %d, indexes [%d,%d] , ", matrix[r][c], r, c);
           printf("Number: %d, indexes [%d,%d] , ", matrix[r][c+1], r, c+1);
           printf("Number: %d, indexes [%d,%d] , ", matrix[r][c+2], r, c+2);
           printf("Number: %d, indexes [%d,%d] , ", matrix[r][c+3], r, c+3); 
           printf("\n");
           printf("Their location is at Rows");
           break;
        }
        case 1:
        {
           printf("\n");
           printf("Number: %d, indexes [%d,%d] , ", matrix[r][c] , r, c );
           printf("Number: %d, indexes [%d,%d] , ", matrix[r+1][c], r+1, c);
           printf("Number: %d, indexes [%d,%d] , ", matrix[r+2][c], r+2, c);
           printf("Number: %d, indexes [%d,%d] , ", matrix[r+3][c], r+3, c);
           printf("\n");
           printf("Their location is at Columns");
           break;
        }
        case 2:
        {
            printf("\n");
            printf("Number: %d, indexes [%d,%d] , ", matrix[r][c], r, c  );
            printf("Number: %d, indexes [%d,%d] , ", matrix[r+1][c+1], r+1, c+1);
            printf("Number: %d, indexes [%d,%d] , ", matrix[r+2][c+2], r+2, c+2);
            printf("Number: %d, indexes [%d,%d] , ", matrix[r+3][c+3], r+3, c+3);  
            printf("\n");
            printf("Their location is at DiagonalLeftToRight");
            break;
        }
        case 3:
        {
            printf("\n");
            printf("Number: %d, indexes [%d,%d] , ", matrix[r][c], r, c );
            printf("Number: %d, indexes [%d,%d] , ", matrix[r+1][c-1], r+1, c-1);
            printf("Number: %d, indexes [%d,%d] , ", matrix[r+2][c-2], r+2, c-2);
            printf("Number: %d, indexes [%d,%d] , ", matrix[r+3][c-3], r+3, c-3);
            printf("\n");
            printf("Their location is at DiagonalRightToLeft");
            break;
        }  
    }

    return 0;
}
