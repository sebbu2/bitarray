#include "test_shifts.hpp"

TYPE test_shifts(ARG) {
	bitarray btest(32);
	if(btest.getSize()!=32) {
		throw "bad size 32";
	}
	unsigned int count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=0) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad bitarray init";
	}
	//btest.setBit(2);btest.setBit(3);btest.setBit(5);
	//btest.setBit(7);btest.setBit(11);btest.setBit(13);
	//btest.setBit(17);btest.setBit(19);btest.setBit(23);
	//btest.setBit(29);
	btest.forceBit(2, 1);btest.forceBit(3, 1);btest.forceBit(5, 1);
	btest.forceBit(7, 1);btest.forceBit(11, 1);btest.forceBit(13, 1);
	btest.forceBit(17, 1);btest.forceBit(19, 1);btest.forceBit(23, 1);
	btest.forceBit(29, 1);
	if(btest.getSize()!=32) {
		throw "bad setBit somewhere";
	}
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=10) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad setBit after counts";
	}
	{
		if( btest.getBit(0)!=0 || btest.getBit(1)!=0 || btest.getBit(4)!=0 ||
			btest.getBit(6)!=0 || btest.getBit(8)!=0 || btest.getBit(9)!= 0 ||
			btest.getBit(10)!=0 || btest.getBit(12)!=0 || btest.getBit(14)!=0 ||
			btest.getBit(15)!=0 || btest.getBit(16)!=0 || btest.getBit(18)!=0 ||
			btest.getBit(20)!=0 || btest.getBit(21)!=0 || btest.getBit(22)!=0 ||
			btest.getBit(24)!=0 || btest.getBit(25)!=0 || btest.getBit(26)!=0 ||
			btest.getBit(27)!=0 || btest.getBit(28)!=0 || btest.getBit(30)!=0 ||
			btest.getBit(31)!=0) {
				throw "wrong bits were set to 1";
		}
		if( btest.getBit(2)!=1 || btest.getBit(3)!=1 || btest.getBit(5)!=1 ||
			btest.getBit(7)!=1 || btest.getBit(11)!=1 || btest.getBit(13)!=1 ||
			btest.getBit(17)!=1 || btest.getBit(19)!=1 || btest.getBit(23)!=1 ||
			btest.getBit(29)!=1) {
				throw "good bits weren't set to 1";
		}
	}
	btest.print(stdout);
	btest.forceBit(0, 0);btest.forceBit(1, 0);btest.forceBit(4, 0);
	btest.forceBit(6, 0);btest.forceBit(8, 0);btest.forceBit(9, 0);
	btest.forceBit(10, 0);btest.forceBit(12, 0);btest.forceBit(14, 0);
	btest.forceBit(15, 0);btest.forceBit(16, 0);btest.forceBit(18, 0);
	btest.forceBit(20, 0);btest.forceBit(21, 0);btest.forceBit(22, 0);
	btest.forceBit(24, 0);btest.forceBit(25, 0);btest.forceBit(26, 0);
	btest.forceBit(27, 0);btest.forceBit(28, 0);btest.forceBit(30, 0);
	btest.forceBit(31, 0);
	{
		if( btest.getBit(0)!=0 || btest.getBit(1)!=0 || btest.getBit(4)!=0 ||
			btest.getBit(6)!=0 || btest.getBit(8)!=0 || btest.getBit(9)!= 0 ||
			btest.getBit(10)!=0 || btest.getBit(12)!=0 || btest.getBit(14)!=0 ||
			btest.getBit(15)!=0 || btest.getBit(16)!=0 || btest.getBit(18)!=0 ||
			btest.getBit(20)!=0 || btest.getBit(21)!=0 || btest.getBit(22)!=0 ||
			btest.getBit(24)!=0 || btest.getBit(25)!=0 || btest.getBit(26)!=0 ||
			btest.getBit(27)!=0 || btest.getBit(28)!=0 || btest.getBit(30)!=0 ||
			btest.getBit(31)!=0) {
				throw "good bits weren't set to 0";
		}
		if( btest.getBit(2)!=1 || btest.getBit(3)!=1 || btest.getBit(5)!=1 ||
			btest.getBit(7)!=1 || btest.getBit(11)!=1 || btest.getBit(13)!=1 ||
			btest.getBit(17)!=1 || btest.getBit(19)!=1 || btest.getBit(23)!=1 ||
			btest.getBit(29)!=1) {
				throw "bad bits were set to 0";
		}
	}
	btest.print(stdout);
	btest<<=2;
	if(btest.getSize()!=32) {
		throw "bad <<= somewhere";
	}
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=10) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad value after <<=";
	}
	btest.print(stdout);
	btest>>=2;
	if(btest.getSize()!=32) {
		throw "bad >>= somewhere";
	}
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=10) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad value after >>=";
	}
	btest.print(stdout);
	btest>>=2;
	if(btest.getSize()!=32) {
		throw "bad >>= somewhere 2";
	}
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=10) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad value after >>= 2";
	}
	btest.print(stdout);
	btest<<=2;
	if(btest.getSize()!=32) {
		throw "bad <<= somewhere 2";
	}
	count=0;
	for(unsigned int i=0;i<btest.getSize();++i) {
		if(btest.getBit(i)) ++count;
	}
	if(count!=10) {
		fprintf(stderr, "count=%u\n", count);
		btest.print(stderr);
		throw "bad value after <<= 2";
	}
	btest.print(stdout);
#if RETURN==0
#elif RETURN==1
	return NULL;
#else
#error "bad RETURN value"
#endif
}
//
