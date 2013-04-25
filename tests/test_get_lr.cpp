#include "test_get_lr.hpp"

TYPE test_get_lr(ARG) {
	if(get_l(0)!=0x00) {
		throw "bad get_l 0";
	}
	if(get_l(1)!=0x80) {
		fprintf(stderr, "[INFO] get_l 1 = %02X\n", get_l(1) );
		throw "bad get_l 1";
	}
	if(get_l(2)!=0xC0) {
		fprintf(stderr, "[INFO] get_l 2 = %02X\n", get_l(1) );
		throw "bad get_l 2";
	}
	if(get_l(3)!=0xE0) throw "bad get_l 3";
	if(get_l(4)!=0xF0) throw "bad get_l 4";
	if(get_l(5)!=0xF8) throw "bad get_l 5";
	if(get_l(6)!=0xFC) throw "bad get_l 6";
	if(get_l(7)!=0xFE) throw "bad get_l 7";
	if(get_l(8)!=0xFF) throw "bad get_l 8";
	if(get_r(0)!=0x00) throw "bad get_r 0";
	if(get_r(1)!=0x01) throw "bad get_r 1";
	if(get_r(2)!=0x03) throw "bad get_r 2";
	if(get_r(3)!=0x07) throw "bad get_r 3";
	if(get_r(4)!=0x0F) throw "bad get_r 4";
	if(get_r(5)!=0x1F) throw "bad get_r 5";
	if(get_r(6)!=0x3F) throw "bad get_r 6";
	if(get_r(7)!=0x7F) throw "bad get_r 7";
	if(get_r(8)!=0xFF) throw "bad get_r 8";
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
