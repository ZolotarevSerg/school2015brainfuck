#include "derivn.h"

enum Lexemes_t
{
    plus_  = '+',
    minus_ = '-',
    point_ = '.',
    comma_ = ','
};

const int SizeOfProgram = 300;

void Clean (char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = ' ';
    }
}

void ReadFile (const char* name, char* str)
{
    FILE* f = fopen (name, "r");
    
    assert (f);
    
    char c = 0;
    
    int i = 0;
    
    for (i = 0; true; i++)
    {
        fscanf (f, "%c", &c);
        
        str[i] = c;
        
        if (c == '\n') break;
    }
    
    str[i + 1] = 0;
    
    fclose (f);
}

void PutS (char* str)
{
    for (int i = 0; str[i]; i++)
    {
        printf ("%c", str[i]);
    }
}

bool ErrorLexis (char* str)
{
    for (int i = 0; str[i]; i++)
    {
        if (! (plus_  == '+' ||
               minus_ == '-' ||
               point_ == '.' ||
               comma_ == ',')
           )
           return false;
    }
}

/*#define DO( position, do_something )\
        cur->Do##position##son (0, 0);\
        cur = cur->position##son;\
        do_something;\
        cur = cur->Parent;

#define SN( number )      cur->Set (number, Number);
#define SO( operator )    cur->Set (operator##_f, Operator);
#define SV( number )      cur->Set (number, Variable);

#undef DO
#undef SN
#undef SO
#undef SV

#endif*/




#define printdfl    {FILE* spec = fopen ("0debug", "a"); fprintf (spec, "%d ", __LINE__); fclose (spec);}
#define printdfb    {FILE* spec = fopen ("0debug", "a"); fprintf (spec, "\n"); fclose (spec);}


#define DO( position, do_something )\
        printdfl cur->Do##position##son (0, 0); printdfl\
        printdfl cur = cur->position##son; printdfl\
        printdfl do_something; printdfl\
        printdfl cur = cur->Parent; printdfl

/*
    +Root              = 0,
    +User_function     = 1,
    +Number            = 2,
    +Variable          = 3,
    +Operator          = 4,
    -Logic             = 5,
    +Main              = 6,
    +Standart_function = 7,
    +Var_init          = 8,
    -Service           = 9
*/

/*
#define SR                cur->Set (Root, Root);
#define SU                cur->Set (User_function, User_function);
#define SN( number )      cur->Set (number, Number);
#define SV( number )      cur->Set (number, Variable);
#define SO( operator )    cur->Set (operator, Operator);
#define SM                cur->Set (Main, Main);
#define SS                cur->Set (Standart_function, Standart_function);
#define SVI               cur->Set (Var_init, Var_init);

void BuildTree (Node_t* n)
{
    SR
    
    DO (0, SVI);
    DO (1, SS);
    DO (2, SU);
    DO (3, SM);
}*/

int main()
{
    printdfb
    
    char* StrProgram = new char [SizeOfProgram];
    
    Clean (StrProgram, SizeOfProgram);
    
    ReadFile ("Program.txt", StrProgram);
    
    assert (ErrorLexis (StrProgram));
    
    $E printf ("%s\n\n", StrProgram); $g
    
    
    
    Node_t n (0, 0);
    
    Node_t* cur = &n;
    /*
    SO (Multiply);
    
    printdfl
    
    DO (L, SV ('x'));
    DO (R, SN (937));
    
    d.Manager (&n);
    
    $W (d.current_)->DumpInfics(); sn*/
    
    printc (("THE END"), L);
    sn
}


#undef DO
#undef SN
#undef SO
#undef SV


/*Node_t n (0, 0);
    Derivative_t d (0, 0);
    
    Node_t* cur = &n;
    
    SO (Mul);
    DO (L, SV ('x'));
    DO (R, SN (937));
    
    d.Manager (&n);
    
    $W (d.current_)->DumpInfics(); sn
    
    printc (("THE END"), L);
    sn*/


