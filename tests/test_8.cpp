#include "test_8.hpp"

TYPE test_8(ARG) {
	unsigned int res=0;
	if((res=next_multiple_8(0))!=0) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 0";
	}
	if((res=next_multiple_8(1))!=8) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 1";
	}
	if((res=next_multiple_8(2))!=8) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 2";
	}
	if((res=next_multiple_8(7))!=8) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 7";
	}
	if((res=next_multiple_8(8))!=8) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 8";
	}
	if((res=next_multiple_8(9))!=16) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 9";
	}
	if((res=next_multiple_8(16))!=16) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 16";
	}
	if((res=next_multiple_8(17))!=24) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 17";
	}
	if((res=next_multiple_8(24))!=24) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 24";
	}
	if((res=next_multiple_8(25))!=32) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 25";
	}
	if((res=next_multiple_8(32))!=32) {
		fprintf(stderr, "result is '%u'\n", res);
		throw "bad multiple 8 32";
	}
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
