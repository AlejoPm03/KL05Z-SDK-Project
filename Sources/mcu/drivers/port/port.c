/***************************************************************************************
 * M�dulo      : port.c
 * Revis�o     : 1.1
 * Data        : 24/05/2023
 * Descri��o   : Arquivo com implementa��es dos M�dulos PORT da Familia Kinetis KL05.
 * Coment�rios : Nenhum.
 * Autor(es)   : Matheus Leitzke Pinto
 ***************************************************************************************/

/*ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

#include "port.h"

/*FIM: ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

/*FUN��ES P�BLICAS*/
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
void PORT_Init(PORT_Type* base)
{
	SYSTEM_ASSERT(base);

	if( PORTA == base )
	{
		   SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; /* Ativa o clock do perif�rico PORTA*/
	}
	else
	{
		if( PORTB == base )
		{
			SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /* Ativa o clock do perif�rico PORTB*/
			/*Desabilita NMI em PTB5 e habilita como GPIO*/
			base->PCR[5] &= ~PORT_PCR_MUX_MASK; /*Limpa configura��es anteriores*/
			base->PCR[5] |= PORT_PCR_MUX(PORT_MUX_ALT1);
		}
	}
}

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
void PORT_EnableIRQ(PORT_Type *base, uint8_t pin, portIRQ_t irq)
{
	SYSTEM_ASSERT(base);
	SYSTEM_ASSERT( ( pin >= 0 ) && ( pin < 32 ) );

	base->PCR[pin] &= ~PORT_PCR_IRQC_MASK; /*Limpa configura��es anteriores*/
	base->PCR[pin] |= PORT_PCR_IRQC(irq);
}

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
uint32_t PORT_GetIRQFlag(PORT_Type *base, uint8_t pin)
{
	SYSTEM_ASSERT(base);
	SYSTEM_ASSERT( ( pin >= 0 ) && ( pin < 32 ) );

	return base->ISFR & ((uint32_t)1 << pin);
}

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
void PORT_ClearIRQFlag(PORT_Type *base, uint8_t pin)
{
	SYSTEM_ASSERT(base);
	SYSTEM_ASSERT( ( pin >= 0 ) && ( pin < 32 ) );

	base->ISFR = ( (uint32_t) 1 << pin );
}

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
void PORT_EnablePull(PORT_Type *base, uint8_t pin)
{
	SYSTEM_ASSERT(base);
	SYSTEM_ASSERT( ( pin >= 0 ) && ( pin < 32 ) );

	base->PCR[pin] |= PORT_PCR_PE_MASK;
}

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
void PORT_EnableHighStrength(PORT_Type *base, uint8_t pin)
{
	SYSTEM_ASSERT(base);
	SYSTEM_ASSERT( ( pin >= 0 ) && ( pin < 32 ) );

	base->PCR[pin] |= PORT_PCR_DSE_MASK;
}

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
void PORT_SetMux(PORT_Type *base, uint8_t pin, portMux_t mux)
{
	SYSTEM_ASSERT(base);
	SYSTEM_ASSERT( ( pin >= 0 ) && ( pin < 32 ) );

	base->PCR[pin] &= ~PORT_PCR_MUX_MASK; /*Limpa configura��es anteriores*/
	base->PCR[pin] |= PORT_PCR_MUX(mux);
}

/*FIM: FUN��ES P�BLICAS*/
/*=======================================================================================*/

/***************************************************************************************
 * FIM: M�dulo - port.c
 ***************************************************************************************/
