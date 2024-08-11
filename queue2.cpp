#include <iostream>
using namespace std;
#define SIZE 5

class QUEUE {

public:
    int arr[SIZE];
    int f = -1, r = -1;

    bool isFull() {
        if (r == SIZE - 1) return true;
        else return false;
    }

    bool isEmpty() {
        if ((f == -1 && r == -1) || (f > r)) return true;
        else return false;
    }

    bool enqueue(int val) {
        if (isFull()) return false;
        else if (isEmpty()) {
          f = 0;
          r = 0;
        } 
        else r++;
        arr[r] = val;
        return true;
    }

    int dequeueF() {
        int val;
        if (isEmpty()) return -1;
        else {
          val = arr[f];
          f++;
        }
        return val;
    }

    int dequeueR()
    {
        int val;
        if (isEmpty()) return -1;
        else{
             val = arr[r];
             r--;
        }
        return val;
    }
};

int main() {
    
    QUEUE Q1, Q2;

    int el;
    cout << "Enter the elements of the queue: ";
    while(!Q1.isFull()){
        cin >> el;
        Q1.enqueue(el);
    }

    while(!Q1.isEmpty()){
        Q2.enqueue(Q1.dequeueR());
    }

    cout << "The elements of the Stack are: " << endl;
    for (int i = Q2.f; i <= Q2.r; i++){
        if(i == Q2.f) cout << Q2.arr[i] << " -> Last In & First Out" << endl;
        else if(i == Q2.r) cout << Q2.arr[i] << " -> First In & Last Out" << endl;
        else cout << Q2.arr[i] << endl;
    }
    cout << endl;
    return 0;
}
