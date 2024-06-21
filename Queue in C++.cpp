#include<iostream>
#include<conio.h>
using namespace std;

int first = 0 , last = -1;

class queue
{
    private:
        int q[20] , r , num;

    public:
        void loop(int ch)
        {
            switch(ch)
            {
                case 1:
                    cout << "Enter the Element to Insert: ";
                    cin >> num;
                    r = insert( q , num );
                    if(r == 0)
                    {
                        cout << "Queue is Full!";
                    }
                    else
                    {
                        cout << "Element Inserted!";
                    }
                    break;

                case 2:
                    r = delet( q , &num );
                    if(r == 0)
                    {
                        cout << "Queue s Empty!";
                    }
                    else
                    {
                        cout << "Element Deleted : " << num; 
                    }
                    break;

                case 3:
                    if(first-1 == last)
                    {
                        cout << "Queue is Empty!";
                    }
                    else
                    {
                        display( q );
                    }
                    break;

                case 4:
                    exit(0);
            }
        }
        int insert(int q[] , int num)
        {
            if(last == 19)
            {
                return(0);
            }
            else
            {
                q[++last] = num;
                return(1);
            }
        }
        int delet(int q[] , int *num)
        {
            if(first-1 == last)
            {
                return(0);
            }
            else
            {
                *num = q[first++];
                return(1);
            }
        }
        void display( int q[] )
        {
            for(int i = first ; i-1 != last ; i++)
            {
                cout << q[i] << " ";
            }
        }
};
int main()
{
    system("cls");
    queue a;
    int ch;
    while(1)
    {
        cout << "1.To Insert Elements\n2.To Delete the element\n3.To Display the Queue\n4.Exit\n : ";
        cin >> ch;
        a.loop(ch);
        cout << "\n\n";
    }
    return(0);
}