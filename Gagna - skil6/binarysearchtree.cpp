#include "binarysearchtree.h"
#include "binarytree.cpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : BinaryTree<T>()
{
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem) : BinaryTree<T>(rootItem)
{
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findAt(BinaryNode<T> * node, const T& anItem) const
// Retrieves an item starting searching at node
{
    if (node == NULL) {      // Then the item was not found
        return NULL;
    }
    else if (anItem == node->item) { // Then found
        return node;
    }
    else if (anItem < node->item) {  // Search in the left tree
        return (findAt(node->leftChild, anItem));
    }
    else {                            // Search in the right tree
        return (findAt(node->rightChild, anItem));
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::find(const T& anItem) const // Retrieves the node corresponding to the item. If not found, returns null
{
    return (findAt(BinaryTree<T>::root, anItem));
}

template <class T>
void BinarySearchTree<T>::insert(const T& anItem)
{
    insertAt(this->root, anItem);
}

template <class T>
void BinarySearchTree<T>::insertAt(BinaryNode<T> *& node, const T& anItem)
{
    if(node == NULL)
    {
        node = new BinaryNode<T>(anItem);
    }
    else if(node->item < anItem)
    {
        insertAt(node->rightChild,anItem);
    }
    else if(node->item > anItem)
    {
        insertAt(node->leftChild,anItem);
    }
    return;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode() const
{
    return maxNode(this->root);
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode(BinaryNode<T> *node) const
{
    if(node != NULL && node->rightChild != NULL)
    {
        return maxNode(node->rightChild);
    }
    return node;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode() const
{
    return minNode(this->root);
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T> *node) const
{
    if(node != NULL && node->leftChild != NULL)
    {
        return minNode(node->leftChild);
    }
    return node;
}

template <class T>
void BinarySearchTree<T>::removeNode(BinaryNode<T> *& node)
{
    delete node;
    node = NULL;
}

template <class T>
void BinarySearchTree<T>::remove(const T& anItem)
{
    removeAt(this->root,anItem);
}

template <class T>
void BinarySearchTree<T>::removeAt(BinaryNode<T> *& node, const T& anItem)
{
    // recursively go through the nodes
    if(node == NULL)
        return;
    if(node->item > anItem)
        removeAt(node->leftChild,anItem);
    else if (node->item < anItem)
        removeAt(node->rightChild,anItem);

    //we will only enter this block if anItem == node->item
    else
    {
        //two children
        if(node->leftChild != NULL && node->rightChild != NULL)
        {
            node->item = processLeftmost(node);
        }
        else
        {
            //no children
            if(node->isLeaf())
            {
                removeNode(node);
            }
            else //one child
            {
                BinaryNode<T> *temp = node;
                node = (node->leftChild != NULL) ? node->leftChild : node->rightChild; //checks which child it is that is not null
                removeNode(temp);
            }
        }
    }
}

template <class T>
T BinarySearchTree<T>::processLeftmost(BinaryNode<T> *& node)
{
    BinaryNode<T> *temp = minNode(node->rightChild);
    T ret = temp->item;
    removeAt(node,ret);
    return ret;
}
