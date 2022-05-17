#include <iostream>

template <typename T> class AVLNode
{
    public:
        AVLNode(T newData);
        ~AVLNode();
        int getHeight();
        AVLNode<T>* getLeft();
        AVLNode<T>* getRight();
        void setLeft(AVLNode<T>* newNode);
        void setRight(AVLNode<T>* newNode);
        void setHeight(int newHeight);
        T getData();
    private:
        T data;
        AVLNode<T> *left;
        AVLNode<T> *right;
        int height;
};

template <typename T>
AVLNode<T>::AVLNode(T newData)
{
    data = newData;
    height = 1;
    left = nullptr;
    right = nullptr;
}

template <typename T>
int AVLNode<T>::getHeight()
{
    return height;
}

template <typename T>
AVLNode<T>::~AVLNode()
{
    std::cout << "DESTRUCTOR" << std::endl;
}

template <typename T>
AVLNode<T>* AVLNode<T>::getLeft()
{
    return this->left;
}

template <typename T>
AVLNode<T>* AVLNode<T>::getRight()
{
    return this->right;
}

template <typename T>
void AVLNode<T>::setLeft(AVLNode<T>* newNode)
{
    this->left = newNode;
}

template <typename T>
void AVLNode<T>::setRight(AVLNode<T>* newNode)
{
    this->right = newNode;
}

template <typename T>
 T AVLNode<T>::getData()
 {
     return data;
 }

template <typename T>
 void AVLNode<T>::setHeight(int newHeight)
 {
     height = newHeight;
 }