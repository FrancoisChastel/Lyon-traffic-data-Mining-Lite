/*************************************************************************
 Sensor  -  description
 -------------------
 début                : 21/10/2015
 copyright            : (C) 2015 par F. Chastel && L. Cristol
 *************************************************************************/

//---------- Interface of <Sensor>'s class (file Sensor.h) -------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//-------------------------------------------------------- Used interfaces
#include "EventArchivePerDay.h"

//------------------------------------------------------------------------
// Class's job <Sensor>
//      Sensor modelization providing intel about trafic's state.
//
//------------------------------------------------------------------------

class Sensor
{
    //-------------------------------------------------------------- PUBLIC
    
public:
    //-------------------------------------------------------Public Methods
    
    EventArchivePerDay * GetArchivePerDay();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void InsertEvent(const int year,
                     const int month,
                     const int day,
                     const int hour,
                     const int minute,
                     const char trafic);
    // Parameters :
    //      - 'year'        : correspond to the year when event happen ;
    //      - 'month'       : correspond to the month when event happen ;
    //      - 'day'         : correspond to the day when event happen ;
    //      - 'hour'        : correspond to the hour when event happen ;
    //      - 'minute'      : correspond to the minute when event happen ;
    //      - 'trafic'      :   correspond to a trafic's state.
    //
    // Manual :
    //      - Add an event to a sensor ;
    //      - 'year' need to be strictly inferior or equal to 'MAX_YEAR' and strictly
    //      superior or equal to 'MIN_YEAR' ;
    //      - 'month' need to be strictly inferior or equal to 'MAX_MONTH' and strictly
    //      superior or equal to 'MIN_MONTH'
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY' ;
    //      - 'hour' need to be strictly inferior or equal to 'MAX_HOUR' and strictly
    //      superior or equal to 'MIN_HOUR' ;
    //      - 'minute' need to be strictly inferior or equal to 'MAX_MINUTE' and strictly
    //      superior or equal to 'MIN_MINUTE' ;
    //      - 'trafic' need to be equal to one of the four states, 'GREEN_TRAFFIC' or 'YELLOW_TRAFFIC
    //      or 'RED_TRAFFIC' or 'BLACK_TRAFFIC'.
    //
    // Contract :
    //      - None
    //
    
    void StatisticsForSensor();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int TimeOfWaitingTraffic(const short int day,
                             const short int hour,
                             const short int minute);
    // Parameters :
    //      - 'day'         : correspond to the day when we want time of waiting in traffic ;
    //      - 'hour'        : correspond to the hour when we want time of waiting in traffic ;
    //      - 'minute'      : correspond to the minute when we want time of waiting in traffic.
    //
    // Manual :
    //      - Return a int of the time of waiting in traffic in function of the most representative state of traffic ;
    //      - If all the states are equally representative, program call 'TimeOfWaitingTrafficByAverage';
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY' ;
    //      - 'hour' need to be strictly inferior or equal to 'MAX_HOUR' and strictly
    //      superior or equal to 'MIN_HOUR' ;
    //      - 'minute' need to be strictly inferior or equal to 'MAX_MINUTE' and strictly
    //      superior or equal to 'MIN_MINUTE'.
    //
    // Contract :
    //      - None
    //
    
    int TimeOfWaitingTrafficByAverage(const short int day);
    // Parameters :
    //      - 'day'         : correspond to the day when we want time of waiting in traffic.
    //
    // Manual :
    //      - Return a int of the time of waiting in traffic in function of the most representative state of traffic
    //      for a day ;
    //      - If all the states are equally representative, program return DEFAULT_WAITING_TIME ;
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY'.
    //
    // Contract :
    //      - None
    //

    void StatisticsDayForSensor(const short int day, int* greenOccured, int* yellowOccured, int* redOccured, int* blackOccured);
    // Parameters :
    //      - 'day'             : correspond to the day when we statistics ;
    //      - 'greenOccured'    : correspond to the number of green occurence(s). Will be modify in the function ;
    //      - 'yellowOccured'   : correspond to the number of yellow occurence(s). Will be modify in the function ;
    //      - 'redOccured'      : correspond to the number of red occurence(s). Will be modify in the function ;
    //      - 'blackOccured'    : correspond to the number of black occurence(s). Will be modify in the function.
    //
    // Manual :
    //      - Modify 'greenOccured', 'yellowOccured', 'redOccured' and 'blackOccured' in order to get statstics
    //      for a day of each sensor's states ;
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY'.
    //
    // Contract :
    //      - None
    //
    
    void StatisticsJamPerHourByHourForSensor(const short int day, int* jamOccured, int* totalOccured);
    // Parameters :
    //      - 'day'             : correspond to the day when we statistics ;
    //      - 'jamOccured'      : correspond to the number of jam occurence(s). Will be modify in the function ;
    //      - 'totalOccured'    : correspond to the number of total state occurence(s). Will be modify in the function ;
    //
    // Manual :
    //      - Modify 'jamOccured' and 'totalOccured' in order to get jam statistics of a sensor for a day ;
    //      - Jam is consider to be state equal to 'RED_TRAFFIC' or 'BLACK_TRAFFIC' ;
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY'.
    //
    // Contract :
    //      - None
    //

    long GetSensorId();
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool operator<(Sensor*  element_2);
    // Parameters :
    //      - 'element_2'  : correspond to a adress of initialize sensor.
    //
    // Manual :
    //      - Specify the '<' operator's behavior with a Sensor.
    //
    // Contract :
    //      - None
    //

    bool operator>(Sensor*  element_2);
    // Parameters :
    //      - 'element_2'  : correspond to a adress of initialize sensor.
    //
    // Manual :
    //      - Specify the '>' operator's behavior with a Sensor.
    //
    // Contract :
    //      - None
    //

    bool operator==(Sensor*  element_2);
    // Parameters :
    //      - 'element_2'  : correspond to a adress of initialize sensor.
    //
    // Manual :
    //      - Specify the '==' operator's behavior with a Sensor.
    //
    // Contract :
    //      - None
    //

    bool operator<(const long  element_2);
    // Parameters :
    //      - 'element_2'  : correspond to a int.
    //
    // Manual :
    //      - Specify the '<' operator's behavior with a int.
    //
    // Contract :
    //      - None
    //

    bool operator>(const long element_2);
    // Parameters :
    //      - 'element_2'  : correspond to a int.
    //
    // Manual :
    //      - Specify the '>' operator's behavior with a int.
    //
    // Contract :
    //      - None
    //

    bool operator==(const long element_2);
    // Parameters :
    //      - 'element_2'  : correspond to a int.
    //
    // Manual :
    //      - Specify the '==' operator's behavior with a int.
    //
    // Contract :
    //      - None
    //

    //------------------------------------------------ Constructors - destructor
    Sensor ( );
    // Manual :
    //      - Initialize an array of NB_DAY element ;
    //      - Affect DEFAULT_SENSOR_ID to sensorId's attribute.
    //
    // Contract :
    //      - None
    
    Sensor(long sensorId);
    // Manual :
    //      - Initialize an array of NB_DAY element ;
    //      - Affect 'sensorId' to sensorId's attribute.
    //
    // Contract :
    //      - None
    
    virtual ~Sensor ( );
    // Manual :
    //      - Destroy array archivePerDay
    // Contract :
    //      - None

    //---------------------------------------------------------------- PRIVATE

protected:
    //---------------------------------------------------- Protected attributes
    long sensorId;
    EventArchivePerDay * archivePerDay;
};

#endif // SENSOR_H
