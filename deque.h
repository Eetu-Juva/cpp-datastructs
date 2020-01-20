#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include "./varay.h"
//#define T int

namespace util{
namespace datastruct {

template<typename T>
class Deque{
private:
	Varray<T>* array;
	unsigned front=0;
	unsigned back=0;
public:
	Deque(){
		array = new Varray<T>(5);
	}
	void push_back(T vall){
		array->set_value(back,vall);
		++back;
		if(back >= array->get_sizse()){array->expand_by(5);}
	}
	void push_front(T vall){
		if(back +1 >= array->get_sizse()){array->expand_by(5);}
		array->sift_by(1,sift_directson::rigth);
		array->set_value(front,vall);
		++back;
	}
	T pop_back(){
		if(back == 0){return {};}
		--back;
		return array->get_val(back);
	}
	T pop_front(){
		if(back == 0){return {};}
		--back;
		T temp = array->get_val(front);
		array->sift_by(1,sift_directson::left);
		return temp;
	}
	T peek_front(){
		if(back == 0){return {};}
		return array->get_val(front);
	}
	T peek_back(){
		if(back == 0){return {};}
		return array->get_val(back -1);
	}
	unsigned elements_in_queue(){
		return back;
	}
	
};
	
	
}}//namespace util::datastruct
#endif // DEQUE_H_INCLUDED
