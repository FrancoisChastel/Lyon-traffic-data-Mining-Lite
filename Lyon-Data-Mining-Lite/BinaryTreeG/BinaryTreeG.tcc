/*************************************************************************
 BinaryTreeG  -  description
 -------------------
 Begin                : 27/10/2015
 Copyright            : (C) 2015 par F.Chastel
 -------------------
 Reference :
 - MIT Video course : http://ocw.mit.edu/courses/electrical-engineering-and
 -computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/
 lecture-6-avl-trees-avl-sort/
 *************************************************************************/

//---------- Realization of <BinaryTreeG>'s class (fichier BinaryTreeG.cpp)

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include
using namespace std;
#include <iostream>

//---------------------------------------------------- Personnal's include
#include "BinaryTreeG.h"
#include "BinaryTreeGNodes.h"



//--------------------------------------------------------- Public methods

template<typename T, typename TCompare>
BinaryTreeGNode<T,TCompare>* BinaryTreeG<T, TCompare>::addElement(T element)
// Algorithm :
//
{
    return addElement((BinaryTreeGNode<T,TCompare> *&) root, element);
} //----- End of method

template<typename T, typename TCompare>
T* BinaryTreeG<T, TCompare>::addElement(TCompare element)
// Algorithm :
//
{
    T* tmp = searchElement(element);
    if (tmp != NULL)
    {   return tmp;
    }
    return addElement((BinaryTreeGNode<T,TCompare> *&) root, element);
} //----- End of method

template<typename T, typename TCompare>
T* BinaryTreeG<T,TCompare>::searchElement(TCompare element)
// Algorithm :
//
{
    BinaryTreeGNode<T,TCompare>* tmp = root;
    if (tmp == NULL)
    {
        return NULL;
    }
    while ( (tmp->rightSon != NULL && *(tmp->node)<element)  ||
            (tmp->leftSon != NULL && (*(tmp->node)>element)) ||
            (*(tmp->node) == element))
    {   if (*(tmp->node)<element)
        {   tmp = tmp->rightSon;
        }
        else if((*(tmp->node)>element))
        {   tmp = tmp->leftSon;
        }
        else if(*(tmp->node) == element)
        {   return (tmp->node);
        }
    }
    return NULL;
} //----- End of method


template <typename T, typename TCompare>
BinaryTreeGNode<T,TCompare>* BinaryTreeG<T,TCompare>::GetRoot()
{
    return root;
} //----- End of method

template <typename T, typename TCompare>
void BinaryTreeG<T,TCompare>::display( )
// Algorithm :
//
{
    display(root);
} //----- End of method


//----------------------------------------------------- Protected methods
template<typename T, typename TCompare>
void BinaryTreeG<T, TCompare>::leftRotation(BinaryTreeGNode<T,TCompare>*& node)
// Algorithm : rotate to the left this node (see reference for more informations).
//
{
    BinaryTreeGNode<T,TCompare>* tmp;

    tmp = node->leftSon;
    node->leftSon = tmp->rightSon;
    tmp->rightSon = node;
    node = tmp;

} //----- End of method

template<typename T, typename TCompare>
void BinaryTreeG<T, TCompare>::rightRotation(BinaryTreeGNode<T,TCompare>*& node)
// Algorithm : rotate to the right this node (see reference for more informations).
//
{
    BinaryTreeGNode<T,TCompare>* tmp;

    tmp = node->rightSon;
    node->rightSon = tmp->leftSon;
    tmp->leftSon = node;
    node = tmp;
} //----- End of method

template<typename T, typename TCompare>
void BinaryTreeG<T, TCompare>::leftRotationTwice(BinaryTreeGNode<T,TCompare>*& node)
// Algorithm : rotate to the right node's left son and to the left this node
// (see reference for more informations).
{
    rightRotation(node->leftSon);
    leftRotation(node);
} //----- End of method

template<typename T, typename TCompare>
void BinaryTreeG<T, TCompare>::rightRotationTwice(BinaryTreeGNode<T,TCompare>*& node)
// Algorithm : rotate to the left node's right son and to the right this node
// (see reference for more informations).
{
    leftRotation(node->rightSon);
    rightRotation(node);
} //----- End of method

template<typename T, typename TCompare>
BinaryTreeGNode<T,TCompare>* BinaryTreeG<T, TCompare>::addElement(BinaryTreeGNode<T,TCompare>*& node, T element)
// Algorithm : Add element on the tree, if there is no root, this element become root, else
// he add to the left if it is free and inferior to node's value or to the right if it is
// free and superior to node's value, he do that until he can add element on tree.
{
    BinaryTreeGNode<T,TCompare>* tmp;
    if (node == NULL)
    {   node = new BinaryTreeGNode<T,TCompare>(element);
        tmp = node;
    }
    else if (element < node->node)
    {   tmp = addElement(node->leftSon, element);

        if (getHeight(node->leftSon) - getHeight(node->rightSon) == 2)
        {   if(element < node->leftSon->node)
            {   leftRotation(node);
            }
            else
            {   leftRotationTwice(node);
            }
        }
    }
    else if (element > node->node)
    {   tmp = addElement(node->rightSon, element);
        if (getHeight(node->rightSon) - getHeight(node->leftSon) == 2)
        {   if(element > node->rightSon->node)
            {   rightRotation(node);
            }
            else
            {   rightRotationTwice(node);
            }
        }
    }
    else
    {   delete(&element);
        tmp = node;
    }

    return tmp;
} //----- End of method


template<typename T, typename TCompare>
T* BinaryTreeG<T, TCompare>::addElement(BinaryTreeGNode<T,TCompare>*& node, TCompare element)
// Algorithm :
//
{
    T* tmp;
    if (node == NULL)
    {   node = new BinaryTreeGNode<T,TCompare>(element);
        tmp = node->node;
    }
    else if (*(node->node) > element)
    {   tmp = addElement(node->leftSon, element);

        if (getHeight(node->leftSon) - getHeight(node->rightSon) == 2)
        {   if(*(node->leftSon->node) > element)
            {   leftRotation(node);
            }
            else
            {   leftRotationTwice(node);
            }
        }
    }
    else if (*(node->node) < element)
    {   tmp = addElement(node->rightSon, element);
        if (getHeight(node->rightSon) - getHeight(node->leftSon) == 2)
        {   if(*(node->rightSon->node) < element)
            {   rightRotation(node);
            }
            else
            {   rightRotationTwice(node);
            }
        }
    }
    else
    {   tmp = node->node;
    }

    return tmp;
} //----- End of method

template<typename T, typename TCompare>
int BinaryTreeG<T, TCompare>::getHeight(BinaryTreeGNode<T,TCompare>* node)
// Algorithm :
//
{
    int leftHeight;
    int rightHeight;

    if (node == NULL)
    {   return 0;
    }
    else
    {   leftHeight = getHeight(node->leftSon);
        rightHeight = getHeight(node->rightSon);

        if(leftHeight > rightHeight)
        {   return leftHeight+1;
        }
        else
        {   return rightHeight + 1;
        }
    }
} //----- End of method

template <typename T, typename TCompare>
void BinaryTreeG<T,TCompare>::display(BinaryTreeGNode<T,TCompare>* node)
// Algorithm :
//
{
    if (node != NULL)
    {   display(node->leftSon);
        cout << &node->node << SEPARATOR_CHAR;
        display(node->rightSon);
    }
} //----- End of method

//---------------------------------------------- Constructors - destructor
template<typename T,typename TCompare>
BinaryTreeG<T,TCompare>::BinaryTreeG ( )
// Algorithm :
//
{

    #ifdef MAP
        cout << "Call of <BinaryTreeG>'s constructor'" << endl;
    #endif
    root = NULL;
} //----- End of BinaryTreeG


template<typename T,typename TCompare>
BinaryTreeG<T,TCompare>::~BinaryTreeG ( )
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of <BinaryTreeG>'s destructor'" << endl;
#endif
    delete root;
} //----- End of ~BinaryTreeG
