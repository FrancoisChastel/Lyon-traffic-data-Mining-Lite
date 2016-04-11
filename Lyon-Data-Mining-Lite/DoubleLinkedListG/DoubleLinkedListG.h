/*************************************************************************
 DoubleLinkedList  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par F. Chastel && L. Cristol
 *************************************************************************/

//---------- Interface de la classe <EventArchivePerMinute> (fichier DoubleLinkedList.h) ------
#if ! defined ( DOUBLELINKEDLIST_H )
#define DOUBLELINKEDLIST_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DoubleLinkedList>
//
//
//------------------------------------------------------------------------

template<typename T>
class DoubleLinkedListG
{
    
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques
    
    void insert(T value);
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool remove(T value);
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool removeRepititiveValues();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const T getLastElement();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const T getElement(int index);
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const T getFirstElement();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const int getNumberOfElements();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const void display();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void empty();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const bool isEmpty();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    DoubleLinkedListG ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~DoubleLinkedListG ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    typedef struct LinkedLists{
        T value;
        struct LinkedLists* previous;
        struct LinkedLists* next;
    }LinkedList;

    //----------------------------------------------------- Attributs protégés
    LinkedList* root;
    int numberOfElements;
};

#include "DoubleLinkedListG.tcc"

//----------------------------------------- Types dépendants de <DoubleLinkedList>


#endif // DOUBLELINKEDLIST_H
