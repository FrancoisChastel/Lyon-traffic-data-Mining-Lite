/*************************************************************************
 SensorTree
 -------------------
 Begin                : 21/10/2015
 copyright            : (C) 2015 by F. Chastel && L. Cristol
 *************************************************************************/

//---------- Interface of <SensorTree>'s class (file SensorTree.h) -------
#if ! defined ( SENSORTREE_H )
#define SENSORTREE_H

//-------------------------------------------------------- Used interfaces
#include "BinaryTreeG/BinaryTreeG.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes
    /**     Refs : config.h     **/

//------------------------------------------------------------------------
// Class's job <SensorTree>
//      Binary tree's modelization of sensors
//
//------------------------------------------------------------------------

class SensorTree
{
    //------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Public Methods
    
    void AddEventToSensor(const long sensorId,
                          const int year,
                          const int month,
                          const int day,
                          const int hour,
                          const int minute,
                          const char trafic);
    // Parameters :
    //      - 'sensorId'    : correspond to a sensor's id ;
    //      - 'year'        : correspond to the year when event happen ;
    //      - 'month'       : correspond to the month when event happen ;
    //      - 'day'         : correspond to the day when event happen ;
    //      - 'hour'        : correspond to the hour when event happen ;
    //      - 'minute'      : correspond to the minute when event happen ;
    //      - 'trafic'      :   correspond to a trafic's state.
    //
    // Manual :
    //      - Add an event to a sensor ;
    //      - If there is no sensor with a SensorId equal to 'sensorId' in parameter
    //      a new sensor is created ;
    //      - If there is a sensor with a SensorId equal to 'sensorId' an event is
    //      created ;
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

    void StatisticsForSensor(const long sensorId);
    // Parameters :
    //      - 'sensorId'  : correspond to the sensor's sensorId concerned by the statistics.
    //
    // Manual :
    //      - Print in standard output (linux's meaning) statistics (in percentage) for a day
    //      of the trafic's differents states (which can be 'GREEN_TRAFFIC' or 'YELLOW_TRAFFIC
    //      or 'RED_TRAFFIC' or 'BLACK_TRAFFIC') for a sensor with a SensorId equal to 'sensorId';
    //
    // Contract :
    //      - None
    //

    void TraficJamPerDayPerHour(const short int day);
    // Parameters :
    //      - 'day'  : correspond to the day concerned by the statistics.
    //
    // Manual :
    //      - Print in standard output (linux's meaning) statistics (in percentage) for all hours of a 'day'
    //      of the jam's occurence (which can be 'RED_TRAFFIC' or 'BLACK_TRAFFIC') for all the sensor(s) ;
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY' ;
    //
    // Contrat :
    //      - None

    void TraficStatisticsForADay(const short int day);
    // Parameters :
    //      - 'day'  : correspond to the day concerned by the statistics.
    //
    // Manual :
    //      - Print in standard output (linux's meaning) statistics (in percentage) for a 'day'
    //      of the trafic's differents states (which can be 'GREEN_TRAFFIC' or 'YELLOW_TRAFFIC
    //      or 'RED_TRAFFIC' or 'BLACK_TRAFFIC') for all the sensor(s) ;
    //      - 'day' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY ;
    //
    // Contract :
    //      - None

    void OptimalTimeOfLeaving(const int dayOfDeparture,
                              const int startHour,
                              const int endHour,
                              const int*sensorsToExplore,
                              const int size);
    // Parameters :
    //      - 'dayOfDeparture'  : correspond to a departure day ;
    //      - 'startHour'       : correspond to the starting hour which can potentially
    //                            be the sooner hour of departure ;
    //      - 'endHour'         : correspond to the ending hour which can potentially
    //                            be the sooner hour of departure ;
    //      - 'nodesToExplore'  : correspond to the list of sensors which compose path ;
    //      - 'size'            : correspond to the size of 'sensorsToExplore' ;
    //
    // Manual :
    //      - Print in standard output (linux's meaning) best time of leaving at specific 'dayOfDeparture'
    //      between 'startHour' and 'endHour' with a path of N 'sensorsToExplore', it will print in standard
    //      output day of leaving, hour of leaving, munute of leaving and the time to complete the path ;
    //      - 'dayOfDeparture' need to be strictly inferior or equal to 'MAX_DAY' and strictly
    //      superior or equal to 'MIN_DAY' ;
    //      - 'startHour' need to be strictly inferior or equal to 'MAX_HOUR' and strictly
    //      superior or equal to 'MIN_HOUR' ;
    //      - 'endHour' need to be strictly inferior or equal to 'MAX_HOUR' and strictly
    //      superior or equal to 'MIN_HOUR' and endHour need to be stricly superior or equal to 'startHour' ;
    //
    // Contract :
    //      - 'size' need to be the exact size in memory of 'sensorsToExplore'.

    //-------------------------------------------- Constructeurs - destructeur
    SensorTree ( );
    // Manual :
    //      - Initialize an instance of BinaryTreeG.
    // Contract :
    //      - None

    
    virtual ~SensorTree ( );
    // Manual :
    //      - Free root, an instance of BinaryTreeG.
    // Contract :
    //      - None

    //----------------------------------------------------------------- PRIVATE
    
protected:
    //---------------------------------------------------- Protected attributes
    BinaryTreeG<Sensor, long>* binaryTreeG;
    
    //------------------------------------------------------- Protected methods
    Sensor * SearchSensorForId(const long sensorId);
    // Parameters :
    //      - 'sensorId'  : correspond to a sensor's id ;
    //
    // Manual :
    //      - Search in the tree a sensor with an id equal to 'sensorId'.
    //
    // Contract :
    //      - None.
    
    void TraficJamPerDayPerHour(const short int day,
                                int* jamOccured,
                                int* totalOccured);
    // Parameters :
    //      - 'day'         : correspond to the day concerned by the statistics ;
    //      - 'jamOccured'  : correspond to a one-d matrix by hour of jam occuring ;
    //      - 'totalOccured': correspond to a one-d matrix by hour of all of the events occuring.
    //
    // Manual :
    //      - Search in the tree a sensor with an id equal to 'sensorId'.
    //
    // Contract :
    //      - None.
    
    void TraficJamPerDayPerHour(BinaryTreeGNode<Sensor,long>*& node,
                                const short int day,
                                int* jamOccured,
                                int* totalOccured);
    // Parameters :
    //      - 'node'        : correspond to the node and all his son concerned by the statistics
    //                        (be careful by the recursive's call) ;
    //      - 'day'         : correspond to the day concerned by the statistics ;
    //      - 'jamOccured'  : correspond to a one-d matrix by hour of jam occuring ;
    //      - 'totalOccured': correspond to a one-d matrix by hour of all of the events occuring.
    //
    // Manual :
    //      - Search in the tree a sensor with an id equal to 'sensorId'.
    //
    // Contract :
    //      - None.
    
    
    void TraficStatisticForADay(const short int day,
                                int* greenOccured,
                                int* yellowOccured,
                                int* redOccured,
                                int* blackOccured);
    // Parameters :
    //      - 'day'          : correspond to the day concerned by the statistics ;
    //      - 'greenOccured' : correspond to a one-d matrix by hour of green state occuring ;
    //      - 'yellowOccured': correspond to a one-d matrix by hour of yellow state occuring ;
    //      - 'redOccured'   : correspond to a one-d matrix by hour of red state occuring ;
    //      - 'blackOccured' : correspond to a one-d matrix by hour of black state occuring.
    //
    // Manual :
    //      - Search in the tree a sensor with an id equal to 'sensorId'.
    //
    // Contract :
    //      - None.
    
    void TraficStatisticForADay(BinaryTreeGNode<Sensor,long>*& node,
                                const short int day,
                                int* greenOccured,
                                int* yellowOccured,
                                int* redOccured,
                                int* blackOccured);
    // Parameters :
    //      - 'node'         : correspond to the node and all his son concerned by the statistics
    //                         (be careful by the recursive's call) ;
    //      - 'day'          : correspond to the day concerned by the statistics ;
    //      - 'greenOccured' : correspond to a one-d matrix by hour of green state occuring ;
    //      - 'yellowOccured': correspond to a one-d matrix by hour of yellow state occuring ;
    //      - 'redOccured'   : correspond to a one-d matrix by hour of red state occuring ;
    //      - 'blackOccured' : correspond to a one-d matrix by hour of black state occuring.
    //
    // Manual :
    //      - Search in the tree a sensor with an id equal to 'sensorId'.
    //
    // Contract :
    //      - None.
};

#endif // SENSORTREE_H
