#include "debug.h"

const int SizeOfStr = 1000;

char* str = new char [SizeOfStr];

char* s = str;

int GetG0();
int GetN();
int GetE();
int GetT();

const char* Expression = "3+2*3+2+1";

int main()
{
    strcpy (str, Expression);
    
    printc ((Expression), L) sn
    
    GetG0();
}

int GetG0()
{
    GetE();

    if (*s != '\0')
    {
        printc (("ERROR: "), E)
        coutc  ((*s), e)
    }
}

int GetN()
{
    int val = 0;

    while ('0' <= *s && *s <= '9')
    {
        val = val * 10 + *s - '0';

        s++;
    }
    coutc ((val), i) sn
    return val;
}

int GetE()
{
    int val = GetT();

    int val2 = 0;
    
    while (*s == '+')
    {
        s++;

        int val2 = GetT();

        val += val2;
    }
    coutc ((val), I) sn
    return val;
}

int GetT()
{
    int val = GetN();
    
    int val2 = 0;
    
    //$E std::cout << *s; $d
    
    //$w std::cout << (*s == '*'); $d
    
    while (*s == '*')
    {                                                                                                                                                                                                                                                                           printf ("meow ");
        //$g printf ("In while '*' T\n"); $d
        
        s++;
        
        int val2 = GetN();
        
        val *= val2;
    }
    coutc ((val), a) sn
    return val;
}


