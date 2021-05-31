#include<iostream>
using namespace std;

class  QNode {
public:
	int data;
	QNode* next;
	QNode(int _data)
	{
		data = _data;
		next = NULL;
	}
};

class Queue {
public:
	QNode *front, *rear;
	Queue()
	{
		front = rear = NULL;
	}

	void enQueue(int x)
	{
		QNode* temp = new QNode(x);
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	bool deQueue(int &data )
	{
		// If queue is empty, return NULL.
		if (front == NULL)
			return false;

		QNode* pDelete = front;
		front = front->next;

		/*if (front == NULL)
			rear = NULL;*/
		data = pDelete->data;
		delete (pDelete);
		return true;
		
	}
	void display()
	{
		QNode*newNode = front;
		while (newNode != NULL)
		{
			cout << newNode->data << "\n";
			newNode = newNode->next;
		}
	}
};


int main()
{

	Queue q;
	q.enQueue(3);
	q.enQueue(5);
	q.enQueue(7);
	q.enQueue(9);
	q.enQueue(11);
	q.display();
	cout << "========/ \n";
	int data;
	q.deQueue(data);
	cout << data << endl;


	q.display();

	/*while (q.isEmpty())
	{
		q.deQueue(data);
		cout << data << endl;

	}*/
	
	//q.deQueue();
	//q.display();
	

	return 0;
}