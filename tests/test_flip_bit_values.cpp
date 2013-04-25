#include "test_flip_bit_values.hpp"

TYPE test_flip_bit_values(ARG) {
	bitarray btest;
	for(unsigned int i=0;i<btest.getSize();++i) {
		//btest default value
		if(btest.getBit(i)!=false) {
			throw "bad default value";
		}
		//btest flip value
		btest.flipBit(i);
		if(btest.getBit(i)!=true) {
			throw "bad flip value";
		}
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
