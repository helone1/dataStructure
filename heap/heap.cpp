/**
 * @brief һ����
 * @author zhanghl
 * @date 2022/5/4
 */
#include <iostream>
#include "heap.h"

CHeap::CHeap(int capacity)
    : m_data(capacity, 0), m_nHeapSize(0)
{
}


void CHeap::Insert(int data)
{
    // �����ݲ��뵽β��
    if(m_nHeapSize >= m_data.size())
    {
        m_data.push_back(data);
    }
    else
    {   
        m_data[m_nHeapSize] = data;
    }

    // ���¶��ϵĶѻ�
    int i = m_nHeapSize;
    while((i>0) && (m_data[(i-1)/2] < m_data[i]))
    {
        swap((i-1)/2, i);
        i = (i-1)/2;
    }

    // �ѵĴ�С��1
    m_nHeapSize++;
}

int CHeap::DeleteTop()
{
    int tmp = m_data[0];
    m_data[0] = m_data[m_nHeapSize-1];// ���ǶѶ�Ԫ�أ��� ɾ���˶Ѷ�Ԫ�أ�
    m_nHeapSize--; // �ѵĴ�С��һ

    // ���϶��µĶѻ�
    int i=0;
    int maxIdx=i;
    while(true)
    {
        int leftIdx = 2*i+1;
        int rightIdx = 2*i+2;

        if(leftIdx<m_nHeapSize && m_data[maxIdx] < m_data[leftIdx])
            maxIdx = leftIdx;
        if(rightIdx<m_nHeapSize && m_data[maxIdx] < m_data[rightIdx])
            maxIdx = rightIdx;

        if(maxIdx != i)
        {
            swap(maxIdx, i);
            i = maxIdx;
        }
        else
        {
            break;
        }
    }
    return tmp;
}

std::vector<int> & CHeap::sort()
{
    int i=m_nHeapSize-1;
    for(; i>=0; --i)
    {
        m_data[i] = DeleteTop();
    }
    return m_data;
}

void CHeap::heapify(std::vector<int> &data, int len, int nodeIdx)
{
    int maxIdx = nodeIdx;
    while (true)
    {
        int leftIdx = nodeIdx * 2 + 1, rightIdx = nodeIdx * 2 + 2;
        if (leftIdx < len && data[maxIdx] < data[leftIdx])
            maxIdx = leftIdx;
        if (rightIdx < len && data[maxIdx] < data[rightIdx])
            maxIdx = rightIdx;    
        if (maxIdx != nodeIdx)
        {
            int tmp = data[maxIdx];
            data[maxIdx] = data[nodeIdx];
            data[nodeIdx] = tmp;

            nodeIdx = maxIdx;
        }
        else
        {
            break;
        }
    }
    
}

void CHeap::sort(std::vector<int> &data)
{
    int len = data.size();
    // ���ѡ������һ����Ҷ�ӽڵ㿪ʼ�ѻ�
    for(int idx=len/2-1; idx>=0; --idx)
        heapify(data, len, idx);
    int lastHeapdata = len-1;
    for (; lastHeapdata >= 0; --lastHeapdata)
    {
        // ���Ѷ��������
        int tmp = data[lastHeapdata];
        data[lastHeapdata] = data[0];
        data[0] = tmp;
        heapify(data, lastHeapdata, 0);
    }
}