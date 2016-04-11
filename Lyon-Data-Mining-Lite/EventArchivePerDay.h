/*************************************************************************
 EventArchivePerDay  -  description
 -------------------
 Begin                : 21/10/2015
 Copyright            : (C) 2015 by F. Chastel && L. Cristol
 *************************************************************************/

//---------- Interface of <EventArchivePerDay>'s class (file EventArchivePerDay.h) -------
#if ! defined ( EVENTARCHIVEPERDAY_H )
#define EVENTARCHIVEPERDAY_H

//-------------------------------------------------------- Used interfaces
#include "EventArchivePerHour.h"

//------------------------------------------------------------- Constantes
/**     Refs : config.h     **/


//------------------------------------------------------------------------
// Class's job <EventArchivePerDay>
//      Event's modelisation of an archive by days which have been
//      inserted in a sensor. This class has been developed only for an
//      easiest code and conception comprehension purpose.
//------------------------------------------------------------------------

class EventArchivePerDay
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    
    
    EventArchivePerHour * GetArchivePerHour();
    // Manual :
    //      - Return array correspond to ArchivePerHour.
    //
    // Contrat :
    //      - None.

    void InsertEvent(const short int hour,
                     const short int minute,
                     const char trafic);
    // Parameters :
    //      - 'hour'     : correspond to the hour when event happen ;
    //      - 'minute'   : correspond to the minute when event happen ;
    //      - 'trafic'   : correspond to a trafic's state.
    //
    // Manual :
    //      - Add an event to a sensor ;
    //      - 'hour' need to be strictly inferior or equal to 'MAX_HOUR' and strictly
    //      superior or equal to 'MIN_HOUR' ;
    //      - 'minute' need to be strictly inferior or equal to 'MAX_MINUTE' and strictly
    //      superior or equal to 'MIN_MINUTE' ;
    //      - 'trafic' need to be equal to one of the four states, 'GREEN_TRAFFIC' or 'YELLOW_TRAFFIC
    //      or 'RED_TRAFFIC' or 'BLACK_TRAFFIC'.
    //
    // Contract :
    //      - None.
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    EventArchivePerDay ( );
    // Manual :
    //      - Allocate memory for an array of 'NB_HOUR' elements.
    //
    // Contract :
    //      - None.
    //

    virtual ~EventArchivePerDay ( );
    // Manual :
    //      - Destruct array archivePerHour.
    //
    // Contract :
    //      - None.

    //----------------------------------------------------------------- PRIVATE

protected:
    //---------------------------------------------------- Protected attributes
    EventArchivePerHour * archivePerHour;
};

#endif // EVENTARCHIVEPERDAY_H
