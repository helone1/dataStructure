/**
 * @brief 实现一个二叉树类
 * @author zhanghl
 * @date 2022/04/27
 */ 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    // 前序遍历-递归
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
    // 中序遍历-递归
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
    // 后续遍历-递归
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
    // 前序遍历-迭代
    void preorderIteration()
    {
        m_pSequence.clear();
        std::stack<TTreeNode<T>*> nodeStack;
        TTreeNode<T> *pNode = m_pTree;

        while(true)
        {
            while(pNode != nullptr)
            {
                m_pSequence.push_back(pNode->m_value);
                nodeStack.push(pNode);
                pNode = pNode->m_pLfNode;
            }

            if(nodeStack.empty())
                break;
            pNode = nodeStack.top();
            nodeStack.pop();
            pNode = pNode->m_pRtNode;

        }
    }

public:
    // 中序遍历-迭代
    void inorderIteration()
    {
        m_pSequence.clear();
        std::stack<TTreeNode<T> *> nodeStack;
        TTreeNode<T> *pNode = m_pTree; 

        while(true)
        {
            _inorderIteration(pNode, nodeStack);
            if(nodeStack.empty())
                break;
            pNode = nodeStack.top();
            nodeStack.pop();
            m_pSequence.push_back(pNode->m_value);
            pNode = pNode->m_pRtNode;
        }
    }
private:
    void _inorderIteration(TTreeNode<T> *pNode, std::stack<TTreeNode<T>*> &nodeStack)
    {
        while(pNode != nullptr)
        {
            nodeStack.push(pNode);
            pNode = pNode->m_pLfNode;
        }
    }


public:
    void postorderIteration()
    {
        m_pSequence.clear();
        std::stack<TTreeNode<T>*> nodeStack;
        TTreeNode<T> *pNode = m_pTree;
        TTreeNode<T> *pPrev = nullptr;
        while(true)
        {
            _postorderIteration(pNode, nodeStack);
            if(nodeStack.empty())
                break;
            pNode = nodeStack.top();

            if(pNode->m_pRtNode == nullptr || pNode->m_pRtNode == pPrev)
            {
                m_pSequence.push_back(pNode->m_value);
                nodeStack.pop();
                pPrev = pNode;
                // std::cout<<pNode->m_value<<",";
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->m_pRtNode;
            }
        }
    }
private:
    void _postorderIteration(TTreeNode<T> *pNode, std::stack<TTreeNode<T>*> &nodeStack)
    {
        while(pNode != nullptr)
        {
            nodeStack.push(pNode);
            pNode = pNode->m_pLfNode;
        }
    }

public:
    void levelOrder()
    {
        m_pSequence.clear();
        if(m_pTree==nullptr)
            return;

        std::queue<TTreeNode<T>*> q;
        q.push(m_pTree);
        TTreeNode<T> *pNode = nullptr;
        while(!q.empty())
        {
            int stkSize = q.size();

            for(int i=0; i< stkSize; ++i)
            {
                pNode = q.front();
                q.pop();
                m_pSequence.push_back(pNode->m_value);

                if(pNode->m_pLfNode != nullptr)
                {
                    q.push(pNode->m_pLfNode);
                }
                if(pNode->m_pRtNode != nullptr)
                {
                    q.push(pNode->m_pRtNode);
                }
                
            }

        }
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