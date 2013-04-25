#include "test_shifts32.hpp"

TYPE test_shifts32(ARG) {
	bitarray btest(32);
	for(unsigned int i=0;i<32;++i) {
		btest.setBit(i);
	}
	unsigned int count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=32) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad setBit/getBit somewhere";
	}
	btest<<=1;
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=31) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad <<=1 somewhere";
	}
	//reset
	for(unsigned int i=0;i<32;++i) {
		btest.setBit(i);
	}
	btest>>=1;
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=31) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad >>=1 somewhere";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
