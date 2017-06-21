#include "Address.h"

#ifdef DEBUG
void *WASM_ADDRESS_STORE_PTR = malloc(100000);
#endif

namespace memory{
	void Address::clear(){
		_ptr = WASM_NULL_PTR;
		_len = 0;
	}

	size_t Address::getSpaceTo(Address *addr){
		void
			*start = (void*)((size_t)_ptr + _len),
			*end = addr->_ptr;

		if (start > end){
			return 0;
		}

		return (size_t)end - (size_t)start;
	}

	Address &Address::operator =(Address const &addr) {
		_ptr = addr._ptr;
		_len = addr._len;

		return *this;
	}

#ifdef DEBUG
	std::ostream &operator<<(std::ostream& stream, const Address &addr){
		return stream << std::hex << std::setw(sizeof(size_t) * 2) << std::setfill('0') << addr._ptr << ' ' << std::setw(sizeof(size_t) * 2) << std::setfill('0') << addr._len;
	}
#endif
}