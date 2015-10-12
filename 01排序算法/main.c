//
//  main.m
//  01排序算法
//
//  Created by peng on 15/10/10.
//  Copyright © 2015年 test. All rights reserved.
//
#include <stdio.h>
/**
 *  排序算法简介
 *  排序算法分为内排序和外排序。
 *  内排序：被排序的数据都在内存里面，排序的过程中不会访问外存设备（如：硬盘）
 *  外排序：被排序的数据比较大，不能一次性都放到内存当中，排序的过程中需要访问外部设备（如：硬盘）
 *
 *
 *  内排序分为：插入排序、选择排序、交换排序、归并排序、基数排序。
 *
 *  插入排序：直接插入排序、希尔排序
 *  选择排序：简单选择排序、堆排序
 *  交换排序：冒泡排序、快速排序
 */



/**
 *  数组打印方法（主要是打印脾虚前后的数组）
 *
 *  @param a      被打印的数组
 *  @param length 数组的长度
 */
void myPrint(int a[], int length);
/**
 *  直接插入排序
 *
 *  @param a      被排序的数组
 *  @param length 数组的长度
 */
void straightInsertSort(int a[], int length);


int main(int argc, const char * argv[]) {
    // 定义数组
    int a[] = {45, 23, 77, 56, 32, 66, 45, 99, 83};
    // 数组长度
    int length = sizeof(a)/sizeof(a[0]);
    
    // 打印排序前的数组
    printf("排序前的数组 = ");
    myPrint(a, length);
    
    // 打印排序后的数组
    straightInsertSort(a, length);
    printf("排序后的数组= ");
    myPrint(a, length);
    
    return 0;
}
#pragma mark - 公共方法
void myPrint(int a[], int length)
{
    printf("{");
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", a[i]);
        }else{
            printf("%d, ", a[i]);
        }
    }
    printf("}\n");
}

#pragma mark - 插入排序
/**
 *  直接插入排序
 *  基本思想：把一个记录插入到已经排好序的有序表中，从而得到一个新的，记录数加1的有序表。即：把序列的第一个记录看成是一个有序的子序列，从序列的第2个记录
 *  逐个插入，直到整个序列有序为止。
 *  要点：设立哨兵，用于临时存储和判断数组边界之用.
 */
void straightInsertSort(int a[], int length)
{
    for(int i = 1; i < length; i++)// 从第二个记录开始查找
    {
        if (a[i] < a[i - 1]) {// 如果第i位置的记录大于第i - 1位置的记录直接插入（其实什么也不需要做，直接遍历下一个元素）,否则就要移动有序列表插入
            int temp = a[i];// 复制哨兵
            a[i] = a[i - 1];// 后移一个元素
            int j = i - 1;
            while (temp < a[j] && j >= 0) {// 移动数组元素找到哨兵的位置
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;// 插入哨兵
            myPrint(a, length);
        }
    }
}