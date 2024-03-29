#ifndef __CHARS_H__
#define __CHARS_H__

int charmax = 8;

// Custom Character Banner Message
char ctop[] = { 0xA2, 0x20, 0x20, 0x20, 0x20, 0x00, 0x02, 0x04, 0x06, 0x04, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 };
char cbot[] = { 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x03, 0x05, 0x07, 0x05, 0x20, 0x20, 0x20, 0x20, 0x20, 0xA3 };

// Custom Character Data Array
unsigned char chardata[] = {
    0x00, 0x00, 0x00, 0x1F, 0x1F, 0x06, 0x06, 0x06,    0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x0F, 0x18, 0x18, 0x0E,    0x0E, 0x03, 0x03, 0x1F, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x18, 0x19, 0x1B, 0x1E,    0x1E, 0x1E, 0x1B, 0x1B, 0x18, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x1E, 0x03, 0x03, 0x0E,    0x0E, 0x03, 0x03, 0x06, 0x1E, 0x18, 0x00, 0x00
};


#endif
