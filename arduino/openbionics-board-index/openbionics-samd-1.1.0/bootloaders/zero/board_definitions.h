/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2015 Atmel Corporation/Thibaut VIARD.  All right reserved.

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

#ifndef _BOARD_DEFINITIONS_H_
#define _BOARD_DEFINITIONS_H_

/*
 * If BOOT_DOUBLE_TAP_ADDRESS is defined the bootloader is started by
 * quickly tapping two times on the reset button.
 * BOOT_DOUBLE_TAP_ADDRESS must point to a free SRAM cell that must not
 * be touched from the loaded application.
 */
#define BOOT_DOUBLE_TAP_ADDRESS           (0x20007FFCul)
#define BOOT_DOUBLE_TAP_DATA              (*((volatile uint32_t *) BOOT_DOUBLE_TAP_ADDRESS))

/*
 * If BOOT_LOAD_PIN is defined the bootloader is started if the selected
 * pin is tied LOW.
 */
//#define BOOT_LOAD_PIN                     PIN_PA21 // Pin 7
//#define BOOT_LOAD_PIN                     PIN_PA15 // Pin 5
#define BOOT_PIN_MASK                     (1U << (BOOT_LOAD_PIN & 0x1f))

#define CPU_FREQUENCY                     (48000000ul)



/* Frequency of the board main oscillator */
#define VARIANT_MAINOSC	                  (32768ul)

/* Master clock frequency */
#define VARIANT_MCK			                  CPU_FREQUENCY

#define NVM_SW_CALIB_DFLL48M_COARSE_VAL   (58)
#define NVM_SW_CALIB_DFLL48M_FINE_VAL     (64)



#define BOARD_LEDRX_PORT                  (1)
#define BOARD_LEDRX_PIN                   (3)

#define BOARD_LEDTX_PORT                  (0)
#define BOARD_LEDTX_PIN                   (27)

#endif // _BOARD_DEFINITIONS_H_
