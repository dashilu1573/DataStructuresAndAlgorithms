//
// Created by 芦yafei  on 18/7/17.
// 参考《大话数据结构》
//

#ifndef SORT_SORT_H
#define SORT_SORT_H


// 打印列表
void PrintArray(int arr[], int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
        printf("%6d, ", arr[i]);
    printf("\n");
}


// 交换数据
void swap(int *num_a, int *num_b) {
    int temp = *num_b;
    *num_b = *num_a;
    *num_a = temp;
}


// 冒泡排序
void BubbleSort(int arr[], int n)
{
    int i = 0, j = 0;

    // 遍历n遍，循环一次，就排好一个数，放在最后面
    for(i = 0; i < n; i++)
    {
        // 每次遍历从下标0开始，到n-1-i结束
        for(j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}


// 数组分割（还有些bug）
// 使枢轴之前的记录都小于它，之后的记录都大于它，并返回枢轴位置。
int Partition(int arr[],  int low, int high)
{
    // 第一条记录作为比较基准值
    int pivotkey = arr[low];

    // 从两端向中间扫描
    while(low < high)
    {
        if(arr[low] < pivotkey)
        {
            swap(&arr[low], &arr[high]);
            low++;
            continue;
        }

        if(arr[high] < pivotkey)
        {
            swap(&arr[low], &arr[high]);
            high--;
            continue;
        }
    }

    return low;
}


// 快速排序
void QuickSort(int arr[], int low, int high)
{
    int pivot;

    if(low < high) {
        // 将arr一分为二，算出枢轴pivot
        pivot = Partition(arr, low, high);
        // 对左侧递归排序
        QuickSort(arr, low, pivot - 1);
        // 对右侧递归排序
        QuickSort(arr, pivot + 1, high);
    }
}


// arr是待调整的堆数组,i是待调整的数组元素的位置,n是数组的长度
void heapAdjust(int arr[], int i, int n)
{
    int child;
    int t = arr[i];

    // 递归终止条件
    if(i > n / 2 - 1)
    {
        return;
    }

    // 左叶子节点
    child = 2 * i;
    // 比较得到叶子节点中较大的节点
    if (child != n - 1 && arr[child + 1] > arr[child]) {
        child++;
    }

    // 如果较大的叶子节点大于父节点，把较大的叶子节点往上移动，替换其父节点
    if (arr[child] > t) {
        swap(&arr[i], &arr[child]);
        heapAdjust(arr, child, n);
    } else {
        // 递归终止条件
        return;
    }

}


// 堆排序
void heapSort(int arr[], int n) {
    //构建最大堆
    //调整序列的前半部分元素（即每个有孩子的节点），调整完之后是一个大顶堆，第一个元素是序列的最大的元素。
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapAdjust(arr, i, n);
    }

    //排序
    // 最大值的根节点和当前未经排序子序列的最后一个节点交换，再调整为最大堆。
    for (int j = n -1; j > 0; j--) {
        swap(&arr[0], &arr[j]);
        heapAdjust(arr, 0, j);
    }
}

#endif //SORT_SORT_H
