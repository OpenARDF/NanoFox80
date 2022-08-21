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
	uint8_t fox_setting;  /* 65 */
	uint8_t utc_offset; /* 66 */
	uint32_t frequency; /* 67 */
	uint32_t rtty_offset; /* 71 */
	uint16_t rf_power; /* 75 */
	uint8_t pattern_codespeed; /* 77 */
	int16_t off_air_seconds; /* 78 */
	int16_t on_air_seconds; /* 80 */
	int16_t ID_period_seconds; /* 82 */
	int16_t intra_cycle_delay_time; /* 84 */
	uint8_t event_setting; /* 86 */
	uint32_t foxoring_frequencyA; /* 87 */
	uint32_t foxoring_frequencyB; /* 91 */
	uint32_t foxoring_frequencyC; /* 95 */	
	uint8_t foxoring_fox_setting; /* 99 */
	uint8_t master_setting; /* 100 */
	char foxA_pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 101 */
	char foxB_pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 123 */
	char foxC_pattern_text[MAX_PATTERN_TEXT_LENGTH + 2]; /* 145 */
	float voltage_threshold; /* 167 */
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
	Fox_setting = 65, /* 1 bytes */ 
	Utc_offset = 66, /* 1 byte */
	Frequency = 67, /* 4 bytes */
	RTTY_offset = 71, /* 4 bytes */
	RF_Power = 75, /* 2 bytes */
	Pattern_Code_Speed = 77, /* 1 byte */
	Off_Air_Seconds = 78, /* 2 bytes */
	On_Air_Seconds = 80, /* 2 bytes */
	ID_Period_Seconds = 82, /* 2 bytes */
	Intra_Cycle_Delay_Seconds = 84, /* 2 bytes */
	Event_setting = 86, /* 1 byte */ 
	Foxoring_FrequencyA = 87,  /* 4 bytes */
	Foxoring_FrequencyB = 91,  /* 4 bytes */
	Foxoring_FrequencyC = 95,  /* 4 bytes */
	Foxoring_fox_setting = 99, /* 1 byte */ 
	Master_setting = 100, /* bool: 1 byte */ 
	FoxA_pattern_text = 101,  /* 22 bytes */
	FoxB_pattern_text = 123,  /* 22 bytes */
	FoxC_pattern_text = 145,  /* 22 bytes */
	Voltage_threshold = 167   /* 4 bytes */
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
