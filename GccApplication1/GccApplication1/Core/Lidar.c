/*
 * Lidar.c
 *
 * Created: 3/1/2016 6:35:41 PM
 *  Author: Mihai
 */ 
#include <avr/io.h>
#include "USART.h"

const int bPerRevolution = 1980;
const int bPerPacket = 22;
const uint8_t bStartOfPacket = 0xFA; // start of packet
const uint8_t bNumberOfPackets = 90;
const uint8_t bTimeout = 1000; // number of bytes until bStartOfPacket
struct 
{
	uint16_t distance;
	uint8_t angle;
	uint16_t signalStrength;
}angleData;

uint8_t readLidar(char* p, uint8_t start_idx,uint8_t end_idx){
	uint8_t data[bPerPacket];
	uint8_t bTimeoutCounter = 0;
	bool receiveStartOfReading= false;
	
	while(!receiveStartOfReading)
	{
		if(bStartOfPacket == usart1Read())
		{
			if(start_idx == usart1Read())
			{
				receiveStartOfReading = true;
			}
		}
		else
		{
			if(++bTimeoutCounter > bTimeoutCounter)
			{
				 return ERR_START_OF_PACKET_TIMEOUT;
			}
		}
	}

	
}

