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
	
	bool matching(char a, char b)
	{
		if (a == '(' && b == ')') return true;
		else if(a == '{' && b == '}') return true;
		else if(a == '[' && b == ']') return true;
		else return false;
	}

public:
	bool parenMatch(string exp){
		
		STACK S;
		
		for(int i = 0; i < exp.length(); i++){
			if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
				S.push(exp[i]);
			}
			else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
				if(S.isEmpty()){
					return false;
				}
				else{
					char popped = S.pop();
					if(!matching(popped, exp[i])){
						return false;
					}
				}
			}
		}
		if(S.isEmpty()) return true;
		else return false;
	}
};

int main() {
	string exp;
	cout << "Enter a expression: ";
	cin >> exp;

	Solution S;
	if(S.parenMatch(exp)){
		cout << exp << " has valid parentheses" <<endl;
	}
	else cout << exp << " don't have valid parentheses" <<endl;
}
