#if !defined (__DEBUG_H_INCLUDED)
#define       __DEBUG_H_INCLUDED

#include "txLib.h"

/*
#define $T            txSetConsoleAttr (0x00);
#define $B            txSetConsoleAttr (0x01);
#define $G            txSetConsoleAttr (0x02);
#define $C            txSetConsoleAttr (0x03);
#define $R            txSetConsoleAttr (0x04);
#define $M            txSetConsoleAttr (0x05);
#define $Y            txSetConsoleAttr (0x06);
#define $d            txSetConsoleAttr (0x07);
#define $D            txSetConsoleAttr (0x08);
#define $b            txSetConsoleAttr (0x09);
#define $g            txSetConsoleAttr (0x0a);
#define $c            txSetConsoleAttr (0x0b);
#define $r            txSetConsoleAttr (0x0c);
#define $m            txSetConsoleAttr (0x0d);
#define $y            txSetConsoleAttr (0x0e);
#define $t            txSetConsoleAttr (0x0f);

#define $i            txSetConsoleAttr (0x1b);
#define $I            txSetConsoleAttr (0x1e);
#define $a            txSetConsoleAttr (0x2a);
#define $A            txSetConsoleAttr (0x2e);
#define $e            txSetConsoleAttr (0x4f);
#define $E            txSetConsoleAttr (0x4e);
#define $w            txSetConsoleAttr (0x5d);
#define $W            txSetConsoleAttr (0x5e);
#define $f            txSetConsoleAttr (0xc0);
#define $F            txSetConsoleAttr (0xc5);
#define $l            txSetConsoleAttr (0x80);
#define $L            txSetConsoleAttr (0x87);
*/

#define printd( param )    printf param;

#define printc( param, color )    {$##color printf param; $d}

#define coutd( param )    std::cout << param;

#define coutc( param, color )    {$##color std::cout << param; $d}

#define couts( param1, param2, param3, color )    {$##color std::cout << param1; std::cout << param2; std::cout << param3; $d}

#define sn    printd (("\n"));

#define Line    {coutc ((__LINE__), W) sn}

#define L    {coutc ((__LINE__), W) sn}

#define R    {coutc ((__LINE__), R) sn}

//#define K( param )    printf ( ##"param"## );



#endif
