/*************************************************************************
 main  -  description
 -------------------
 Begin                : 21/10/2015
 copyright            : (C) 2015 ny F. Chastel && L. Cristol
 *************************************************************************/

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include
#include <iostream>
#include <string.h>
#include <stdio.h>

//---------------------------------------------------- Personnal's include
#include "SensorTree.h"


//------------------------------------------------------------ Main method
int main(int argc, const char * argv[]) {
    SensorTree arbre;
    
    int id;
    int annee;
    int mois;
    int heure;
    int min;
    int jour;
    int d7;
    char trafic;
    
    int tmp;
    
    int minHour;
    int maxHour;
    int numberOfSensors;
   
    char commandInput[10];

    bool loop = true;

    int* sensors;

    while (loop == true)
    {   scanf("%s",commandInput);
        
        if(strcmp(commandInput,"ADD") == TRUE_INT_EQUIVALENT)
        {   scanf("%d",&id);
            scanf("%d",&annee);
            scanf("%d",&mois);
            scanf("%d",&jour);
            scanf("%d",&heure);
            scanf("%d",&min);
            scanf("%d",&d7);
            scanf(" %c",&trafic);
            arbre.AddEventToSensor(id,annee,mois,d7,heure,min,trafic);
        }
        else if(strcmp(commandInput,"STATS_C") == TRUE_INT_EQUIVALENT)
        {   scanf("%d",&id);
            arbre.StatisticsForSensor(id);
        }
        else if(strcmp(commandInput,"JAM_DH") == TRUE_INT_EQUIVALENT)
        {   scanf("%d",&d7);
            arbre.TraficJamPerDayPerHour(d7);
        }
        else if(strcmp(commandInput,"STATS_D7") == TRUE_INT_EQUIVALENT)
        {   scanf("%d",&d7);
            arbre.TraficStatisticsForADay(d7);
        }
        else if(strcmp(commandInput,"OPT") == TRUE_INT_EQUIVALENT)
        {   scanf("%d",&d7);
            scanf("%d",&minHour);
            scanf("%d",&maxHour);
            scanf("%d",&numberOfSensors);
            sensors = new int[numberOfSensors];
            
            for (int cursor=INITIAL_LOOP_VALUE; cursor<numberOfSensors; cursor++)
            {   scanf("%d",&tmp);
                sensors[cursor] = tmp;
            }
    

            arbre.OptimalTimeOfLeaving(d7, minHour, maxHour, sensors, numberOfSensors);
            
            delete [] sensors;

        }
        else if(strcmp(commandInput,"EXIT") == TRUE_INT_EQUIVALENT)
        {   loop=false;
        }
    }
    
    return 0;
}  //----- End of method
