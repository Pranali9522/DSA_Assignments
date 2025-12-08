//1.Write a linear search algorithm to return 
//index of last occurance of key.

#include<stdio.h>
#define SIZE 7

int count=0;
int  lastindex=-1;
int linear_serach(int arr[SIZE],int key);

int main()
{
    int arr[SIZE]={11,22,11,33,44,11,44};

    int key;
    printf("Enter the key from user:");
    scanf("%d",&key);

    int i=linear_serach(arr,key);
    if(count==0)
    {
        printf("key not found\n");
    }

    else
    {
        printf("key found at indexes %d times\n ",count);
        printf("last occurence=%d\n",lastindex);
    }
}

int linear_serach(int arr[SIZE],int key)
{
    
    for(int i=0;i<SIZE;i++)
    {
        if(arr[i]==key)
        {
            
            count++;
            lastindex = i;
            printf("key found indexes are %d\n",i);
        }
    }
    return -1;
}