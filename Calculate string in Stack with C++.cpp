#include<iostream>
#include<conio.h>
using namespace std;
int pos = -1;
int push( char  [], char );
int pop(char [] , char * );
int opretor(char );
int proty(char );

// ERROR in this program which is yet to find
int main()
{
    int i=0 , j=0 , r;
    char st[50] , infix[100] , postfix[100];
    char ch , op;
    cout << "Enter the infix : ";               //4$2*3-3+8/4/(1+1)
    cin >> infix ;
    while(infix[i] != '\0' )
    {
        ch = infix[i];
        if( !opretor(ch) )
        {
            postfix[j] = ch;
            i++;
            j++;
        }
        else
        {
            if(ch == '(')
            {
                r = push(st , ch);
                i++;
            }
            else
            {
                if( opretor(ch) && ch != ')')
                {
                    if(pos == -1)
                    {
                        r = push(st,ch);
                    }
                    else
                    {
                        r = pop(st , &ch);
                        while( proty(op) >= proty(ch) && r==1 )
                        {
                            postfix[j++] = op;
                            r = pop(st , &op);
                        }
                        if( r == 1)
                        {
                            r = push(st , op);
                        }
                        r = push(st , ch);
                    }
                    i++;
                }
                else
                {
                    if(ch == ')')
                    {
                        r = pop(st , &op);
                        while(op != '(')
                        {
                            postfix[j++] = op;
                            r = pop(st , &op);
                        }
                        i++;
                    }
                }
            }
        }
    }
    while(pos != -1)
    {
        r = pop(st , &op);
        postfix[j] = op;
        j++;
    }
    postfix[j] = '\0';
    cout << "Postfix Expression : " << postfix;
    return(0);
}
int push(char s[] , char n)
{
    if(pos == 99)
    {
        return(0);
    }
    else
    {
        s[++pos] = n;
        return(1);
    }
}
int pop(char s[] , char *n)
{
    if(pos == -1)
    {
        return(0);
    }
    else
    {
        *n = s[pos--];
        return(1);
    }
}
int opretor(char c )
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '(' || c == ')')
    {
        return(1);
    }
    else 
    {
        return(0);
    }
}
int proty( char op)
{
    if( op == '$')
    {
        return(4);
    }
    if( op == '/' || op == '*')
    {
        return(3);
    }
    if( op == '+' || op == '-')
    {
        return(2);
    }
    return(1);
}
