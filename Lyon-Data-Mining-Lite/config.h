/*************************************************************************
Config  -  This header can be used to modify all the constants of TP2's
           project. You can find the use of the constants in our report (find it in attach)
-------------------
Begin                : 21/10/2015
copyright            : (C) 2015 by F. Chastel && L. Cristol
*************************************************************************/
#include <limits.h>

#if ! defined ( CONFIG_H )
#define CONFIG_H

//------------------------------------------------------------------------
// Header's job <Config>
//  This header can be used to modify all the constants of TP2's project
//  You can find the use of the constants in our report (find it in attach)
//------------------------------------------------------------------------

//-------------------------------------------------------------- Constants

/** General constants **/
static const int MAX_VALUE_INT = INT_MAX;
static const int MIN_VALUE_INT = INT_MIN;

static const int INITIAL_LOOP_VALUE = 0;

static const int INITIAL_VALUE     = 0;
static const int PERCENTAGE_VALUE  = 100;

static const int TRUE_INT_EQUIVALENT   = 0;
static const int FALSE_INT_EQUIVALENT  = 1;

static const char PERCENTAGE_CHAR  = '%';
static const char* TABULATION_CHAR = "    ";

static const char* SEPARATOR_CHAR = " :: ";


/** Specific constants **/
static const unsigned short int MIN_YEAR   = 2015;
static const unsigned short int MAX_YEAR   = 2015;

static const unsigned short int MIN_MONTH  = 1;
static const unsigned short int MAX_MONTH  = 12;
static const unsigned short int NB_MONTH   = 12;

static const unsigned short int MIN_DAY    = 1;
static const unsigned short int MAX_DAY    = 7;
static const unsigned short int NB_DAY     = 7;

static const unsigned short int MIN_HOUR   = 0;
static const unsigned short int MAX_HOUR   = 23;
static const unsigned short int NB_HOUR    = 24;

static const unsigned short int MIN_MINUTE = 0;
static const unsigned short int MAX_MINUTE = 59;
static const unsigned short int NB_MINUTE  = 60;

static const unsigned short int GREEN_WAITING_TIME     = 1;
static const unsigned short int YELLOW_WAITING_TIME    = 2;
static const unsigned short int RED_WAITING_TIME       = 4;
static const unsigned short int BLACK_WAITING_TIME     = 10;

static const long DEFAULT_SENSOR_ID = LONG_MAX;

static const unsigned short int DEFAULT_WAITING_TIME   = 5;

static const unsigned char DAY_CHAR   = 'D';

static const char GREEN_TRAFFIC    = 'V';
static const char YELLOW_TRAFFIC   = 'J';
static const char RED_TRAFFIC      = 'R';
static const char BLACK_TRAFFIC    = 'N';

#endif