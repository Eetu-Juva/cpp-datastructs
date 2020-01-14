#ifndef INCLUDE_LINKLIST_H
#define INCLUDE_LINKLIST_H


namespace util{
namespace datastruct{

//#define T int
template<typename T>
struct LinkdListLink{
	//LinkdListLink(T arg1,LinkdListLink* arg2){value = arg1 ; next_link = arg2;}
	T value;
	LinkdListLink<T>* next_link = nullptr;
};

template<typename T>
class LinkdList{
private:
	LinkdListLink<T>* base = nullptr;
	LinkdListLink<T>* curent = nullptr;
	unsigned* refcount;
public:
	LinkdList(T value){
		
		base = new LinkdListLink<T>;
		base->value = value;
		curent = base;
		refcount = new unsigned{1};
		
	}
	LinkdList(const LinkdList& other):base(other.base),curent(other.curent),refcount(other.refcount){
		(*refcount)++;
	}
	~LinkdList(){
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
	void add_element_to_list(T value){
		if(curent->next_link == nullptr){
			curent->next_link = new LinkdListLink<T>;
			curent->next_link->value = value;
			return;
		}
		auto temp = curent->next_link;
		curent->next_link = new LinkdListLink<T>;
		curent->next_link->value = value;
		curent->next_link->next_link = temp;
		return;
	}
	T get_vlue(){
		return curent->value;
	}
	void set_value(T value){
		curent->value = value;
	}
	bool delete_next_element(){
		if(curent->next_link == nullptr){;return false;}
		auto temp = curent->next_link->next_link;
		delete curent->next_link;
		curent->next_link = temp;
		return true;
	}
	bool mov_to_next_element(){
		if(curent->next_link == 0){return false;}
		curent = curent->next_link;
		return true;
	}
	void mov_to_first_element(){
		curent = base;
	}
// 	void remove_this_iterator(LinkdList** this_iterator){
// 		*this_iterator = nullptr;
// 		--refcount;
// 		if(refcount == 0){delete this; return;}
// 	}
};

}}//namespase util::datastruct






#endif
