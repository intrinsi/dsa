#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> stack1, stack2; 

	void enqueue(int x) 
	{ 
		// Move all elements from s1 to s2 
		while (!stack1.empty()) { 
			stack2.push(stack1.top()); 
			stack1.pop(); 
		} 

		// Push item into s1 
		stack1.push(x); 

		// Push everything back to s1 
		while (!stack2.empty()) { 
			stack1.push(stack2.top()); 
			stack2.pop(); 
		} 
	} 

	// Dequeue an item from the queue 
	int dequeue() 
	{ 
		// if first stack is empty 
		if (stack1.empty()) { 
			cout << "queue is Empty"; 
			exit(0); 
		} 

		// Return the top of stack1 
		int x = stack1.top(); 
		stack1.pop(); 
		return x; 
	} 
}; 

int main() 
{ 
	Queue q; 
	q.enqueue(3); 
	q.enqueue(4); 
	q.enqueue(5); 

	cout << q.dequeue() << endl; 
	cout << q.dequeue() << endl; 
	cout << q.dequeue() << endl; 

	return 0; 
} 
