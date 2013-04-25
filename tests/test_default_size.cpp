#include "test_default_size.hpp"

TYPE test_default_size(ARG) {
	bitarray btest;
	if(btest.getSize()!=8) {
		throw "bad size";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
