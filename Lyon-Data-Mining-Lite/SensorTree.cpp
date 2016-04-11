/*************************************************************************
 SensorTree  -  description
 -------------------
 Begin                : 21/10/2015
 copyright            : (C) 2015 ny F. Chastel && L. Cristol
 *************************************************************************/

//---------- Realization of <SensorTree>'s class (fichier SensorTree.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include
#include <iostream>

//---------------------------------------------------- Personnal's include
#include "SensorTree.h"

//--------------------------------------------------------- Public methods
void SensorTree::AddEventToSensor(const long sensorId,
                                  const int year,
                                  const int month,
                                  const int day,
                                  const int hour,
                                  const int minute,
                                  const char trafic)
// Algorithme :
//
{
    (binaryTreeG->addElement(sensorId))->InsertEvent(year, month, day, hour, minute, trafic);
} //----- End of method


void SensorTree::TraficJamPerDayPerHour(const short int day)
// Algorithme :
//
{
    int * jamOccured    = new int[NB_HOUR];
    int * totalOccured  = new int[NB_HOUR];
    
    for (int indexHour = INITIAL_LOOP_VALUE; indexHour < NB_HOUR ; indexHour ++)
    {   jamOccured[indexHour]   = INITIAL_VALUE;
        totalOccured[indexHour] = INITIAL_VALUE;
    }

    TraficJamPerDayPerHour(day, jamOccured, totalOccured);

    for (int indexHour = INITIAL_LOOP_VALUE; indexHour < NB_HOUR ; indexHour++)
    {   int trafficJam = INITIAL_VALUE;
        if (totalOccured[indexHour] != INITIAL_VALUE)
        {   trafficJam = PERCENTAGE_VALUE * (jamOccured[indexHour]) / totalOccured[indexHour];
            cout << DAY_CHAR << day << TABULATION_CHAR << indexHour << TABULATION_CHAR << trafficJam    << PERCENTAGE_CHAR << endl;
        }
        else
        {   cout << DAY_CHAR << day << TABULATION_CHAR << indexHour << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << endl;
        }
    }
} //----- End of method


void SensorTree::TraficStatisticsForADay(const short int day)
// Algorithme :
//
{
    int greenOccured  = INITIAL_VALUE;
    int yellowOccured = INITIAL_VALUE;
    int redOccured    = INITIAL_VALUE;
    int blackOccured  = INITIAL_VALUE;
    
    TraficStatisticForADay(day, &greenOccured, &yellowOccured, &redOccured, &blackOccured);
    
    int total       = INITIAL_VALUE;
    int greenStat   = INITIAL_VALUE;
    int yellowStat  = INITIAL_VALUE;
    int redStat     = INITIAL_VALUE;
    int blackStat   = INITIAL_VALUE;
    
    total       = greenOccured + yellowOccured + redOccured + blackOccured;
    if (total != INITIAL_VALUE)
    {   greenStat   = PERCENTAGE_VALUE * greenOccured  / total;
        yellowStat  = PERCENTAGE_VALUE * yellowOccured / total;
        redStat     = PERCENTAGE_VALUE * redOccured    / total;
        blackStat   = PERCENTAGE_VALUE * blackOccured  / total;
        
        cout << GREEN_TRAFFIC   << TABULATION_CHAR << greenStat << PERCENTAGE_CHAR << endl;
        cout << YELLOW_TRAFFIC  << TABULATION_CHAR << yellowStat<< PERCENTAGE_CHAR << endl;
        cout << RED_TRAFFIC     << TABULATION_CHAR << redStat   << PERCENTAGE_CHAR << endl;
        cout << BLACK_TRAFFIC   << TABULATION_CHAR << blackStat << PERCENTAGE_CHAR << endl;
    }
    else
    {   cout << GREEN_TRAFFIC   << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << endl;
        cout << YELLOW_TRAFFIC  << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << endl;
        cout << RED_TRAFFIC     << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << endl;
        cout << BLACK_TRAFFIC   << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << endl;
    }
} //----- End of method


void SensorTree::OptimalTimeOfLeaving(const int dayOfDeparture,
                                      const int startHour,
                                      const int endHour,
                                      const int* sensorsToExplore,
                                      const int size)
{
    int bestHour=INITIAL_VALUE;
    int bestMinute=INITIAL_VALUE;

    int tmpHourOfRide;
    int tmpMinuteOfRide;

    int bestTimeOfRide=MAX_VALUE_INT;
    
    for (int cursorHour = startHour; cursorHour < endHour; cursorHour++)
    {   for (int indexMinute = INITIAL_LOOP_VALUE; indexMinute < NB_MINUTE; indexMinute++)
        {   tmpHourOfRide=INITIAL_VALUE;
            tmpMinuteOfRide=INITIAL_VALUE;
            
            for(int cursorNode = INITIAL_LOOP_VALUE; cursorNode < size && (tmpHourOfRide*60)+tmpMinuteOfRide < bestTimeOfRide; cursorNode++)
            {   while (tmpMinuteOfRide+indexMinute >= NB_MINUTE)
                {   tmpHourOfRide++;
                    tmpMinuteOfRide-=NB_MINUTE;
                }
                tmpMinuteOfRide += SearchSensorForId(sensorsToExplore[cursorNode])->TimeOfWaitingTraffic(dayOfDeparture,
                                                                                                         tmpHourOfRide+cursorHour,
                                                                                                         tmpMinuteOfRide+indexMinute);
            }
            
            if ((tmpHourOfRide*60)+tmpMinuteOfRide < bestTimeOfRide)
            {   bestTimeOfRide = (tmpHourOfRide*60)+tmpMinuteOfRide;
                bestHour = cursorHour;
                bestMinute = indexMinute;
            }

        }
    }
        
    
    cout << dayOfDeparture << TABULATION_CHAR << bestHour << TABULATION_CHAR << bestMinute << TABULATION_CHAR << bestTimeOfRide << endl;
} //----- End of method


//----------------------------------------------------- Protected methods

void SensorTree::StatisticsForSensor(const long sensorId)
// Algorithme :
//
{
    SearchSensorForId(sensorId)->StatisticsForSensor();
} //----- End of method


void SensorTree::TraficJamPerDayPerHour(const short int day,
                                        int* jamOccured,
                                        int* totalOccured)
{
    BinaryTreeGNode<Sensor,long>* root = binaryTreeG->GetRoot();
    
    if (root != NULL)
    {   TraficJamPerDayPerHour(root,day, jamOccured,totalOccured);
    }
} //----- End of method


void SensorTree::TraficJamPerDayPerHour(BinaryTreeGNode<Sensor, long>*& node,
                                        const short int day,
                                        int* jamOccured,
                                        int* totalOccured)
{
    if (node != NULL)
    {   node->node->StatisticsJamPerHourByHourForSensor(day,jamOccured,totalOccured);
        TraficJamPerDayPerHour(node->leftSon,day,jamOccured,totalOccured);
        TraficJamPerDayPerHour(node->rightSon,day,jamOccured,totalOccured);
    }
}


Sensor * SensorTree::SearchSensorForId(const long sensorId)
// Algorithme :
//
{
    Sensor * tmp = binaryTreeG->searchElement(sensorId);
    return tmp;
} //----- End of method


void SensorTree::TraficStatisticForADay(const short int day,
                                        int* greenOccured,
                                        int* yellowOccured,
                                        int* redOccured,
                                        int* blackOccured)
{
    BinaryTreeGNode<Sensor, long>* root = binaryTreeG->GetRoot();
    
    if (root != NULL)
    {   TraficStatisticForADay(root,day,greenOccured,yellowOccured,redOccured,blackOccured);
    }
} //----- End of method


void SensorTree::TraficStatisticForADay(BinaryTreeGNode<Sensor, long>*& node,
                                        const short int day,
                                        int* greenOccured,
                                        int* yellowOccured,
                                        int* redOccured,
                                        int* blackOccured)
{
    if (node != NULL)
    {   node->node->StatisticsDayForSensor(day,greenOccured,yellowOccured,redOccured,blackOccured);
        TraficStatisticForADay(node->leftSon,day,greenOccured,yellowOccured,redOccured,blackOccured);
        TraficStatisticForADay(node->rightSon,day,greenOccured,yellowOccured,redOccured,blackOccured);
    }
} //----- End of method

//-------------------------------------------- Constructors - destructor
SensorTree::SensorTree ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Call of <SensorTree>'s constructor" << endl;
#endif
    binaryTreeG = new BinaryTreeG<Sensor, long>;
} //----- End of SensorTree




SensorTree::~SensorTree ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Call of <SensorTree>'s destructor" << endl;
#endif
    delete binaryTreeG;
} //----- End of ~SensorTree
