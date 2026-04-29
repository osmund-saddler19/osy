#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int mutex = 1;
int empty = MAX;
int full = 0;

int queue[MAX];
int front = 0;
int rear = -1;
int itemcount = 0;
int buffer = 0;

bool isFull()
{
    return itemcount == MAX;
}

bool isEmpty()
{
    return itemcount == 0;
}

void insert_item(int data)
{
    if (!isFull())
    {
        if (rear == MAX - 1)
        {
            rear = -1;
        }
        queue[++rear] = data;
        itemcount++;
    }
}

int deleteData()
{
    if (!isEmpty())
    {
        int data = queue[front++];
        if (front == MAX)
        {
            front = 0;
        }
        itemcount--;
        return data;
    }
    return -1;   // 🔥 fix (safe return)
}

void producer()
{
    --mutex;
    --empty;

    insert_item(buffer + 1);   // 🔥 fixed function + value

    printf("Producer produces: %d\n", buffer + 1);

    ++full;
    ++buffer;
    ++mutex;

    printf("Count: %d\n", itemcount);
    printf("Buffer: %d\n", buffer);
    printf("Empty: %d\n", empty);
}

void consumer()
{
    --mutex;
    --full;

    int x = deleteData();

    printf("Consumer consumes: %d\n", x);   // 🔥 removed +1

    ++empty;
    --buffer;
    ++mutex;

    printf("Count: %d\n", itemcount);
    printf("Buffer Count: %d\n", buffer);
    printf("Empty Count: %d\n", empty);
}

int main()
{
    int n, i;
    printf("\n1.Press 1 for Producer");
    printf("\n2.Press 2 for Consumer");
    printf("\n3.Press 3 for Exit");

    for (i = 1; i > 0; i++)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full!\n");
            break;

        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty!\n");
            break;

        case 3:
            exit(0);
        }
    }
}
