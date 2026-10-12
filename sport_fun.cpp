#include "head.h"

SqQueue InitQueue_Sq(int size)
{
    SqQueue Q;
    Q = (SqQueue)malloc(sizeof(*Q));
    if (!Q) exit(-1);
    Q->base = (ElemType*)calloc(size, sizeof(ElemType));
    if (!Q->base) exit(-1);
    Q->front = Q->rear = 0;
    Q->size = size;
    return Q;
}


bool EnQueue_Sq(SqQueue Q, ElemType e)
{
    if (!Q || (Q->rear + 1) % Q->size == Q->front)
    {
        return false;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % Q->size;
    return true;
}

bool DeQueue_Sq(SqQueue Q, ElemType& e)
{
    if (!Q || QueueEmpty(Q))
    {
        return false;
    }
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % Q->size;
    return true;
}

bool QueueEmpty(SqQueue Q)
{
    return Q->front == Q->rear;
}

void DestroyQueue(SqQueue Q)
{
    free(Q->base);
    free(Q);
}

void division(int R[][10], int n, int result[])
{
    int group = 0;
    int pre = n - 1;

    SqQueue Q = InitQueue_Sq(10);
    int clash[10];

    for (int k = 0; k < n; k++)
    {
        EnQueue_Sq(Q, k);
    }

    while (!QueueEmpty(Q))
    {
        int i;
        DeQueue_Sq(Q, i);

        if (i <= pre)
        {
            group++;
            for (int j = 0; j < n; j++)
            {
                clash[j] = 0;
            }
        }

        if (clash[i] == 0) 
        {
            result[i] = group;
            for (int j = 0; j < n; j++)
            {
                if (R[i][j] == 1)
                {
                    clash[j]++;
                }
            }
        }
        else
        {
            EnQueue_Sq(Q, i);
        }
        pre = i;
    }

    DestroyQueue(Q);
}

void printResult(int n, int result[])
{
    cout << "item number  : ";
    for (int i = 0; i < n; i++)
    {
        cout << i << "  ";
    }
    cout << endl;

    cout << "group number : ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "  ";
    }
    cout << endl;
}