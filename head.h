#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType* base;
    int front;
    int rear;
    int size;
} *SqQueue;

SqQueue InitQueue_Sq(int size);
bool EnQueue_Sq(SqQueue Q, ElemType e);
bool DeQueue_Sq(SqQueue Q, ElemType& e);
bool QueueEmpty(SqQueue Q);
void DestroyQueue(SqQueue Q);

void division(int R[][10], int n, int result[]);
void printResult(int n, int result[]);