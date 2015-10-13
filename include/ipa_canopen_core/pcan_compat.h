
#ifndef PCAN_COMPAT_H
#define PCAN_COMPAT_H

#include <stdint.h>


/***************************************************************/
//      compatibility with libpcan library from Peak, adapt to Linux SocketCAN
//      TODO: runtime switch to choose SocketCAN or libpcan.
/***************************************************************/


typedef int HANDLE;

/* return a handle or 0 or -1 on error. mode is ignored */
HANDLE LINUX_CAN_Open(const char *devname, int mode);

/* return 0 on success, error code on error. frametype is ignored. */
int CAN_Init(HANDLE h, int baudrate, int frametype);
#define CAN_INIT_TYPE_EX		0x01	//Extended Frame
#define CAN_INIT_TYPE_ST		0x00	//Standart Frame

void CAN_Close(HANDLE h);

typedef struct {
  uint32_t ID;
  char MSGTYPE;
  char LEN;
  char DATA[8];
} TPCANMsg;

typedef struct {
  TPCANMsg Msg;
  uint32_t dwTime;
  uint16_t wUsec;
} TPCANRdMsg;

/* return 0 on success, error code on error */
int CAN_Write(HANDLE h, TPCANMsg *msg);

/* return 0 on success, error code on error */
int LINUX_CAN_Read(HANDLE h, TPCANRdMsg *rdmsg);

#define CAN_BAUD_1M     1000  //   1 MBit/s
#define CAN_BAUD_500K   500  // 500 kBit/s
#define CAN_BAUD_250K   250  // 250 kBit/s
#define CAN_BAUD_125K   125  // 125 kBit/s
#define CAN_BAUD_100K   100  // 100 kBit/s
#define CAN_BAUD_50K    50  //  50 kBit/s
#define CAN_BAUD_20K    20  //  20 kBit/s
#define CAN_BAUD_10K    10  //  10 kBit/s
#define CAN_BAUD_5K     5  //   5 kBit/s

#endif
