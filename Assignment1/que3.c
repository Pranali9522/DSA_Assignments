//3.implement binary search algorithm if array is sorted in descending order.

#include<stdio.h>
#define SIZE 10

int binary_search(int arr[SIZE],int key);

int main()
{
    int arr[SIZE]={100,90,80,70,60,50,40,30,20,10};

    int key;
    printf("Enter key from user:");
    scanf("%d",&key);

    int i=binary_search(arr,key);
    if(i==-1)
    {
        printf("key not found\n");
    }
    else
    {
        printf("key found at index %d\n",i);
    }

    return 0;
}

int binary_search(int arr[SIZE],int key)
{
    int left=0,right=SIZE-1,mid;
    
    while(left <= right)
    {
        mid = (left + right)/2;

        if(key == arr[mid])
            return mid;

        else if(key< arr[mid])
        {
            //continue to right sub array
            left= mid+1;
        }
        else
        {
            //continue to left sub array
            right = mid-1;
        }

    }
    return -1;  //key not found
}