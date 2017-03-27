#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

#include <cstddef>

template <class T>
class Node{
    public:
      Node* next;
      T data;
      Node(T val){
	  this -> data = val;
          this -> next = NULL;
      }

};

template <class T>
class LinkedList{

  private:
	Node<T>* head;
	Node<T>* current;
	int length;

  public:
	LinkedList();
	LinkedList(const LinkedList<T> & sll);
	~LinkedList();
	void insert(T data);
	T read();
	void reset();
	bool empty();
	bool remove(T &data);
	T find(T &val);
	void operator << (T other);
};


template <class T>
LinkedList<T>::LinkedList(){
	length = 0;
	head = NULL;
	current = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & otherList){
	if(otherList.head == NULL){
                head = NULL;
                current = NULL;
                length = 0;
    }
    else{
            head = new Node<T> (otherList.head->data);
            current = head;
            length++;
            Node<T>* temp = otherList.head;
            while(temp -> next != NULL){
                current -> next = new Node<T> (temp->next->data);
                current = current-> next;
                temp = temp->next;
                length++;
            }
        }
}

template <class T>
LinkedList<T>::~LinkedList(){

	Node<T>* temp = head;
        Node<T> *next = NULL;
        while(temp != NULL){
                next = temp->next;
                delete temp;
                temp = next;
        }
}

template <class T>
void LinkedList<T>::insert(T data){
	if(head == NULL){
        head = new Node<T> (data);
     }
     else if(head != NULL){
        Node<T>* temp = this -> head;
        while(temp->next != NULL){
                temp = temp->next;
        }
        temp->next = new Node<T> (data);
     }
     length++;
}

template <class T>
T LinkedList<T>::read(){
    if(current == NULL){
          current = head;
    }
    T val = current -> data;
    if(current->next != NULL){
       current = current->next;
    }
    return val;
}

template <class T>
void LinkedList<T>::reset(){
	current = NULL;
}

template <class T>
bool LinkedList<T>::empty(){
	if (head == NULL){
		return true;
	}
	return false;
}

template <class T>
bool LinkedList<T>::remove(T &other)
{
        Node<T> *temp = this->head;
        Node<T> *prev = NULL;

        while (temp)
        {
                if (temp->data == other)
                {
                        if (prev)
                                prev->next = temp->next;
                        else
                                this->head = temp->next;

                        delete temp;
                        temp = NULL;
                        return true;
                }
                else
                {
                        prev = temp;
                        temp = temp->next;
                }
        }

        return false;
}


template <class T>
T LinkedList<T>::find(T &val){
        Node<T>* temp = this->head;
        while(temp){
                if(temp->data == val){
                        return temp->data;
                }else{
                        temp = temp->next;
                }

        }
        return NULL;
}

template <class T>
void LinkedList<T>::operator << (T other){
	this->insert(other);
}






#endif
