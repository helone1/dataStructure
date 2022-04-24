/**
 * @brief 树的遍历，中序遍历、前序遍历、后序遍历
 * @date 2022/04/24
 * @author zhanghl
 */ 
#include <vector>
#include "tree.h"

/** 递归-前序遍历 VLR
 * @param pTree 树结构指针
 * @param pRes 结果序列
 */
void preorderTraversal(Tree *pTree, std::vector<int> *pRes)
{
    if(nullptr == pTree)
    {
        return;
    }

    pRes->push_back(pTree->m_value);
    preorderTraversal(pTree->m_pLeftNode, pRes);
    preorderTraversal(pTree->m_pRightNode, pRes);
}

/** 递归-中序遍历 LVR
 * @param pTree 树结构指针
 * @param pRes 结果序列
 */
void inorderTraversal(Tree *pTree, std::vector<int> *pRes)
{
    if(nullptr == pTree)
    {
        return;
    }

    inorderTraversal(pTree->m_pLeftNode, pRes);
    pRes->push_back(pTree->m_value);
    inorderTraversal(pTree->m_pRightNode, pRes);
}

/** 递归-后序遍历 LRV
 * @param pTree 树结构指针
 * @param pRes 结果序列
 */
void postorderTraversal(Tree *pTree, std::vector<int> *pRes)
{
    if(nullptr == pTree)
    {
        return;
    }

    postorderTraversal(pTree->m_pLeftNode, pRes);
    postorderTraversal(pTree->m_pRightNode, pRes);
    pRes->push_back(pTree->m_value);
}

void test1(Tree *pTree)
{
    std::vector<int> res1; // 结果
    preorderTraversal(pTree, &res1);

    std::vector<int> res2; // 结果
    inorderTraversal(pTree, &res2);

    std::vector<int> res3; // 结果
    postorderTraversal(pTree, &res3);
}




