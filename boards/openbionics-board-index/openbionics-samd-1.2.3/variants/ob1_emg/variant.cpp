/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


/* Open Bionics - OB1 EMG
*
* + Pin number |  PIN   |  Label         |        Details          | Comments (* is for default peripheral in use)
* +------------+--------+----------------+-------------------------+--------------------------------------------------------------------------------------
* | 1          |  PA00  | XIN32          | 32kHz crystal osc       | EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0] *XTAL
* | 2          |  PA01  | XOUT32         | 32kHz crystal osc       | EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1] *XTAL
* | 3          |  PA02  | GND            | Ground reference        | EIC/EXTINT[2] *ADC/AIN[0] PTC/Y[0] DAC/VOUT
* | 4          |  PA03  | AREF           | Analogue reference      | *DAC/VREFP PTC/Y[1]
* | 5          |        | GND		     | Ground		           | *GND
* | 6          |        | VDD            | Vdd				       | *VDD
* | 7          |  PB08  | BATT_VOLTAGE   | 6V monitor (redundant)  | EIC/EXTINT[8] *ADC/AIN[2] PTC/Y[14] SERCOM4/PAD[0] TC4/WO[0]
* | 8          |  PB09  | GND            | Ground reference        | EIC/EXTINT[9] *ADC/AIN[3] PTC/Y[15] SERCOM4/PAD[1] TC4/WO[1]
* | 9          | *PA04  | UNUSED         | NC	                   | EIC/EXTINT[4] ADC/AIN[4] AC/AIN[0] PTC/Y[2] SERCOM0/PAD[0] TCC0/WO[0]
* | 10         | *PA05  | UNUSED         | NC	      	           | EIC/EXTINT[5] ADC/AIN[5] AC/AIN[1] PTC/Y[5] SERCOM0/PAD[1] TCC0/WO[1]
* | 11         |  PA06  | MUSLCE0        | Muscle 0 sense  	       | EIC/EXTINT[6] *ADC/AIN[6] AC/AIN[2] PTC/Y[4] SERCOM0/PAD[2] TCC1/WO[0]
* | 12         | *PA07  | UNUSED         | NC	      	           | EIC/EXTINT[7] DC/AIN[7] AC/AIN[3] PTC/Y[5] SERCOM0/PAD[3] TCC1/WO[1]
* | 13         | *PA08  | UNUSED         | NC	      	           | EIC/NMI ADC/AIN[16] PTC/X[0] SERCOM0/PAD[0] SERCOM2/PAD[0] TCC0/WO[0] TCC1/WO[2]
* | 14         |  PA09  | MUSCLE1        | Muscle 1 sense          | EIC/EXTINT[9] *ADC/AIN[17] PTC/X[1] SERCOM0/PAD[1] SERCOM2/PAD[1] TCC0/WO[1] TCC1/WO[3]
* | 15         |  PA10  | TRIMPOT        | Software sensitivity    | EIC/EXTINT[10] *ADC/AIN[18] PTC/X[2] SERCOM0/PAD[2] TCC1/WO[0] TCC0/WO[2]
* | 16         |  PA11  | ANALOG_VOLTAGE | Analogue amp level      | EIC/EXTINT[11] *ADC/AIN[19] PTC/X[3] SERCOM0/PAD[3] SERCOM2/PAD[3] TCC1/WO[1] TCC0/WO[3]
* | 17         |        | VDD            | Vdd					   | *VDD
* | 18         |        | GND		     | Ground		           | *GND
* | 19         | *PB10  | LED            | Controllable LED        | EIC/EXTINT[10] SERCOM4/PAD[2] TC5/WO[0] TCC0/WO[4]
* | 20         | *PB11  | UNUSED         | NC	        	       | EIC/EXTINT[11] SERCOM4/PAD[3] TC5/WO[1] TCC0/WO[5]
* | 21         | *PA12  | UNUSED         | NC	      	           | EIC/EXTINT[12] SERCOM2/PAD[0] SERCOM4/PAD[0] TCC2/WO[0] TCC0/WO[6]
* | 22         | *PA13  | UNUSED         | NC	                   | EIC/EXTINT[13] TCC2/WO[1] TCC0/WO[7]
* | 23         | *PA14  | UNUSED         | NC	        	       | EIC/EXTINT[14] SERCOM2/PAD[2] SERCOM4/PAD[2] TC3/WO[0] TCC0/WO[4]
* | 24         | *PA15  | REG_3V3_RST    | NC	                   | EIC/EXTINT[15] SERCOM2/PAD[3] SERCOM4/PAD[3] TC3/WO[1] TCC0/WO[5]
* | 25         | *PA16  | UNUSED         | NC                      | EIC/EXTINT[0] PTC/X[4] SERCOM1/PAD[0] SERCOM3/PAD[0] TCC2/WO[0] TCC0/WO[6]
* | 26         | *PA17  | VIBRATOR       | Haptic vibration motor  | EIC/EXTINT[1] PTC/X[5] SERCOM1/PAD[1] SERCOM3/PAD[1] TCC2/WO[1] *TCC0/WO[7]
* | 27         | *PA18  | UNUSED         | NC	     	           | EIC/EXTINT[2] PTC/X[6] SERCOM1/PAD[2] SERCOM3/PAD[2] TC3/WO[0] TCC0/WO[2]
* | 28         | *PA19  | UNUSED         | NC	                   | EIC/EXTINT[3] PTC/X[7] SERCOM1/PAD[3] SERCOM3/PAD[3] TC3/WO[1] TCC0/WO[3]
* | 29         | *PA20  | UNUSED     	 | NC	                   | EIC/EXTINT[4] PTC/X[8] SERCOM5/PAD[2] SERCOM3/PAD[2] TC7/WO[0] *TCC0/WO[6]
* | 30         | *PA21  | UNUSED         | NC	                   | EIC/EXTINT[5] PTC/X[9] SERCOM5/PAD[3] SERCOM3/PAD[3] TC7/WO[1] TCC0/WO[7]
* | 31         |  PA22  | SDA (I2C)      | HAND                    | EIC/EXTINT[6] PTC/X[10] *SERCOM3/PAD[0] SERCOM5/PAD[0] TC4/WO[0] TCC0/WO[4]
* | 32         |  PA23  | SCL (I2C)      | HAND                    | EIC/EXTINT[7] PTC/X[11] *SERCOM3/PAD[1] SERCOM5/PAD[1] TC4/WO[1] TCC0/WO[5]
* | 33         |  PA24  | D+ (USB)       | USB D+	               | EIC/EXTINT[12] SERCOM3/PAD[2] SERCOM5/PAD[2] TC5/WO[0] TCC1/WO[2] *USB/DM
* | 34         |  PB25  | D-             | USB D-                  | EIC/EXTINT[13] SERCOM3/PAD[3] SERCOM5/PAD[3] TC5/WO[1] TCC1/WO[3] *USB/DP
* | 35         |        | GND		     | Ground		           | *GND
* | 36         |        | VDD            | Vdd					   | *VDD
* | 37         | *PB22  | UNUSED         | NC	      	           | EIC/EXTINT[6] SERCOM5/PAD[2] 
* | 38         | *PB23  | UNUSED         | NC	     	           | EIC/EXTINT[7] SERCOM5/PAD[3] 
* | 39         | *PA27  | UNUSED         | NC	                   | EIC/EXTING[15]
* | 40         |        | RESET          | Reset     	           | *RESET
* | 41         | *PA28  | UNUSED         | NC	                   | EIC/EXTINT[8]
* | 42         |        | GND		     | Ground		           | *GND
* | 43         |        | VDD            | Vdd				       | *VDD
* | 44         |        | VDD            | Vdd   		           | *VDD
* | 45         |  PA30  | SWCLK (JTAG)   | JTAG Programming        | EIC/EXTINT[10] SERCOM1/PAD[2] TCC!/WO[0] *SWCLK
* | 46         |  PA31  | SWDIO (JTAG)   | JTAG Programming        | EIC/EXTINT[11] SERCOM1/PAD[3] TCC1[WO[1] *SWDIO
* | 47         | *PB02  | UNUSED         | NC	                   | EIC/EXTINT[2] ADC/AIN[10] PTC/Y[8] SERCOM5/PAD[0] 
* | 48         | *PB03  | UNUSED         | NC	                   | EIC/EXTINT[3] ADC/AIN[11] PTC/Y[9] SERCOM5/PAD[1] 
*/


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
	// 0 - 21, DIGITAL & PWM 
	{ PORTA,  4, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D0 - PA04
	{ PORTA,  5, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D1 - PA05
	{ PORTA,  7, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D2 - PA07
	{ PORTA,  8, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D3 - PA08
	{ PORTB, 10, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM), No_ADC_Channel, PWM5_CH0, TC5_CH0, EXTERNAL_INT_NONE },		// D4 - PB10, TC5/WO[0]
	{ PORTB, 11, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D5 - PB11
	{ PORTA, 12, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D6 - PA12
	{ PORTA, 13, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D7 - PA13
	{ PORTA, 14, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D8 - PA14
	{ PORTA, 15, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D9 - PA15
	{ PORTA, 16, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D10 - PA16
	{ PORTA, 17, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, TCC0_CH7, EXTERNAL_INT_1 },		// D11 - PA17, TCC0/WO[7]
	{ PORTA, 18, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D12 - PA18
	{ PORTA, 19, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D13 - PA19
	{ PORTA, 20, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D14 - PA20
	{ PORTA, 21, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D15 - PA21
	{ PORTA, 22, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D16 - PB22
	{ PORTA, 23, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D17 - PB23
	{ PORTA, 27, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D18 - PA27
	{ PORTA, 28, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D19 - PA28
	{ PORTB,  2, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D20 - PB02
	{ PORTB,  3, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// D21 - PB03

	// 22 - 28, ANALOGUE 
	{ PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A0 - ADC/AIN[0]
	{ PORTB,  8, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel2, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A1 - ADC/AIN[2]
	{ PORTB,  9, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel3, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A2 - ADC/AIN[3]
	{ PORTA,  6, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel6, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A3 - ADC/AIN[6]
	{ PORTA,  9, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel17, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A4 - ADC/AIN[17]
	{ PORTA, 10, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A5 - ADC/AIN[18]
	{ PORTA, 11, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel19, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// A6 - ADC/AIN[19]
	
	// 29 - 30, USB
	{ PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },						// USB/DM
	{ PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },						// USB/DP

	// 31 - 32, I2C
	{ PORTB, 22, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// D19 - EIC/EXTINT[6]
	{ PORTB, 23, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },					// D20 - EIC/EXTINT[7]
	
	// 33, AREF
	{ PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },				// AREF - DAC/VREFP

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM5_Handler()
{
  Serial.IrqHandler();
}

