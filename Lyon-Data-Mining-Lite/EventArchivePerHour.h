/*************************************************************************
 EventArchivePerHour  -  description
 -------------------
 Begin                : 21/10/2015
 Copyright            : (C) 2015 by F. Chastel && L. Cristol
 *************************************************************************/

//---------- Interface of <EventArchivePerHour>'s class (file EventArchivePerHour.h) -------
#if ! defined ( EVENTARCHIVEPERHOUR_H )
#define EVENTARCHIVEPERHOUR_H

//-------------------------------------------------------- Used interfaces
#include "EventArchivePerMinute.h"

//------------------------------------------------------------- Constantes
/**     Refs : config.h     **/


//------------------------------------------------------------------------
// Class's job <EventArchivePerHour>
//      Event's modelisation of an archive by hours which have been
//      inserted in a sensor. This class has been developed only for an
//      easiest code and conception comprehension purpose.
//------------------------------------------------------------------------

class EventArchivePerHour
{
    //------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Public Methods
    
    EventArchivePerMinute * GetArchivePerMinute();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void InsertEvent(const short int minute,
                     const char trafic);
    // Parameters :
    //      - 'minute'      : correspond to the minute when event happen ;
    //      - 'trafic'      :   correspond to a trafic's state.
    //
    // Manual :
    //      - Add an event to a sensor ;
    //      - 'minute' need to be strictly inferior or equal to 'MAX_MINUTE' and strictly
    //      superior or equal to 'MIN_MINUTE' ;
    //      - 'trafic' need to be equal to one of the four states, 'GREEN_TRAFFIC' or 'YELLOW_TRAFFIC
    //      or 'RED_TRAFFIC' or 'BLACK_TRAFFIC'.
    //
    // Contract :
    //      - None
    //

    //------------------------------------------------ Constructors - destructor
    EventArchivePerHour ( );
    // Manual :
    //      - Allocate memory for an array of 'NB_MINUTE' elements.
    //
    // Contract :
    //      - None.
    //

    virtual ~EventArchivePerHour ( );
    // Manual :
    //      - Destruct array EventArchivePerMinute
    //
    // Contrat :
    //      - None
    //

    //----------------------------------------------------------------- PRIVATE
    
protected:
    //---------------------------------------------------- Protected attributes
    EventArchivePerMinute * archivePerMinute;
};

#endif // EVENTARCHIVEPERHOUR_H
