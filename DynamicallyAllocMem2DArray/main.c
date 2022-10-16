#include <stdio.h>
#include <stdlib.h>

#define FAIL 1

void freeAllocatedMemory(int **piBuffer, int nRow)
{
    int iRow = 0;
    for (iRow =0; iRow < nRow; iRow++)
    {
        free(piBuffer[iRow]);
    }
    free(piBuffer);
}

int main(int argc, const char * argv[]) {

    int **piBuffer = NULL;
    int nRow = 0;
    int nColumn = 0;
    int iRow = 0;
    int iCol = 0;
    
    printf("\nEnter the number of Row = ");
    scanf("%d" ,&nColumn);
    
    piBuffer = (int **)malloc(nRow * sizeof(int*));
    if(piBuffer == NULL)
    {
        return FAIL;
    }

    for (iRow = 0; iRow < nRow; iRow++)
    {
        piBuffer[iRow] = (int *)malloc(nColumn * sizeof(int));
        if(piBuffer[iRow] == NULL)
        {
            freeAllocatedMemory(piBuffer, iRow);
            return FAIL;
        }
    }
    
    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol=0; iCol < nColumn; iCol++)
        {
            printf("\npiBuffer[%d][%d] = %d\n", iRow, iCol, piBuffer[iRow][iCol]);
        }
    }
                   freeAllocatedMemory(piBuffer,nRow);
                   
    return 0;
}
