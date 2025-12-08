/*6. to find rank of an element in a stream of integers. rank: rank of a given integer "x", in stream is "total
no. of ele's less than or equal to x (including x).
Input: { 10, 20, 15, 3, 4, 4, 1 }
Ouput: Rank of 4 is: 4*/

#include<stdio.h>
#define SIZE 7

int main()
{
    int x;
    int arr[SIZE]={10,20,15,3,4,4,1};
    //int x=4;
    int rank=0;

    printf("Enter the element which have to calculate the element: ");
    scanf("%d",&x);
    
    for(int i=0;i<SIZE;i++)
    {
        if(arr[i] <= x)
        rank++;
    }

    printf("Rank of %d is %d\n",x,rank);

    return 0;
}