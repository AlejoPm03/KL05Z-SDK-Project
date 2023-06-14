/***************************************************************************************
 * M�dulo      : port.h
 * Revis�o     : 1.1
 * Data        : 24/05/2023
 * Descri��o   : Arquivo com implementa��es dos M�dulos PORT da Familia Kinetis KL05.
 * Coment�rios : Nenhum.
 * Autor(es)   : Matheus Leitzke Pinto
 ***************************************************************************************/

#ifndef PORT_DRV_H_
#define PORT_DRV_H_

/*ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

#include <mcu/common.h>

/*FIM: ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

#if defined(__cplusplus)
extern "C" {
#endif

/*TIPOS ENUMERADOS*/
/*=======================================================================================*/

/*Poss�veis alternativas de multiplexa��o dos pinos das PORTs*/
typedef enum{
	PORT_MUX_ALT0 		= 0x0u,
	PORT_MUX_ALT1 		= 0x1u,
	PORT_MUX_ALT2 		= 0x2u,
	PORT_MUX_ALT3 		= 0x3u,
	PORT_MUX_DISABLE 	= PORT_MUX_ALT0
}portMux_t;

/*Poss�veis alternativas de interrup��o dos pinos das PORTs*/
typedef enum{
	PORT_IRQ_DISABLE 		 	 = 0x0U,
	PORT_IRQ_DMA_ON_RISING_EDGE  = 0x1U,
	PORT_IRQ_DMA_ON_FALLING_EDGE = 0x2U,
	PORT_IRQ_DMA_ON_EITHER_EDGE  = 0x3U,
	PORT_IRQ_ON_lOW_LEVEL		 = 0x8U,
	PORT_IRQ_ON_RISING_EDGE 	 = 0x9U,
	PORT_IRQ_ON_FALLING_EDGE 	 = 0xAU,
	PORT_IRQ_ON_EITHER_EDGE 	 = 0xBU,
	PORT_IRQ_ON_HIGH_LEVEL 	 	 = 0xCU
}portIRQ_t;

/*FIM: TIPOS ENUMERADOS*/
/*=======================================================================================*/

/*PROTOTIPOS - FUN��ES P�BLICAS*/
/*=======================================================================================*/

/**********************************************************************
 * Fun��o		:	PORT_Init
 *
 * Descri��o	:   Deve ser chamado antes de utilizar um m�dulo PORT.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *
 * Sa�das 		:   Nenhuma.
 *
 * Coment�rios 	: 	Nenhum.
 * ********************************************************************/
void PORT_Init(PORT_Type* base);

/**********************************************************************
 * Fun��o		:	PORT_EnableIRQ
 *
 * Descri��o	:   Habilita a gera��o de interrup��o pelo pino de
 * 					um m�dulo PORT.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	- numera��o do pino;
 * 					irq - uma das alternativas de interrup��o do pino.
 *
 * Sa�das		:  Nenhuma.
 *
 * Coment�rios 	:  Nenhum.
 * ********************************************************************/
void PORT_EnableIRQ(PORT_Type *base, uint8_t pin, portIRQ_t irq);

/**********************************************************************
 * Fun��o		:	PORT_GetIRQFlag
 *
 * Descri��o	:   Retorna se a flag de interrup��o de pino do PORT foi setada.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	- numera��o do pino;
 *
 * Sa�das		:  0 - se flag n�o setada;
 *                 !0 - se flag setada.
 *
 * Coment�rios 	:  Nenhum.
 * ********************************************************************/
uint32_t PORT_GetIRQFlag(PORT_Type *base, uint8_t pin);

/**********************************************************************
 * Fun��o		:	PORT_ClearIRQFlag
 *
 * Descri��o	:   Limpa flag de interrup��o do pino de PORT.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	- numera��o do pino;
 *
 * Sa�das		:  Nenhuma.
 *
 * Coment�rios 	:  Nenhum.
 * ********************************************************************/
void PORT_ClearIRQFlag(PORT_Type *base, uint8_t pin);

/**********************************************************************
 * Fun��o		:	PORTB_SetMux
 *
 * Descri��o	:   Configura a multiplexa��o no pino do m�dulo PORTB.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	- numera��o do pino;
 * 					mux - uma das alternativas de multiplexa��o do pino.
 *
 * Sa�das		:   Nenhuma.
 *
 * Coment�rios 	: 	Nenhum.
 * ********************************************************************/
void PORT_SetMux(PORT_Type *base, uint8_t pin, portMux_t mux);

/**********************************************************************
 * Fun��o		:	PORT_EnablePull
 *
 * Descri��o	:   Habilita pullUp no pino do m�dulo PORT.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	  - numera��o do pino;
 *
 * Sa�das		:   Nenhuma.
 *
 * Coment�rios 	: 	Nenhum.
 * ********************************************************************/
void PORT_EnablePull(PORT_Type *base, uint8_t pin);

/**********************************************************************
 * Fun��o		:	PORT_EnableHighStrength
 *
 * Descri��o	:   Habilita a intensidade da corrente do pino como alta.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	  - numera��o do pino;
 *
 * Sa�das		:   Nenhuma.
 *
 * Coment�rios 	: 	Nenhum.
 * ********************************************************************/
void PORT_EnableHighStrength(PORT_Type *base, uint8_t pin);

/**********************************************************************
 * Fun��o		:	PORTB_SetMux
 *
 * Descri��o	:   Configura a multiplexa��o no pino do m�dulo PORTB.
 *
 * Entradas		:   *base - registrador base do perif�rico PORT.
 *                  pin	- numera��o do pino;
 * 					mux - uma das alternativas de multiplexa��o do pino.
 *
 * Sa�das		:   Nenhuma.
 *
 * Coment�rios 	: 	Nenhum.
 * ********************************************************************/
void PORT_SetMux(PORT_Type *base, uint8_t pin, portMux_t mux);

/*FIM: PROTOTIPOS - FUN��ES P�BLICAS*/
/*=======================================================================================*/

#if defined(__cplusplus)
}
#endif

#endif /* PORT_DRV_H_ */

/***************************************************************************************
 * FIM: M�dulo - port.h
 ***************************************************************************************/
