/*************************************************************************
 EventArchivePerMinute  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par F. Chastel && L. Cristol
 *************************************************************************/

//---------- Interface of <EventArchivePerMinute>'s class (file EventArchivePerMinute.h) -------
#if ! defined ( EVENTARCHIVEPERMINUTE_H )
#define EVENTARCHIVEPERMINUTE_H

//------------------------------------------------------------- Constantes
#include "config.h"

//------------------------------------------------------------------------
// Class's job <EventArchivePerMinute>
//      Event's modelisation of an archive by minutes which have been
//      inserted in a sensor. This class has been developed only for an
//      easiest code and conception comprehension purpose.
//------------------------------------------------------------------------

class EventArchivePerMinute
{
    //------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Public Methods

    int NbTimeGreenOccured();
    // Manual :
    //      - Return number of green state occuring for a specific minute.
    //
    // Contract :
    //      - None
    //
    
    int NbTimeYellowOccured();
    // Manual :
    //      - Return number of yellow state occuring for a specific minute.

    //
    // Contract :
    //      - None
    //
    
    int NbTimeRedOccured();
    // Manual :
    //      - Return number of red state occuring for a specific minute.

    //
    // Contract :
    //      - None
    //
    
    int NbTimeBlackOccured();
    // Manual :
    //      - Return number of black state occuring for a specific minute.
    //
    // Contract :
    //      - None
    //
    
    
    void InsertEvent(const char trafic);
    // Parameters :
    //      - 'trafic' :  correspond to a trafic's state.
    //
    // Manual :
    //      - Add an event to a sensor ;
    //      - 'trafic' need to be equal to one of the four states, 'GREEN_TRAFFIC' or 'YELLOW_TRAFFIC
    //      or 'RED_TRAFFIC' or 'BLACK_TRAFFIC'.
    //
    // Contract :
    //      - None
    //


    //------------------------------------------------ Constructors - destructor
    EventArchivePerMinute ( );
    // Manual :
    //      - Initialize to INITIAL_VALUE, all the state's occurence (greenOccured, yellowOccured, redOccured and
    //      blackOccured).
    // Contract :
    //      - None
    //
    
    virtual ~EventArchivePerMinute ( );
    // Manual :
    // Contrat :
    //      - None
    //
    
    //----------------------------------------------------------------- PRIVATE
    
protected:
    //---------------------------------------------------- Protected attributes
    int greenOccured;
    int yellowOccured;
    int redOccured;
    int blackOccured;
    
};

#endif // EVENTARCHIVEPERMINUTE_H
