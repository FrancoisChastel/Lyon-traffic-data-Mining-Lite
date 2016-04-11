/*************************************************************************
 BinaryTreeG  -  description
 -------------------
 Begin                : 21/10/2015
 Copyright            : (C) 2015 by F.Chastel && L. Cristol
 *************************************************************************/

//---------- Interface of <BinaryTreeG>'s class (file BinaryTreeG.h) -------
#if ! defined ( BINARYTREEG_H )
#define BINARYTREEG_H

//-------------------------------------------------------- Used interfaces
#include "../Sensor.h"
#include "BinaryTreeGNodes.h"
//------------------------------------------------------------- Constantes
        /**     Refs : config.h     **/

//------------------------------------------------------------------------
// Class's job <BinaryTreeG>
//      Generic modelization of a AVL Tree, you can stock object (type T)
//------------------------------------------------------------------------

// Specification template :
//      - T         : object on the node of the Binary Tree. For that
//                    purpose you need to overload your operators ;
//      - TCompare  : object part of T object, you can add, search and
//                    delete based on this TCompare. For that purpose you
//                    need to overload your operator.
template<typename T, typename TCompare>
class BinaryTreeG
{
    //----------------------------------------------------------------- PUBLIC

public:

    //----------------------------------------------------- Méthodes publiques
    T* addElement(TCompare element);
    // Parameters :
    //      - 'element' : correspond to an element, you need to add to your BinaryTreeG.
    //
    // Manual :
    //      - Add 'element' on BinaryTreeG based on operator of TCompare and T ;
    //      - If there is no node stricly equal to 'element' returning a pointer of the new node ;
    //      - If a node stricly equal to 'element' returning a pointer of this node.
    //
    // Contract :
    //      - None
    //

    BinaryTreeGNode<T,TCompare>* addElement(T element);
    // Parameters :
    //      - 'element' : correspond to an element, you need to add to your BinaryTreeG.
    //
    // Manual :
    //      - Add 'element' on BinaryTreeG based on operator of T and T ;
    //      - If there is no node stricly equal to 'element' returning a pointer of the new node ;
    //      - If a node stricly equal to 'element' returning a pointer of this node.
    //
    // Contract :
    //      - None
    //

    T * searchElement(TCompare element);
    // Parameters :
    //      - 'element' : correspond to an element, you need to search to your BinaryTreeG.
    //
    // Manual :
    //      - Add 'element' on BinaryTreeG based on operator of T and T ;
    //      - If there is no node stricly equal to 'element' returning a nullptr ;
    //      - If a node stricly equal to 'element' returning a pointer of this node.
    //
    // Contract :
    //      - None
    //

    void display( );
    // Manual :
    //      - Print in standard output (linux's meaning) an ordered's diplay of all the nodes of the tree.
    //
    // Contract :
    //      - None
    //


    //-------------------------------------------- Constructeurs - destructeur
    BinaryTreeG ( );
    // Mode d'emploi :
    //
    // Contrat :
    //      - None.
    //

    virtual ~BinaryTreeG ( );
    // Mode d'emploi :
    //
    // Contrat :
    //      - None.
    //

    BinaryTreeGNode<T,TCompare>* GetRoot();
    // Manual :
    //      - Add 'element' on BinaryTreeG based on operator of TCompare and T ;
    //      - If there is no node stricly equal to 'element' returning a pointer of the new node ;
    //      - If a node stricly equal to 'element' returning a pointer of this node.
    //
    // Contract :
    //      - None.
    //

    //---------------------------------------------------------------- PRIVATE
protected:
    //----------------------------------------------------- Attributs protégés
    BinaryTreeGNode<T,TCompare>* root;

    void rightRotation(BinaryTreeGNode<T,TCompare>*& node);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Switch to the right son of a node, node is like a pivot.
    //
    // Contract :
    //      - None.
    //

    void leftRotation(BinaryTreeGNode<T,TCompare>*& node);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Switch to the left son of a node, node is like a pivot.
    //
    // Contract :
    //      - None.
    //

    void rightRotationTwice(BinaryTreeGNode<T,TCompare>*& node);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Switch to the left the right son of a node, and call right rotation.
    //
    // Contract :
    //      - None.
    //

    void leftRotationTwice(BinaryTreeGNode<T,TCompare>*& node);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Switch to the right the left son of a node, and call left rotation.
    //
    // Contract :
    //      - None.
    //

    BinaryTreeGNode<T,TCompare>* addElement(BinaryTreeGNode<T,TCompare>*& node,
                                   T element);
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //      - None.
    //

    T* addElement(BinaryTreeGNode<T,TCompare>*& node,
                  TCompare element);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Return distance of the node from the last son.
    //
    // Contract :
    //      - None.
    //

    int getHeight(BinaryTreeGNode<T,TCompare>* node);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Return distance of the node from the last son ;
    //      - Use recursive call.
    //
    // Contract :
    //      - None.
    //


    void display(BinaryTreeGNode<T,TCompare>* node);
    // Parameters :
    //      - 'node' : correspond to a node, part of BinaryTreeG.
    //
    // Manual :
    //      - Recursive display of the son of 'node', the lowest to the highest (ASC ordering) ;
    //      - Use recursive call.
    //
    // Contract :
    //      - None
    //
};

//----------------------------------------------- Include of template file
#include "BinaryTreeG.tcc"

#endif // BINARYTREEG_H
