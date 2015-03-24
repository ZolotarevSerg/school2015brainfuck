#if !defined (__RECDOWN_H_INCLUDED)
#define       __RECDOWN_H_INCLUDED

#include "debug.h"
#include "deriv.h"

const int SizeOfStr = 1000;

struct RecursDown_t
{
    Node_t* RootNode_t;
    Node_t* current_;
    
    char* str;
    char* s;
    
    RecursDown_t (const char expression[]):
        RootNode_t (new Node_t (0, 0)),
        current_   (RootNode_t),
        str        (new char [SizeOfStr]),
        s          (str)
    {
        strcpy (str, expression);
    }
    
    ~RecursDown_t()
    {
        current_->~Node_t();
        
        delete [] str;
        
        str = NULL;
    }
    
    #define DO( position, do_something )\
            {current_->Do##position##son (0, 0);\
            current_ = current_->position##son;\
            do_something;\
            current_ = current_->Parent;}
            
    #define SN( number )       current_->Set (number, Number);
    #define SO( operator )     current_->Set (operator, Operator);
    #define SV( number )       current_->Set (number, Variable);
    
    
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
    
    void GetN()
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
        
        SN (val);
    }
    
    void GetE()
    {
        printc (("->E"), I)
        
        GetT();
        
        char* s_last = s;
        
        while (*s == '+' || *s == '-')
        {
            s_last = s;
            
            s++;
            
            if (!current_->Parent)
            {
                current_->DoParentL (*s, Operator);
                current_ = current_->Parent;
                
                current_->DoRson();
                current_ = current_->Rson;
                GetT();
                
                current_ = current_->Parent;
            }
            
            else
            {
                Node_t* n1 = current_->Parent;
                
                current_->Disattach();
                
                n1->DoRson (*s, Operator);
                
                current_->AttachL (n1->Rson);
                
                current_ = current_->Parent;
                
                current_->DoRson();
                current_ = current_->Rson;
                GetT();
                
                current_ = current_->Parent;
            }
        }
        printc (("E->"), I)
    }
    
    void GetT()
    {
        printc (("->T"), a)
        
        GetP();
        
        char* s_last = s;
        
        while (*s == '*' || *s == '/')
        {
            s_last = s;
            
            s++;
            
            current_->DoParentL (*s, Operator);
            current_->DoRson();
            GetP();
            current_ = current_->Parent;
        }
        printc (("T->"), a)
    }
    
    void GetP()
    {
        printc (("->P"), W)
        
        if (*s == '(')
        {
            s++;
            
            GetE();
            
            if (*s != ')')
            {
                printc (("ERROR: ) != "), E)
                coutc  ((*s), e)
            }
            s++;
        }
        
        else
        {
            GetN();
        }        
        
        printc (("P->"), W)
    }
    
    #undef DO
    #undef SN
    #undef SO
    #undef SV
};

#endif

