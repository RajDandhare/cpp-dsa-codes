#include<iostream>
#include<conio.h>
using namespace std;

int pos = -1;

class stack
{
    private:
        int st[20], num, r;

    public:
        void loop(int ch)
        {
            switch(ch)
            {
                case 1:
                    cout << "Enter the Element: ";
                    cin >> num;
                    r = push(st , num);
                    if(r == 0)
                    {
                        cout << "Stack Full!";
                    }
                    else
                    {
                        cout << "Element Inserted!";
                    }
                    break;

                case 2:
                    r = pop(st , &num);
                    if(r == 0)
                    {
                        cout << "Stack is Empty!";
                    }
                    else
                    {
                        cout << "Element Deleted! : " << num;
                    }
                    break;

                case 3:
                    if(pos == -1)
                    {
                        cout << "Stack is Empty!";
                    }
                    else
                    {
                        display(st);
                    }
                    break;

                case 4:
                    exit(0);
            }
        }
        int push(int st[], int num)
        {
            if(pos == 19)
            {
                return(0);
            }
            else
            {
                st[++pos] = num;
                return(1);
            }
        }
        int pop(int st[] , int *num)
        {
            if(pos == -1)
            {
                return(0);
            }
            else
            {
                *num = st[pos--];
                return(1);
            }
        }
        void display(int st[])
        {
            for(int i=0 ; i <= pos ; i++)
            {
                cout << st[i] << " ";
            }
        }
};

int main()
{
    system("cls");
    stack a;
    int ch;
    while(1)
    {
        cout << "1.To Insert the element\n2.To Delete the Element\n3.To Display the Stack\n4.Exit\n: ";
        cin >> ch;
        a.loop(ch);
        cout << "\n\n";
    }
    return(0);
}