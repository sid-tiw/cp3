// On the order of the CP Lead, Siddharth Mani Tiwari
// Written by Siddhartha Tiwari.


/***
	Waise ek raz ki baat batata hoon. Iss file ko dekhne yaa padhne se placement mein kuch nahi ukhdega. Jisko kuch karna hai woh bina isko dekhe bhi kar lega.
	Haan ek do bade logon ka naam zaroor maloom ho jayega (Line: 146-150).
***/

import java.util.*;

/*
	COLLECTIONS IN JAVA:

	1=> "ArrayList", the Java equivalent of the c++ vectors
	2=> "PriorityQueue", same as c++ except basic constructs. You can use it as min-heap as well as max-heap.
	3=> "Set", the perfectly balanced binary tree. A class is needed to implement it as it is an interface. Luckily HashSet does the job.
	4=> "Map", the interface which is implemented by the HashMap class in Java.
	5=> "Stack"
	6=> "Queue", using the LinkedList for implementation
	7=> "Deque", using the LinkedList for implementation
*/

class Main {
	public static void main(String[] args) {
		
		/******************************
			1=> ArrayList
		*******************************/


		// The great ArrayList that is analogous to c++ stl vectors in many ways
		
		int n = 10; // The initial size of the array list. You can provide the size if you know
					// beforehand. This improves the performance.

		ArrayList<Integer> arr = new ArrayList<Integer>(n); // ArrayList is a dynamically sized array. The constructor creates an array list of size n. It can be omitted if you don't know what the size is going to be.

		for (int i = 0; i < n; i++) {
			// There are two ways you need to know to insert in an arraylist.
			// The first way is to just provide the object(in this case a number) to push at
			// the last position
			arr.add(n - i);

			// Or you can provide the index at which to add and the number also.

			arr.add(0, n - i);
		}

		// to sort any object that is a java collection you can use Collections.sort()
		Collections.sort(arr);

		// Or the sort() method of ArrayList can also be used here.
		// I have used lambda expressions to implement the compare function of the Comparator interface. You can use a class too. However life is easy with the lambda expressions.
		arr.sort((o1, o2) -> {
			return o1.intValue() - o2.intValue();
		});

		// To sort the array in decreasing order just modify the content of the comparator inside of the sort. Yeah it's that easy.

		arr.sort((o1, o2)-> {
			return o2.intValue() - o1.intValue();
		});

		// print any container using the for-each loop
		
		for (int it : arr)
			System.out.print(it + " ");
		System.out.println();

		// You can also print by just passing the array into println() function. But then you cannot format it according to your choice.

		System.out.println(arr);

		
		
		/******************************
			2=> PriorityQueue
		*******************************/



		// The priority queue is the data structure that is equivalent to Heap. Yeah the name says the same.

		// I personally recommend the following constructor for PriorityQueue, because this also defines the comparator. Therfore, you can use it to implement both the min-heap and max-heap.

		PriorityQueue<Integer> minHeap= new PriorityQueue<Integer>(n, (o1, o2) -> {
			return o1.intValue() - o2.intValue();	// For max heap just reverse the ordering. It's genius whoever wrote this implementation of PriorityQueue. I don't know, James Gosling maybe!
		});

		for (int i = 0; i < n; i++) {
			
			// The insertion in priority is as easy as in ArrayList.
			minHeap.add(n - i);

			// Alternatively a whole collection(ArrayList, Set etcetra) can also be added in one go.
			minHeap.addAll(arr);
		}

		// Access the value using peek() function.
		System.out.println(minHeap.peek());
		
		// Remove the root using the remove function.
		minHeap.remove();

		
		
		/******************************
			3=> Set
		*******************************/


		
		// Just like any other collection in java you can give the intial size for better performance.
		// You can also create a set from a pre existing collection like the "arr" above by passing it into the constructor.
		Set<Integer> intSet = new HashSet<Integer>(n);

		for (int i = 0; i < n; i++) {
			
			// Set is a collection just like the ArrayList. So the add function can be used to insert the elements.
			intSet.add(n - i);
			intSet.add(i);
		}
		
		// to search for an element in the set use the contains() functions. Sadly Java only indicates whether the element is in the set or not as opposed to c++ set.
		System.out.println(intSet.contains(11));

		// to remove an element use the remove() function
		intSet.remove(10);

		System.out.println(intSet);

		
		
		/******************************
			4=> Map
		*******************************/



		// Use HashMap's constructor to create a Map object in Java.
		// Here first String object is the key and the second String object is its value.
		Map<String, String> coders = new HashMap<String, String>(n);

		// To add a key value pair, use the put() method of the Map interface.
		coders.put("Secretary", "Pushkar Patel");
		coders.put("CP Lead", "Siddharth Mani Tiwari");
		coders.put("AI/ML Lead", "Tanmay Ambadkar");
		coders.put("Web Development Lead", "Aman Raj");
		coders.put("Baki sab", "Chutiye");	// Aisa nahi hai isilye is entry ko delete kar raha hoon (Line: 156). No offense to me and other IIITians.

		// To get the value of a key use the get() method. It returns null if no such key is found.
		System.out.println(coders.get("Baki sab"));

		// To remove elements from the map use the remove() method
		coders.remove("Baki sab");

		System.out.println(coders);


		
		/******************************
			5=> Stack
		*******************************/


		// Use the default constructor to create a Stack object in Java.
		Stack<Integer> intStack = new Stack<Integer>();

		// To add any element just use the push() method of the Stack class
		intStack.push(1729);
		intStack.push(5);	// This is the crap that I'm going to remove in the next line.

		// To remove the top element of the stack use the pop() method. Also returns the element at head.
		intStack.pop();

		// To just read the top element of the stack use the peek() method.
		int holyNumber = intStack.peek();
		
		System.out.println(holyNumber);

		
		
		/******************************
			6=> Queue
		*******************************/


		// Because the queue is an interface in java, you can create an object of Queue type by using the constructor of a class that implements the Queue type. Here this class is the LinkedList.
		Queue<Integer> intQueue = new LinkedList<Integer>();

		// To enqueue use the add() method
		intQueue.add(5);
		intQueue.add(1729);

		// To dequeue use the pop() method. This also returns the number at the head.
		int trash = intQueue.remove();

		// To access the element at head without deleting it, use the peek() function.
		holyNumber = intQueue.peek();

		System.out.println(trash);
		System.out.println(holyNumber);


		/******************************
			7=> Deque
		*******************************/

		
		// This is just the same as queue with one exception that you can add elements to the front as well as to the back. It is same as stack + queue.

		// Create the object of a Deque type by using any one of the constructors of the LinkedList class.
		Deque<Integer> intDeque = new LinkedList<Integer>();

		// To add at the front use the addFirst() method
		intDeque.addFirst(1729);
		intDeque.addFirst(500);

		// To add at the last use the addLast() method or the add() method
		intDeque.addLast(2030);
		intDeque.add(1127);

		// To remove from the front use the removeFirst() method (easier to debug) or the pollFirst() method or the remove() method.
		trash = intDeque.removeFirst();
		holyNumber = intDeque.pollFirst();
		
		// To remove from the last use the removelast() method or the pollLast() method.
		int l1 = intDeque.removeLast();
		int l2 = intDeque.pollLast();

		System.out.println(trash + ", " + holyNumber + ", " + l1 + ", " + l2);

		/*	
			Thank you CP Lead for providing me an opportunity like this.
											.... Your Employee- Siddhartha Tiwari
		*/

		/*
			Aage kuch nahi hai. THE END ho gaya is file ka.
		*/
	}
}