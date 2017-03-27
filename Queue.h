#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class T>
class Queue{

	private:
		LinkedList<T>* list;
		int length;
	public:
		Queue();
		~Queue();
		void enqueue(T data);
		T dequeue();
		T peek();
		bool empty();
		void clear();



};


template <class T>
Queue<T>::Queue(){
	list = new LinkedList<T>();
}

template <class T>
Queue<T>::~Queue(){
	delete list;
}

template <class T>
void Queue<T>::enqueue(T data){
	list->insert(data);
}

template <class T>
T Queue<T>::dequeue(){
	list->reset();
	T obj = list->read();
	list->remove(obj);
	list->reset();
	return obj;
}

template <class T>
T Queue<T>::peek(){
	list->reset();
	T obj = list->read();
	list->reset();
	return obj;
}

template <class T>
bool Queue<T>::empty(){
	return list->empty();
}

#endif
