#ifndef DUBLELINKLIST_H_INCLUDED
#define DUBLELINKLIST_H_INCLUDED
#include <iostream>

namespace util{
namespace datastruct{
//#define T int
template<typename T>
struct DubleLinkdListLink{
	T value;
	DubleLinkdListLink<T>* next_link = nullptr;
	DubleLinkdListLink<T>* prev_link = nullptr;
};

template<typename T>
class DubleLinkdList {
private:
	DubleLinkdListLink<T>* base = nullptr;
	DubleLinkdListLink<T>* curent = nullptr;
	unsigned* refcount;
public:
	DubleLinkdList(T value){
		
		base = new DubleLinkdListLink<T>;
		base->value = value;
		curent = base;
		refcount = new unsigned{1};
		
	}
	DubleLinkdList(const DubleLinkdList& other):base(other.base),curent(other.curent),refcount(other.refcount){
		(*refcount)++;
		//std::cout << *refcount <<"\n";
	}
	~DubleLinkdList(){
		--(*refcount);
		if(*refcount == 0){
			delete refcount;
			curent = base;
			base = nullptr;
			while(curent->next_link != nullptr){
				delete_next_element();
			}
			delete curent;
		}
	}
	void add_element_to_back(T value){
		if(curent->prev_link == nullptr){
			curent->prev_link = new DubleLinkdListLink<T>;
			curent->prev_link->next_link = curent;
			curent->prev_link->value = value;
			base = curent->prev_link;
			return;
		}
		curent->prev_link->next_link = new DubleLinkdListLink<T>;
		curent->prev_link->next_link->prev_link = curent->prev_link;
		curent->prev_link = curent->prev_link->next_link;
		curent->prev_link->next_link = curent;
		return;
	}
	void add_element_to_front(T value){
		if(curent->next_link == nullptr){
			curent->next_link = new DubleLinkdListLink<T>;
			curent->next_link->prev_link = curent;
			curent->next_link->value = value;
			return;
		}
		curent->next_link->prev_link = new DubleLinkdListLink<T>;
		curent->next_link->prev_link->next_link = curent->next_link;
		curent->next_link = curent->next_link->prev_link;
		curent->next_link->prev_link = curent;
		return;
	}
	bool mov_to_next_element(){
		if(curent->next_link == nullptr){return false;}
		curent = curent->next_link;
		return true;
	}
	bool mov_to_prev_element(){
		if(curent->prev_link == nullptr){return false;}
		curent = curent->prev_link;
		return true;
	}
	bool mov_to_base_element(){
		curent = base;
		return true;
	}
	bool delete_prev_element(){
		if(curent->prev_link == nullptr){return false;}
		if(curent->prev_link->prev_link == nullptr){
			delete curent->prev_link;
			curent->prev_link = nullptr;
			return true;
		}
		auto temp = curent->prev_link->prev_link;
		temp->next_link = curent;
		delete curent->prev_link;
		curent->prev_link = temp;
		return true;
	}
	bool delete_next_element(){
		if(curent->next_link == nullptr){return false;}
		if(curent->next_link->next_link == nullptr){
			delete curent->next_link;
			curent->next_link = nullptr;
			return true;
		}
		auto temp = curent->next_link->next_link;
		temp->prev_link = curent;
		delete curent->next_link;
		curent->next_link = temp;
		return true;
	}
	T get_value() const{
		return curent->value;
	}
	void set_value(T value){
		curent->value = value;
	}
	
	
};


}}//namespase util::datastruct


#endif // DUBLELINKLIST_H_INCLUDED
