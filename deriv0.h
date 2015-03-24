#if !defined (__DERIV_H_INCLUDED)
#define       __DERIV_H_INCLUDED

#include "debug.h"

enum Funcs
{
    Mul_f = '*',
    Div_f = '/',
    Add_f = '+',
    Sub_f = '-'
};

enum Types
{
    Number_t   = 1301,
    Operator_t = 1302,
    Variable_t = 1303
};


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


struct Node_t
{
    Node_t *Lson, *Rson, *Parent;
    double value_;
    int    type_;

    Node_t (double value, int type):
        Lson   (NULL),
        Rson   (NULL),
        Parent (NULL),
        value_ (value),
        type_  (type)
    {
        //printc (("Constructor Node_t()\n"), g)
    }

    ~Node_t()
    {
        //printc (("Destructor Node_t()\n"), r)

        if (Lson != NULL)
        {
            delete Lson;
            Lson = NULL;
        }

        if (Rson != NULL)
        {
            delete Rson;
            Rson = NULL;
        }
    }

    void Set (double value, int type)
    {
        value_ = value;
        type_  = type;
    }

    void DoLson (double value = 0, int type = Number_t)
    {
        Lson         = new Node_t (value, type);
        Lson->Parent = this;
    }

    void DoRson (double value = 0, int type = Number_t)
    {
        Rson         = new Node_t (value, type);
        Rson->Parent = this;
    }
    
    void DoParentL (double value = 0, int type = Number_t)
    {
        Parent       = new Node_t (value, type);
        Parent->Lson = this;
    }
    
    void DoParentR (double value = 0, int type = Number_t)
    {
        Parent       = new Node_t (value, type);
        Parent->Rson = this;
    }

    void DumpPrefics()
    {
        if (type_ == Number_t)   printd (("%lg", value_))
        if (type_ == Operator_t) printd (("%c" , (int) value_))
        if (type_ == Variable_t) printd (("%c" , (int) value_))

        if (Lson)
        {
            printd (("("))
            Lson->DumpPrefics();
            printd ((")"))
        }

        if (Rson)
        {
            printd (("("))
            Rson->DumpPrefics();
            printd ((")"))
        }
    }

    void DumpOldVeryOldButGoodYesGoodOldInfics()
    {
        if (Lson)
        {
            printd (("("))
            Lson->DumpInfics();
            printd ((")"))
        }

        if (type_ == Number_t)   printd (("%lg", value_))
        if (type_ == Operator_t) printd (("%c" , (int) value_))
        if (type_ == Variable_t) printd (("%c" , (int) value_))

        if (Rson)
        {
            printd (("("))
            Rson->DumpInfics();
            printd ((")"))
        }
    }
    
    void DumpInfics()
    {
        if (Lson)
        {
            printc (("("), L)
            Lson->DumpInfics();
            printc ((")"), L)
        }
        
        if (type_ == Number_t)   printc (("%lg", value_), C)
        if (type_ == Operator_t) printc (("%c" , (int) value_), C)
        if (type_ == Variable_t) printc (("%c" , (int) value_), C)

        if (Rson)
        {
            printc (("("), r)
            Rson->DumpInfics();
            printc ((")"), r)
        }
    }
    
    void DumpPostfics()
    {
        if (Lson)
        {
            printd (("("))
            Lson->DumpPostfics();
            printd ((")"))
        }

        if (Rson)
        {
            printd (("("))
            Rson->DumpPostfics();
            printd ((")"))
        }

        if (type_ == Number_t)   printd (("%lg", value_))
        if (type_ == Operator_t) printd (("%c" , (int) value_))
        if (type_ == Variable_t) printd (("%c" , (int) value_))
    }
    
    void Disattach()
    {
        if (!Parent) return;
        
        if (Parent->Lson == this) Parent->Lson = NULL;
                
        if (Parent->Rson == this) Parent->Rson = NULL;
        
        Parent = NULL;
    }
    
    void AttachL (Node_t* n1)
    {
        Parent = n1;
        
        Parent->Lson = this;
    }
    
    void AttachR (Node_t* n1)
    {
        Parent = n1;
        
        Parent->Rson = this;
    }
};

struct Derivative_t
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

    #define SN( number )      current_->Set (number, Number_t);
    #define SO( operator )    current_->Set (operator##_f, Operator_t);
    #define SV( number )      current_->Set (number, Variable_t);

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
        SO (Add);
        DO (L, Manager (n->Lson));
        DO (R, Manager (n->Rson));
    }

    void DoSub (Node_t* n)
    {
        SO (Add);
        DO (L, Manager (n->Lson));
        DO (R, Manager (n->Rson));
    }

    void DoMul (Node_t* n)
    {
        SO (Add);

        DO (L, SO (Mul);
           DO (L, Manager (n->Lson);)
           DO (R, Copy (n->Rson);))

        DO (R, SO (Mul);
           DO (L, Manager (n->Rson);)
           DO (R, Copy (n->Lson);))
    }

    void DoDiv (Node_t* n)
    {
        SO (Div);

        DO (L, SO (Sub);
            DO (L, SO (Mul);
               DO (L, Manager (n->Lson);)
               DO (R, Copy (n->Rson);))

            DO (R, SO (Mul);
               DO (L, Manager (n->Rson);)
               DO (R, Copy (n->Lson);))
            )

        DO (R, SO (Mul);
           DO (L, Copy (n->Rson);)
           DO (R, Copy (n->Rson)))
    }

    void Manager (Node_t* n)
    {
        couts (("n->type_ = "), (n->type_), (";\n"), C)

        if (n->type_ == Number_t)
        {
            couts (("const "), (n->value_), ("\n"), c)
            DoConst ();
        }

        if (n->type_ == Variable_t)
        {
            couts (("param "), ((char) n->value_), ("\n"), c)
            DoParam ();
        }

        if (n->type_ == Operator_t)
        {
            couts (("operator "), ((char) n->value_), ("\n"), c);

            if ((int) n->value_ == '+') DoAdd (n);
            if ((int) n->value_ == '-') DoSub (n);
            if ((int) n->value_ == '*') DoMul (n);
            if ((int) n->value_ == '/') DoDiv (n);
        }
    }

    #undef DO
    #undef SN
    #undef SO
    #undef SV
};


#define DO( position, do_something )\
        cur->Do##position##son (0, 0);\
        cur = cur->position##son;\
        do_something;\
        cur = cur->Parent;

#define SN( number )      cur->Set (number, Number_t);
#define SO( operator )    cur->Set (operator##_f, Operator_t);
#define SV( number )      cur->Set (number, Variable_t);

#undef DO
#undef SN
#undef SO
#undef SV

#endif

