/*************************************************************************
 EventArchivePerDay  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par F. Chastel && L. Cristol
 *************************************************************************/

//---------- Realization of <EventArchivePerDay>'s class (fichier EventArchivePerDay.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include
#include <iostream>

//---------------------------------------------------- Personnal's include
#include "EventArchivePerDay.h"


//--------------------------------------------------------- Public methods


EventArchivePerHour * EventArchivePerDay::GetArchivePerHour()
// Algorithm :
//
{
    return archivePerHour;
} //----- Fin de Méthode


void EventArchivePerDay::InsertEvent(const short hour,
                                     const short minute,
                                     const char trafic)
// Algorithme :
//
{
    archivePerHour[hour].InsertEvent(minute, trafic);
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
EventArchivePerDay::EventArchivePerDay ( )
// Algorithme :
//
{
    #ifdef MAP
    cout << "Call of <EventArchivePerDay>'s constructor" << endl;
    #endif
    archivePerHour = new EventArchivePerHour[NB_HOUR];
} //----- Fin de EventArchivePerDay



EventArchivePerDay::~EventArchivePerDay ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Call of <EventArchivePerDay>'s destructor" << endl;
#endif
    delete [] archivePerHour;
} //----- Fin de ~EventArchivePerDay
