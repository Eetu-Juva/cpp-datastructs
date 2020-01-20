#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "./deque.h"
//#define T int

namespace util{
namespace datastruct {
	
template<typename T>
class Queue{
private:
	Varray<T>* array;
	unsigned front=0;
	unsigned back=0;
public:
	Queue(){
		array = new Varray<T>(5);
	}
	void push(T vall){
		array->set_value(back,vall);
		++back;
		if(back >= array->get_sizse()){array->expand_by(5);}
	}
	T get_next(){
		if(back == 0){return {};}
		--back;
		T temp = array->get_val(front);
		array->sift_by(1,sift_directson::left);
		return temp;
	}
	unsigned elements_in_queue(){
		return back;
	}
	
	
	
};

}}//namespace util::datastruct
#endif // QUEUE_H_INCLUDED
