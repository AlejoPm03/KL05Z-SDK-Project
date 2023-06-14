/*
 * fsm.h
 *
 *  Created on: 13/06/2023
 *      Author: mathe
 */

#ifndef SOURCES_FSM_FSM_H_
#define SOURCES_FSM_FSM_H_

/* Ponteiro de fun��o da FSM. Ele aponta sempre para a
fun��o atual que deve ser executada */
void (*FSM_CurrentState )();

typedef void (*fsmStateFunction_t )();

/* Prot�tipos */

/* Fun��o que representa o estado inicial da FSM */
void FSM_State1( void );

/* Outro estado qualquer */
void FSM_State2( void );

/*Retorna o estado inicial*/
fsmStateFunction_t FSM_GetInitialState( void );

inline void FSM_Start( void )
{
	/* Aponta para o estado inicial .*/
	FSM_CurrentState = FSM_GetInitialState();

	for ( ; ; )
	{
		/* Chama a fun��o apontada pelo ponteiro de fun��o */
		FSM_CurrentState();
	}
}

#endif /* SOURCES_FSM_FSM_H_ */
