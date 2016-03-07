/*
 * GccApplication1.c
 *
 * Created: 2/29/2016 5:38:33 PM
 *  Author: Mihai
 */ 
#define F_CPU 16000000UL


#include <avr/io.h>
#include "Core/USART.h"

int main(void)
{
	usart0Init();
	usart1Init();
	usart2Init();
	unsigned char send = 3;
	unsigned char sendB = 5;
	unsigned char read;
	
    while(1)
    {
        
		usart0Send(send);
		read = usart1Read();
		usart1Send(read);
		usart2Send(sendB);
    }
	
	return 0;
}