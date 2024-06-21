#include<iostream>
#include<conio.h>
using namespace std;

int first = 0 , last = -1 ;

class queue
{
    private:
        int q[5] , r , num;

    public:
        void loop(int ch)
        {
            switch(ch)
            {
                case 1:
                    cout << "Enter the Element to Insert: ";
                    cin >> num;
                    r = insert( q , num );
                    if(r == 1)
                    {
                        cout << "Element Inserted!";
                    }
                    else
                    {
                        cout << "Queue is Full!";
                    }
                    break;

                case 2:
                    r = delet( q , &num );
                    if(r == 1)
                    {
                        cout << "Element Deleted : " << num;
                    }
                    else
                    {
                        cout << "Queue s Empty!";
                    }
                    break;

                case 3:
                    /*if(first-1 == last)
                    {
                        cout << "Queue is Empty!";
                    }
                    else
                    {
                        display( q );
                    }*/
                    display( q );
                    break;

                case 4:
                    exit(0);
            }
        }
        int insert(int qu[] , int num)
        {
            if((last == 4 && first == 0 ) || (first != 0 && last+1 == first))
            {
                return(0);
            }
            else
            {
                last = (last+1) % 5;
                qu[last] = num;
                return(1);
            }
        }
        int delet(int qu[] , int *num)
        {
            if(first == 0 && last ==-1)
            {
                return(0);
            }
            else
            {
                *num = qu[first];
                first = (first+1) % 5;
                if((last == 4 && first == 0) || (first != 0 && last == first-1))
                {
                    first = 0;
                    last = -1;
                }
                return(1);
            }
        }
        void display( int qu[] )
        {
            for(int i = first ; last != -1 ; i = (i+1) % 5 )
            {
                cout << qu[i] << " ";
                if( i == last )
                {
                    break;
                }
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