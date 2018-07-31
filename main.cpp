#include <iostream>
#include "Sort.h"
#include "Str.h"

// 产生随机列表
void GenerateArray(int arr[], int n)
{
    int i;
    srand((unsigned)time(0));

    for(i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}


// 打印列表
void PrintArray1(int arr[], int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
        printf("%6d, ", arr[i]);
    printf("\n");
}


int main() {

    int array[10] = {3, 1, 5, 8, 9, 2, 4, 6, 7, 0};
    char s[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};

    // 数组操作
    PrintArray(array, 10);
    //BubbleSort(array, 10);
    QuickSort(array, 0, 9);
    //heapSort(array,10);
    PrintArray1(array, 10);

    // 字符串操作
    //int index = substr(s,"efg");
    //printf("%d", index);
    //printf(s);
    //printf("\n");
    //reverse(s);
    //printf(s);

    return 0;
}