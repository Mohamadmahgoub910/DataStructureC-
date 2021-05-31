#include<iostream>
#include<string>
using namespace std;
class Stack
{
	//(1) push pop peak
	int *arr;
	int size , top;
public:
	Stack(int _size) {
		this->size = _size;
		arr = new int[size];
		top = -1;
	}
	void push(int data) {
		//2 i need to know where i am as a top.
		if (top <= size - 1) {
			top++;
			arr[top] = data;
		}
		else {
			cout << "Full \n";
		}
	}
	int pop() {
		if (size != -1) {
			return arr[top--];
		}
		else {
			cout << "Empty \n";
			return -1;
		}
		
	}
	int peek() {
		// return to top of arr 
		if (top <= size - 1) {
			return arr[top];
		}
	}
	int sizeq() {
		return top + 1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << "\n";
		}
		
	}
};





int main() {

	// make arr in stack with 10 elements
	Stack stack(10);
	stack.push(2);
	stack.push(3);
	stack.push(5);
	stack.push(7);
	cout << "Push \n";
	stack.display();
	cout << endl;
	cout << "pop \n";
	// delete 7
	stack.pop();
	stack.display();

	cout << "The top element is " << stack.peek() << endl;
	cout << "The stack size is " << stack.sizeq() << endl;
	return 0;
}