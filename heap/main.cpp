/**
 * @brief Ò»¸ö¶Ñ
 * @author zhanghl
 * @date 2022/5/4
 */
#include <iostream>
#include "heap.h"

void show(const std::vector<int> &data)
{
    for(auto num : data)
    {
        std::cout<<num<<", ";
    }
    std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> tmp {3, 4, 56, 23, 67, 1, 0, 2};
    CHeap heap(5);

    show(heap.getHeapSeq());
    // while(!heap.Empty())
    //     std::cout<<heap.DeleteTop()<<std::endl;
    
    // show(heap.getHeapSeq());

    // show(heap.sort());

    // if(heap.Empty())
    //     std::cout<< "heap is empty"<<std::endl;

    show(tmp);
    CHeap::sort(tmp);
    show(tmp);
}