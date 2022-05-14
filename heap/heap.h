/**
 * @brief һ���󶥶�
 * @author zhanghl
 * @date 2022/5/4
 */ 
#include <vector>

/** һ���򵥵ĵĶ�
 */ 
class CHeap
{
public:
// ��̬���ߺ���:��������ص�
    // ������
    static void sort(std::vector<int> &data);
private:
// ��̬���ߺ���:��������ص�
    // ��nodeIdx�±�Ľڵ㿪ʼ ���϶��� �ѻ�
    static void heapify(std::vector<int> &data, int len, int nodeIdx);
    


public:
    CHeap(int capicity);

    void Insert(int data);
    int DeleteTop();
    std::vector<int> & sort();

    std::vector<int> getHeapSeq()
    {
        if(m_nHeapSize != 0)
            return std::vector<int>(m_data.begin(), m_data.begin()+m_nHeapSize);
        else
            return std::vector<int>();
    }

    bool Empty()
    {
        return m_nHeapSize==0;
    }
private:
    void swap(int idx1, int idx2)
    {
        int tmp = m_data[idx1];
        m_data[idx1] = m_data[idx2];
        m_data[idx2] = tmp;
    }
private:
    std::vector<int> m_data;
    int m_nHeapSize;
};