#include "Global/Global.h"
#include "Rfid/RFID.h"
#include <cstdio>

int main(){
    RFID rfid(PA_5 , PA_7, PA_6 ,PB_6);
    rfid.begin();
    rfid.init();
 
    while(1){
           if(rfid.read()){
               printf("%s\r\n",rfid.getUid().c_str());
           }
    }
}