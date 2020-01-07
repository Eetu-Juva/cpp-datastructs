#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <cstddef>

template<typename T>
class LinkdListLnk{
    private:
        T* point = nullptr;
        LinkdListLnk<T>* linknext= nullptr;

    public:
    LinkdListLnk(T initval){
        point = new T{initval};
		this->LinkdListLnk = nullptr;
    }
    
	LinkdListLnk(T initval , LinkdListLnk<T>* next){
        point = new T{initval};
		this->LinkdListLnk = next;
    }
    
    ~LinkdListLnk(){
        delete point;
    }
    
    const T& getval() const{
        return *point;
    }
    
    const LinkdListLnk* getlink() const{
        return this->linknext;
    }

    bool set_next_link(LinkdListLnk* next){
        if (linknext != nullptr){
           linknext = next;
           return true; 
        }
        else {
			next->setnext(this->linknext);
			linknext = next;
			return true;
		}
		return false;
        
    }
    bool remove_next_link(){
		if(this->LinkdListLnk != nullptr){
			LinkdListLnk<T> temp = this->linknext->getlink();
			this->linknext->~LinkdListLnk();
			this->linknext = temp;
		}
		return false;
	}

    void setval (T val){
        *point = val;
    }

};

template<typename T>
class LinkdList{
    private:
		LinkdListLnk<T>* first;
		LinkdListLnk<T>* curent;
		std::size_t ref_count=0;
      
   
    public:
		LinkdList(T val){
			first = LinkdListLnk<T>(val);
		}
		void insert_value_to_list(T val){
			curent = LinkdListLnk<T>(val, curent->getlink);
		}
		
		
		
		~LinkdList(){}
		
		

};


#endif // LINKLIST_H_INCLUDED
