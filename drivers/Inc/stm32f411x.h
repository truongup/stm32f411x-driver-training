#ifndef STM32F411X_H_
#define STM32F411X_H_

#include <stdint.h>

/*	MEMORY ADDRESS DEFINE */
#define FLASH_BASE_ADDR		0x08000000U		/* Flash address */
#define SRAM1_BASE_ADDR		0x20000000U		/* SRAM address  */
#define ROM_BASE_ADDR		0x1FFF0000U 	/* ROM address - System memory   */
#define SRAM	SRAM1_BASE_ADDR				/* SRAM sẽ sử dụng */

/*	BUS PERIPHERAL ADDRESS DEFINE */
#define PERIPHERAL_BASE				0x40000000U
#define APB1_PERIPHERAL_BASE_ADDR 	PERIPHERAL_BASE	/*	APB1	*/
#define APB2_PERIPHERAL_BASE_ADDR 	0x40010000U		/*	APB2	*/
#define AHB1_PERIPHERAL_BASE_ADDR	0x40020000U		/*	AHB1	*/
#define AHB2_PERIPHERAL_BASE_ADDR	0x50000000U		/*	AHB2	*/

#endif
