/*4. Implement linear search algorithm to find the nth occurence of the given element. If nth occurrence is
not found, return -1.
*/

#include<stdio.h>
#define SIZE 7

int count=0;
//int  lastindex=-1;
int linear_serach(int arr[SIZE],int key,int n);

int main()
{
    int arr[SIZE]={11,22,11,33,44,11,44};

    int key,n;
    printf("Enter the key from user:");
    scanf("%d",&key);

    printf("Enter which occurence(n): ");
    scanf("%d",&n);

    int i=linear_serach(arr,key,n);
    if(count==0)
    {
        printf("key not found\n");
    }

    else
    {
        printf("key found at indexes %d times\n ",count);
        if(i == -1)
        {
             printf("%d nth occurence %d not found\n",n,key);
        }
        else
        {
            printf("%d nth occurence %d found\n",n,key);
        }
    }
}

int linear_serach(int arr[SIZE],int key,int n)
{
    
    for(int i=0;i<SIZE;i++)
    {
        if(arr[i]==key)
        {
            
            count++;
            //lastindex = i;
            printf("key found indexes are %d\n",i);

            if(count==n)
                return i;   //nth occurenece found
        }
    }
    return -1;
}