#include<iostream>
#include<conio.h>
using namespace std;
int pos = -1,i = 0;
class postfix
{
    private:
        char postfix[100] , stack[50];
        char ch , op;
        int j = 0, r;

    public:

        void loop(char infix[])
        {
            while(infix[i] != '\0')
            {
                ch = infix[i];
                if( !isopr(ch) )
                {
                    postfix[j] = ch;
                    i++;
                    j++;
                }
                else
                {
                    if(ch == '(')
                    {
                        r = push(stack,ch);
                        i++;
                    }
                    else
                    {
                        if( isopr(ch) && ch!=')' )
                        {
                            if(pos == -1)
                            {
                                r = push(stack,ch);
                                //printf("%s\n",stack);
                            }
                            else
                            {
                                r = pop(stack,&op);
                                while( proty(op) >= proty(ch) && r==1 ) // r==1 Added
                                {
                                    postfix[j++] = op;
                                    r = pop(stack,&op);
                                }
                                if(r == 1)// if Added
                                {   
                                    r = push(stack,op); 
                                }
                                //r = push(stack,op);
                                r = push(stack,ch);
                            }
                            i++;
                        }
                        else
                        {
                            if(ch==')')
                            {
                                r = pop(stack,&op);
                                while(op != '(')
                                {
                                    postfix[j++] = op;
                                    r = pop(stack,&op);
                                }
                                i++;
                            }
                        }
                    }
                }
            }  
            while(pos != -1)
            {
                r = pop(stack,&op);
                postfix[j] = op;
                j++;
            }
            postfix[j] = '\0';
            cout << "Postfix Exprssion " << postfix << "\n\n";     //  42$3*3-84/11+/+
        }

        int push(char st[], char c)
        {
            if(pos == 99)
            {   return(0);  }
            else
            {
                st[++pos] = c;
                return(1);
            }
        }
        int pop(char st[], char *c)
        {
            if(pos == -1)
            {   return(0);  }
            else
            {
                *c = st[pos--];
                return(1);
            }
        }
        int isopr(char c)
        {
            if(c=='+'||c=='-'||c=='*'||c=='/'||c=='$'||c=='('||c==')')
            {   return(1);  }
            else
            {   return(0);  }
        }
        int proty(char op)
        {
            if(op == '$')
            {   return(4);  }

            if(op == '/' || op == '*')
            {   return(3);  }

            if(op == '+' || op == '-')
            {   return(2);  }

            return(1);
        }
};

int main()
{
    postfix a;
    char infix[100] ;
    cout << "\nEnter the infix expretion : ";         //4$2*3-3+8/4/(1+1)
    cin >> infix;
    a.loop(infix);
    return(0);
}
