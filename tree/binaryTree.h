/**
 * @brief 实现一个二叉树类
 * @author zhanghl
 * @date 2022/04/27
 */ 

#include <iostream>
#include <vector>
#include <stack>

template<typename T>
struct TTreeNode
{
    T m_value;
    TTreeNode *m_pLfNode;
    TTreeNode *m_pRtNode;
};

template<typename T>
class CBinaryTree
{
public:
    CBinaryTree()
    {
        m_pTree = nullptr;
    }

    CBinaryTree(const CBinaryTree &binaryTree)
    {
        m_pTree = binaryTree.m_pTree;
    }

    // 通过中序遍历、前序遍历恢复一个二叉树
    void recoveryTree(T *pMid, T *pPre, int len)
    {
        m_pTree = _recoveryTree(pMid, pPre, len);
    }

private:
    TTreeNode<T>* _recoveryTree(T *pMid, T *pPre, int len)
    {
        TTreeNode<T> *pTree;
        if (len <= 0)
        {
            return nullptr;
        }
        if (len == 1)
        {
            pTree = new TTreeNode<T>();
            pTree->m_value = *pMid;
            pTree->m_pLfNode = nullptr;
            pTree->m_pRtNode = nullptr;
            return pTree;
        }

        pTree = new TTreeNode<T>();

        int *pRoot = pPre;
        pTree->m_value = *pRoot;
        int *pLeftTree = pMid;
        int i = 0;
        for (; i < len; ++i)
        {
            if (pLeftTree[i] == *pRoot)
            {
                break;
            }
        }

        pTree->m_pLfNode = _recoveryTree(pMid, pPre + 1, i); // 左子树
        pTree->m_pRtNode = _recoveryTree(pMid + i + 1, pPre + i + 1, len - i - 1);
    }

public:
    // 前序遍历
    void preorderRecursion()
    {
        m_pSequence.clear();
        if(nullptr == m_pTree)
        {
            return;
        }
        _preorderRecursion(m_pTree);
    }

private:
    void _preorderRecursion(TTreeNode<T> *pTree)
    {
        if(nullptr == pTree)
        {
            return;
        }

        m_pSequence.push_back(pTree->m_value);
        _preorderRecursion(pTree->m_pLfNode);
        _preorderRecursion(pTree->m_pRtNode);
    }

public:
    // 中序遍历
    void inorderRecursion()
    {
        m_pSequence.clear();
        if(nullptr == m_pTree)
        {
            return;
        }
        _inorderRecursion(m_pTree);
    }

private:
    void _inorderRecursion(TTreeNode<T> *pTree)
    {
        if(nullptr == pTree)
        {
            return;
        }

        _inorderRecursion(pTree->m_pLfNode);
        m_pSequence.push_back(pTree->m_value);
        _inorderRecursion(pTree->m_pRtNode);
    }

public:
    // 后续遍历
    void postorderRecursion()
    {
        m_pSequence.clear();
        if(nullptr == m_pTree)
        {
            return;
        }
        _postorderRecursion(m_pTree);
    }

private:
    void _postorderRecursion(TTreeNode<T> *pTree)
    {
        if(nullptr == pTree)
        {
            return;
        }

        _postorderRecursion(pTree->m_pLfNode);
        _postorderRecursion(pTree->m_pRtNode);
        m_pSequence.push_back(pTree->m_value);
    }

public:
    // 显示所有遍历的结果
    void showResultSeq()
    {
        for(auto &item : m_pSequence)
        {
            std::cout<< item << ", ";
        }
        std::cout << std::endl;
    }

private:
    TTreeNode<T> *m_pTree;
    std::vector<T> m_pSequence;
};