#include<iostream>
using namespace std;
const int  Max_size = 10;
class CQueue {
	int *arr;
	int front, rear, count;
public:
	CQueue(int _data) {
		front = rear = -1;
		rear = Max_size - 1;
		count = 0;
		arr = new int[_data];
	}
	bool isEmpty();
	bool isFull();
	void addQ(int data);
	bool  deleteQ(int data);
	void display();
};



int main() {
	CQueue cq(5);
	cq.addQ(3);
	cq.addQ(5);
	cq.addQ(7);
	cq.addQ(9);
	cq.addQ(11);
	cq.display();

	return 0;
}

bool CQueue::isEmpty()
{
	return count == 0;
	/*if (count == 0) {
		return 0;
	}*/
}

bool CQueue::isFull()
{
	return count == Max_size;
}

void CQueue::addQ(int data)
{
	if (isFull()) {
		cout << "full \n";
	}
	else {
		rear = (rear + 1) % Max_size;
		arr[rear] = data;
		count++;
	}
}

bool CQueue::deleteQ(int data)
{
	if (isEmpty()) {
		cout << "Empty \n";
		return false;
	}
	else {
		front = (front + 1) % Max_size;
		arr[front] = data;
		--count;
		return true;
	}
}

void CQueue::display()
{
	for (int i = front; i !=rear; i=(i+1)%Max_size) {
		cout << arr[i] << "\n";
	}cout << arr[rear];
}
