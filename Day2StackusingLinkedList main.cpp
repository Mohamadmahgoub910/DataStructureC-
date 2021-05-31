#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int Data;
	Node *Prev;
	Node(int _data) {
		Data = _data;
		Prev = NULL;
	}
};
class Stack {
	Node *Top;
public:
	Stack() {
		Top = NULL;
	}
	void push(int data) {
		Node *newNode = new Node(data);
		if (Top == NULL) {
			Top = newNode;
		}
		else {
			newNode->Prev = Top;
			Top = newNode;
		}
	}
	int pop(int &data) {
		if (Top == NULL) {
			return 0;
		}
		else {
			data = Top->Data;
			// temp pointer 
			Node *pDelete = Top;
			Top = Top->Prev;
			delete pDelete;
		}
	}
	void display() {
		Node *curr = Top;
		// loop to move and i will stop when curr->next ==>Null
		while (Top != NULL)
		{
			cout << curr->Data << "\t";
			curr = curr->Prev;
		}
	}
};


int main() {
	Stack stack;
	stack.push(3);
	stack.push(5);
	stack.push(7);
	stack.push(9);
	stack.display();
	return 0;
}