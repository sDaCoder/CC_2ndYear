#include <iostream>
using namespace std;
#define SIZE 40

class STACK {
	public:
		char arr[SIZE];
		int top = -1;

		bool isFull() {
			if (top == SIZE - 1) return true;
			else return false;
		}
		
		bool isEmpty() {
			if (top == -1) return true;
			else return false;
		}

		char push(char value) {
			if (isFull()) return '\0';
			else {
				arr[++top] = value;
				return arr[top];
			}
		}

		char pop() {
			if (isEmpty()) return '\0';  
			else {
				return arr[top--];
			}
		}

		char peek() {
			if (isEmpty()) return '\0'; 
			else return arr[top];
		}
};

class Solution{

	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
	}
	
	int prec(char c) {
		if (c == '+' || c == '-') return 1;
		else if (c == '/' || c == '*' || c == '%') return 2;
		else return 0;
	}
	
public:
	
	string postfix(string infix) {
		string result;
		STACK S;
	
		S.push('(');
		infix.push_back(')');
	
		for (int i = 0; infix[i] != '\0'; i++) {
			
			if (infix[i] == '(') {
				S.push('(');
			}
				
			else if (isdigit(infix[i]) || isalpha(infix[i])) {
				result.push_back(infix[i]);
			}
				
			else if (infix[i] == ')') {
				while (S.peek() != '(') {
					result.push_back(S.pop());
				}
				S.pop();
			}
				
			else if (isOperator(infix[i])) {
				while (S.peek() != '(' && prec(S.peek()) >= prec(infix[i])) {
					result.push_back(S.pop());
				}
				S.push(infix[i]);
			}
		}
	
		return result;
	}
};

int main() {
	string exp;
	cout << "Enter a expression: ";
	cin >> exp;
	
	Solution S;
	cout << S.postfix(exp) << endl;
}