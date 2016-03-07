/*
 * USART.c
 *
 * Created: 2/29/2016 5:40:51 PM
 *  Author: Mihai
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include "USART.h"

// ------------------------------
// USART 0 initialization
// ------------------------------
void usart0Init(void){
	#define BAUD 115200
	#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	
	#if USE_2X
		UCSR0A |= (1<<U2X0);
	#else
		UCSR0A &= ~(1<<U2X0);
	#endif
	
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
}

// ------------------------------
// USART 1 initialization
// ------------------------------
void usart1Init(void){
	#undef BAUD
	#define BAUD 115200
	#include <util/setbaud.h>
	
	UBRR1H = UBRRH_VALUE;
	UBRR1L = UBRRL_VALUE;
	
	#if USE_2X
		UCSR1A |= (1<<U2X1);
	#else
		UCSR1A &= ~(1<<U2X1);
	#endif
	
	UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
}

// ------------------------------
// USART 2 initialization
// ------------------------------
void usart2Init(void){
	#undef BAUD
	#define BAUD 9600
	#include <util/setbaud.h>
	
	UBRR2H = UBRRH_VALUE;
	UBRR2L = UBRRL_VALUE;
	
	#if USE_2X
		UCSR2A |= (1<<U2X2);
	#else
		UCSR2A &= ~(1<<U2X2);
	#endif
	
	UCSR2C = (1<<UCSZ21)|(1<<UCSZ20);
	UCSR2B = (1<<RXEN2)|(1<<TXEN2);
}

// ------------------------------
// USART 0 - Send / Read
// ------------------------------
void usart0Send(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

unsigned char usart0Read(void){
	while(!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
}

// ------------------------------
// USART 1 - Send / Read
// ------------------------------
void usart1Send(unsigned char data){
	while(!(UCSR1A & (1<<UDRE1)));
	
	UDR1 = data;
}

unsigned char usart1Read(void){
	while(!(UCSR1A & (1<<RXC1)));
	
	return UDR1;
}

// ------------------------------
// USART 2 - Send / Read
// ------------------------------
void usart2Send(unsigned char data){
	while(!(UCSR2A & (1<<UDRE2)));
	
	UDR2 = data;
}

unsigned char usart2Read(void){
	while(!(UCSR2A & (1<<RXC2)));
	
	return UDR2;
}