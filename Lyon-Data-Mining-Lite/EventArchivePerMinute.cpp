/*************************************************************************
 EventArchivePerMinute  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par F. Chastel && L. Cristol
 *************************************************************************/

//---------- Realization of <EventArchivePerMinute>'s class (fichier EventArchivePerMinute.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include
#include <iostream>

//---------------------------------------------------- Personnal's include
#include "EventArchivePerMinute.h"


//--------------------------------------------------------- Public methods
int EventArchivePerMinute::NbTimeGreenOccured()
// Algorithm :
//      Return the number of green's occurences
{   return greenOccured;
} //----- End of method


int EventArchivePerMinute::NbTimeYellowOccured()
// Algorithm :
//      Return the number of yellow's occurences
{   return yellowOccured;
} //----- End of method


int EventArchivePerMinute::NbTimeRedOccured()
// Algorithm :
//      Return the number of red's occurences
{   return redOccured;
} //----- End of method


int EventArchivePerMinute::NbTimeBlackOccured()
// Algorithm :
//      Return the number of black's occurences
{   return blackOccured;
} //----- End of method


void EventArchivePerMinute::InsertEvent(const char trafic)
// Algorithm :
//      Increasing occurence number of traffic's state
{   if (trafic == GREEN_TRAFFIC)
    {   greenOccured++;
    }
    else if (trafic == YELLOW_TRAFFIC)
    {   yellowOccured++;
    }
    else if (trafic == RED_TRAFFIC)
    {   redOccured++;
    }
    else if (trafic == BLACK_TRAFFIC)
    {   blackOccured++;
    }
} //----- End of method


//-------------------------------------------- Constructors - destructorr
EventArchivePerMinute::EventArchivePerMinute ( )
{
#ifdef MAP
    cout << "Call of <EventArchivePerMinute>'s constructor" << endl;
#endif
    greenOccured    = INITIAL_VALUE;
    yellowOccured   = INITIAL_VALUE;
    redOccured      = INITIAL_VALUE;
    blackOccured = INITIAL_VALUE;
} //----- End of EventArchivePerMinute


EventArchivePerMinute::~EventArchivePerMinute ( )
{
#ifdef MAP
    cout << "Call of <EventArchivePerMinute>'s destructor" << endl;
#endif

} //----- End of ~EventArchivePerMinute
