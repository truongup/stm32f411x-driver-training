#ifndef STM32F411X_H_
#define STM32F411X_H_

#include <stdint.h>

#define __vo volatile

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

/*	PERRIPHERAL ADDRESS IN BUS AHB1 */
/*	GPIO	*/
#define GPIOA_BASE_ADDR 	(AHB1_PERIPHERAL_BASE_ADDR + 0x0000)	// 0x4002 0000
#define GPIOB_BASE_ADDR		(AHB1_PERIPHERAL_BASE_ADDR + 0x0400)	// 0X4002 0400
#define GPIOC_BASE_ADDR		(AHB1_PERIPHERAL_BASE_ADDR + 0x0800)	// 0x4002 0800
#define GPIOD_BASE_ADDR		(AHB1_PERIPHERAL_BASE_ADDR + 0x0C00)	// 0x4002 0C00
#define GPIOE_BASE_ADDR		(AHB1_PERIPHERAL_BASE_ADDR + 0x1000)	// 0x4002 1000
#define GPIOH_BASE_ADDR		(AHB1_PERIPHERAL_BASE_ADDR + 0x1C00)	// 0x4002 1C00

/*	RCC	*/
#define RCC_BASE_ADDR		(AHB1_PERIPHERAL_BASE_ADDR + 0x3800)	// 0x4002 3800

/*	PERRIPHERAL ADDRESS IN BUS APB1 */
/*	TIMER 2 & 3*/
#define TIM2_BASE_ADDR		(APB1_PERIPHERAL_BASE_ADDR + 0x0000)
#define TIM3_BASE_ADDR		(APB1_PERIPHERAL_BASE_ADDR + 0x4000)

/*	USART2*/
#define USART2_BASE_ADDR	(APB1_PERIPHERAL_BASE_ADDR + 0x4400)

/*	I2C1	*/
#define I2C1_BASE_ADDR		(APB1_PERIPHERAL_BASE_ADDR + 0x5400)	// 0x4000 5400

/*	PERRIPHERAL ADDRESS IN BUS APB2 */
/*	TIMER 1*/
#define TIM1_BASE_ADDR		(APB2_PERIPHERAL_BASE_ADDR + 0x0000)

/*	USART1	*/
#define USART1_BASE_ADDR	(APB2_PERIPHERAL_BASE_ADDR + 0x1000)

/*	SPI1	*/
#define SPI1_BASE_ADDR		(APB2_PERIPHERAL_BASE_ADDR + 0x3000)

/*	EXTI*/
#define EXTI_BASE_ADDR		(APB2_PERIPHERAL_BASE_ADDR + 0x3C00)

/*	SYSTEM CONFIG	*/
#define SYSCFG_BASE_ADDR	(APB2_PERIPHERAL_BASE_ADDR + 0x3800)	/*	Quan trọng vì nó dùng để tạo ngắt */


/*	------------ GPIO AHB1 ---------------- */
typedef struct {
	__vo uint32_t MODER;			// port mode register
	__vo uint32_t OTYPER;			// output type register
	__vo uint32_t OSPEEDR;			// output speed register
	__vo uint32_t PUPDR;			// port pull up / down register
	__vo uint32_t IDR;				// input data register
	__vo uint32_t ODR;				// output data register
	__vo uint32_t BSRR;				// bit set / reset register
	__vo uint32_t LCKR;				// port configuration lock register
	__vo uint32_t AFR[2];			// alternate function low / high register
}GPIO_Def_t;


#define GPIOA   ((GPIO_Def_t *)GPIOA_BASE_ADDR)
#define GPIOB   ((GPIO_Def_t *)GPIOB_BASE_ADDR)
#define GPIOC   ((GPIO_Def_t *)GPIOC_BASE_ADDR)
#define GPIOD   ((GPIO_Def_t *)GPIOD_BASE_ADDR)
#define GPIOE   ((GPIO_Def_t *)GPIOE_BASE_ADDR)
#define GPIOH   ((GPIO_Def_t *)GPIOH_BASE_ADDR)

/*	------------ RCC AHB1 ---------------- */
typedef struct {
    __vo  uint32_t CR;          // clock control register
    __vo  uint32_t PLLCFGR;     // configuration register
    __vo  uint32_t CFGR;        // clock configuration register
    __vo  uint32_t CIR;         // clock interrupt register

    __vo  uint32_t AHB1RSTR;    // AHB1 peripheral reset register
    __vo  uint32_t AHB2RSTR;    // AHB2 peripheral reset register

    uint32_t RESERVED_0;
    uint32_t RESERVED_1;

    __vo  uint32_t APB1RSTR;    // APB1 peripheral reset register for
    __vo  uint32_t APB2RSTR;    // APB2 peripheral reset register for

    uint32_t RESERVED_2;
    uint32_t RESERVED_3;

    __vo  uint32_t AHB1ENR;     // AHB1 peripheral clock enable register
    __vo  uint32_t AHB2ENR;     // AHB2 peripheral clock enable register

    uint32_t RESERVED_4;
    uint32_t RESERVED_5;

    __vo  uint32_t APB1ENR;     // APB1 peripheral clock enable register
    __vo  uint32_t APB2ENR;     // APB2 peripheral clock enable register

    uint32_t RESERVED_6;
    uint32_t RESERVED_7;

    __vo  uint32_t AHB1LPENR;   // AHB1 clock enable in low power mode register
    __vo  uint32_t AHB2LPENR;   // AHB2 clock enable in low power mode register

    uint32_t RESERVED_8;
    uint32_t RESERVED_9;

    __vo  uint32_t APB1LPENR;   // APB1 clock enable in low power mode regiser
    __vo  uint32_t APB2LPENR;   // APB2 clock enable in low power mode regiser

    uint32_t RESERVED_10;
    uint32_t RESERVED_11;

    __vo  uint32_t BDCR;        // backup domain control register
    __vo  uint32_t CSR;         // clock control & status register

    uint32_t RESERVED_12;
    uint32_t RESERVED_13;

    __vo  uint32_t SSCGR;       // spread spectrum clock generation register
    __vo  uint32_t PLLI2SCFGR;  // PLLI2S configuration register

    uint32_t RESERVED_14;
    __vo  uint32_t DCKCFGR;     // Dedicated clocks configuration register
}RCC_Def_t;

#define RCC ((RCC_Def_t *) RCC_BASE_ADDR)


#endif
