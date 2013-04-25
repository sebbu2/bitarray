#include "test_sizes.hpp"

TYPE test_sizes(ARG) {
	bitarray btest(0);
	if(btest.getSize()!=0) {
		throw "bad size 0";
	}
	btest.setSize(1);
	if(btest.getSize()!=1) {
		throw "bad size 1";
	}
	btest.setSize(8);
	if(btest.getSize()!=8) {
		throw "bad size 8";
	}
	btest.setSize(9);
	if(btest.getSize()!=9) {
		throw "bad size 9";
	}
	btest.setSize(9);
	if(btest.getSize()!=9) {
		throw "bad size 9 (bis)";
	}
	btest.setSize(8);
	if(btest.getSize()!=8) {
		throw "bad size 8 (bis)";
	}
	btest.setSize(1);
	if(btest.getSize()!=1) {
		throw "bad size 1 (bis)";
	}
	btest.setSize(0);
	if(btest.getSize()!=0) {
		throw "bad size 0 (bis)";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
