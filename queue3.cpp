#include <iostream>
using namespace std;

class STACK {

public:
	int arr[20];
	int top = -1;
	int stackSize = 20;

	bool isFull() {
		if (top == stackSize - 1) return true;
		else return false;
	}

	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}

	int push(int value) {
		if (isFull()) return -1;
		else {
			top++;
			arr[top] = value;
		}
		return arr[top];
	}

	int pop() {
		if (isEmpty()) return -1;
		else {
			int value = arr[top];
			top--;
			return value;
		}
	}

	int peek() {
		if (isEmpty()) return 0;
		else return arr[top];
	}
};

class QUEUE {

public:
	int arr[20];
	int f = -1, r = -1;
	int queueSize = 20;

	bool isFull() {
		if (r == queueSize - 1) return true;
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
	STACK S;
	QUEUE Q;

    int el;
    cout << "Enter elements of the queue, Enter 0 to exit: ";

    do{
        cin >> el;
        Q.enqueue(el);
	}while(el != 0);
    Q.dequeueR();

    while (!Q.isEmpty())
    {
		S.push(Q.dequeueF());    
    }

	while(!S.isEmpty()){
		Q.enqueue(S.pop());
	}

	for(int i = Q.f; i <= Q.r; i++){
		cout << Q.arr[i] << endl;
	}
	
}