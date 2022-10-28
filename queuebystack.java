import java.util.Stack;

class Queue<T> {
	private Stack<T> s;

	// Constructor
	Queue() {
		s = new Stack<>();
	}

	// Add an item to the queue
	public void enqueue(T data)
	{
		// push item into the first stack
		s.push(data);
	}

	// Remove an item from the queue
	public T dequeue()
	{
		// if the stack is empty
		if (s.isEmpty())
		{
			System.out.println("Underflow!!");
			System.exit(0);
		}

		// pop an item from the stack
		T top = s.pop();

		// if the stack becomes empty, return the popped item
		if (s.isEmpty()) {
			return top;
		}

		// recur
		T item = dequeue();

		// push popped item back into the stack
		s.push(top);

		// return the result of dequeue() call
		return item;
	}
}

class Main
{
	public static void main(String[] args)
	{
		int[] keys = { 5, 4, 3, 2, 1 };
		Queue<Integer> q = new Queue<Integer>();

		// insert the above keys into the queue
		for (int key: keys) {
			q.enqueue(key);
		}

		System.out.println(q.dequeue());
		System.out.println(q.dequeue());	
	}
}
