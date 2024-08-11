#include <iostream>
using namespace std;
#define SIZE 7

class QUEUE
{

public:
    int arr[SIZE];
    int f = -1, r = -1;

    bool isFull()
    {
        if (r == SIZE - 1) return true;
        else return false;
    }

    bool isEmpty()
    {
        if ((f == -1 && r == -1) || (f > r)) return true;
        else return false;
    }

    bool enqueue(int val)
    {
        if (isFull()) return false;
        else if (isEmpty())
        {
            f = 0;
            r = 0;
        }
        else r++;
        arr[r] = val;
        return true;
    }

    int dequeue()
    {
        int val;
        if (isEmpty()) return -1;
        else
        {
            val = arr[f];
            f++;
        }
        return val;
    }
};

int main()
{

    QUEUE Q;
    int option;
    do
    {
        cout << endl
             << "Enter a option:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;

        case 1:
            if (Q.isFull())
            {
                cout << "Can't Insert any Element" << endl;
                break;
            }
            int val;
            cout << "Enter a number: ";
            cin >> val;
            Q.enqueue(val);
            break;

        case 2:
            if (Q.isEmpty())
            {
                cout << "Can't Delete any Element" << endl;
                break;
            }
            cout << "The deleted element is: " << Q.dequeue();
            break;

        default:
            cout << "Invalid Option" << endl;
        }
    } while (option != 0);

    cout << "The elements of the Queue is: " << endl;
    for (int i = Q.f; i <= Q.r; i++) cout << Q.arr[i] << " ";
}