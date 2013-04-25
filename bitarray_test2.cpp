#include <stdio.h>
#include "bitarray.hpp"

int main(void) {
	bitarray btest(32);
	//btest.printRL(stdout);
	btest.print(stdout);
	printf("---\n");
	
	/*printf("%s%s%s\n", "\x1b[1;33m", "test forceBit 1&0", "\x1b[0m");
	printf("---\n");
	for(unsigned int i=0;i<32;++i) {
		btest.forceBit(i,1);
		btest.print(stdout);
		btest.forceBit(i,0);
		btest.print(stdout);
		printf("---\n");
	}//*/
	
	bitarray btest2(32);
	for(unsigned int i=0;i<32;++i) {
		btest2.forceBit(i,1);
	}
	//btest2.printRL(stdout);
	btest2.print(stdout);
	printf("---\n");
	printf("%s%s%s\n", "\x1b[1;33m", "test <<=1 & >>= 1, >>=1 & <<=1", "\x1b[0m");
	printf("---\n");
	btest2<<=1;
	btest2.print(stdout);
	printf("---\n");
	btest2>>=1;
	btest2.print(stdout);
	printf("---\n");
	for(unsigned int i=0;i<32;++i) {
		btest2.forceBit(i,1);
	}
	btest2>>=1;
	btest2.print(stdout);
	printf("---\n");
	btest2<<=1;
	btest2.print(stdout);
	printf("---\n");
	
	bitarray btest3(12);
	btest3.forceBit(0,1);
	btest3.forceBit(3,1);
	//btest3.printRL(stdout);
	btest3.print(stdout);
	btest3.forceBit(0,0);
	btest3.forceBit(3,0);
	for(unsigned int i=0;i<btest3.getSize();++i) {
		btest3.forceBit(i,1);
		btest3.print(stdout);
	}
	//btest3.printRL(stdout);
	return 0;
}
//

