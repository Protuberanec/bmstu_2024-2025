#ifndef _uniquq_ptr_h_
#define _uniquq_ptr_h_


template<class T>
class UniquePtr {
	private :
		T* ptr_ { nullptr};

	public :
		UniquePtr() : ptr_(nullptr) {}
		UniquePtr(T* ptr) : ptr_(ptr) {}
		~UniquePtr() { delete ptr_; }

		T* get() const { return ptr_; }
		void reset(T* new_ptr) {
			if (ptr_) {
				delete ptr_;
				ptr_ = nullptr;
			}
			ptr_ = new_ptr;
		}

		T* operator->() const { return ptr_; }


};


#endif
