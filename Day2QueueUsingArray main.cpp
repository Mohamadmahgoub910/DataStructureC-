#include<iostream>
#include<string>
using namespace std;

class Queue {
	int *arr;
	int size, front, rear;
public:
	Queue(int _size) {
		size = _size;
		arr = new int[size];
		front = rear = -1;

	}
	void enqueue(int data) {

		if (isFull()) {
			cout << "is Full \n";
			return;
		}
		else {
			rear++;
			arr[rear] = data;
			if (isEmpty()) {
				front++;
			}
		}

	}
	void dequeue(int &data) {
		if (!isFull()) {
			cout << "Empty \n";
		}
		//shift data
		data = arr[front];
		shift();
		rear--;
	} // 3 5 7 9 ...
	int isEmpty() {
		// valid for all condition except 
		// one condition
		return front == -1 || (front > rear);

	}
	int isFull() {
		if (rear ==size-1) {
			return 1;
		}
		else
			return 0;
	}
	void display()
	{
		for (int i = front; i <=rear; i++)
		{
			cout << arr[i] << endl;
		}
	}
private:
	void shift() {
		
		for (int i = 0; i < rear; i++) {
			arr[i] = arr[i + 1];
		}
	}
};
int main() {

	Queue queue(5);

	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(7);
	queue.enqueue(9);
	queue.enqueue(11);
	queue.display();
	cout << "===========  \n";
	int data;

	queue.dequeue(data);
	queue.display();
	//cout << data << endl;
	cout << "===========  \n";
	queue.enqueue(90);
	queue.enqueue(100);
	cout << "===========  \n";
	queue.display();
	return 0;
}