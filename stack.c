#include <stdio.h>
#include <stdlib.h>
#define max 4
int arr[max],top=-1;

void push( int val)
{
    if(top==max-1)
    printf("full");
    else{
       arr[++top]=val;
    }
}
void pop(){
    if(top==-1)
    printf("empty");
    else{
        printf("element deleted is%d",arr[top--]);

    }
}
void show(){
    int i;
    for(i=0;i<=top;i++){
        printf("%d", arr[i]);
    }
}
int main()
{
    int choice,val;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter value\n");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}
