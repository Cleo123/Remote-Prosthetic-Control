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

 /* Open Bionics - Chestnut
 *
 * + Pin number |  PIN   |  Label         |        Details          | Comments (* is for default peripheral in use)
 * +------------+--------+----------------+-------------------------+--------------------------------------------------------------------------------------
 * | 1          |  PA00  | XIN32          | 32kHz crystal osc       | EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0] *XTAL
 * | 2          |  PA01  | XOUT32         | 32kHz crystal osc       | EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1] *XTAL
 * | 3          |  PA02  | A0             | Motor1 sense			| EIC/EXTINT[2] *ADC/AIN[0] PTC/Y[0] DAC/VOUT
 * | 4          |  PA03  | AREF           | Analogue reference      | *DAC/VREFP PTC/Y[1]
 * | 5          |        | GND		      | Ground		            | *GND
 * | 6          |        | VDD            | Vdd				        | *VDD
 * | 7          |  PB08  | A1             | Motor2 sense		    | EIC/EXTINT[8] *ADC/AIN[2] PTC/Y[14] SERCOM4/PAD[0] TC4/WO[0]
 * | 8          |  PB09  | A2             | Motor3 sense	        | EIC/EXTINT[9] *ADC/AIN[3] PTC/Y[15] SERCOM4/PAD[1] TC4/WO[1]
 * | 9          |  PA04  | A3             | Motor4 sense            | EIC/EXTINT[4] *ADC/AIN[4] AC/AIN[0] PTC/Y[2] SERCOM0/PAD[0] TCC0/WO[0]
 * | 10         |  PA05  | A4             | EMG ADC 0  	            | EIC/EXTINT[5] *ADC/AIN[5] AC/AIN[1] PTC/Y[5] SERCOM0/PAD[1] TCC0/WO[1]
 * | 11         |  PA06  | A5	          | EMG ADC 1		 	    | EIC/EXTINT[6] *ADC/AIN[6] AC/AIN[2] PTC/Y[4] SERCOM0/PAD[2] TCC1/WO[0]
 * | 12         | *PA07  | D0 (PWM)       | Motor4 PWM	            | EIC/EXTINT[7] DC/AIN[7] AC/AIN[3] PTC/Y[5] SERCOM0/PAD[3] *TCC1/WO[1]
 * | 13         | *PA08  | D1 (PWM)       | Motor1 PWM 	            | EIC/NMI ADC/AIN[16] PTC/X[0] SERCOM0/PAD[0] SERCOM2/PAD[0] TCC0/WO[0] *TCC1/WO[2]
 * | 14         | *PA09  | D2 (PWM)       | Motor1 PWM	            | EIC/EXTINT[9] ADC/AIN[17] PTC/X[1] SERCOM0/PAD[1] SERCOM2/PAD[1] TCC0/WO[1] *TCC1/WO[3]
 * | 15         |  PA10  | A6	          | Motor1 curr sense	    | EIC/EXTINT[10] *ADC/AIN[18] PTC/X[2] SERCOM0/PAD[2] TCC1/WO[0] TCC0/WO[2]
 * | 16         |  PA11  | A7			  | Motor4 curr sense       | EIC/EXTINT[11] *ADC/AIN[19] PTC/X[3] SERCOM0/PAD[3] SERCOM2/PAD[3] TCC1/WO[1] TCC0/WO[3]
 * | 17         |        | VDD            | Vdd					    | *VDD
 * | 18         |        | GND		      | Ground		            | *GND
 * | 19         |  PB10  | MOSI           | MOSI (SPI)		        | EIC/EXTINT[10] *SERCOM4/PAD[2] TC5/WO[0] TCC0/WO[4]
 * | 20         |  PB11  | SCK		      | SCK (SPI)      	        | EIC/EXTINT[11] *SERCOM4/PAD[3] TC5/WO[1] TCC0/WO[5]
 * | 21         |  PA12  | MISO           | MISO (SPI) 	            | EIC/EXTINT[12] *SERCOM2/PAD[0] SERCOM4/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * | 22         |  PA13  | NC		      | NC		                | EIC/EXTINT[13] TCC2/WO[1] TCC0/WO[7]
 * | 23         | *PA14  | D3	          | NeoPixel       	        | EIC/EXTINT[14] SERCOM2/PAD[2] SERCOM4/PAD[2] TC3/WO[0] TCC0/WO[4]
 * | 24         | *PA15  | D4 (PWM)		  | Motor3 PWM	            | EIC/EXTINT[15] SERCOM2/PAD[3] SERCOM4/PAD[3] TC3/WO[1] *TCC0/WO[5]
 * | 25         | *PA16  | D5 (PWM)       | Motor2 PWM              | EIC/EXTINT[0] PTC/X[4] SERCOM1/PAD[0] SERCOM3/PAD[0] *TCC2/WO[0] TCC0/WO[6]
 * | 26         | *PA17  | D6             | Broken out pin          | EIC/EXTINT[1] PTC/X[5] SERCOM1/PAD[1] SERCOM3/PAD[1] TCC2/WO[1] TCC0/WO[7]
 * | 27         | *PA18  | D7 (PWM)       | Motor2 PWM 	            | EIC/EXTINT[2] PTC/X[6] SERCOM1/PAD[2] SERCOM3/PAD[2] *TC3/WO[0] TCC0/WO[2]
 * | 28         | *PA19  | D8 (PWM)       | Motor3 PWM              | EIC/EXTINT[3] PTC/X[7] SERCOM1/PAD[3] SERCOM3/PAD[3] TC3/WO[1] *TCC0/WO[3]
 * | 29         | *PA20  | D9 (PWM)       | Motor4 PWM              | EIC/EXTINT[4] PTC/X[8] SERCOM5/PAD[2] SERCOM3/PAD[2] TC7/WO[0] *TCC0/WO[6]
 * | 30         | *PA21  | D10            | Comms switch            | EIC/EXTINT[5] PTC/X[9] SERCOM5/PAD[3] SERCOM3/PAD[3] TC7/WO[1] TCC0/WO[7]
 * | 31         |  PA22  | SDA (I2C)      | SDA (I2C)               | EIC/EXTINT[6] PTC/X[10] *SERCOM3/PAD[0] SERCOM5/PAD[0] TC4/WO[0] TCC0/WO[4]
 * | 32         |  PA23  | SCL (I2C)      | SCL (I2C)               | EIC/EXTINT[7] PTC/X[11] *SERCOM3/PAD[1] SERCOM5/PAD[1] TC4/WO[1] TCC0/WO[5]
 * | 33         |  PA24  | D+ (USB)       | USB D+	                | EIC/EXTINT[12] SERCOM3/PAD[2] SERCOM5/PAD[2] TC5/WO[0] TCC1/WO[2] *USB/DM
 * | 34         |  PB25  | D- (USB)       | USB D-                  | EIC/EXTINT[13] SERCOM3/PAD[3] SERCOM5/PAD[3] TC5/WO[1] TCC1/WO[3] *USB/DP
 * | 35         |        | GND		      | Ground		            | *GND
 * | 36         |        | VDD            | Vdd					    | *VDD
 * | 37         |  PB22  | TX			  | Broken out  TX          | EIC/EXTINT[6] *SERCOM5/PAD[2]
 * | 38         |  PB23  | RX			  | Broken out  RX	        | EIC/EXTINT[7] *SERCOM5/PAD[3]
 * | 39         |  PA27  | NC	          | NC	                    | EIC/EXTING[15]
 * | 40         |        | RESET          | Reset     	            | *RESET
 * | 41         |  PA28  | USB HOST EN    | NC	                    | EIC/EXTINT[8]
 * | 42         |        | GND		      | Ground		            | *GND
 * | 43         |        | VDD            | Vdd				        | *VDD
 * | 44         |        | VDD            | Vdd   		            | *VDD
 * | 45         |  PA30  | SWCLK (JTAG)   | JTAG Programming        | EIC/EXTINT[10] SERCOM1/PAD[2] TCC!/WO[0] *SWCLK
 * | 46         |  PA31  | SWDIO (JTAG)   | JTAG Programming        | EIC/EXTINT[11] SERCOM1/PAD[3] TCC1[WO[1] *SWDIO
 * | 47         |  PB02  | A8			  | Motor3 curr sense       | EIC/EXTINT[2] *ADC/AIN[10] PTC/Y[8] SERCOM5/PAD[0]
 * | 48         |  PB03  | A9			  | Motor2 curr sense		| EIC/EXTINT[3] *ADC/AIN[11] PTC/Y[9] SERCOM5/PAD[1]
 */


#include "variant.h"

 //
 // Pins descriptions
 //
const PinDescription g_APinDescription[]=
{
	// 0 - 10, DIGITAL & PWM 
	{ PORTA,  7, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 },		// D0 - PA07, TCC1/WO[1]
	{ PORTA,  8, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_NMI },		// D1 - PA08, TCC0/WO[0]
	{ PORTA,  9, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_9 },		// D2 - PA09, TCC0/WO[1]
	{ PORTA, 14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },								// D3 - PA14
	{ PORTA, 15, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_15 },			// D4 - PA15, TC3/WO[1]
	{ PORTA, 16, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_0 },		// D5 - PA16, TCC2/WO[0]
	{ PORTA, 17, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 },									// D6 - PA17
	{ PORTA, 18, PIO_TIMER, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 },		// D7 - PA18, TC3/WO[0]
	{ PORTA, 19, PIO_TIMER_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH3, TCC0_CH3, EXTERNAL_INT_3 },	// D8 - PA19, TCC0/WO[3]
	{ PORTA, 20, PIO_TIMER_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH6, TCC0_CH6, EXTERNAL_INT_4 },	// D9 - PA20, TCC0/WO[6]
	{ PORTA, 21, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },									// D10 - PA21

	// 11 - 20, ANALOGUE 
	{ PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },										// A0 - ADC/AIN[0]
	{ PORTB,  8, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel2, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, 									// A1 - ADC/AIN[2]
	{ PORTB,  9, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel3, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, 									// A2 - ADC/AIN[3]
	{ PORTA,  4, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel4, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },										// A3 - ADC/AIN[4]
	{ PORTA,  5, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel5, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, 									// A4 - ADC/AIN[5]
	{ PORTA,  6, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel6, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, 									// A5 - ADC/AIN[6]
	{ PORTA, 10, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, 									// A6 - ADC/AIN[18]
	{ PORTA, 11, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel19, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, 									// A7 - ADC/AIN[19]
	{ PORTB,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel10, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, 									// A8 - ADC/AIN[10]
	{ PORTB,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 								// A9 - ADC/AIN[11]

	// 21 - 23, USB
	{ PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },										// USB/DM
	{ PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },										// USB/DP
	{ PORTA, 28, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },										// USB Host enable

	// 24 - 25, UART																										
	{ PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },								// TX - SERCOM5/PAD[2]
	{ PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },								// RX - SERCOM5/PAD[3]

	// 26 - 27, I2C
	{ PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },									// SDA - SERCOM3/PAD[0]
	{ PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },									// SCL - SERCOM3/PAD[1]

	// 28 - 30, SPI
	{ PORTA, 12, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 },								// MISO - SERCOM4/PAD[0]
	{ PORTB, 10, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 },								// MOSI - SERCOM4/PAD[2]
	{ PORTB, 11, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },								// SCK - SERCOM4/PAD[3]

	// 31, AREF
	{ PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },								// AREF - DAC/VREFP

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
Uart Serial( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;
void SERCOM0_Handler()
{
  Serial1.IrqHandler();
}

void SERCOM5_Handler()
{
  Serial.IrqHandler();
}
