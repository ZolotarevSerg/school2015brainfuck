#if !defined (__DERIVN_H_INCLUDED)
#define       __DERIVN_H_INCLUDED

#include "debug.h"


enum Types_Node_
{
    Root              = 0,
    User_function     = 1,
    Number            = 2,
    Variable          = 3,
    Operator          = 4,
    Logic             = 5,
    Main              = 6,
    Standart_function = 7,
    Var_init          = 8,
    Service           = 9
};

enum Standart_function_
{
    Input         = 1,
    Output        = 2,
    Sin           = 3,
    Cos           = 4,
    Getch         = 5,
    Call          = 6,
    Defferentiate = 7,
    Square_root   = 8
};

enum Operators_
{
    Equal            = 1,
    Plus             = 2,
    Minus            = 3,
    Multiply         = 4,
    Divide           = 5,
    Power            = 6,
    Bool_equal       = 7,
    Bool_not_equal   = 8,
    Bool_lower       = 9,
    Bool_greater     = 10,
    Bool_not_lower   = 11,
    Bool_not_greater = 12,
    Bool_not         = 13,
    Bool_or          = 14,
    Bool_and         = 15,
    Plus_equal       = 16,
    Minus_equal      = 17,
    Multiply_equal   = 18,
    Divide_equal     = 19
};

enum Logic_
{
    If             = 1,
    While          = 2,
    Else           = 3,
    Condition      = 4,
    Condition_met  = 5
};

const int max_son = 10;

struct Node_t
{
    Node_t *son [max_son];
    Node_t *Parent;
    double value_;
    int    type_;
    
    Node_t (double value, int type):
        son (),
        Parent (NULL),
        value_ (value),
        type_  (type)
    {
        printc (("Constr"), g)
        
        printc (("uctor Node_t()\n"), g)
    }
    
    ~Node_t()
    {
        printc (("Destr"), r)
        
        printc (("uctor Node_t()\n"), r)
    }
    
    void Set (double value, int type)
    {
        value_ = value;
        type_  = type;
    }
    
    void Doson (int numbson, double value = 0, int type = Number)
    {
        son[numbson]         = new Node_t (value, type);
        son[numbson]->Parent = this;
    }
    
    void DoParent (int numbson, double value = 0, int type = Number)
    {
        Parent               = new Node_t (value, type);
        Parent->son[numbson] = this;
    }
    
    void DumpPrefics()
    {
        printc (("\nDumpPrefics - Begin\n"), a)
        
        if (type_ == Root)              printc (("%d",  value_), C)
        if (type_ == User_function)     printc (("%d", value_), C)
        if (type_ == Number)            printc (("%lg", value_), C)
        if (type_ == Variable)          printc (("%c" , (int) value_), C)
        if (type_ == Operator)          printc (("<%d>" , (int) value_), C)
        if (type_ == Logic)             printc (("%d",  value_), C)
        if (type_ == Main)              printc (("%d",  value_), C)
        if (type_ == Standart_function) printc (("%d",  value_), C)
        if (type_ == Var_init)          printc (("%d",  value_), C)
        if (type_ == Service)           printc (("%d",  value_), C)
        
        for (int i = 0; i < max_son; i++)
        {
            if (son[i])
            {
                printd (("("))
                son[i]->DumpPrefics();
                printd ((")"))
            }
        }
        
        printc (("\nDumpPrefics - End\n"), a)
    }
    
    void Disattach()
    {
        if (!Parent) return;
        
        for (int i = 0; i < max_son; i++)
        {
            if (Parent->son[i] == this) Parent->son[i] = NULL;
        }
        
        Parent = NULL;
    }
    
    void Attach (int numbson, Node_t* n1)
    {
        Parent = n1;
        
        Parent->son[numbson] = this;
    }
};

/*struct Derivative_t
{
    Node_t* DerivNode_t;
    Node_t* current_;
    
    Derivative_t (double value, int type):
        DerivNode_t (new Node_t (value, type)),
        current_    (DerivNode_t)
    {
        //printc (("Constructor Derivative_t()\n\n\n"), G)
    }
    
    ~Derivative_t()
    {
        current_->~Node_t();

        //printc (("Destructor Derivative_t()\n"), R)
    }
    
    #define DO( position, do_something )\
            {current_->Do##position##son (0, 0);\
            current_ = current_->position##son;\
            do_something;\
            current_ = current_->Parent;}

    #define SN( number )      current_->Set (number, Number);
    #define SO( operator )    current_->Set (operator, Operator);
    #define SV( number )      current_->Set (number, Variable);
    
    void Copy (Node_t* n)
    {
        if (!n) return;

        current_->value_ = n->value_;
        current_->type_  = n->type_;

        if (n->Lson) DO (L, Copy (n->Lson);)
        if (n->Rson) DO (R, Copy (n->Rson))
    }
    
    void DoConst ()
    {
        current_->value_ = 0;

        SN (0);
    }
    
    void DoParam ()
    {
        current_->value_ = 1;

        SN (1);
    }
    
    void DoAdd (Node_t* n)
    {
        SO (Plus);
        DO (L, Manager (n->Lson));
        DO (R, Manager (n->Rson));
    }
    
    void DoSub (Node_t* n)
    {
        SO (Plus);
        DO (L, Manager (n->Lson));
        DO (R, Manager (n->Rson));
    }
    
    void DoMul (Node_t* n)
    {
        SO (Plus);

        DO (L, SO (Multiply);
           DO (L, Manager (n->Lson);)
           DO (R, Copy (n->Rson);))

        DO (R, SO (Multiply);
           DO (L, Manager (n->Rson);)
           DO (R, Copy (n->Lson);))
    }
    
    void DoDiv (Node_t* n)
    {
        SO (Divide);

        DO (L, SO (Minus);
            DO (L, SO (Multiply);
               DO (L, Manager (n->Lson);)
               DO (R, Copy (n->Rson);))

            DO (R, SO (Multiply);
               DO (L, Manager (n->Rson);)
               DO (R, Copy (n->Lson);))
            )

        DO (R, SO (Multiply);
           DO (L, Copy (n->Rson);)
           DO (R, Copy (n->Rson)))
    }
    
    void Manager (Node_t* n)
    {
        couts (("n->type_ = "), (n->type_), (";\n"), C)
        
        if (n->type_ == Number)
        {
            couts (("const "), (n->value_), ("\n"), c)
            DoConst ();
        }
        
        if (n->type_ == Variable)
        {
            couts (("param "), ((char) n->value_), ("\n"), c)
            DoParam ();
        }
        
        if (n->type_ == Operator)
        {
            couts (("operator <"), (n->value_), (">\n"), c);

            if (n->value_ == Plus)     DoAdd (n);
            if (n->value_ == Minus)    DoSub (n);
            if (n->value_ == Multiply) DoMul (n);
            if (n->value_ == Divide)   DoDiv (n);
        }
    }
    
    #undef DO
    #undef SN
    #undef SO
    #undef SV
};


/*#define DO( position, do_something )\
        cur->Do##position##son (0, 0);\
        cur = cur->position##son;\
        do_something;\
        cur = cur->Parent;

#define SN( number )      cur->Set (number, Number);
#define SO( operator )    cur->Set (operator, Operator);
#define SV( number )      cur->Set (number, Variable);

#undef DO
#undef SN
#undef SO
#undef SV*/

#endif

