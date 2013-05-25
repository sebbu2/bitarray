#include <cstdio>
#include <cstdlib>
//#include <cmath>
#include <math.h>
#include <cstring>
#include <cassert>
#include <cerrno>
#include "bitarray.hpp"

inline unsigned int next_multiple_8(unsigned int i) {
	if(i>8) return 8+next_multiple_8(i-8);
	else if(i>0) {
		return 8;
	}
	else if(i==0) {
		return 0;
	}
	else throw "error";
}

inline unsigned char get_l(unsigned char i) {
	assert(i<=8);
	unsigned char res=0x00;
	if(i==0) return res;
	unsigned j=0;
	do {
		res|=(1<<(8-j));
	}
	while(++j<=i);
	return res;
}

inline unsigned char get_r(unsigned char i) {
	assert(i<=8);
	unsigned char res=0x00;
	if(i==0) return res;
	do {
		res|=(1<<(i-1));
	}
	while(--i);
	return res;
}

inline unsigned char get_l(unsigned char i, unsigned char c) {
	return (get_l(i)&c);
}

inline unsigned char get_r(unsigned char i, unsigned char c) {
	return (get_r(i)&c);
}

bitarray_reference::bitarray_reference() {
	ptr=NULL;
	i=0;
}

bitarray_reference::bitarray_reference(bitarray* b, unsigned int idx) {
	ptr=b;
	i=idx;
}

bitarray_reference& bitarray_reference::operator=(const bitarray_reference& b) {
	assert(ptr!=NULL);
	if(b.operator bool()) {
		ptr->setBit(i);
	}
	else {
		ptr->resetBit(i);
	}
	return (*this);
}

bitarray_reference& bitarray_reference::operator=(bool b) {
	assert(ptr!=NULL);
	if(b) {
		ptr->setBit(i);
	}
	else{
		ptr->resetBit(i);
	}
	return (*this);
}

bitarray_reference::operator bool() const {
	assert(ptr!=NULL);
	return ptr->getBit(i);
}

const_bitarray_reference::const_bitarray_reference() {
	ptr=NULL;
	i=0;
}

const_bitarray_reference::const_bitarray_reference(const bitarray* b, unsigned int idx) {
	ptr=b;
	i=idx;
}

const_bitarray_reference::operator bool() const {
	assert(ptr!=NULL);
	return ptr->getBit(i);
}

bitarray::bitarray() {
	data=(unsigned char*)calloc(1, sizeof(unsigned char));
	assert(data!=NULL);
	size=8;
	assert(size==8);
	memset(data, 0, 1);
}

bitarray::bitarray(unsigned int s) {
	unsigned int size2=next_multiple_8(s);
	assert(size2>=s);
	data=(unsigned char*)calloc(size2/8, sizeof(unsigned char));
	assert(data!=NULL);
	size=s;
	memset(data, 0, size2/8);
}

bitarray::bitarray(const bitarray &b) {
	data=NULL;
	size=0;
	operator=(b);
}

bitarray::~bitarray() {
	if(data!=NULL&&size>0) free(data);
}

bitarray& bitarray::operator=(const bitarray &b) {
	free(data);
	size=0;
	setSize(b.getSize());
	unsigned int size2=next_multiple_8(size);
	memcpy(data, b.data, size2/8);
	return (*this);
}

int bitarray::cmp(const bitarray &b) const {
	if(size<b.size) return -1;
	else if(size>b.size) return 1;
	for(unsigned int i=0;i<size;++i) {
		if(getBit(i)<b.getBit(i)) return -1;
		else if(getBit(i)>b.getBit(i)) return 1;
	}
	return 0;
}

//const char* getData() const;

unsigned int bitarray::getSize() const {
	return size;
}

void bitarray::setSize(unsigned int s) {
	if(size==s) {
		//do nothing
		return;
	}
	if(s==0) {
		if(data!=NULL) free(data);
		data=NULL;
		size=0;
		return;
	}
	unsigned int size_=next_multiple_8(size);//old
	unsigned int size2=next_multiple_8(s);//new
	if(size2==size_) {
		size=s;
		return;
	}
	if(size==0) {
		if(data!=NULL) free(data);
		data=(unsigned char*)calloc(size2/8, sizeof(unsigned char));
		memset(data, 0, size2/8);
		size=s;
		return;
	}
	errno=0;
	unsigned char* tmp=(unsigned char*)realloc(data, (size2/8)*sizeof(unsigned char));
	assert(errno==0);
	assert(tmp!=NULL);
	data=tmp;
	if(size2>size_) {
		memset(data+(size_/8), 0, (size2-size_)/8);
	}
	size=s;
}

bool bitarray::getBit(unsigned int i) const {
	assert(i<size);
	return (data[i/8]&(1<<(7-i%8)))>>(7-i%8);
	//return (data[i/8]&(1<<(i%8)))>>(i%8);
}

/*bool bitarray::operator[](unsigned int i) const {
	return getBit(i);
}//*/

const const_bitarray_reference bitarray::operator[](unsigned int i) const {
	assert(i<size);
	return const_bitarray_reference(this, i);
}

bitarray_reference bitarray::operator[](unsigned int i) {
	assert(i<size);
	return bitarray_reference(this, i);
}

void bitarray::setBit(unsigned int i) {
	assert(i<size);
	data[i/8]|=(1<<(7-i%8));
}

void bitarray::resetBit(unsigned int i) {
	assert(i<size);
	data[i/8]&=0xFF^(1<<(7-i%8));
}

void bitarray::flipBit(unsigned int i) {
	assert(i<size);
	/*printf(" data=%02x\n", data[i/8] );//debug printf's
	printf("~data=%02x\n", ~(data[i/8]) );
	printf(" mask=%02x\n", (1<<(i%8)) );
	printf(" ~d^m=%02x\n", ~(data[i/8])^(1<<(i%8)) );
	printf("~~d^m=%02x\n", ~(~(data[i/8])^(1<<(i%8))) );//*/
	data[i/8]=~(~(data[i/8])^(1<<(7-i%8)));
}

void bitarray::forceBit(unsigned int i, bool b) {
	/*if(getBit(i)!=b) {
		if(b) setBit(i);
		else resetBit(i);
	}//*/
	/*if(b==1) {
		assert( (get_l(i%8)|b<<(7-i%8)|get_r(7-i%8)) == 0xFF);
	}
	else {
		assert(b<<(7-i%8) == 0x00);
	}//*/
	data[i/8]&=(get_l(i%8)|b<<(7-i%8)|get_r(7-i%8));//put the 0 if b==0
	data[i/8]|=b<<(7-i%8);//put the 1 if b==1
}

bool bitarray::operator< (const bitarray &b) const {
	return cmp(b)<0;
}

bool bitarray::operator<=(const bitarray &b) const {
	return cmp(b)<=0;
}

bool bitarray::operator==(const bitarray &b) const {
	return cmp(b)==0;
}

bool bitarray::operator!=(const bitarray &b) const {
	return cmp(b)!=0;
}

bool bitarray::operator> (const bitarray &b) const {
	return cmp(b)>0;
}

bool bitarray::operator>=(const bitarray &b) const {
	return cmp(b)>=0;
}

/*bitarray& bitarray::operator<<=(unsigned int i) {
	if(i==0) return (*this);
	if(i>=size) {
		unsigned int size2=next_multiple_8(size);
		memset(data, 0, size2/8);
		return (*this);
	}
	for(unsigned int j=0;j<i;++j) {
		forceBit(j, 0);
	}
	for(unsigned int j=0;j<size-1-i;++j) {
		forceBit(j, getBit(j+i));
	}
	for(unsigned int j=0;j<i;++j) {
		forceBit(size-1-j, 0);
	}
	return (*this);
}//*/

/*bitarray& bitarray::operator>>=(unsigned int i) {
	if(i==0) return (*this);
	if(i>=size) {
		unsigned int size2=next_multiple_8(size);
		memset(data, 0, size2/8);
		return (*this);
	}
	for(unsigned int j=0;j<i;++j) {
		forceBit(size-1-j, 0);
	}
	for(unsigned int j=size-i;j>=i;--j) {
		forceBit(j, getBit(j-i));
	}
	for(unsigned int j=0;j<i;++j) {
		forceBit(j, 0);
	}
	return (*this);
}//*/

bitarray& bitarray::operator<<=(unsigned int i) {
	unsigned int size2=next_multiple_8(size)/8;
	data[0]&=~get_l(i);
	//
	unsigned int j=0;
	for(;j<size2-1;++j) {
		data[j]<<=i;
		data[j]|=get_l(i, data[j+1])>>(8-i);
	}
	data[j]<<=i;
	//
	data[size2-1]&=~get_r(i);
	return (*this);
}

bitarray& bitarray::operator>>=(unsigned int i) {
	unsigned int size2=next_multiple_8(size)/8;
	data[size2-1]&=~get_r(i);
	//
	unsigned int j=size2-1;
	for(;j>0;--j) {
		data[j]>>=i;
		data[j]|=get_r(i, data[j-1])<<(8-i);
	}
	data[0]>>=i;
	//
	data[0]&=~get_l(i);
	return (*this);
}//*/

bool bitarray::peek_front() const {
	return getBit(0);
}

bool bitarray::peek_back() const {
	return getBit(size-1);
}

bool bitarray::pop_front() {
	bool res=getBit(0);
	operator<<=(1);
	setSize(size-1);
	return res;
}

void bitarray::push_front(bool b) {
	setSize(size+1);
	operator>>=(1);
	forceBit(0, b);
}

bool bitarray::pop_back() {
	bool res=getBit(size-1);
	setSize(size-1);
	return res;
}

void bitarray::push_back(bool b) {
	setSize(size+1);
	forceBit(size-1, b);
}

void bitarray::feed_front(bool b) {
	/*pop_back();
	push_front(b);//*/
	operator>>=(1);
	forceBit(0, b);
}

void bitarray::feed_back(bool b) {
	/*pop_front();
	push_back(b);//*/
	operator<<=(1);
	forceBit(size-1, b);
}

void bitarray::printRL(FILE* stream) const {
	unsigned int tmp=0;
	unsigned int i=0;
	for(;i<size/8;++i) {
		tmp=data[i];
		for(unsigned int j=0;j<8;++j) {
			fprintf(stream, "%d", (tmp>>(j))%2);
		}
		fprintf(stream, "|");
	}
	if(i*8<size) {
		tmp=data[i];
		for(unsigned int j=0;j<(8-(size-i*8));++j) {
			fprintf(stream, "0");
		}
		for(unsigned int j=0;j<(size-i*8);++j) {
			fprintf(stream, "%d", (tmp>>(7-(size-i*8-1-j)))%2);
		}
		fprintf(stream, "|");
	}
	fprintf(stream, "\n");
}

void bitarray::print(FILE* stream) const {
	unsigned int tmp=0;
	unsigned int i=0;
	for(;i<(size/8);++i) {
		tmp=data[i];
		for(unsigned int j=0;j<8;++j) {
			fprintf(stream, "%d", (tmp>>(7-j))%2);
		}
		fprintf(stream, "|");
	}
	if(i*8<size) {
		tmp=data[i];
		for(unsigned int j=0;j<(size-i*8);++j) {
			fprintf(stream, "%d", (tmp>>(7-j))%2);
		}
		for(unsigned int j=0;j<(8-(size-i*8));++j) {
			fprintf(stream, "0");
		}
		fprintf(stream, "|");
	}
	fprintf(stream, "\n");
}
//
