#ifndef RFID_H
#define RFID_H

#include <PN532/NfcAdapter.h>
#include <PN532/NfcDriver.h>
#include <PN532/PN532_SPI.h>
#include "Global/Global.h"

//RFID STATES
#define RFID_DISABLED		0
#define RFID_ENABLED		1
#define RFID_IDLE			2
#define RFID_END_SESSION	3

//RFID pins
#define RFID_MISO   PE_13
#define RFID_MOSI   PE_14
#define RFID_SCK    PE_12
#define RFID_SS     PE_15


#define RFID_MIN_SESSION_TIME		1000


// unsigned char rfid_init();
// bool check_rfid();
// void rfid_handler();
// unsigned char get_rfid_session();
// void set_rfid_session(unsigned char);
// unsigned char http_send_rfid_tag(uint16_t);
// String get_rfid_tag_str();

class RFID {
    public:
        RFID(PinName SCK, PinName MOSI, PinName MISO, PinName SS);
        bool begin();
        bool read();
        string getUid();
        void set_rfid_session(unsigned char);
        unsigned char get_rfid_session();        
        bool init();
                       

    private:
        SPI _spi_iface;
        PN532_SPI _RFID_SPI;
        NfcAdapter _RFID_READER;
        string uidString;
        unsigned int uidLen;
        uint8_t uidHolder [4] = {0};
        unsigned char rfidSession = RFID_DISABLED;

};

#endif