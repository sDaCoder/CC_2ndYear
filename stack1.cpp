#include <iostream>
using namespace std;

class STACK {

  public:
    int arr[4];
    int top = -1;
    int stackSize = 4;
  
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

int main() {
  STACK S;

  int option;
  do {
    cout << endl << "Enter your option:" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cin >> option;

    switch (option) {

    case 0:
        break;

    case 1:
      if (S.isFull()) {
        cout << "Can't Push any elemets." << endl;
        break;
      }
      int value;
      cout << "Enter the value: ";
      cin >> value;
      S.push(value);
      break;

    case 2:
      if (S.isEmpty()) {
        cout << "Can't Pop any elemets." << endl;
        break;
      }
      S.pop();
      break;

    case 3:
      if (S.isEmpty()) {
        cout << "Stack is Empty." << endl;
        break;
      }
      cout << "The peek value of the stack is: " << S.peek() << endl;
      break;

    default:
      cout << "Invalid option" << endl;
    }

  } while (option != 0);

  cout << "The stack is: " << endl;
  for (int i = 0; i <= S.top; i++) 
    cout << S.arr[i] << " ";

  cout << endl;
}
