/*****************************************************************************
|*
|*  Copyright:      Copyright (c) 2008, Altium
|*
|*  Description:    Canopen client program. This engeneering example will query
|*                  OD entries from a remote CANopen server.
|*
\*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "framework.h"
#include <canopen.h>

extern int dbgint;

/* main() *********************************************************************
 * This CANopen device uses CANopen features that are default generated by
 * the CANopen configurator (CO_OD.c/h and USER.c). Except for USER.c, normally
 * you do not need to edit those files. Most important CANopen
 * feature in this example is SDO Client functionality. In the CANopen
 * configurator feature list we did:
 * - set the number of SDO clients to 1
 * - set the number of SDO servers to 0
 * - set the number of user CANTX to 1
 * - set the CAN id (object id 2101) to 6
 */
int main (int argc, char *argv[])
{
    unsigned char sz;  // size of received value
    unsigned char buf[100];
    UNSIGNED32    ac;  // abort code
    unsigned char *pbuf = buf;
    uint32_t      u32val;
    CO_ResetComm();   // Reset communication

    printf("CANopen test program\n");

    printf("\nStart sending user defined can packet \"ABCDEFGH\"\n");
    printf("This packet can be seen using a CAN monitor on the CAN bus\n");
    // configure user defined can packet
    CO_TXCANconfigure(CO_TXCAN_USER, 0x11, 0, 8, 0);
    strcpy((char *)CO_TXCAN[CO_TXCAN_USER].data, "ABCDEFGH");
    CO_TXCANsend(CO_TXCAN_USER);
    printf("\n1. Reading manufacturer ID of server (index 1008)\n");
    // read remote OD index from remote device (id)
    if (CO_SDOclientUpload_wait(5/*id*/, 0x1008/*index manufacturer*/, 0/*subindex*/, buf, 100, &sz, &ac) >= 0)
    {
        switch (sz)
        {
        case 4:
            u32val = SWAP4(*buf);
            break;
        case 2:
            u32val = SWAP2(*buf);
            break;
        case 1:
            u32val = (uint8_t)(*buf);
            break;
        default:
            buf[sz] = 0; // string
            break;
        }
        if (strcmp((const char*)buf, "CANopenNode"))
        {
            printf("-->Failed: Read: %s\n", (const char*)buf);
            return -1;
        }
    }
    else
    {
        printf("-->Failed: Abortcode: 0x%x\n", ac);
        return -1;
    }
    printf("-->Succes: Read: %s\n", (const char*)buf);

    // write remote OD
    printf("2. Writing \"ABCD\" to non-writable! manufacturer id (index 1008)\n");
    pbuf = (unsigned char*)"ABCD";
    if(CO_SDOclientDownload_wait(5/*id*/, 0x1008/*index*/, 0/*subindex*/, pbuf, sz/*bytesize*/, &ac) >= 0)
    {
        printf("-->Failed: Write succeeded?!?!\n");
        return -1;
    }
    else
    {
        if(ac != 0x06010002)
        {
            printf("-->Failed: Write failed but with wrong abortcode: %x\n", ac);
            return -1;
        }
        else
        {
            printf("-->Succes: Write failed\n");
        }
    }

    printf("3. Reading CAN id of server\n");
    sz = 3;
    *buf = 0;
    if (CO_SDOclientUpload_wait(5/*id*/, 0x2101/*index canopen id*/, 0/*subindex*/, buf, 100, &sz, &ac) >= 0)
    {
        if (*buf != 5)
        {
            printf("-->Failed: Read wrong CAN id %d\n", *buf);
            return -1;
        }
    }
    printf("-->Succes: Read CAN id: %d\n", *buf);

    printf("4. Writing new CAN id (110) into server (index 2101)\n");
    *buf = 110;
    if (CO_SDOclientDownload_wait(5/*id*/, 0x2101/*index canopen id*/, 0/*subindex*/, buf, sz, &ac) < 0)
    {
       printf("-->Failed: Abortcode: 0x%x\n", ac);
       return -1;
    }
    printf("-->Succes\n");

    printf("5. Reading back the new CAN id of the server\n");
    *buf = 0;
    if (CO_SDOclientUpload_wait(5/*id*/, 0x2101/*index canopen id*/, 0/*subindex*/, buf, 100, &sz, &ac) >= 0)
    {
        if (*buf != 110)
        {
            printf("-->Failed: Readback failed!\n");
            return -1;
        }
    }
    printf("-->Succes: Read CAN id:%d\n", *buf);
    printf("\nTests finished succesfuly\n");

    // reseting the CAN id for a next run
    printf("\nReseting CAN id of server for a next run\n");
    *buf = 5;
    if (CO_SDOclientDownload_wait(5/*id*/, 0x2101/*index canopen id*/, 0/*subindex*/, buf, sz, &ac) >= 0)
    {
       printf("ToDo: server does not support changing its id on the fly\n");
       printf("look into boot feature of CANopenNode\n");
    }
    return 0;
}

