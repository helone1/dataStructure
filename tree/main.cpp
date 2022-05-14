
#include "binaryTree.h"
#include <iostream>
#include <vector>

int main(int argc, char*argv[])
{

    
    int pre[] = {1, 2, 4, 7, 8, 5, 3, 6, 9};
    int mid[] = {7, 4, 8, 2, 5, 1, 6, 9, 3};
    int treeLen = 9;

    CBinaryTree<int> t;
    t.recoveryTree(mid, pre, treeLen);
    t.preorderRecursion();
    t.showResultSeq();
    t.inorderRecursion();
    t.showResultSeq();
    t.postorderRecursion();
    t.showResultSeq();

    t.preorderIteration();
    t.showResultSeq();
    t.inorderIteration();
    t.showResultSeq();
    t.postorderIteration();
    t.showResultSeq();

    t.levelOrder();
    t.showResultSeq();
    return 0;
}