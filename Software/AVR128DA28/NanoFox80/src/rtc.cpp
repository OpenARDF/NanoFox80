/*
 *  MIT License
 *
 *  Copyright (c) 2022 DigitalConfections
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
 *
 * rtc.cpp
 */

#include "defs.h"
#include "rtc.h"

void RTC_init(void)
{
    while (RTC.STATUS > 0) { /* Wait for all registers to be synchronized */
    }
    //Compare 
    RTC.CMP = 0x00;

    //Count
    RTC.CNT = 0x00;

    //Period
    RTC.PER = 32767;

    //Clock selection: XOSC32K
    RTC.CLKSEL = 0x02;

    //CMP disabled; OVF enabled; 
    RTC.INTCTRL = 0x01;

    //RUNSTDBY disabled; PRESCALER DIV1; CORREN disabled; RTCEN enabled; 
    RTC.CTRLA = 0x81;
	RTC.DBGCTRL = 0x01; /* Run in debug mode */
    
    while (RTC.PITSTATUS > 0) { /* Wait for all register to be synchronized */
    }
    //PI disabled; 
    RTC.PITINTCTRL = 0x00;    
}

void RTC_init_backup(void)
{
    while (RTC.STATUS > 0) { /* Wait for all registers to be synchronized */
    }
    //Compare 
    RTC.CMP = 0x00;

    //Count
    RTC.CNT = 0x00;

    //Period
    RTC.PER = 32767;

    //Clock selection: OSC32K
    RTC.CLKSEL = 0x00;

    //CMP disabled; OVF enabled; 
    RTC.INTCTRL = 0x01;

    //RUNSTDBY disabled; PRESCALER DIV1; CORREN disabled; RTCEN enabled; 
    RTC.CTRLA = 0x01;
    
    while (RTC.PITSTATUS > 0) { /* Wait for all register to be synchronized */
    }
    //PI disabled; 
    RTC.PITINTCTRL = 0x00;    
}
