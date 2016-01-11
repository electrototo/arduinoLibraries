/*
	Xbee.h - Library for working with xbees that are in API mode.
	Created by Cristobal Liendo I, August 9, 2015.
	Released into the pulic domain.
	This code is under Creative Commons Attritbution 
*/

#ifndef Xbee_h
#define Xbee_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class XBee{
	public:
		XBee(SoftwareSerial xbee);
		void transmit(String payload);
	private:
		String _payload;
		byte frame[];
		int frame_size;

		SoftwareSerial _xbee;

		byte checksum(byte frame[], int frame_size);
		void write(uint8_t val);

};

#endif