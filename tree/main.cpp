
#include "binaryTree.h"
#include <iostream>
#include <vector>

int main(int argc, char*argv[])
{
    int treeLen = 6;
    int pre[] = {1, 2, 3, 4, 5, 6}; // 前序遍历
    int mid[] = {3, 2, 1, 5, 4, 6}; // 中序遍历
    CBinaryTree<int> t;
    t.recoveryTree(mid, pre, treeLen);
    t.preorderRecursion();
    t.showResultSeq();
    t.inorderRecursion();
    t.showResultSeq();
    t.postorderRecursion();
    t.showResultSeq();


    return 0;
}