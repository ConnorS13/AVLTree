#include "AVLNode.hpp"

template <typename T> class AVLTree
{
    public:
    AVLTree();
    ~AVLTree();
    
    int checkBalance(AVLNode<T> *pCur);
    int calculateHeight(AVLNode<T> *pCur);
    int getHeight(AVLNode<T> *node);
    AVLNode<T>* insert(T newData, AVLNode<T> *pCur, AVLNode<T> *pTemp);
    bool contains(T dataSearch, AVLNode<T> *node);
    bool validate(AVLNode<T> *pCur);
    AVLNode<T>* getRoot();
    AVLNode<T>* rotateR(AVLNode<T>* pCur);
    AVLNode<T>* rotateL(AVLNode<T>* pCur);
    int returnMaxHeight(int h1, int h2);
    void printTree(AVLNode<T>* pCur);

    private:
    AVLNode<T> *root;
};

template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    std::cout << "DESTRUCTOR" << std::endl;
}

template <typename T>
int AVLTree<T>::getHeight(AVLNode<T> *pCur)
{
    return pCur->getHeight();
}

template <typename T>
AVLNode<T>* AVLTree<T>::insert(T newData, AVLNode<T> *pCur, AVLNode<T> *pTemp)
{
    int balance = 0;

   // AVLNode<T>* pPrev = nullptr;

    if (root == nullptr)
    {
        return root = new AVLNode<int>(newData);
    }

    else if (pTemp == nullptr)
    {
        pTemp = new AVLNode<int>(newData);
    }

    if (pCur != nullptr && newData < pCur->getData())
    {
        if (pCur->getLeft() != nullptr)
        {
            insert(newData, pCur->getLeft(), pTemp);
        }
        else if (pCur->getLeft() == nullptr)
        {
            pCur->setLeft(pTemp);
        }
    }

    else if (pCur != nullptr && newData > pCur->getData())
    {
        if (pCur->getRight() != nullptr)
        {
            insert(newData, pCur->getRight(), pTemp);
        }
        else if (pCur->getRight() == nullptr)
        {
            pCur->setRight(pTemp);
        }
    }

    // above is inserting into a BST normally

    balance = checkBalance(pCur);

    if (balance < -1 && newData > pCur->getRight()->getData())
    {
        // std::cout << "R";
        // return pCur = rotateR(pCur);
    }

    else if (balance > 1 && newData < pCur->getLeft()->getData())
    {
        // std::cout << "L";
        // return pCur = rotateL(pCur);
    }

    else if (balance > 1 && newData > pCur->getLeft()->getData())
    {
        std::cout << "LR";
        pCur->setLeft(rotateL(pCur->getLeft()));
        return pCur = rotateR(pCur);
    }

    else if (balance < -1 && newData < pCur->getRight()->getData())
    {
        std::cout << "RL";
        pCur->setRight(rotateR(pCur->getRight()));
        return pCur = rotateL(pCur);
    }

    return pCur;
}

template <typename T>
bool AVLTree<T>::validate(AVLNode<T> *pCur)
{
    int rightHeight = 0, leftHeight = 0;

    rightHeight = calculateHeight(pCur->getRight()); // these two lines retrieve the height of both sides
    leftHeight = calculateHeight(pCur->getLeft());

    rightHeight = rightHeight - leftHeight;

    if (rightHeight == 1 || rightHeight == 0 || rightHeight == -1)
    {
        return true;
    }

    return false;
}

template <typename T>
bool AVLTree<T>::contains(T dataSearch, AVLNode<T> *node)
{

    bool val = false;

    while (node->getLeft() != nullptr)
    {
        if (dataSearch == node->getData())
        {
            return true;
        }
        node = node->getLeft();
    }

    node = root;

    while (node->getRight() != nullptr)
    {
        if (dataSearch == node->getData())
        {
            return true;
        }
        node = node->getRight();
    }

    return val;
}

template <typename T>
AVLNode<T>* AVLTree<T>::getRoot()
{
    return this->root;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateR(AVLNode<T>* pCur)
{
    AVLNode<int>* pTemp = nullptr, *pTemp2 = nullptr;

    pTemp = pCur->getRight();
    pCur->setRight(pTemp->getLeft());

    pTemp->setLeft(pCur);

    int bal = 0;
    bal = returnMaxHeight(calculateHeight(pCur->getLeft()), calculateHeight(pCur->getRight()));

    pCur->setHeight(bal + 1);

    bal = returnMaxHeight(calculateHeight(pTemp->getLeft()), pCur->getHeight());

    pTemp->setHeight(bal + 1);

    return pTemp;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateL(AVLNode<T>* pCur)
{
   AVLNode<int>* pTemp = nullptr, *pTemp2 = nullptr;

    pTemp = pCur->getLeft();
    pCur->setLeft(pTemp->getRight());

    pTemp->setRight(pCur);

    int bal = 0;
    bal = returnMaxHeight(calculateHeight(pCur->getLeft()), calculateHeight(pCur->getRight()));

    pCur->setHeight(bal + 1);

    bal = returnMaxHeight(calculateHeight(pTemp->getRight()), pCur->getHeight());

    pTemp->setHeight(bal + 1);

    return pTemp;
}

template <typename T>
int AVLTree<T>::returnMaxHeight(int h1, int h2)
{
    if (h1 > h2)
    {
        return h1;
    }
    else
    {
        return h2;
    }
}

template <typename T>
void AVLTree<T>::printTree(AVLNode<T>* pCur)
 {
     if (pCur != nullptr)
     {
        printTree(pCur->getLeft());
        std::cout << pCur->getData() << std::endl;
        printTree(pCur->getRight());
     }
 }

template <typename T>
int AVLTree<T>::calculateHeight(AVLNode<T> *pCur)
 {
     int height = 0, leftHeight = 0, rightHeight = 0;

     if (pCur != nullptr)
     {
         leftHeight = calculateHeight(pCur->getLeft());
         rightHeight = calculateHeight(pCur->getRight());
         
            if (leftHeight >= rightHeight)
            {
                height = 1 + leftHeight;
            }
            else if (rightHeight > leftHeight)
            {
                height = 1 + rightHeight;
            }
     }
     return height;
 }

 template <typename T>
 int AVLTree<T>::checkBalance(AVLNode<T> *pCur)
 {
     int balance = 0; 

     if (pCur != nullptr)
     {
         balance = calculateHeight(pCur->getLeft()) - calculateHeight(pCur->getRight());
     }

     return balance;
 }