
#include<stdio.h>
void main()
{
    int a,n,i;
    printf("Enter memory size\n");
    scanf("%d",&a);
    printf("Enter no. of processes\n");
    scanf("%d",&n);
    int size[n];
    for(i=0;i<n;i++)
    {
        printf("Enter size of process %d:  ",i+1);
        scanf("%d",&size[i]);
    }
     printf("\n");
    for(i=0;i<n;i++)
    {
        if(size[i]<=a)
        {
            printf("Process %d occupied: %d\n",i+1,size[i]);
            a=a-size[i];
            printf("Bytes remaining: %d \n\n",a);
        }
        else
        {
            printf("Insufficient memory\n\n");
        }
    }
}
