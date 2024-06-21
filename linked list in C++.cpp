#include<iostream>
#include<conio.h>
using namespace std;

struct list
{
    int info;
    struct list *next;
};
typedef struct list node;

class link
{
    private:
        node *start , *newnode , *prev , *temp;
        int num;

    public:
        node *creat()
        {
            char loop = 'y';
            start = NULL;
            while(loop == 'y')
            {
                cout << "Enter the Element : ";
                cin >> num;
                newnode = (node *)malloc(sizeof(node));
                newnode -> info = num;
                newnode -> next = NULL;
                if(start == NULL)
                {
                    start = newnode;
                }
                else
                {
                    prev -> next = newnode;
                }
                prev = newnode;
                cout << "Would you wish to Continue[y/n]? : ";
                cin >> loop;
            }
            return(start);
        }
        node *insert(node *s, int n , int p)
        {
            newnode = (node *)malloc(sizeof(node));
            newnode -> info = n;
            newnode -> next = NULL;
            if(p == 1 || s == NULL)
            {
                newnode -> next = s;
                s = newnode;
            }
            else
            {
                temp = s;
                int c = 2;
                while(temp -> next != NULL && c < p)
                {
                    c++;
                    temp = temp -> next;
                }
                newnode -> next = temp -> next;
                temp -> next = newnode;
            }
            cout << "Node Inserted!\n\n";
            return(s);
        }
        int delet(node **s , int n)
        {
            if(*s == NULL)
            {
                return(0);
            }
            else
            {
                prev = NULL;
                temp = *s;
                while(temp != NULL && temp -> info != n )
                {
                    prev = temp;
                    temp = temp -> next;
                }
                if(temp == NULL)
                {
                    return(0);
                }
                else
                {
                    if(temp == *s)
                    {
                        *s = (*s) -> next;
                    }
                    else
                    {
                        prev -> next = temp -> next;
                    }
                    free(temp);
                    return(1);
                }
            }
        }
        void display(node *s)
        {
            cout << "Linked List : ";
            for(temp = s ; temp != NULL ; temp = temp -> next)
            {
                cout << temp -> info << " ";
            }
        }
};
int main()
{
    class link a;
    node *start;
    int num , pos , r, ch;
    while(1)
    {
        cout << "1.To creat the Linked list\n2.To Insert the number\n3.To Delete the number\n4.To Display the Linked List\n5.Exit\n : ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                start = a.creat();
                cout << "Linked List created!\n\n";
                break;

            case 2:
                cout << "\nEnter the Number to be inserted and it's position : ";
                cin >> num >> pos;
                start = a.insert(start , num , pos);
                break;

            case 3:
                cout << "Enter the number to be Deleted: ";
                cin >> num;
                r = a.delet(&start , num);
                if(r == 1)
                {
                    cout << "Number  Deleted! :" << num << "\n\n" ;
                }
                if(r == 0)
                {
                    cout << "Number not Deleted\n\n";
                }
                break;
            
            case 4:
                if(start != NULL)
                {
                    a.display(start);
                    cout << "\n\n";
                }
                else
                {
                    cout << "List is Empty!\n";
                }
                break;
                
            case 5:
                exit(0);
        }
    }   
    return(0);
}