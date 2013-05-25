#ifndef BITARRAY_HPP
#define BITARRAY_HPP

unsigned int next_multiple_8(unsigned int i);

unsigned char get_l(unsigned char i);
unsigned char get_r(unsigned char i);

unsigned char get_l(unsigned char i, unsigned char c);
unsigned char get_r(unsigned char i, unsigned char c);

class bitarray;

class bitarray_reference {
private:
	bitarray* ptr;
	unsigned int i;
public:
	bitarray_reference();
	bitarray_reference(bitarray* b, unsigned int idx);
	bitarray_reference& operator=(const bitarray_reference& b);
	bitarray_reference& operator=(bool b);
	operator bool() const;
};

class const_bitarray_reference {
private:
	const bitarray* ptr;
	unsigned int i;
public:
	const_bitarray_reference();
	const_bitarray_reference(const bitarray* b, unsigned int idx);
	operator bool() const;
};

class bitarray {
private:
	unsigned char* data;
	unsigned int size;
	int cmp(const bitarray &b) const;
public:
	bitarray();
	bitarray(unsigned int s);
	bitarray(const bitarray &b);
	~bitarray();
	bitarray& operator=(const bitarray &b);
	unsigned int getSize() const;
	void setSize(unsigned int s);
	bool getBit(unsigned int i) const;
	//bool operator[](unsigned int i) const;
	const const_bitarray_reference operator[](unsigned int i) const;
	bitarray_reference operator[](unsigned int i);
	void setBit(unsigned int i);
	void resetBit(unsigned int i);
	void flipBit(unsigned int i);
	void forceBit(unsigned int i, bool b);
	//comparaison
	bool operator< (const bitarray &b) const;
	bool operator<=(const bitarray &b) const;
	bool operator==(const bitarray &b) const;
	bool operator!=(const bitarray &b) const;
	bool operator> (const bitarray &b) const;
	bool operator>=(const bitarray &b) const;
	//other operators
	bitarray& operator<<=(unsigned int i);
	bitarray& operator>>=(unsigned int i);
	//non-modifiers
	bool peek_front() const;
	bool peek_back() const;
	//size modifiers
	bool pop_front();
	void push_front(bool b);
	bool pop_back();
	void push_back(bool b);
	//const-size modifiers
	void feed_front(bool b);
	void feed_back(bool b);
	void printRL(FILE* stream) const;
	void print(FILE* stream) const;
};

#endif
//
