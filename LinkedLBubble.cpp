#include<iostream>
#include<string>
using namespace std;
class Node {
private:

public:
	//(1)
	int Data;
	// pointer next 
	Node *Next;
	Node *Prev;
	//(2)
	Node(int _data) {
		Data = _data;
		//(9)
		Next = Prev = NULL;
	}
	Node() {
		Next = Prev = NULL;
	}

};
// set of functions and actions on LL
class LinkedList {
	Node *Head;
	Node *Tail;
public:

	//(3)
	LinkedList() {
		Head = Tail = NULL;
	}
	//(6)
	void add(int data) {
		// create object in stack
		// die after func die
		//Node node(data);
		//Head = &node;
		//(7)
		//still exist in heap
		Node *Newnode = new Node(data);
		//(8) ==>goto construct and make it next , prev = null
		// because u don't have to make prev , next = null as you want to create 
		// a new object.
		//Newnode->Next = NULL;
		//Newnode->Prev = NULL;
		//(10)pointer head point to newnode
		// Head ==> points to newnode
		//Head = Newnode;
		//tail must point to newnode also
		//Tail = Newnode;
		if (Head == NULL) {
			Head = Tail = Newnode;
			// add first node
		}
		//=====================
		else {
			//(11)
			// 3 steps prev,next,tail
			// important goto object that point to 3 and get the pointer next and make it 
			// equal to newnode = 5;
			Tail->Next = Newnode;
			// 5 point to 3 
			// new node point to prev node
			// connection between prev , tail
			Newnode->Prev = Tail;
			//add from Tail not Head why? we do this?
			Tail = Newnode;
			// Tail->next=NewNode; Gives you NULL

		}
	}
	void display() {
		// 12 make a temp curr to move
		Node *curr = Head;
		// loop to move and i will stop when curr->next ==>Null
		while (curr != NULL)
		{
			cout << curr->Data << "\t";
			curr = curr->Next;
		}
	}

	bool isEmpty() {
		if (Head == NULL && Tail == NULL) {
			return true;
		}
		else
		{
			return false;
		}
	}

	void Delete(int data) {
		// search on the data to find it first at which node?
		Node *pDelete = search(data);
		if (pDelete == NULL) {
			return;
		}
		if (pDelete == Head) {
			// it's same head ? or head point to next?
			//(13)
			if (pDelete == Tail) {
				// elnode el2la w ela5ira
				Head = Tail = NULL;
			}
			else
			{
				//(14)
				//delete and make new update
				Head = Head->Next;
				//update.
				Head->Prev = NULL;
			}
		}
		//(15) we delete tail ?
		else if (pDelete == Tail) {
			Tail = Tail->Prev;
			Tail->Next = NULL;
		}
		else
		{
			// (16) el node el in the middle
			//5->next=9
			//A->Next = pDelete->next
			//ÑæÍ ááäæÏ Çá ÈíÔÇæÑ ÚáíåÇ ÇáÈÑÝíÓ ÈÊÇÚ ÇáÈí ÏáíÊ
			//ÇáäßÓÊ ÇäÇ ÈÔÇæÑ Úá ÇáäæÏ Çá ÈíÔÇæÑ Úá ÇáÈÑÝíÓ
			pDelete->Prev->Next = pDelete->Next;
			//9->prev=5
			pDelete->Next->Prev = pDelete->Prev;
		}
		delete pDelete;
	}
	int getLength() {
		int nodeCounter = 0;
		if (isEmpty() == true) {
			return false;
		}
		else {
			Node *nodCount = Head;
			while (nodCount->Next != NULL)
			{
				nodeCounter++;
				nodCount = nodCount->Next;
			}
			return nodeCounter;
		}
	}
	int getByIndex(int index) {
		// check if i stop on the head at first or not 
		if (index == 0) {
			index = this->Head->Data;
			return index;
		}
		else
		{
			// loop untill get the index for loop not whilei have number of loop
			Node *nodeCurr = Head;
			for (int i = 0; i < index; i++) {
				nodeCurr = nodeCurr->Next;
			}return nodeCurr->Data;
		}

	}
	void addFront(int value) {
		Node *currNode = new Node(value);
		if (Head == NULL) {
			Head = currNode;
		}
		else
		{
			currNode->Next = Head;
			Head = currNode;
		}
	}

	/*void insertLast(int val) {

	Node *newNode = new Node;
	newNode->Data = val;
	newNode->Next = NULL;
	Tail->Next = newNode;
	newNode->Next = NULL;
	Tail = newNode;
	}*/
	void insertAfter(int val, int position)
	{
		Node *p = new Node;
		p->Data = val;
		if (position == 0) {
			addFront(val);
		}
		else if (position == getLength()) {
			add(val);
		}
		else {
			Node *curr = Head;
			for (int i = 0; i < position; i++) {
				curr = curr->Next;
			}
			p->Next = curr->Next;
			curr->Next->Prev = p;
			curr->Next = p;
			p->Prev = curr;


		}

	}

// Bubble sort 
	void bubblesort(int size) {
		int swapped = 1;
		for (int i = 0; swapped && i < size; i++) {
			swapped = 0;
			Node* temp = Head;
			for (int j = 0; j < size - i - 1; j++) {

				if (temp->Data > temp->Next->Data) {
					int tempNumber = temp->Data;
					temp->Data = temp->Next->Data;
					temp->Next->Data = tempNumber;
					swapped = 1;
				}
				temp = temp->Next;
			}
		}
	}


private:
	Node* search(int data) {
		// pointer to jump till found the data else null
		Node *current = Head;
		while (current->Next != NULL)
		{
			if (current->Data == data) {
				return current;
			}
			current = current->Next;

		}
		return NULL;
	}


};


#include<stack>
int main() {
	/*stack<char>s;
	string word = "stack";
	int i = 0;
	while (word[i] != 0) {
		s.push(word[i]);
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		i++;
	}*/

	
	// Linked List.
	//(4)
	LinkedList list;

	////(5)add in list.
	//list.add(3);
	//list.add(5);
	//list.add(7);
	//list.add(9);
	//list.add(11);

	//cout << "List Display \n";
	//list.display();
	//cout << endl;
	////check is empty
	//cout << "Check list is empty?==> \n";
	//cout << list.isEmpty() << endl;
	////display
	////list.display();

	////search

	//cout << "After Del \n";
	////delete
	//list.Delete(3);
	//list.display();
	//cout << endl;
	//cout << "counter of List is ==> ";
	//// Count the list
	//cout << list.getLength() << endl;
	//cout << "getByIndex = 2==>  ";
	//cout << list.getByIndex(2) << endl;
	//cout << endl;
	//cout << "ADD AFTER 90 \n";
	//list.addFront(90);
	//cout << endl;
	//cout << "insertLast 11 \n";
	//list.add(11);

	//list.display();
	//cout << "\n";

	//cout << "insertAfter  (1,1 ) ==> \n";
	//list.insertAfter(1, 1);
	//list.display();
	//cout << endl;



	
	int size, num;
	cout << "How many Numbers Do You Want to Store: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Enter Number " << i + 1 << ": ";
		cin >> num;
		list.add(num);
	}
	system("CLS");
	cout << " Before: \n" << endl;
	list.display();
	list.bubblesort(size);
	cout << "using Bubble: " << endl;
	list.display();









	/*int isPrime(int num)
	{
	int i; //loop counter
	//it will be 1 when number is not prime
	int flag = 0;
	//loop to check number is prime or not
	//we will check, if number is divisible
	//by any number from 2 to num/2, then it
	//will not be prime
	for (i = 2; i<num / 2; i++)
	{
	if (num%i == 0)
	{
	flag = 1;
	break;
	}
	}
	//flag is 1, if number is not prime
	if (flag == 1)
	return 0;
	else
	return 1;
	}
	void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	}
	int a = 3;
	int b = 4;
	cout << "before swap " << a << b << endl;
	swap(a, b);
	cout << "after swap " << a << b<<endl;


	int loop; //loop counter
	//declaring array with prime and not prime numbers
	int arr[] = { 3, 2, 4, 8 };
	//calculate length of the array
	int len = sizeof(arr) / sizeof(arr[0]);

	//print array elements with message
	//"prime" or "Not prime"
	for (loop = 0; loop<len; loop++)
	{
	printf("%3d - %s\n", arr[loop], (isPrime(arr[loop]) ? "Prime" : "Not Prime"));
	}
	*/





	return 0;
}