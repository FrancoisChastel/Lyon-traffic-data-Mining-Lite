/*************************************************************************
 EventArchivePerHour  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par F. Chastel && L. Cristol
 *************************************************************************/

//---------- Realization of <EventArchivePerHour>'s class (fichier EventArchivePerHour.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include

#include <iostream>

//---------------------------------------------------- Personnal's include
#include "EventArchivePerHour.h"

//--------------------------------------------------------- Public methods
EventArchivePerMinute * EventArchivePerHour::GetArchivePerMinute()
// Algorithme :
//
{
    return archivePerMinute;
} //----- Fin de Méthode


void EventArchivePerHour::InsertEvent(const short minute,
                                      const char trafic)
// Algorithme :
//
{
    archivePerMinute[minute].InsertEvent(trafic);
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
EventArchivePerHour::EventArchivePerHour ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Call of <EventArchivePerHour>'s constructor'" << endl;
#endif
    archivePerMinute = new EventArchivePerMinute[NB_MINUTE];
} //----- Fin de EventArchivePerHour



EventArchivePerHour::~EventArchivePerHour ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Call of <EventArchivePerHour>'s destructor" << endl;
#endif
    delete [] archivePerMinute;
} //----- Fin de ~EventArchivePerHour
