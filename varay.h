#ifndef VARAY_H_INCLUDED
#define VARAY_H_INCLUDED


//#define T int
//#define nullval 0
namespace util{
namespace datastruct {
	enum sift_directson{rigth,left};
template<typename T,T nullval>	
class Varray{
private:
	T* arr;
	unsigned count = 0;
	
public:
	Varray(unsigned sizse){
		count = sizse;
		arr = new T[count];
	}
	~Varray(){
	delete arr;
	}
	T get_val(unsigned index){
		if(index > count){return nullval;}
		return arr[index];
	}
	unsigned get_sizse(){return count;}
	bool set_value(unsigned index,T vallue){
		if(index > count){return false;}
		arr[index] = vallue;
		return true;
	}
	void expand_by(unsigned amount){
		T* temp = new T[amount +count];
		for(unsigned i=0;i<count;++i){
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		count = count + amount;
	}
	void sift_by(unsigned amount,sift_directson direction){
		if(direction == sift_directson::left){
			for(unsigned i=0;i<count;++i){
				if(i+amount >= count){arr[i]=nullval; continue;}
				arr[i] = arr[i + amount];
			}
			return;
		}
		else if(direction == sift_directson::rigth){
			for(unsigned i = count - 1; i < count ; --i){
				if((int)i - (int)amount <= 0){arr[i]=nullval; continue;}
				arr[i] = arr[i - amount];
			}
			return;
		}
	}
	
	
	
};
	
	
}}//namespace util::datastruct

#endif // VARAY_H_INCLUDED












