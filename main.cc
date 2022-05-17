#include "AVLTree.h"

/*
Name: Connor Strom
Class: CPTS 223
Assignment: AVL template tree
Date: November 15, 2021
*/

int main (void)
{
    int i = 0, k = 0;
    AVLTree<int> *ascendingTree, *descendingTree, *randomTree;

    int ascendingArray[50] = {0}, descendingArray[50] = {0}, randomArray[50] = {0};

    for (int x = 1; x < 100; ++x)
    {
        ascendingArray[i] = x;
        ++i, ++x;
    }

    for (int x = 99; x > 0; --x)
    {
        descendingArray[k] = x;
        ++k, --x;
    }

    k = 0;

    for (int x = 99; x > 0; --x)
    {
        randomArray[k] = x;
        ++k, --x;
    }

    ascendingTree = new AVLTree<int>();
    descendingTree = new AVLTree<int>();
    randomTree = new AVLTree<int>();

    AVLNode<int> *pCur = nullptr;

    for (int x = 0; x < 50; ++x)
    {
        pCur = ascendingTree->insert(ascendingArray[x], ascendingTree->getRoot(), nullptr);
    }

    pCur = nullptr;
   
    for (int x = 0; x < 50; ++x)
    {
       descendingTree->insert(descendingArray[x], descendingTree->getRoot(), nullptr);
    }

    // shuffle

    for (int x = 0; x < 50; ++x)
    {
       randomTree->insert(randomArray[x], randomTree->getRoot(), nullptr);
    }

    std::cout << "Height of ascending tree: " << ascendingTree->calculateHeight(ascendingTree->getRoot()) << std::endl << std::endl;
    std::cout << "Height of descending tree: " << descendingTree->calculateHeight(descendingTree->getRoot()) << std::endl << std::endl;
    std::cout << "Height of random tree: " << randomTree->calculateHeight(randomTree->getRoot()) << std::endl << std::endl;

    // ascendingTree->printTree(ascendingTree->getRoot());

    std::cout << "BONUS: Value of Validate() for ascending = " << ascendingTree->validate(ascendingTree->getRoot()) << std::endl << std::endl;
    std::cout << "BONUS: Value of Validate() for descending = " << descendingTree->validate(descendingTree->getRoot()) << std::endl << std::endl;
    std::cout << "BONUS: Value of Validate() for random = " << randomTree->validate(randomTree->getRoot()) << std::endl << std::endl;

    std::cout << "BONUS: contains() IN TREE" << std::endl;

    for (int x = 0; x < 100; ++x)
    {
        std::cout << ascendingTree->contains(x, ascendingTree->getRoot()) << ", ";
    }

    std::cout << std::endl << std::endl;

    for (int x = 0; x < 100; ++x)
    {
        std::cout << descendingTree->contains(x, descendingTree->getRoot()) << ", ";
    }

    std::cout << std::endl << std::endl;

    for (int x = 0; x < 100; ++x)
    {
        std::cout << randomTree->contains(x, randomTree->getRoot()) << ", ";
    }

    std::cout << std::endl << std::endl;

    return 0;
}