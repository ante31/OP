#include<iostream>

template<class T>
class Stack {
	T* array;
	int size;
	int capacity;
public:
	Stack(int size);
	~Stack() { 
		delete[] array;
	}
	void push(T& number);
	void pop();
	bool isEmpty();
	void print();
};

template <class T>
Stack<T>::Stack(int size)
{
	array = new T[size];
	this->size = 0;
	capacity = size;
}

template <class T>
void Stack<T>::push(T& number) {
	if (size == capacity)
	{
		capacity *= 2;
		T* myArray = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			myArray[i] = array[i];
		}
		delete[] array;
		array = myArray;
	}
	array[size] = number;
	++size;
}

template <class T>
void Stack<T>::pop() {
	--size;
}

template <class T>
bool Stack<T>::isEmpty() {
	return size;
}

template <class T>
void Stack<T>::print() {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
}
