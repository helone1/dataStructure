/**
 * @brief 树的遍历，中序遍历、前序遍历、后序遍历
 * @date 2022/04/24
 * @author zhanghl
 */ 
 #include "tree.h"
 #include <vector>
 #include <iostream>




Tree * recoveryTree(int *pMid, int *pPre, int treeLen)
{
    Tree *pTree;
    if (treeLen <= 0)
    {
        return nullptr;
    }
    if (treeLen == 1)
    {
        pTree = new Tree();
        pTree->m_value = *pMid;
        pTree->m_pLeftNode = nullptr;
        pTree->m_pRightNode = nullptr;
        return pTree;
    }

    pTree = new Tree();

    int *pRoot = pPre;
    pTree->m_value = *pRoot;
    int *pLeftTree = pMid;
    int i = 0;
    for (; i < treeLen; ++i)
    {
        if (pLeftTree[i] == *pRoot)
        {
            break;
        }
    }

    pTree->m_pLeftNode = recoveryTree(pMid, pPre + 1, i); // 左子树
    pTree->m_pRightNode = recoveryTree(pMid + i + 1, pPre + i + 1, treeLen - i - 1);
}

