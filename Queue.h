#include "iostream"

template <class T>
struct Element
{
	Element<T> *next;
	T value;
};

template <class T>
class Queue
{
private:
	Element<T> *first;
	int length;
	void push_pv(Element<T> *element, T value);

public:

	Queue(){
		first = new Element<T>();
		first->next = NULL;
		length = 0;
	};

	~Queue(){
		delete first->next;
		delete first;
	};

	void push(T value);
	T pull();
	std::string to_string();
	
	int size_of(){
		return length;
	};	
};

template <class T>
void Queue<T>::push(T value){
	
	length++;
	if(first->next == NULL ){

		first->value = value;
		first->next = new Element<T>();
		first->next->next = NULL;

	}else{
		push_pv(first->next,value);
	}

};


template <class T>
void Queue<T>::push_pv(Element<T> *element,T value){

	if(element->next == NULL ){

		element->value = value;
		element->next = new Element<T>();
		element->next->next = NULL;

	}else{
		push_pv(element->next,value);
	}
}


template <class T>
std::string Queue<T>::to_string(){
	
	Element<T> *tmp_queue = first;
	
	std::string list = "";
	while(tmp_queue->next != NULL ){

		list = list + std::to_string(tmp_queue->value) + " ";
		tmp_queue = tmp_queue->next;
	}

	return list;
};

template <class T>
T Queue<T>::pull(){
	
	if(first->next == NULL){
		
		throw "Error: The queue is empty\n";

	
	}else{

		length--;
		T tmp_variable = first->value;
		first = first->next;
		return tmp_variable;
	}

};