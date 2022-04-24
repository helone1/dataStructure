/**
 * @brief ���ı��������������ǰ��������������
 * @date 2022/04/24
 * @author zhanghl
 */ 
#include <vector>
#include "tree.h"

/** �ݹ�-ǰ����� VLR
 * @param pTree ���ṹָ��
 * @param pRes �������
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

/** �ݹ�-������� LVR
 * @param pTree ���ṹָ��
 * @param pRes �������
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

/** �ݹ�-������� LRV
 * @param pTree ���ṹָ��
 * @param pRes �������
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
    std::vector<int> res1; // ���
    preorderTraversal(pTree, &res1);

    std::vector<int> res2; // ���
    inorderTraversal(pTree, &res2);

    std::vector<int> res3; // ���
    postorderTraversal(pTree, &res3);
}




