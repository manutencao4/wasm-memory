#include "memory.h"

using namespace memory;

void init() {
	AddressStore::get()->init();
}

void *operator new(size_t len) {
	return AddressStore::get()->alloc(len);
}

void *operator new[](size_t len) {
	return AddressStore::get()->alloc(len);
}

void operator delete(void *ptr) {
	AddressStore::get()->dealloc(ptr);
}

void operator delete[](void *ptr) {
	AddressStore::get()->dealloc(ptr);
}

namespace memory {
	void *malloc(size_t len) {
		return AddressStore::get()->alloc(len);
	}

	void *realloc(void *src, size_t len) {
		return AddressStore::get()->realloc(src, len);
	}

	void free(void *ptr) {
		AddressStore::get()->dealloc(ptr);
	}

	void *memcpy(void *dest, void *src, size_t len) {
		uint8_t
			*_dest = (uint8_t*)dest,
			*_src = (uint8_t*)src;

		for (size_t i = 0; i < len; ++i) {
			_dest[i] = _src[i];
		}

		return dest;
	}

	void *memset(void *dest, uint8_t val, size_t len) {
		uint8_t *_dest = (uint8_t*)dest;

		for (size_t i = 0; i < len; ++i) {
			_dest[i] = val;
		}

		return dest;
	}
}