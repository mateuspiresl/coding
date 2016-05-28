#include <iostream>

namespace mystd {

	template <class T>
	class vector {

	public:
		~vector();
		std::size_t size() const;

		void push_back(const T &a) {
			if (num_elements_ == allocated_size_)
				reallocate_vector();

			elemets_ptr_[num_elements_++] = a;
		}

		T& operator[](std::size_t i) {
			return elemets_ptr_[i];
		}

		const T& operator[](std::size_t i) const {
			return elemets_ptr_[i];
		}

	private:
		T *elemets_ptr_ = nullptr;
		std::size_t allocated_size_ = 0;
		std::size_t num_elements_ = 0;

		void reallocate_vector() {
			if ( ! num_elements_) {
				elemets_ptr_ = new T;
				allocated_size_++;
			}
			else {
				T* tmp = new T[allocated_size_ << 1];
				for (std::size_t i = 0; i < allocated_size_; i++)
					tmp[i] = elemets_ptr_[i];

				delete [] elemets_ptr_;
				elemets_ptr_ = tmp;
				allocated_size_ <<= 1;
			}
		}

	};

}