#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#define M 30           // M: Maximum size of the stack (30).
#define symbol 10      // symbol: Identifier for symbols (10). 
#define str 20         // str: Identifier for strings (20). 

/*  1. Structure Definition
Defines a structure prepost (aliased as Fix) to implement a stack for evaluating expressions.
*/
typedef struct prepost
{
    int top;         // top: Tracks the top element of the stack.
    int s[M];        // s[M]: Array to store elements of the stack.
} Fix;

/* 2. Function Prototypes
- Function prototypes for:
*/
void init(Fix*);                  // init(): Initializes the stack.
void push(Fix*, int);             // push(): Pushes an element onto the stack.
int pop(Fix*);                    // pop(): Pops an element from the stack.
void eval(Fix*, char, int, int);  // eval(): Evaluates an expression (+, -, *, /, %, ^).
int gettype(char);                // gettype(): Determines the type of character (symbol or str).  

/* 3. main() Function
- main() function initiates the program.
- Displays a menu to choose between evaluating prefix, postfix expressions, or exiting (1: PreFix, 2: PostFix, 3: Exit).
- Uses a switch-case statement to perform operations based on user input (k).
- For prefix and postfix evaluation:
        - Initializes the stack (init(&stk)).
        - Reads the expression from the user (gets(str1) for prefix, gets(str1) for postfix).
        - Processes each character in the expression:
        - If it's a symbol (+, -, *, /, %, ^), pushes it onto the stack.
        - If it's a string, pops two operands from the stack, evaluates using eval(), and pushes the result back onto the stack.
- Displays the evaluated result.
*/
void main()
{
    char str1[M];
    int item1, item2, item, l, i, pr;
    Fix stk;
    fflush(stdin);
    int k;
    clrscr();
    
    do {
        cout << "\n\t\tEvaluation of Expression.";
        cout << "\n\t1: PreFix\t2: PostFix\t3: Exit\n\t";
        cin >> k;
        
        switch (k) {
            case 1:
            {
                init(&stk);
                cout << " ENTER THE PREFIX EXPRESSION ";
                gets(str1);
                l = strlen(str1);
                
                for (i = l; i >= 0; i--)
                {
                    if (str1[i] == ' ' || str1[i] == '\0')
                        continue;
                    
                    switch (gettype(str1[i]))
                    {
                        case symbol:
                            item = str1[i] - '0';
                            push(&stk, item);
                            break;
                        case str:
                            item1 = pop(&stk);
                            item2 = pop(&stk);
                            eval(&stk, str1[i], item1, item2);
                            break;
                    }
                }
                
                cout << "\n\tResult of prefix evaluation is: ";
                cout << stk.s[0];
                getch();
            }
            break;
            
            case 2:
            {
                init(&stk);
                cout << " ENTER THE POSTFIX EXPRESSION ";
                gets(str1);
                l = strlen(str1);
                
                for (i = 0; i <= l; i++)
                {
                    if (str1[i] == ' ' || str1[i] == '\0')
                        continue;
                    
                    switch (gettype(str1[i]))
                    {
                        case symbol:
                            item = str1[i] - '0';
                            push(&stk, item);
                            break;
                        case str:
                            item2 = pop(&stk);
                            item1 = pop(&stk);
                            eval(&stk, str1[i], item1, item2);
                            break;
                    }
                }
                
                cout << "\n\tResult of postfix evaluation is: ";
                cout << stk.s[0];
                getch();
            }
            break;
            
            case 3:
                k = 3;
                break;
                
            default:
                cout << "\n End";
        }
        
    } while (k != 3);
    
    getch();
}

/*
Stack Operations (init(), push(), pop(), eval(), gettype())
Explanation:
init(&stk): Initializes the stack by setting top to -1.
push(&stk, num): Pushes num onto the stack (s[top++] = num).
pop(&stk): Pops the top element from the stack (return s[top--]).
eval(&stk, opr, item1, item2): Evaluates the expression based on the operator (opr) and operands (item1, item2), then pushes the result onto the stack.
gettype(c): Determines if c is a symbol or a string based on predefined constants (symbol, str).
*/

/*
Notes:
Input Handling: Uses gets() to read expressions, which is generally discouraged due to security risks (gets() may cause buffer overflow).
Expression Evaluation: Supports basic arithmetic operations (+, -, *, /, %, ^) for both prefix and postfix expressions.
User Interaction: Provides a simple menu-driven interface using cin and cout.
Stack Usage: Utilizes a stack (Fix structure) to handle operands and operators during expression evaluation.
*/
