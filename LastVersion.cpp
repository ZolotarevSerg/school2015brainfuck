#include "debug.h"

const int SizeOfStr = 1000;

struct RecursDown_t
{
    char* str;
    char* s;
        
    int GetG0();
    int GetN();
    int GetE();
    int GetT();
    int GetP();
    
    RecursDown_t():
        str (new char [SizeOfStr]),
        s   (str)
        {}
    
    ~RecursDown_t()
    {
        delete str [];
        
        str = NULL;
    }
}

const char* Expression = "2-4";//"18/3+4*3/2-1/1";//"3-2*3+2*4-1";

int main()
{
    //txSleep (4000);
    
    strcpy (str, Expression);
    
    printc ((Expression), F) sn
    
    GetG0();
    
    printc (("The End"), L) sn
}

int GetG0()
{
    printc (("->G0"), L)
    
    GetE();
    
    if (*s != '\0')
    {
        printc (("ERROR: "), E)
        coutc  ((*s), e)
    }
    printc (("G0->"), L)
}

int GetN()
{
    printc (("->N"), i)
    
    int val = 0;
    
    couts (("*s = "), (*s), (";"), f) sn
    
    while ('0' <= *s && *s <= '9')
    {
        printc (("whileN\n\n"), f)
        
        val = val * 10 + *s - '0';
        
        s++;
    }
    couts (("GetN: "), (val), (";"), i) sn
    
    printc (("N->"), i)
    
    return val;
}

int GetE()
{
    printc (("->E"), I)
    
    int val  = GetT();
    
    int val2 = 0;
    
    char* s_last = s;
    
    while (*s == '+' || *s == '-')
    {
        s_last = s;
        
        s++;
        
        val2 = GetT();
        
             if (*s_last == '+') val += val2;
        else if (*s_last == '-') val -= val2;
        else {printc (("Something strange+-"), E) sn}
    }
    couts (("GetE: "), (val), (";"), I) sn
    
    printc (("E->"), I)
    
    return val;
}

int GetT()
{
    printc (("->T"), a)
    
    int val  = GetP();
    
    int val2 = 0;
    
    char* s_last = s;
    
    while (*s == '*' || *s == '/')
    {
        s_last = s;
        
        s++;
        
        val2 = GetP();
        
             if (*s_last == '*') val *= val2;
        else if (*s_last == '/') val /= val2;
        else {printc (("Something strange*/"), E) sn}
    }
    couts (("GetT: "), (val), (";"), a) sn
    
    printc (("T->"), a)
    
    return val;
}

int GetP()
{
    printc (("->P"), W)
    
    int val = 0;
    
    if (*s == '(')
    {
        s++;
        
        val = GetE();
        
        if (*s != ')')
        {
            printc (("ERROR: ) != "), E)
            coutc  ((*s), e)
        }
        s++;
    }
    
    else
    {
        val = GetN();
    }
    
    couts (("GetP: "), (val), (";"), W) sn
    
    printc (("P->"), W)
    
    return val;
}



