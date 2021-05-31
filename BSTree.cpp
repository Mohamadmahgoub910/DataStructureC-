#include<iostream>
using namespace std;

class Node {
public:
	Node *Left, *Right;
	int Data;
	Node(int _data) {
		Data = _data;
		Left = Right = NULL;
	}
	Node() {
		Left = Right = NULL;
	}
};

class Tree {
	Node *Root;
public:
	Tree() {
		Root = NULL;
	}
	void add(int data) {
		Node *newNode = new Node(data);
		if (Root == NULL) {
			Root = newNode;
		}
		else {//1 if and else check empty node
			//msh3arf a7t elnode fin lw wslt be elcurr null
			//mabrook 7t eldata
			Node *current = Root;
			//pointer that save previous step for curr
			Node *parent = new Node();//GetParent(Root);
			while (current!=NULL) {
				parent = current;
				if (data < current->Data) {
					// left 
					current = current->Left;
				}
				else {
					current = current->Right;
				}
			}
			if (data < parent->Data) {
				parent->Right = newNode;
			}
			else {
				parent->Left = newNode;
			}
			
			

		}//1
	}
	
	void Delet(int data) {
		Node *pDelete = Search(data);
		Node *current;
		if (pDelete == Root) {
			// elola w ela5ira
			if (Root->Left == NULL && Root->Right == NULL) {
				Root = NULL;
			}
			// has a child in 3 cases 
			else if(Root->Right==NULL) {
				// root has left 
				Root = Root->Left;
			}
			// root has right 
			else if (Root->Left == NULL) {
				Root = Root->Right;
			}
			// root has both
			else {
				// aksa al yameen
				current = GetMaxRight(Root->Left);
				current->Right = Root->Right;
				Root = Root->Left;
			}
		}
		else {
			// delete a simple node 
			//1- mlhash children
			Node *parent = GetParent(pDelete);
			if (pDelete->Left == NULL && pDelete->Right == NULL) {
				// a3rf hia 3 elshmal wla elymeen
				if (parent->Left == pDelete) {
					//yes 
					parent->Left = NULL;
				}
				else {
					parent->Right = NULL;
				}
			}
			//2-node 3dia liha left bs
			else if (pDelete->Right == NULL)
			{
				// has left bs
				if (parent->Left == pDelete) {
					//yes 
					parent->Left = pDelete->Left;
				}
				else {
					parent->Right = pDelete->Left;
				}
			}
			else if (pDelete->Left == NULL)
			{
				if (parent->Left == pDelete) {
					//yes 
					parent->Left = pDelete->Right;
				}
				else {
					parent->Right = pDelete->Right;
				}
			}
			else
			{
				//3ndoh ymenn w shmall
				current = GetMaxRight(pDelete->Left);
				current->Right = pDelete->Right;
				if (parent->Left == pDelete) {
					//yes 
					parent->Left = pDelete->Left;
				}
				else {
					parent->Right = pDelete->Left;
				}
			}

	
		}
		delete pDelete;
}
	// LDR 
	void Traverse() {
		Display(Root);
	}
private:
	void Display(Node *pDisplay) {
		if (pDisplay == NULL) 
			return;
		Display(pDisplay->Left);
		cout << pDisplay->Data << "\t";
		Display(pDisplay->Right);
	}
	Node *GetMaxRight(Node *current) {
		while (current->Right != NULL)
		{
			current = current->Right;
		}
		return current;
	}
	Node *Search(int data) {
		Node *current = new Node(data);
		while (current !=NULL) {
			// compare data and node ==?true 
			if (data == current->Data) {
				return current;
			}
			if (data > current->Data) {
				current = current->Right;
			}
			else
			{
				current = current->Left;
			}
		}
		return NULL;
	}
	Node *GetParent(Node *child) {
		Node *parent = Root;
		while (parent !=NULL) {
			if (parent->Left == child || parent->Right==child){
				return parent;
			}
			if (child->Data > parent->Data) {
				parent = parent->Left;
			}
			else {
				parent = parent->Right;
			}
		}
		return NULL;
}
};
int main() {
	Tree tree;
	tree.add(50);
	tree.add(40);
	tree.Traverse();

	return 0;

}