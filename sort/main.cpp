/**
 * @brief ≈≈–ÚÀ„∑®
 * @author zhanghl
 * @date 2022/5/3
 */ 

#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<int> &data);
void insert(vector<int> &data);
void select(vector<int> &data);
void mergeSort(vector<int> &data, const int start, const int end);
void quickSort(vector<int> &data, const int start, const int end);

void show(std::vector<int> &data)
{
    for(auto num : data)
    {
        std::cout<<num<<", ";
    }
    std::cout<<std::endl;
}

int main(int argc, char*argv[])
{
    int _data1[] = {3, 4, 56, 23, 67, 1, 0};
    int _data2[] = {3, 4, 5, 6, 7, 8, 9};
    int _data3[] = {9, 8, 7, 6, 5, 4, 3};
    std::vector<int> data(_data1, _data1+7);
    show(data);
    // bubble(data);
    // insert(data);
    // select(data);
    // mergeSort(data, 0, data.size()-1);
    quickSort(data, 0, data.size()-1);
    show(data);

    return 0;
}