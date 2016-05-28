#include <iostream>
#include <iostream>

namespace mystd {

	vector::~vector() {
		if (elemets_ptr_) {
			delete [] elemets_ptr_;
			elemets_ptr_ = nullptr;
		}
	}

	std::size_t vector::size() const {
		return num_elements_;
	}

}