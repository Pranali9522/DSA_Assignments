/*2.Create array of employees and search employee by
empid
name
*/

#include<stdio.h>
#include<string.h>
#define SIZE 5

typedef struct employee{
    int empid;
    char name[30];
    int salary;
}emp_t;

int searchById(emp_t emp[],int size,int key);
int searchByName(emp_t emp[],int size,char key[]);

int main()
{
    emp_t emp[SIZE] = {
        {101, "PRANALI", 60000},
        {102, "TRUPTI", 50000},
        {103, "AISH", 40000},
        {104, "PANA", 55000},
        {105, "APT",100000}

    };

    int choice;
    printf("1.Search by Employee ID\n");
    printf("2.Search by Employee Name\n");

    printf("Enter choice:");
    scanf("%d",&choice);

    if(choice == 1)
    {
        int key;
        printf("Enter Employee ID to search:");
        scanf("%d",&key);

        int index = searchById(emp,SIZE,key);
        if(index==-1)
        {
            printf("key not found\n");
        }
        else
        {
            printf("Employee found...\n");
            printf("Employee ID:%d\n",emp[index].empid);
            printf("Employee Name:%s\n",emp[index].name);
            printf("Employee Salary:%d\n",emp[index].salary);
        }

    }

    else if(choice==2)
    {
        char key[30];
        printf("Enter Employee Name to search:");
        scanf("%s",key);

        int index = searchByName(emp,SIZE,key);
        if(index==-1)
        {
            printf("Employee name not found\n");
        }
        else
        {
            printf("Employee found...\n");
            printf("Employee ID:%d\n",emp[index].empid);
            printf("Employee Name:%s\n",emp[index].name);
            printf("Employee Salary:%d\n",emp[index].salary);
        }
    }

    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}

int searchById(emp_t emp[],int size,int key)
{
    for(int i=0;i<SIZE;i++)
    {
        if(emp[i].empid == key)
        {
            return i;
        }

    }
    return -1;
}

int searchByName(emp_t emp[],int size,char key[])
{
    for(int i=0;i<SIZE;i++)
    {
        if(strcmp(emp[i].name,key)==0)
        {
            return i;
        }

    }
    return -1;
}