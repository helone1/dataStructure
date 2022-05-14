/**
 * @brief 排序
 * @author zhanghl
 * @date 2022/05/03
 */
#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序
void bubble(std::vector<int> &data)
{
    int len = data.size();
    bool isSwitch = false; //优化：当某次冒泡操作已经没有数据交换时，说明已经达到完全有序，不用再继续执行后续的冒泡操作。
    for (int loopCnt = 0; loopCnt < len; ++loopCnt)
    {
        isSwitch = false;
        for (int idx = 0; idx < len - loopCnt - 1; ++idx)
        {
            if (data[idx] > data[idx + 1])
            {
                int tmp = data[idx];
                data[idx] = data[idx + 1];
                data[idx + 1] = tmp;
                isSwitch = true;
            }
        }

        if (!isSwitch)
        {
            break;
        }
    }
}

// 插入排序
void insert(std::vector<int> &data)
{
    int len = data.size();
    for (int i = 1; i < len; ++i)
    {
        int tmp = data[i];

        int j = i - 1; // i 前面的数比它小
        for (; j >= 0; --j)
        {
            if (data[j] > tmp)
            {
                data[j + 1] = data[j];
            }
            else
            {
                break;
            }
        }

        data[j + 1] = tmp;
    }
}

// 选择排序
void select(vector<int> &data)
{
    int len = data.size();
    for (int i = 0; i < len; ++i)
    {
        int min = data[i];
        int minIdx = -1;
        for (int j = i + 1; j < len; ++j)
        {
            if (min > data[j])
            {
                min = data[j];
                minIdx = j;
            }
        }
        if (minIdx != -1)
        {
            data[minIdx] = data[i];
            data[i] = min;
        }
    }
}

// 归并排序
void _merge(vector<int> &data, const int start, const int mid, const int end);
void mergeSort(vector<int> &data, const int start, const int end)
{
    if (start >= end)
        return;

    // 分治
    const int mid = (start + end) / 2;
    mergeSort(data, start, mid);
    mergeSort(data, mid + 1, end);

    _merge(data, start, mid, end);
}

void _merge(vector<int> &data, const int start, const int mid, const int end)
{
    // 合并两个有序子集
    vector<int> tmp(end - start + 1, 0);
    int start1 = start;
    int start2 = mid + 1;
    int idx = 0;
    for (; idx < tmp.size(); ++idx)
    {
        if (start1 > mid)
        {
            tmp[idx] = data[start2++];
        }
        else if (start2 > end)
        {
            tmp[idx] = data[start1++];
        }
        else
        {
            if (data[start1] < data[start2])
            {
                tmp[idx] = data[start1++];
            }
            else
            {
                tmp[idx] = data[start2++];
            }
        }
    }

    for (idx = 0; idx < tmp.size(); ++idx)
    {
        data[start + idx] = tmp[idx];
    }
}

// 快速排序
int _partition(vector<int> &data, const int start, const int end);

void quickSort(vector<int> &data, const int start, const int end)
{
    if(start>=end)
        return ;
    int mid = _partition(data, start, end);
    quickSort(data, start, mid - 1);
    quickSort(data, mid + 1, end);
}

int _partition(vector<int> &data, const int start, const int end)
{
    int divValue = data[end];
    int divIdx = start;

    for (int i = start; i <=end; ++i)
    {
        if (data[i] < divValue)
        {
            int tmp = data[i];
            data[i] = data[divIdx];
            data[divIdx] = tmp;

            divIdx++;
        }
    }
    int tmp = data[end];
    data[end] = data[divIdx];
    data[divIdx] = tmp;

    return divIdx;
}
