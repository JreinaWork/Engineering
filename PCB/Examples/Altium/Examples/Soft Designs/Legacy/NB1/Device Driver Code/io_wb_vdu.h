#ifndef __IO_WB_VDU_H__
#define __IO_WB_VDU_H__
//..............................................................................

//..............................................................................
extern unsigned char CaretPosX ;
extern unsigned char CaretPosY;
extern unsigned char BackColor;
extern unsigned char ForeColor;
//..............................................................................

//..............................................................................
unsigned char vdu_get_caret_pos_x ( void );
void          vdu_set_caret_pos_x ( unsigned char x );
unsigned char vdu_get_caret_pos_y ( void );
void          vdu_set_caret_pos_y ( unsigned char y );
//..............................................................................

//..............................................................................
int          vdu_write            ( const char * buf, int size );
//..............................................................................

//..............................................................................
#endif
