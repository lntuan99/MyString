#ifndef _MY_MyString_H_
#define _MY_MyString_H_

#include <cstdlib>
#include <fstream>
#include <iterator>
#include <limits>

using namespace std;

class MyString
{
private:
	static const size_t BLOCKSIZE = 16;
	static const size_t MAXSIZE = INT32_MAX;

	char* _string;
	size_t _length;
	size_t _capacity;

	void updateCapacity();

public:
	static const size_t npos = -1;
	//-------------------CLASS ITERATOR-------------------//
	class Iterator : public iterator<random_access_iterator_tag, char> {
	private:
		char* _p;
	public:
		Iterator();
		Iterator(char*);
		Iterator(const Iterator& otherIterator);
		Iterator& operator= (const Iterator& otherIterator);

		Iterator operator+(size_t n);
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator+=(size_t n);

		Iterator operator-(size_t n);
		Iterator& operator--();
		Iterator operator--(int);
		Iterator& operator-=(size_t n);

		bool operator< (const Iterator& otherIterator) const;
		bool operator> (const Iterator& otherIterator) const;
		bool operator<= (const Iterator& otherIterator) const;
		bool operator>= (const Iterator& otherIterator) const;
		bool operator== (const Iterator& otherIterator) const;
		bool operator!= (const Iterator& otherIterator) const;
		char& operator* ();

	};

	class Const_Iterator : public iterator<random_access_iterator_tag, const char> {
	private:
		const char* _p;
	public:
		Const_Iterator();
		Const_Iterator(const char* s);
		Const_Iterator(const Const_Iterator& otherConstIterator);
		Const_Iterator& operator= (const Const_Iterator& otherConstIterator);

		Const_Iterator operator+(size_t n);
		Const_Iterator& operator++();
		Const_Iterator operator++(int);
		Const_Iterator& operator+=(size_t n);

		Const_Iterator operator-(size_t n);
		Const_Iterator& operator--();
		Const_Iterator operator--(int);
		Const_Iterator& operator-=(size_t n);

		bool operator< (const Const_Iterator& otherConstIterator) const;
		bool operator> (const Const_Iterator& otherConstIterator) const;
		bool operator<= (const Const_Iterator& otherConstIterator) const;
		bool operator>= (const Const_Iterator& otherConstIterator) const;
		bool operator== (const Const_Iterator& otherConstIterator) const;
		bool operator!= (const Const_Iterator& otherConstIterator) const;
		const char operator* () const;

	};

	class Reverse_Iterator : public iterator<random_access_iterator_tag, char> {
	private:
		char* _p;
	public:
		Reverse_Iterator();
		Reverse_Iterator(char* s);
		Reverse_Iterator(const Reverse_Iterator& otherReverseIterator);
		Reverse_Iterator& operator= (const Reverse_Iterator& otherReverseIterator);

		Reverse_Iterator operator+(size_t n);
		Reverse_Iterator& operator++();
		Reverse_Iterator operator++(int);
		Reverse_Iterator& operator+=(size_t n);

		Reverse_Iterator operator-(size_t n);
		Reverse_Iterator& operator--();
		Reverse_Iterator operator--(int);
		Reverse_Iterator& operator-=(size_t n);

		bool operator< (const Reverse_Iterator& otherReverseIterator) const;
		bool operator> (const Reverse_Iterator& otherReverseIterator) const;
		bool operator<= (const Reverse_Iterator& otherReverseIterator) const;
		bool operator>= (const Reverse_Iterator& otherReverseIterator) const;
		bool operator== (const Reverse_Iterator& otherReverseIterator) const;
		bool operator!= (const Reverse_Iterator& otherReverseIterator) const;
		char& operator* ();

	};

	class Const_Reverse_Iterator : public iterator<random_access_iterator_tag, char> {
	private:
		const char* _p;
	public:
		Const_Reverse_Iterator();
		Const_Reverse_Iterator(char* s);
		Const_Reverse_Iterator(const Const_Reverse_Iterator& otherConstReverseIterator);
		Const_Reverse_Iterator& operator= (const Const_Reverse_Iterator& otherConstReverseIterator);

		Const_Reverse_Iterator operator+(size_t n);
		Const_Reverse_Iterator& operator++();
		Const_Reverse_Iterator operator++(int);
		Const_Reverse_Iterator& operator+=(size_t n);

		Const_Reverse_Iterator operator-(size_t n);
		Const_Reverse_Iterator& operator--();
		Const_Reverse_Iterator operator--(int);
		Const_Reverse_Iterator& operator-=(size_t n);

		bool operator< (const Const_Reverse_Iterator& otherConstReverseIterator) const;
		bool operator> (const Const_Reverse_Iterator& otherConstReverseIterator) const;
		bool operator<= (const Const_Reverse_Iterator& otherConstReverseIterator) const;
		bool operator>= (const Const_Reverse_Iterator& otherConstReverseIterator) const;
		bool operator== (const Const_Reverse_Iterator& otherConstReverseIterator) const;
		bool operator!= (const Const_Reverse_Iterator& otherConstReverseIterator) const;
		const char operator* () const;
	};

	//--------------------CONSTRUCTOR---------------------//
	//default (1)
	MyString();

	//copy (2)	
	MyString(const MyString& otherMyString);

	//subMyString(3)
	MyString(const MyString& otherMyString, size_t pos, size_t npos);

	//from c - MyString(4)
	MyString(const char* s);

	//from sequence (5)
	MyString(const char* s, size_t n);

	//fill(6)
	MyString(size_t n, char c);

	//range (7)	
	MyString(Iterator first, Iterator last);
	MyString(Reverse_Iterator first, Reverse_Iterator last);
	MyString(Const_Iterator first, Const_Iterator last);
	MyString(Const_Reverse_Iterator first, Const_Reverse_Iterator last);


	//initializer list (8)	
	MyString(initializer_list<char> il);

	//move (9)
	MyString(MyString&& otherMyString) noexcept;

	//--------------------DESTRUCTOR----------------------//
	~MyString();

	//--------------------OPERATOR =----------------------//
	//MyString (1)
	MyString& operator= (const MyString& otherMyString);

	//c-MyString (2)
	MyString& operator= (const char* s);

	//character (3)
	MyString& operator= (char c);

	//initializer list (4)
	MyString& operator= (initializer_list<char> il);

	//move (5)
	MyString& operator= (MyString&& otherMyString) noexcept;

	//--------------------ITERATORS-----------------------//
	Iterator begin() noexcept;
	Const_Iterator begin() const noexcept;

	Iterator end() noexcept;
	Const_Iterator end() const noexcept;

	Const_Iterator cbegin() const noexcept;
	Const_Iterator cend() const noexcept;

	Reverse_Iterator rbegin() noexcept;
	Const_Reverse_Iterator rbegin() const noexcept;

	Reverse_Iterator rend() noexcept;
	Const_Reverse_Iterator rend() const noexcept;

	Const_Reverse_Iterator crbegin() const noexcept;
	Const_Reverse_Iterator crend() const noexcept;

	//--------------------CAPACITY------------------------//
	size_t length() const noexcept;
	size_t size() const noexcept;
	size_t max_size() const noexcept;
	size_t capacity() const noexcept;
	void resize(size_t n);
	void resize(size_t n, char c);
	void reserve(size_t n);
	void clear() noexcept;
	bool empty() const noexcept;
	void shrink_to_fit();

	//--------------------ELEMENT ACCESS--------------------//
	char& operator[](size_t index);
	const char& operator[] (size_t index) const;
	char& at(size_t index);
	const char& at(size_t index) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;

	//----------------------MODIFIERS----------------------//
	//---------------------OPERATOR +=---------------------//
	//MyString (1)
	MyString& operator+= (const MyString& otherMyString);

	//c-MyString (2)
	MyString& operator+= (const char* s);

	//character (3)
	MyString& operator+= (char c);

	//initializer list (4)
	MyString& operator+= (initializer_list<char> il);

	//------------------------APPEND-----------------------//
	//MyString (1)
	MyString& append(const MyString& otherMyString);

	//subMyString (2)
	MyString& append(const MyString& otherMyString, size_t subpos);
	MyString& append(const MyString& otherMyString, size_t subpos, size_t sublen);

	//c-MyString (3)
	MyString& append(const char* s);

	//buffer (4)
	MyString& append(const char* s, size_t n);

	//fill (5)
	MyString& append(size_t n, char c);

	//initializer list (6)
	MyString& append(initializer_list<char> il);

	//range (7)
	MyString& append(Iterator first, Iterator last);
	MyString& append(Reverse_Iterator first, Reverse_Iterator last);
	MyString& append(Const_Iterator first, Const_Iterator last);
	MyString& append(Const_Reverse_Iterator first, Const_Reverse_Iterator last);

	//-----------------------PUSH_BACK----------------------//
	void push_back(char);

	//------------------------ASSIGN------------------------//
	//MyString (1)
	MyString& assign(const MyString& otherMyString);

	//subMyString (2)
	MyString& assign(const MyString&, size_t subpos);
	MyString& assign(const MyString&, size_t subpos, size_t sublen);

	//c-MyString (3)
	MyString& assign(const char* s);

	//buffer (4)
	MyString& assign(const char* s, size_t n);

	//fill (5)
	MyString& assign(size_t n, char c);

	//initializer list (6)
	MyString& assign(initializer_list<char> il);

	//range (7)
	MyString& assign(Iterator first, Iterator last);
	MyString& assign(Reverse_Iterator first, Reverse_Iterator last);
	MyString& assign(Const_Iterator first, Const_Iterator last);
	MyString& assign(Const_Reverse_Iterator first, Const_Reverse_Iterator last);

	//move (8)
	MyString& assign(MyString&& str) noexcept;

	//------------------------INSERT-------------------------//
	//MyString (1)
	MyString& insert(size_t pos, const MyString& otherMyString);

	//subMyString (2)
	MyString& insert(size_t pos, const MyString& otherMyString, size_t subpos);
	MyString& insert(size_t pos, const MyString& otherMyString, size_t subpos, size_t sublen);

	//c-MyString (3)
	MyString& insert(size_t pos, const char* s);

	//buffer (4)
	MyString& insert(size_t pos, const char* s, size_t n);

	//fill (5)
	MyString& insert(size_t pos, size_t n, char c);
	Iterator insert(Const_Iterator p, size_t n, char c);
	Iterator insert(Iterator p, size_t n, char c);

	//single character (6)
	Iterator insert(Const_Iterator p, char c);
	Iterator insert(Iterator p, char c);

	//range (7)
	Iterator insert(Iterator p, Iterator first, Iterator last);
	Iterator insert(Iterator p, Const_Iterator first, Const_Iterator last);
	Iterator insert(Iterator p, Reverse_Iterator first, Reverse_Iterator last);
	Iterator insert(Iterator p, Const_Reverse_Iterator first, Const_Reverse_Iterator last);

	//initializer list (8)
	MyString& insert(Const_Iterator p, initializer_list<char> il);
	MyString& insert(Iterator p, initializer_list<char> il);

	//-------------------------ERASE--------------------------//
	//sequence (1)
	MyString& erase(size_t pos);
	MyString& erase(size_t pos, size_t npos);

	//character
	Iterator erase(Const_Iterator p);
	Iterator erase(Iterator p);

	//range (3)
	Iterator erase(Const_Iterator first, Const_Iterator last);
	Iterator erase(Iterator first, Iterator last);

	//------------------------REPLACE-------------------------//
	//MyString (1)
	MyString& replace(size_t, size_t, const MyString&);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, const MyString& otherMyString);
	MyString& replace(Iterator i1, Iterator i2, const MyString& otherMyString);

	//subMyString (2)
	MyString& replace(size_t pos, size_t len, const MyString& otherMyString, size_t subpos);
	MyString& replace(size_t pos, size_t len, const MyString& otherMyString, size_t subpos, size_t sublen);

	//c-MyString (3)
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, const char* s);
	MyString& replace(Iterator i1, Iterator i2, const char* s);

	//buffer (4)
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, const char* s, size_t n);
	MyString& replace(Iterator i1, Iterator i2, const char* s, size_t n);

	//fill (5)
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, size_t n, char c);
	MyString& replace(Iterator i1, Iterator i2, size_t n, char c);

	//range (6)
	MyString& replace(Const_Iterator i1, Const_Iterator i2, Iterator first, Iterator last);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, Const_Iterator first, Const_Iterator last);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, Reverse_Iterator first, Reverse_Iterator last);
	MyString& replace(Const_Iterator i1, Const_Iterator i2, Const_Reverse_Iterator first, Const_Reverse_Iterator last);
	MyString& replace(Iterator i1, Iterator i2, Iterator first, Iterator last);
	MyString& replace(Iterator i1, Iterator i2, Const_Iterator first, Const_Iterator last);
	MyString& replace(Iterator i1, Iterator i2, Reverse_Iterator first, Reverse_Iterator last);
	MyString& replace(Iterator i1, Iterator i2, Const_Reverse_Iterator first, Const_Reverse_Iterator last);

	//initializer list (7)
	MyString& replace(Const_Iterator i1, Const_Iterator i2, initializer_list<char> il);
	MyString& replace(Iterator i1, Iterator i2, initializer_list<char> il);

	//-----------------------------SWAP-------------------------------//
	void swap(MyString& str);

	//---------------------------POP BACK-----------------------------//
	void pop_back();

	//----------------------MyString OPERATIONS--------------------------//
	const char* c_str() const noexcept;
	const char* data() const noexcept;
	allocator<char> get_allocator() const noexcept;
	size_t copy(char* s, size_t len, size_t pos) const;
	size_t copy(char* s, size_t len) const;

	//-----------------------------FIND--------------------------------//
	//MyString (1)
	size_t find(const MyString& otherMyString) const noexcept;
	size_t find(const MyString& otherMyString, size_t pos) const noexcept;

	//c-MyString (2);
	size_t find(const char* s) const;
	size_t find(const char* s, size_t pos) const;

	//buffer (3)
	size_t find(const char* s, size_t pos, size_t n) const;

	//character
	size_t find(char c) const noexcept;
	size_t find(char c, size_t pos) const noexcept;

	//-----------------------------RFIND-------------------------------//
	//MyString (1)
	size_t rfind(const MyString& otherMyString) const noexcept;
	size_t rfind(const MyString& otherMyString, size_t pos) const noexcept;

	//c-MyString (2)
	size_t rfind(const char* s) const;
	size_t rfind(const char* s, size_t pos) const;

	//buffer (3)
	size_t rfind(const char* s, size_t pos, size_t n) const;

	//character (4)
	size_t rfind(char c) const noexcept;
	size_t rfind(char c, size_t pos) const noexcept;

	//---------------------------FIND FIRST OF----------------------------//
	//MyString (1)
	size_t find_first_of(const MyString& otherMyString) const noexcept;
	size_t find_first_of(const MyString& otherMyString, size_t pos) const noexcept;

	//c-MyString (2)
	size_t find_first_of(const char* s) const;
	size_t find_first_of(const char* s, size_t pos) const;

	//buffer (3)
	size_t find_first_of(const char* s, size_t pos, size_t n) const;

	//character (4)
	size_t find_first_of(char c) const noexcept;
	size_t find_first_of(char c, size_t pos) const noexcept;


	//---------------------------FIND LAST OF-----------------------------//
	//MyString (1)
	size_t find_last_of(const MyString& otherMyString) const noexcept;
	size_t find_last_of(const MyString& otherMyString, size_t pos) const noexcept;

	//c-MyString (2)
	size_t find_last_of(const char* s) const;
	size_t find_last_of(const char* s, size_t pos) const;

	//bufffer (3)
	size_t find_last_of(const char* s, size_t pos, size_t n) const;

	//character (4)
	size_t find_last_of(char c) const noexcept;
	size_t find_last_of(char c, size_t pos) const noexcept;

	//-------------------------FIND FIRST NOT OF---------------------------//
	//MyString (1)
	size_t find_first_not_of(const MyString& otherMyString) const noexcept;
	size_t find_first_not_of(const MyString& otherMyString, size_t pos) const noexcept;

	//c-MyString (2)
	size_t find_first_not_of(const char* s) const;
	size_t find_first_not_of(const char* s, size_t pos) const;

	//buffer (3)
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;

	//character (4)
	size_t find_first_not_of(char c) const noexcept;
	size_t find_first_not_of(char c, size_t pos) const noexcept;
	
	//---------------------------FIND LAST NOT OF----------------------------//
	//MyString (1)
	size_t find_last_not_of(const MyString& otherMyString) const noexcept;
	size_t find_last_not_of(const MyString& otherMyString, size_t pos) const noexcept;

	//c-MyString (2)
	size_t find_last_not_of(const char* s) const;
	size_t find_last_not_of(const char* s, size_t pos) const;

	//buffer (3)
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;

	//character (4)
	size_t find_last_not_of(char c) const noexcept;
	size_t find_last_not_of(char c, size_t pos) const noexcept;

	//----------------------------SUBMyString---------------------------------//
	MyString substr(size_t pos) const;
	MyString substr(size_t pos, size_t len) const;

	//----------------------------COMPARE-----------------------------------//
	//MyString (1)
	int compare(const MyString& otherMyString) const noexcept;
	int compare(size_t pos, size_t len, const MyString& otherMyString) const;

	//sub MyString (2)
	int compare(size_t pos, size_t len, const MyString& otherMyString, size_t subpos) const;
	int compare(size_t pos, size_t len, const MyString& otherMyString, size_t subpos, size_t sublen) const;

	//c-MyString (3)
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;

	//buffer (4)
	int compare(size_t pos, size_t len, const char* s, size_t n) const;


	//------------------NON MEMBER FUNCTION OVERLOADS------------------------//
	//----------------------------OPERATOR +---------------------------------//
	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend MyString operator+ (MyString&& lhs, MyString&& rhs);
	friend MyString operator+ (MyString&& lhs,  const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, MyString&& rhs);
	friend MyString operator+ (const MyString& lhs, const char* s);
	friend MyString operator+ (MyString&& lhs, const char* s);
	friend MyString operator+ (const char* s, const MyString& rhs);
	friend MyString operator+ (const char* s, MyString&& rhs);
	friend MyString operator+ (const MyString& lhs, char c);
	friend MyString operator+ (MyString&& lhs, char c);
	friend MyString operator+ (char c, const MyString& rhs);
	friend MyString operator+ (char c, MyString&& rhs);

	//----------------------RELATIONAL OPERATOR-------------------------------//
	friend bool operator== (const MyString& lhs, const MyString& rhs) noexcept;
	friend bool operator== (const char* lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const char* rhs);
	friend bool operator!= (const MyString& lhs, const MyString& rhs) noexcept;
	friend bool operator!= (const char* lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char* rhs);
	friend bool operator<  (const MyString& lhs, const MyString& rhs) noexcept;
	friend bool operator<  (const char* lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char* rhs);
	friend bool operator<= (const MyString& lhs, const MyString& rhs) noexcept;
	friend bool operator<= (const char* lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, const char* rhs);
	friend bool operator>  (const MyString& lhs, const MyString& rhs) noexcept;
	friend bool operator>  (const char* lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char* rhs);
	friend bool operator>= (const MyString& lhs, const MyString& rhs) noexcept;
	friend bool operator>= (const char* lhs, const MyString& rhs);
	friend bool operator>= (const MyString& lhs, const char* rhs);

	//--------------------------------SWAP------------------------------------//
	friend void swap(MyString& lhs, MyString& rhs);

	//-----------------------------OPERATOR >>--------------------------------//
	friend istream& operator >> (istream&, MyString&);

	//-----------------------------OPERATOR <<--------------------------------//
	friend ostream& operator << (ostream&, const MyString&);

	//------------------------------GETLINE-----------------------------------//
	friend istream& getline(istream& in, MyString& myString, char delim);
	friend istream& getline(istream&& in, MyString& myString, char delim);
	friend istream& getline(istream& in, MyString& myString);
	friend istream& getline(istream&& in, MyString& myString);
};

#endif

