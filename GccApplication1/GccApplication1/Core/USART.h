/*
 * USART.h
 *
 * Created: 2/29/2016 5:41:36 PM
 *  Author: Mihai
 */ 
#ifndef USART_h
#define USART_h
	
	// USART 0
	void usart0Init(void);
	void usart0Send(unsigned char data);
	unsigned char usart0Read(void);
	
	// USART 1
	void usart1Init(void);
	void usart1Send(unsigned char data);
	unsigned char usart1Read(void);
	
	// USART 2
	void usart2Init(void);
	void usart2Send(unsigned char data);
	unsigned char usart2Read(void);
	
#endif