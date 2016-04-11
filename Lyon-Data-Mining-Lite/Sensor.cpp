/*************************************************************************
 Sensor  -  description
 -------------------
 Begin                : 21/10/2015
 copyright            : (C) 2015 by F. Chastel && L. Cristol
 *************************************************************************/

//---------- Realization of <Sensor>'s class (fichier Sensor.cpp) --

//---------------------------------------------------------------- INCLUDE
static int compteur = 0;
//------------------------------------------------------- System's include
#include <iostream>

//---------------------------------------------------- Personnal's include
#include "Sensor.h"

//--------------------------------------------------------- Public methods
EventArchivePerDay * Sensor::GetArchivePerDay()
// Algorithme :
//
{
    return archivePerDay;
}

void Sensor::InsertEvent(const int year,
                         const int month,
                         const int day,
                         const int hour,
                         const int minute,
                         const char trafic)
// Algorithme :
//
{
    if (   (year >= MIN_YEAR && year <= MAX_YEAR)
        && (month >= MIN_MONTH && month <= MAX_MONTH)
        && (day >= MIN_DAY && day <= MAX_DAY)
        && (hour >= MIN_HOUR && hour <= MAX_HOUR)
        && (minute >= MIN_MINUTE && minute <= MAX_MINUTE)
        && (trafic == GREEN_TRAFFIC || trafic == YELLOW_TRAFFIC || trafic == RED_TRAFFIC || trafic == BLACK_TRAFFIC ))
    {   archivePerDay[day-1].InsertEvent(hour, minute, trafic);
    }
} //----- End of method

void Sensor::StatisticsJamPerHourByHourForSensor(const short int day,
                                                 int* jamOccured,
                                                 int* totalOccured)
// Algorithme :
//
{
    for (int indexHour = INITIAL_LOOP_VALUE; indexHour < NB_HOUR; indexHour++)
    {   for (int indexMinute = INITIAL_LOOP_VALUE; indexMinute < NB_MINUTE ; indexMinute++)
        {   jamOccured[indexHour]   += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeRedOccured();
            jamOccured[indexHour]   += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeBlackOccured();
            
            totalOccured[indexHour] += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeRedOccured();
            totalOccured[indexHour] += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeBlackOccured();
            totalOccured[indexHour] += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeGreenOccured();
            totalOccured[indexHour] += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeYellowOccured();
        }
    }

} //----- End of method

void Sensor::StatisticsDayForSensor(const short int day,
                                    int* greenOccured,
                                    int* yellowOccured,
                                    int* redOccured,
                                    int* blackOccured)
// Algorithme :
//
{
    for (int indexHour = INITIAL_LOOP_VALUE; indexHour < NB_HOUR; indexHour++)
    {   for (int indexMinute = INITIAL_LOOP_VALUE; indexMinute < NB_MINUTE ; indexMinute++)
        {   *greenOccured   += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeGreenOccured();
            *yellowOccured  += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeYellowOccured();
            *redOccured     += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeRedOccured();
            *blackOccured   += archivePerDay[day-1].GetArchivePerHour()[indexHour].GetArchivePerMinute()[indexMinute].NbTimeBlackOccured();
        }
    }

} //----- End of method

void Sensor::StatisticsForSensor()
// Algorithme :
//
{
    int greenOccured  = INITIAL_VALUE;
    int yellowOccured = INITIAL_VALUE;
    int redOccured    = INITIAL_VALUE;
    int blackOccured  = INITIAL_VALUE;

    for (int i = MIN_DAY; i <= NB_DAY ; i++)
    {  StatisticsDayForSensor(i, &greenOccured,&yellowOccured,&redOccured,&blackOccured);
    }
    
    int greenStat   = INITIAL_VALUE;
    int yellowStat  = INITIAL_VALUE;
    int redStat     = INITIAL_VALUE;
    int blackStat   = INITIAL_VALUE;
    
    int total = greenOccured + yellowOccured + redOccured + blackOccured;

    if (total != INITIAL_VALUE)
    {   greenStat   = PERCENTAGE_VALUE * greenOccured   / total;
        yellowStat  = PERCENTAGE_VALUE * yellowOccured  / total;
        redStat     = PERCENTAGE_VALUE * redOccured     / total;
        blackStat   = PERCENTAGE_VALUE * blackOccured   / total;
        
        std::cout << GREEN_TRAFFIC   << TABULATION_CHAR << greenStat << PERCENTAGE_CHAR << std::endl;
        std::cout << YELLOW_TRAFFIC  << TABULATION_CHAR << yellowStat<< PERCENTAGE_CHAR << std::endl;
        std::cout << RED_TRAFFIC     << TABULATION_CHAR << redStat   << PERCENTAGE_CHAR << std::endl;
        std::cout << BLACK_TRAFFIC   << TABULATION_CHAR << blackStat << PERCENTAGE_CHAR << std::endl;
    }
    else
    {   std::cout << GREEN_TRAFFIC   << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << std::endl;
        std::cout << YELLOW_TRAFFIC  << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << std::endl;
        std::cout << RED_TRAFFIC     << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << std::endl;
        std::cout << BLACK_TRAFFIC   << TABULATION_CHAR << INITIAL_VALUE << PERCENTAGE_CHAR << std::endl;
    }

} //----- End of method

int Sensor::TimeOfWaitingTraffic(const short int day,
                                 const short int hour,
                                 const short int minute)
// Algorithme :
//
{
    int greenOccured  = INITIAL_VALUE;
    int yellowOccured = INITIAL_VALUE;
    int redOccured    = INITIAL_VALUE;
    int blackOccured  = INITIAL_VALUE;

    greenOccured  = archivePerDay[day-1].GetArchivePerHour()[hour].GetArchivePerMinute()[minute].NbTimeGreenOccured();
    yellowOccured = archivePerDay[day-1].GetArchivePerHour()[hour].GetArchivePerMinute()[minute].NbTimeYellowOccured();
    redOccured    = archivePerDay[day-1].GetArchivePerHour()[hour].GetArchivePerMinute()[minute].NbTimeRedOccured();
    blackOccured  = archivePerDay[day-1].GetArchivePerHour()[hour].GetArchivePerMinute()[minute].NbTimeBlackOccured();

    if(greenOccured>yellowOccured && greenOccured>redOccured && greenOccured>blackOccured)
    {   return GREEN_WAITING_TIME;
    }
    else if(yellowOccured>greenOccured && yellowOccured>redOccured && yellowOccured>blackOccured)
    {   return YELLOW_WAITING_TIME;
    }
    else if(redOccured>greenOccured && redOccured>yellowOccured && redOccured>blackOccured)
    {   return RED_WAITING_TIME;
    }
    else if (blackOccured>greenOccured && blackOccured>yellowOccured && blackOccured>redOccured)
    {   return BLACK_WAITING_TIME;
    }
    else
    {   return TimeOfWaitingTrafficByAverage(day);
    }
    
    
} //----- End of method

int Sensor::TimeOfWaitingTrafficByAverage(const short int day)
// Algorithme :
//
{
    int greenOccured  = INITIAL_VALUE;
    int yellowOccured = INITIAL_VALUE;
    int redOccured    = INITIAL_VALUE;
    int blackOccured  = INITIAL_VALUE;
    
    StatisticsDayForSensor(day, &greenOccured,&yellowOccured,&redOccured,&blackOccured);
    
    if(greenOccured>yellowOccured && greenOccured>redOccured && greenOccured>blackOccured)
    {   return GREEN_WAITING_TIME;
    }
    else if(yellowOccured>greenOccured && yellowOccured>redOccured && yellowOccured>blackOccured)
    {   return YELLOW_WAITING_TIME;
    }
    else if(redOccured>greenOccured && redOccured>yellowOccured && redOccured>blackOccured)
    {   return RED_WAITING_TIME;
    }
    else if (blackOccured>greenOccured && blackOccured>yellowOccured && blackOccured>redOccured)
    {   return BLACK_WAITING_TIME;
    }
    else
    {   return DEFAULT_WAITING_TIME;
    }
} //----- End of method


long Sensor::GetSensorId()
// Algorithme :
//
{
    return sensorId;
} //----- End of method

bool Sensor::operator<(Sensor*  element_2)
{
    return this->GetSensorId() < element_2->GetSensorId();
} //----- End of method

bool Sensor::operator>(Sensor*  element_2)
{
    return this->GetSensorId() > element_2->GetSensorId();
} //----- End of method

bool Sensor::operator==(Sensor*  element_2)
{
    return this->GetSensorId() == element_2->GetSensorId();
} //----- End of method


bool Sensor::operator<(const long  element_2)
{
    return this->GetSensorId() < element_2;
} //----- End of method

bool Sensor::operator>(const long  element_2)
{
    return this->GetSensorId() > element_2;
} //----- End of method

bool Sensor::operator==(const long  element_2)
{
    return this->GetSensorId() == element_2;
} //----- End of method





//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( )
// Algorithme :
//
{
    compteur++;
#ifdef MAP
    cout << "Call of <Sensor>'s constructor" << endl;
#endif
    this->sensorId =  DEFAULT_SENSOR_ID;
    archivePerDay = new EventArchivePerDay[NB_DAY];
} //----- End of Sensor


Sensor::Sensor (long sensorID)
// Algorithme :
//
{
    compteur++;
#ifdef MAP
    cout << "Call of <Sensor>'s constructor" << endl;
#endif
    this->sensorId =  sensorID;
    archivePerDay = new EventArchivePerDay[NB_DAY];
} //----- End of Sensor

Sensor::~Sensor ( )
// Algorithme :
//
{
    compteur--;
#ifdef MAP
    cout << "Call of <Sensor>'s constructor" << endl;
#endif
    delete [] archivePerDay;
} //----- End of ~Sensor
