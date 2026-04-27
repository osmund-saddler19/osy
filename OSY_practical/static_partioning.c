#include<stdio.h>
void main()
{
    int i,n,s[5],c=1,d[5];
    printf("Enter no. of processes\n");
    scanf("%d",&n);

    if(n<=5)
    {
        printf("Enter size of each process\n");
        for (i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            if(s[i]<=4)
            {
                printf("Process[%d] allocated to block %d\n",i+1,c);
                printf("Bytes remaining: %d\n",4-s[i]);
                d[c-1]=c;
                c++;
            }
            else
            printf("Process can't be allocated\n");
        }
         printf("\nProcesses completed:\n");
        for(i=0;i<c-1;i++)
            printf("Process[%d]\n",d[i]);
    }
    else
        printf("Enter processes less than 5");

}
