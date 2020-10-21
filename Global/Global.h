#ifndef GLOBAL_H_
#define GLOBAL_H_
#include "mbed.h"

#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 115200);

// FileHandle *mbed::mbed_override_console(int fd)
// {
//     return &serial_port;
// }
#endif