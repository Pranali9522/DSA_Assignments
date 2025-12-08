//5.find the first non-repeating element: Input: { 1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8 } Ouput: 3

#include<stdio.h>
#define SIZE 11

int main()
{
    int arr[SIZE] ={1,2,3,-1,2,1,0,4,-1,7,8};
    int i,j,isuninque;
    int found=0;

    for(i=0; i<SIZE; i++)
    {
        isuninque = 1;

        for(j=0; j<SIZE; j++)
        {
            if(i!=j && arr[i] == arr[j])
            {
                isuninque=0;
                break;
                
            }
        }
    

    if(isuninque)
    {
        printf("First non-repeating element = %d\n",arr[i]);
        return 0;
    }
    /* all non repeating elements prints
    if(isuninque == 1)
    {
       printf("non-repeating elements = %d\n",arr[i]);
         found =1;
    }
         */

    }
    if(found == 0)
    {
        printf("No non-repeating element found\n");
    }
    return 0;
}