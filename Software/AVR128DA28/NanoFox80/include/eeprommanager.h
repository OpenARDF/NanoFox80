/*
 *  MIT License
 *
 *  Copyright (c) 2021 DigitalConfections
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef __EEPROMMANAGER_H__
#define __EEPROMMANAGER_H__

#include "defs.h"

#ifdef ATMEL_STUDIO_7
#include <avr/eeprom.h>
#endif  /* ATMEL_STUDIO_7 */

#include <time.h>

struct EE_prom
{
	uint16_t eeprom_initialization_flag; /* 0 */
	time_t event_start_epoch; /* 2 */
	time_t event_finish_epoch; /* 6 */
 	char stationID_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 10 */
 	char pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 32 */
	uint8_t unlockCode[MAX_UNLOCK_CODE_LENGTH + 2]; /* 54 */
	uint8_t id_codespeed;  /* 64 */
	uint16_t fox_setting;  /* 65 */
	uint8_t utc_offset; /* 67 */
	uint32_t frequency; /* 68 */
	uint32_t rtty_offset; /* 72 */
	uint16_t rf_power; /* 76 */
	uint8_t pattern_codespeed; /* 78 */
	int16_t off_air_seconds; /* 79 */
	int16_t on_air_seconds; /* 81 */
	int16_t ID_period_seconds; /* 83 */
	int16_t intra_cycle_delay_time; /* 85 */
	uint8_t event_setting; /* 87 */
	uint32_t foxoring_frequencyA; /* 88 */
	uint32_t foxoring_frequencyB; /* 92 */
	uint32_t foxoring_frequencyC; /* 96 */	
	uint16_t foxoring_fox_setting; /* 100 */
	uint8_t master_setting; /* 102 */
	char foxA_pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 103 */
	char foxB_pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 125 */
	char foxC_pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 147 */
};

typedef enum
{
	Eeprom_initialization_flag = 0, /* 2 bytes */
	Event_start_epoch = 2, /* 4 bytes */
	Event_finish_epoch = 6, /* 4 bytes */
	StationID_text = 10, /* 22 bytes */
	Pattern_text = 32, /* 22 bytes */
	UnlockCode = 54, /* 10 bytes */
	Id_codespeed = 64, /* 1 byte */
	Fox_setting = 65, /* 2 bytes */ 
	Utc_offset = 67, /* 1 byte */
	Frequency = 68, /* 4 bytes */
	RTTY_offset = 72, /* 4 bytes */
	RF_Power = 76, /* 2 bytes */
	Pattern_Code_Speed = 78, /* 1 byte */
	Off_Air_Seconds = 79, /* 2 bytes */
	On_Air_Seconds = 81, /* 2 bytes */
	ID_Period_Seconds = 83, /* 2 bytes */
	Intra_Cycle_Delay_Seconds = 85, /* 2 bytes */
	Event_setting = 87, /* 1 byte */ 
	Foxoring_FrequencyA = 88,  /* 4 bytes */
	Foxoring_FrequencyB = 92,  /* 4 bytes */
	Foxoring_FrequencyC = 96,  /* 4 bytes */
	Foxoring_fox_setting = 100, /* 2 bytes */ 
	Master_setting = 102, /* bool: 1 byte */ 
	FoxA_pattern_text = 103,  /* 22 bytes */
	FoxB_pattern_text = 125,  /* 22 bytes */
	FoxC_pattern_text = 147   /* 22 bytes */
} EE_var_t;

class EepromManager
{
/*variables */
public:
protected:
private:

/*functions */
public:
EepromManager();
~EepromManager();

static const struct EE_prom ee_vars;

bool initializeEEPROMVars(void);
bool readNonVols(void);
void updateEEPROMVar(EE_var_t v, void* val);
void saveAllEEPROM();

protected:
private:
EepromManager( const EepromManager &c );
EepromManager& operator=( const EepromManager &c );
};  /*EepromManager */

#endif  /*__EEPROMMANAGER_H__ */
