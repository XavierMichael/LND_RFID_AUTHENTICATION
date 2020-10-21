#ifndef NfcDriver_H
#define NfcDriver_H

// eventually the NFC drivers should extend this class
class NfcDriver
{
    public:
        virtual NfcTag read(uint8_t * uid, int uidLength) = 0;
        virtual bool write(NdefMessage& message, uint8_t * uid, int uidLength) = 0;
        // erase()
        // format()
};

#endif