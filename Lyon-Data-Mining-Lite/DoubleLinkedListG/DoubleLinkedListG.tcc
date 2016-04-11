/*************************************************************************
 BinaryTreeG  -  description
 -------------------
 début                : 27/10/2015
 copyright            : (C) 2015 par F.Chastel
 *************************************************************************/

//---------- Réalisation de la classe <BinaryTreeG> (fichier DoubleLinkedList.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DoubleLinkedListG.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
template<typename T>
void DoubleLinkedListG<T>::insert(T value)
// Algorithme :
//
{
    LinkedList* nextElement = new LinkedList();
    LinkedList* tmp         = root;

    while ((tmp->next) != root)
    {
        tmp = tmp->next;
    }

    nextElement->previous   =  tmp;
    tmp->next->previous     = nextElement;

    nextElement->next       = tmp->next;
    tmp->next               = nextElement;

    nextElement->value      = value;

    numberOfElements++;
}

template<typename T>
bool DoubleLinkedListG<T>::remove(T value)
// Algorithme :
//
{
    
    LinkedList* tmp = root;
    LinkedList* removedValue;
    
    bool isDeleted = false;
    
    while ((tmp->next) != root && tmp->next->value <= value)
    {
        tmp = tmp->next;
        
        if (tmp->value == value)
        {
            tmp->previous->next     = tmp->next;
            tmp->next->previous     = tmp->previous;
            removedValue            = tmp;
            delete removedValue;
            isDeleted               = true;
            numberOfElements--;
        }
    }
    
    return isDeleted;
}

template<typename T>
bool DoubleLinkedListG<T>::removeRepititiveValues()
// Algorithme :
//
{
    LinkedList* tmp = root->next;
    LinkedList* removedValue;
    
    while ((tmp->next) != root)
    {
        if (tmp->value == tmp->next->value)
        {
            tmp->next->next->previous = tmp;
            removedValue              = tmp->next;
            tmp->next                 = tmp->next->next;
            free(removedValue);
        }
        else
        {
            tmp = tmp->next;
        }
    }
    
    return true;
}

template<typename T>
const T DoubleLinkedListG<T>::getLastElement()
// Algorithme :
//
{
    return root->previous->value;
}

template<typename T>
const T DoubleLinkedListG<T>::getFirstElement()
// Algorithme :
//
{
    if (root == NULL)
    {
        return NULL;
    }
    return root->value;
}

template<typename T>
const void DoubleLinkedListG<T>::display()
// Algorithme :
//
{
    LinkedList* tmp = root;
    
    while (tmp->next != root)
    {
        tmp = tmp->next;
        cout << tmp->value << SEPARATOR_CHAR;
    }

    cout << endl;
}

template<typename T>
const bool DoubleLinkedListG<T>::isEmpty()
// Algorithme :
//
{
    if (getFirstElement() != NULL)
    {
        return false;
    }
    return true;
}

template<typename T>
const int DoubleLinkedListG<T>::getNumberOfElements()
// Algorithme :
//
{
    return numberOfElements;
}

template<typename T>
const T DoubleLinkedListG<T>::getElement(int index)
// Algorithme :
//
{
    LinkedList* tmp = root;

    for (int cursor=INITIAL_VALUE; cursor<=index; cursor++)
    {
        tmp = tmp->next;
    }

    return tmp->value;
}

//-------------------------------------------- Constructeurs - destructeur
template<typename T>
DoubleLinkedListG<T>::DoubleLinkedListG ( )
// Algorithme :
//
{
    
#ifdef MAP
    cout << "Appel au constructeur de <DoubleLinkedList>" << endl;
#endif
    root            = new LinkedList();
    root->next      = root;
    root->previous  = root;

    numberOfElements= INITIAL_VALUE;

} //----- Fin de DoubleLinkedList


template<typename T>
DoubleLinkedListG<T>::~DoubleLinkedListG ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DoubleLinkedList>" << endl;
#endif
   
} //----- Fin de ~DoubleLinkedList


