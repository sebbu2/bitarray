#include "test_default_bit_values.hpp"

TYPE test_default_bit_values(ARG) {
	bitarray btest;
	for(unsigned int i=0;i<btest.getSize();++i) {
		//btest default value
		if(btest.getBit(i)!=false) {
			throw "bad default value";
		}
		//btest 0 value
		btest.resetBit(i);
		if(btest.getBit(i)!=false) {
			throw "bad 0 value";
		}
		//btest 1 value
		btest.setBit(i);
		if(btest.getBit(i)!=true) {
			throw "bad 1 value";
		}
		//btest forceBit 0 value
		btest.forceBit(i, 0);
		if(btest.getBit(i)!=0) {
			throw "bad forceBit 0 value";
		}
		//btest forceBit 1 value
		btest.forceBit(i, 1);
		if(btest.getBit(i)!=1) {
			throw "bad forceBit 1 value";
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
