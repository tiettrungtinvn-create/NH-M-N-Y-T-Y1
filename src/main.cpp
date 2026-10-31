#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
} Node;

typedef struct queue {
	Node* head;
	Node* tail;
	int size;

	void init();
	Node* createNode(int x);
	void enqueue(int x);
	void dequeue();
	void print();
} Queue;

void Queue::init() {
	size = 0;
	head = tail = NULL;
}

Node* Queue::createNode(int x) {
	Node* p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void Queue::enqueue(int x) {
	Node* L = createNode(x);
	if (L == NULL) return;
	if (size == 0) {
		head = tail = L;
	} else {
		tail->next = L;
		tail = L;
	}
	size++;
}

void Queue::dequeue() {
	if (head == NULL) {
		return;
	} else {
		Node* t = head;
		head = head->next;
		delete t;
		if (head == NULL) {
			tail = NULL;
		}
	}
	size--;
}

void Queue::print() {
	for (Node* i = head; i != NULL; i = i->next) {
		cout << i->data << " ";
	}
}

int main() {
	Queue q;
	q.init();
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	q.enqueue(4);//8 9 10 4
	q.dequeue();// 9 10 4
	
	q.print();

	return 0;
}
