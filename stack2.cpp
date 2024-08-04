#include <iostream>
using namespace std;

class STACK
{

public:
    int arr[4];
    int top = -1;
    int stackSize = 4;

    bool isFull()
    {
        if (top == stackSize - 1) return true;
        else return false;
    }

    bool isEmpty()
    {
        if (top == -1) return true;
        else return false;
    }

    int push(int value)
    {
        if (isFull()) return -1;
        else
        {
            top++;
            arr[top] = value;
        }
        return arr[top];
    }

    int pop()
    {
        if (isEmpty()) return -1;
        else
        {
            int value = arr[top];
            top--;
            return value;
        }
    }

    int peek()
    {
        if (isEmpty()) return 0;
        else return arr[top];
    }
};

int main()
{
    STACK S1, S2;
    int el;

    cout << "Enter the elements of the queue: ";
    while (!S1.isFull())
    {
        cin >> el;
        S1.push(el);
    }

    while (!S1.isEmpty())
    {
        S2.push(S1.pop());
    }

    cout << "The Queue is: " << endl;
    for (int i = S2.top; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << S2.arr[i] << " -> Last In & Last Out" << endl;
        }
        else if (i == S2.top)
        {
            cout << S2.arr[i] << " -> First In & First Out" << endl;
        }
        else cout << S2.arr[i] << endl;
    }

    return 0;
}
