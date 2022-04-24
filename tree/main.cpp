#include "tree.h"
#include <iostream>
#include <vector>

Tree * recoveryTree(int *pMid, int *pPre, int treeLen);

void preorderTraversal(Tree *pTree, std::vector<int> *pRes);
void inorderTraversal(Tree *pTree, std::vector<int> *pRes);
void postorderTraversal(Tree *pTree, std::vector<int> *pRes);



void showVector(std::vector<int> &vec)
{
    for(auto val : vec)
    {
        std::cout<< val << ", ";
    }
    std::cout<< std::endl;
}

int treeLen = 6;
int pre[] = {1, 2, 3, 4, 5, 6}; // ǰ�����
int mid[] = {3, 2, 1, 5, 4, 6}; // �������

int main()
{
    Tree *pTree = recoveryTree(mid, pre, 6); // �ָ�һ����

    // ��֤ǰ����������ͬpre
    std::vector<int> res;
    preorderTraversal(pTree, &res);
    showVector(res);

    // ��֤������������ͬmid
    res.clear();
    inorderTraversal(pTree, &res);
    showVector(res);

    // ��������
    res.clear();
    postorderTraversal(pTree, &res);
    showVector(res);
    return 0;
}