#include "RFID.h"
RFID::RFID(PinName SCK, PinName MOSI, PinName MISO, PinName SS) : _spi_iface(MOSI, MISO, SCK) , _RFID_SPI(_spi_iface, SS) , _RFID_READER(_RFID_SPI){
    
}

bool RFID::begin() {
	//debugPrintfln("[RFID DRIVER] ATTEMPTING INIT");
	return _RFID_READER.begin();
}

bool RFID::init(){
	if (!begin()){
        const char *msg="Didn't find PN53x board";
		printf("Didn't find PN53x board");
		return 0;
	}
	// configure board to read RFID tags
	//debugPrintfln("RFID Ready");
	return 1;
}

bool RFID::read() {
	uidString.clear();

    if(! _RFID_READER.tagPresent(uidHolder, uidLen)) {
		//debugPrintfln("[RFID DRIVER] CAN'T READ TAG");
        return false;
    }

	if(_RFID_READER.tagPresent(uidHolder, uidLen)) {
		for(uint8_t i =0; i<sizeof(uidHolder); i++) {
			if(uidHolder[i]>0){
			uidString.append(to_string(uidHolder[i]));
			}
		}
	}
	
    return true;
}

string RFID::getUid() {    
	string UID;

	for(int i=0;i<sizeof(uidHolder);i++){
		char msb = 0, lsb = 0;
		lsb = uidHolder[i] & 0x0f;
		msb = (uidHolder[i]>>4) & 0x0f;
		
		if(msb < 10){
			msb += '0';
        }
		else{
			msb += ('A'-10);
		}
		
		if(lsb < 10){
			lsb += '0';
		}
		else{
			lsb += ('A'-10);
		}
		
		UID += msb;
		UID += lsb;
	}

    return UID;
}

void RFID::set_rfid_session(unsigned char s)
{
	if(s == RFID_ENABLED){
		for(uint8_t i=0; i<sizeof(uidHolder); ++i){
			uidHolder[i] = 0;
		}
	}
	rfidSession = s;
}
unsigned char RFID::get_rfid_session(){
	return rfidSession;
}