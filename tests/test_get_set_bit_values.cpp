#include "test_get_set_bit_values.hpp"

TYPE test_get_set_bit_values(ARG) {
	bitarray btest(8);
	//btest bit 0
	if(btest.getBit(0)!=false) {
		throw "bad default (false) value";
	}
	if(btest[0].operator bool()!=false) {
		throw "bad bool() (false) value";
	}
	if(btest[0]!=false) {
		throw "bad implicit conversion (false) value";
	}
	//btest bit 1
	btest.setBit(1);
	if(btest.getBit(1)!=true) {
		throw "bad set (true) value";
	}
	if(btest[1].operator bool()!=true) {
		throw "bad bool() (true) value";
	}
	if(btest[1]!=true) {
		throw "bad implicit conversion (true) value";
	}
	//btest bit 3
	btest.setBit(3);
	if(btest.getBit(3)!=true) {
		throw "bad set (true) value";
	}
	//btest bit 5
	btest[5]=true;
	if(btest.getBit(5)!=true) {
		throw "bad operator= (true) value";
	}
	//btest bit 7
	btest[7]=btest[1];
	if(btest.getBit(7)!=true) {
		throw "bad operator= (operator[]) value";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
