#include "test_push_pop.hpp"

TYPE test_push_pop_front_1_values(ARG) {
	bitarray btest(0);
	if(btest.getSize()!=0) {
		throw "bad size";
	}
	btest.push_front(1);
	if(btest.getSize()!=1) {
		throw "bad push_front 1";
	}
	if(btest.getBit(0)!=true) {
		throw "bad push_front 1 value";
	}
	bool b=btest.pop_front();
	if(btest.getSize()!=0) {
		throw "bad pop_front 1";
	}
	if(b!=1) {
		throw "bad pop_front 1 value";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}

TYPE test_push_pop_back_1_values(ARG) {
	bitarray btest(0);
	if(btest.getSize()!=0) {
		throw "bad size";
	}
	btest.push_back(1);
	if(btest.getSize()!=1) {
		throw "bad push_back 1";
	}
	if(btest.getBit(0)!=1) {
		throw "bad push_back 1 value";
	}
	bool b=btest.pop_back();
	if(btest.getSize()!=0) {
		throw "bad pop_back 1";
	}
	if(b!=1) {
		throw "bad pop_back 1 value";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}

TYPE test_push_pop_front_0_values(ARG) {
	bitarray btest(0);
	if(btest.getSize()!=0) {
		throw "bad size";
	}
	btest.push_front(0);
	if(btest.getSize()!=1) {
		throw "bad push_front 0";
	}
	if(btest.getBit(0)!=0) {
		throw "bad push_front 0 value";
	}
	bool b=btest.pop_front();
	if(btest.getSize()!=0) {
		throw "bad pop_front 1";
	}
	if(b!=0) {
		throw "bad pop_front 1 value";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}

TYPE test_push_pop_back_0_values(ARG) {
	bitarray btest(0);
	if(btest.getSize()!=0) {
		throw "bad size";
	}
	btest.push_back(0);
	if(btest.getSize()!=1) {
		throw "bad push_back 0";
	}
	if(btest.getBit(0)!=0) {
		throw "bad push_back 0 value";
	}
	bool b=btest.pop_back();
	if(btest.getSize()!=0) {
		throw "bad pop_back 1";
	}
	if(b!=0) {
		throw "bad pop_back 1 value";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
