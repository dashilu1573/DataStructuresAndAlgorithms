//
// Created by 芦yafei  on 18/7/30.
// 栈又称堆栈，它是一种运算受限的线性表，其限制是仅允许在表的一端进行插入和删除运算。
// 参考https://blog.csdn.net/wtfmonking/article/details/16989159
//

#ifndef DATASTRUCTURESANDALGORITHMS_STACK_H
#define DATASTRUCTURESANDALGORITHMS_STACK_H

typedef int ElemType;  //定义元素类型

struct StackSq         //定义栈结构类型
{
    ElemType *stack;   //指向存储栈的的数组空间
    int top;           //存栈顶元素的下标位置
    int MaxSize;       //存stack数组长度
};


//1、初始化栈S为空
void InitStack(struct StackSq* S, int ms)
{
    if (ms < 0) {
        printf("MaxSize的值非法！\n");
        exit(1);
    }

    S->MaxSize = ms;
    S->top = -1;    //表示栈为空

    S->stack = malloc(sizeof(ElemType) * ms);

    if (!S->stack) {
        printf("动态存储分配失败！\n");
        exit(1);
    }
}



//2、新元素进栈，即把它插入到栈顶
void Push(struct StackSq* S, ElemType x)
{
    S->top++;
    S->stack[S->top] = x;
}


//3、删除栈顶元素并返回值
ElemType Pop(struct StackSq* S)
{
    if (S->top == -1) {
        printf("栈空，无元素出栈！\n");
        exit(1);
    }

    S->top--;
    return S->stack[S->top + 1];
}

#endif //DATASTRUCTURESANDALGORITHMS_STACK_H
