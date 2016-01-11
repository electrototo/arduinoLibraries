/*
	Xbee.cpp - Library for working with xbees that are in API mode.
	Created by Cristobal Liendo I, August 9, 2015.
	Released into the pulic domain.
	This code is under Creative Commons Attritbution 
*/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "XBee.h"

XBee::XBee(SoftwareSerial xbee){
	_xbee = &xbee;
	_xbee.begin(9600);
}

void XBee::transmit(String payload){
	_payload = payload;

	_xbee.write(0x7E);

	_xbee.write((byte)0x00);
	_xbee.write((byte)0x12);

	_xbee.write(0x10);
	_xbee.write(0x01);

	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);
	_xbee.write((byte)0x00);

	_xbee.write(0xFF);
	_xbee.write(0xFE);

	_xbee.write(0x00);
	_xbee.write(0x00);

	_xbee.write(0x01);
	_xbee.write(0x02);
	_xbee.write(0x03);
	_xbee.write(0x04);

	_xbee.write(0xE7);
}