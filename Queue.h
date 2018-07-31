//
// Created by 芦yafei  on 18/7/30.
// 队列是一种运算受限的线性表，其限制是仅允许在表的一端进行插入（队尾），在表的另一端进行删除（队首）。
// 参考https://blog.csdn.net/wtfmonking/article/details/16989159
//

#ifndef DATASTRUCTURESANDALGORITHMS_QUEUE_H
#define DATASTRUCTURESANDALGORITHMS_QUEUE_H

typedef int ElemType;  //定义元素类型

struct QueueSq
{
    ElemType *queue;   //指向存储队列的数组空间
    int front, rear;   //存队首、队尾下标位置
    int MaxSize;       //存储queue数组长度
};


//1、初始队列Q为空
void InitQueue(struct QueueSq* Q, int ms)
{
    if (ms < 0) {
        printf("MaxSize的值非法！\n");
        exit(1);
    }

    Q->MaxSize = ms;
    Q->front = 0;
    Q->rear = 0;

    Q->queue = malloc(sizeof(ElemType) * ms);

    if (!Q->stack) {
        printf("动态存储分配失败！\n");
        exit(1);
    }
}


//2、向队列插入元素
void EnQueue(struct QueueSq* Q, int x)
{
    Q->queue[Q->rear] = x;
    Q->rear = (Q->rear + 1) % Q->MaxSize;   //队尾指针后移一个位置
}


//3、从队列中删除元素并返回
ElemType OutQueue(struct QueueSq* Q)
{
    if (Q->front == Q->rear)
    {
        printf("队列已空，无法删除！\n");
        exit(1);
    }

    ElemType t = Q->queue[Q->front];
    Q->front = (Q->front + 1) % Q->MaxSize;
    return t;
}

#endif //DATASTRUCTURESANDALGORITHMS_QUEUE_H
