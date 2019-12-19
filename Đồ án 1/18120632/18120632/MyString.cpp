#include "MyString.h"
#include <cstring>
#include <exception>
#include <iostream>

using namespace std;

void MyString::updateCapacity() {
	_capacity = (_length / BLOCKSIZE) * BLOCKSIZE + BLOCKSIZE - 1;
}

//--------------------------CONSTRUCTOR---------------------------//
MyString::MyString() {
	_string = NULL;
	_length = 0;
	_capacity = 0;
}

MyString::MyString(const MyString& otherMyString) {
	if (otherMyString._length > 0) {
		_length = otherMyString._length;
		_capacity = otherMyString._capacity;

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
	
		memcpy(_string, otherMyString._string, _length + 1);
	}
	else MyString();
	
}

MyString::MyString(const MyString& otherMyString, size_t pos, size_t npos) {
	try {
		if (pos >= otherMyString._length)
			throw exception("Out of range: Pos is out of range to construct the string");

		if (pos + npos > otherMyString._length)
			npos = otherMyString._length - pos;

		_length = npos;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		};

		for (size_t i = 0; i < _length; ++i)
			_string[i] = otherMyString._string[pos + i];

		_string[_length] = '\0';
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::MyString(const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		if (strlen(s) > 0) {
			_length = strlen(s);
			updateCapacity();

			try {
				_string = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}

			memcpy(_string, s, _length + 1);
		}
		else MyString();
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::MyString(const char* s, size_t n) {
	try {
		if (n > strlen(s))
			throw exception("Undefined behavior: n is greater than the array pointer by s");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		_length = n;
		updateCapacity();
		
		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		memcpy(_string, s, _length);
		_string[_length] = '\0';

	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::MyString(size_t n, char c) {
	try {
		if (n < 0)
			throw exception("Undefined behavior: n is a negative number");

		if (n > 0) {
			_length = n;
			updateCapacity();

			try {
				_string = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}

			memset(_string, c, _length);

			_string[_length] = '\0';
		}
		else MyString();
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::MyString(initializer_list<char> il) {
	if (il.size() > 0) {
		_length = il.size();
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (auto c : il)
			_string[i++] = c;

		_string[_length] = '\0';
	}
	else MyString();
}

MyString::MyString(MyString&& otherMyString) noexcept {
	if (otherMyString._length > 0) {
		_length = otherMyString._length;
		_capacity = otherMyString._capacity;
		_string = otherMyString._string;

		otherMyString._string = NULL;
		otherMyString._capacity = otherMyString._length = 0;
	}
	else MyString();
}

MyString::MyString(Const_Iterator first, Const_Iterator last) {
	_length = 0;
	for (Const_Iterator cit = first; cit != last; ++cit)
		++_length;

	if (_length > 0) {
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Const_Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;

		_string[_length] = '\0';
	}
	else MyString();
}

MyString::MyString(Const_Reverse_Iterator first, Const_Reverse_Iterator last) {
	_length = 0;
	for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
		++_length;

	if (_length > 0) {
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;

		_string[_length] = '\0';
	}
	else MyString();
}

MyString::MyString(Iterator first, Iterator last) {
	_length = 0;
	for (Iterator cit = first; cit != last; ++cit)
		++_length;

	if (_length > 0) {
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;

		_string[_length] = '\0';
	}
	else MyString();
}

MyString::MyString(Reverse_Iterator first, Reverse_Iterator last) {
	_length = 0;
	for (Reverse_Iterator cit = first; cit != last; ++cit)
		++_length;

	if (_length > 0) {
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Reverse_Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;

		_string[_length] = '\0';
	}
	else MyString();
}

//--------------------------DESTRUCTOR------------------------------//
MyString::~MyString() {
	if (_string != NULL)
		delete[] _string;
	_string = NULL;
}

//---------------------------OPERATOR =-----------------------------//
MyString& MyString::operator= (const MyString& otherMyString) {
	if (this != &otherMyString) {
		_length = otherMyString._length;
		_capacity = otherMyString._capacity;

		if (_string != NULL)
			delete[] _string;

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		memcpy(_string, otherMyString._string, _length + 1);
	}
	
	return *this;
}

MyString& MyString::operator= (const char* s) {
	_length = strlen(s);
	updateCapacity();

	if (_string != NULL)
		delete[] _string;

	try {
		_string = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}

	memcpy(_string, s, _length + 1);

	return *this;
}

MyString& MyString::operator= (char c) {
	_length = 1;
	updateCapacity();

	if (_string != NULL)
		delete[] _string;

	try {
		_string = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}

	_string[0] = c;
	_string[_length] = '\0';

	return *this;
}

MyString& MyString::operator= (initializer_list<char> il) {
	_length = il.size();
	updateCapacity();

	if (_string != NULL)
		delete[] _string;

	try {
		_string = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}

	size_t i = 0;
	for (auto c : il)
		_string[i++] = c;

	_string[_length] = '\0';

	return *this;
}

MyString& MyString::operator= (MyString&& otherMyString) noexcept{
	if (this != &otherMyString) {
		_length = otherMyString._length;
		_capacity = otherMyString._capacity;

		if (_string != NULL)
			delete[] _string;

		_string = otherMyString._string;

		otherMyString._string = NULL;
		otherMyString._length = otherMyString._capacity = 0;
	}

	return *this;
}

//---------------------IMPLEMENT CLASS ITERATOR---------------------//
MyString::Iterator::Iterator() {
	_p = NULL;
}

MyString::Iterator::Iterator(char* str) {
	_p = str;
}

MyString::Iterator::Iterator(const Iterator& otherIterator) {
	_p = otherIterator._p;
}

MyString::Iterator& MyString::Iterator::operator= (const Iterator& otherIterator) {
	if (this != &otherIterator)
		_p = otherIterator._p;

	return *this;
}

MyString::Iterator& MyString::Iterator::operator++ () {
	++_p;

	return *this;
}

MyString::Iterator MyString::Iterator::operator++ (int) {
	Iterator temp(*this);
	operator++();

	return temp;
}

MyString::Iterator MyString::Iterator::operator+ (size_t n) {
	Iterator temp(*this);

	temp._p = temp._p + n;
	return temp;
}

MyString::Iterator& MyString::Iterator::operator+= (size_t n) {
	_p = _p + n;

	return *this;
}

MyString::Iterator& MyString::Iterator::operator--() {
	--_p;

	return *this;
}

MyString::Iterator MyString::Iterator::operator--(int) {
	Iterator temp(*this);
	operator--();

	return temp;
}

MyString::Iterator MyString::Iterator::operator-(size_t n) {
	Iterator temp(*this);

	temp._p = temp._p - n;
	return temp;
}

MyString::Iterator& MyString::Iterator::operator-= (size_t n) {
	_p = _p - n;

	return *this;
}

bool MyString::Iterator::operator< (const MyString::Iterator& otherIterator) const {
	return *_p < *otherIterator._p;
}

bool MyString::Iterator::operator> (const MyString::Iterator& otherIterator) const {
	return *_p > *otherIterator._p;
}

bool MyString::Iterator::operator<= (const MyString::Iterator& otherIterator) const {
	return *_p <= *otherIterator._p;
}

bool MyString::Iterator::operator>= (const MyString::Iterator& otherIterator) const {
	return *_p >= *otherIterator._p;
}

bool MyString::Iterator::operator== (const MyString::Iterator& otherIterator) const {
	return _p == otherIterator._p;
}

bool MyString::Iterator::operator!= (const MyString::Iterator& otherIterator) const {
	return _p != otherIterator._p;
}

char& MyString::Iterator::operator*() {
	return *_p;
}

//---------------------IMPLEMENT CLASS CONST_ITERATOR---------------------//
MyString::Const_Iterator::Const_Iterator() {
	_p = NULL;
}

MyString::Const_Iterator::Const_Iterator(const char* str) {
	_p = str;
}

MyString::Const_Iterator::Const_Iterator(const Const_Iterator& otherIterator) {
	_p = otherIterator._p;
}

MyString::Const_Iterator& MyString::Const_Iterator::operator= (const Const_Iterator& otherIterator) {
	if (this != &otherIterator)
		_p = otherIterator._p;

	return *this;
}

MyString::Const_Iterator& MyString::Const_Iterator::operator++ () {
	++_p;

	return *this;
}

MyString::Const_Iterator MyString::Const_Iterator::operator++ (int) {
	Const_Iterator temp(*this);
	operator++();

	return temp;
}

MyString::Const_Iterator MyString::Const_Iterator::operator+ (size_t n) {
	Const_Iterator temp(*this);

	temp._p = temp._p + n;
	return temp;
}

MyString::Const_Iterator& MyString::Const_Iterator::operator+= (size_t n) {
	_p = _p + n;

	return *this;
}

MyString::Const_Iterator& MyString::Const_Iterator::operator--() {
	--_p;

	return *this;
}

MyString::Const_Iterator MyString::Const_Iterator::operator--(int) {
	Const_Iterator temp(*this);
	operator--();

	return temp;
}

MyString::Const_Iterator MyString::Const_Iterator::operator-(size_t n) {
	Const_Iterator temp(*this);

	temp._p = temp._p - n;
	return temp;
}

MyString::Const_Iterator& MyString::Const_Iterator::operator-= (size_t n) {
	_p = _p - n;

	return *this;
}

bool MyString::Const_Iterator::operator< (const MyString::Const_Iterator& otherIterator) const {
	return *_p < *otherIterator._p;
}

bool MyString::Const_Iterator::operator> (const MyString::Const_Iterator& otherIterator) const {
	return *_p > * otherIterator._p;
}

bool MyString::Const_Iterator::operator<= (const MyString::Const_Iterator& otherIterator) const {
	return *_p <= *otherIterator._p;
}

bool MyString::Const_Iterator::operator>= (const MyString::Const_Iterator& otherIterator) const {
	return *_p >= *otherIterator._p;
}

bool MyString::Const_Iterator::operator== (const MyString::Const_Iterator& otherIterator) const {
	return _p == otherIterator._p;
}

bool MyString::Const_Iterator::operator!= (const MyString::Const_Iterator& otherIterator) const {
	return _p != otherIterator._p;
}

const char MyString::Const_Iterator::operator*() const {
	return *_p;
}

//---------------------IMPLEMENT CLASS REVERSE_ITERATOR---------------------//
MyString::Reverse_Iterator::Reverse_Iterator() {
	_p = NULL;
}

MyString::Reverse_Iterator::Reverse_Iterator(char* str) {
	_p = str;
}

MyString::Reverse_Iterator::Reverse_Iterator(const Reverse_Iterator& otherIterator) {
	_p = otherIterator._p;
}

MyString::Reverse_Iterator& MyString::Reverse_Iterator::operator= (const Reverse_Iterator& otherIterator) {
	if (this != &otherIterator)
		_p = otherIterator._p;

	return *this;
}

MyString::Reverse_Iterator& MyString::Reverse_Iterator::operator++ () {
	--_p;

	return *this;
}

MyString::Reverse_Iterator MyString::Reverse_Iterator::operator++ (int) {
	Reverse_Iterator temp(*this);
	operator++();

	return temp;
}

MyString::Reverse_Iterator MyString::Reverse_Iterator::operator+ (size_t n) {
	Reverse_Iterator temp(*this);

	temp._p = temp._p - n;
	return temp;
}

MyString::Reverse_Iterator& MyString::Reverse_Iterator::operator+= (size_t n) {
	_p = _p - n;

	return *this;
}

MyString::Reverse_Iterator& MyString::Reverse_Iterator::operator--() {
	++_p;

	return *this;
}

MyString::Reverse_Iterator MyString::Reverse_Iterator::operator--(int) {
	Reverse_Iterator temp(*this);
	operator--();

	return temp;
}

MyString::Reverse_Iterator MyString::Reverse_Iterator::operator-(size_t n) {
	Reverse_Iterator temp(*this);

	temp._p = temp._p + n;
	return temp;
}

MyString::Reverse_Iterator& MyString::Reverse_Iterator::operator-= (size_t n) {
	_p = _p + n;

	return *this;
}

bool MyString::Reverse_Iterator::operator< (const MyString::Reverse_Iterator& otherIterator) const {
	return *_p < *otherIterator._p;
}

bool MyString::Reverse_Iterator::operator> (const MyString::Reverse_Iterator& otherIterator) const {
	return *_p > * otherIterator._p;
}

bool MyString::Reverse_Iterator::operator<= (const MyString::Reverse_Iterator& otherIterator) const {
	return *_p <= *otherIterator._p;
}

bool MyString::Reverse_Iterator::operator>= (const MyString::Reverse_Iterator& otherIterator) const {
	return *_p >= *otherIterator._p;
}

bool MyString::Reverse_Iterator::operator== (const MyString::Reverse_Iterator& otherIterator) const {
	return _p == otherIterator._p;
}

bool MyString::Reverse_Iterator::operator!= (const MyString::Reverse_Iterator& otherIterator) const {
	return _p != otherIterator._p;
}

char& MyString::Reverse_Iterator::operator*() {
	return *_p;
}

//---------------------IMPLEMENT CLASS CONST_REVERSE_ITERATOR---------------------//
MyString::Const_Reverse_Iterator::Const_Reverse_Iterator() {
	_p = NULL;
}

MyString::Const_Reverse_Iterator::Const_Reverse_Iterator(char* str) {
	_p = str;
}

MyString::Const_Reverse_Iterator::Const_Reverse_Iterator(const Const_Reverse_Iterator& otherIterator) {
	_p = otherIterator._p;
}

MyString::Const_Reverse_Iterator& MyString::Const_Reverse_Iterator::operator= (const Const_Reverse_Iterator& otherIterator) {
	if (this != &otherIterator)
		_p = otherIterator._p;

	return *this;
}

MyString::Const_Reverse_Iterator& MyString::Const_Reverse_Iterator::operator++ () {
	--_p;

	return *this;
}

MyString::Const_Reverse_Iterator MyString::Const_Reverse_Iterator::operator++ (int) {
	Const_Reverse_Iterator temp(*this);
	operator++();

	return temp;
}

MyString::Const_Reverse_Iterator MyString::Const_Reverse_Iterator::operator+ (size_t n) {
	Const_Reverse_Iterator temp(*this);

	temp._p = temp._p - n;
	return temp;
}

MyString::Const_Reverse_Iterator& MyString::Const_Reverse_Iterator::operator+= (size_t n) {
	_p = _p - n;

	return *this;
}

MyString::Const_Reverse_Iterator& MyString::Const_Reverse_Iterator::operator--() {
	++_p;

	return *this;
}

MyString::Const_Reverse_Iterator MyString::Const_Reverse_Iterator::operator--(int) {
	Const_Reverse_Iterator temp(*this);
	operator--();

	return temp;
}

MyString::Const_Reverse_Iterator MyString::Const_Reverse_Iterator::operator-(size_t n) {
	Const_Reverse_Iterator temp(*this);

	temp._p = temp._p + n;
	return temp;
}

MyString::Const_Reverse_Iterator& MyString::Const_Reverse_Iterator::operator-= (size_t n) {
	_p = _p + n;

	return *this;
}

bool MyString::Const_Reverse_Iterator::operator< (const MyString::Const_Reverse_Iterator& otherIterator) const {
	return *_p < *otherIterator._p;
}

bool MyString::Const_Reverse_Iterator::operator> (const MyString::Const_Reverse_Iterator& otherIterator) const {
	return *_p > * otherIterator._p;
}

bool MyString::Const_Reverse_Iterator::operator<= (const MyString::Const_Reverse_Iterator& otherIterator) const {
	return *_p <= *otherIterator._p;
}

bool MyString::Const_Reverse_Iterator::operator>= (const MyString::Const_Reverse_Iterator& otherIterator) const {
	return *_p >= *otherIterator._p;
}

bool MyString::Const_Reverse_Iterator::operator== (const MyString::Const_Reverse_Iterator& otherIterator) const {
	return _p == otherIterator._p;
}

bool MyString::Const_Reverse_Iterator::operator!= (const MyString::Const_Reverse_Iterator& otherIterator) const {
	return _p != otherIterator._p;
}

const char MyString::Const_Reverse_Iterator::operator*() const{
	return *_p;
}

//---------------------------ITERATOR------------------------------//

MyString::Iterator MyString::begin() noexcept {
	Iterator temp(_string);

	return temp;
}

MyString::Const_Iterator  MyString::begin() const noexcept {
	Const_Iterator temp(_string);

	return temp;
}

MyString::Iterator MyString::end() noexcept {
	Iterator temp(_string + _length);

	return temp;
}

MyString::Const_Iterator MyString::end() const noexcept {
	Const_Iterator temp(_string + _length);

	return temp;
}

MyString::Const_Iterator  MyString::cbegin() const noexcept {
	Const_Iterator temp(_string);

	return temp;
}

MyString::Const_Iterator MyString::cend() const noexcept {
	Const_Iterator temp(_string + _length);

	return temp;
}

MyString::Reverse_Iterator MyString::rbegin() noexcept {
	Reverse_Iterator temp(_string + _length - 1);

	return temp;
}

MyString::Const_Reverse_Iterator  MyString::rbegin() const noexcept {
	Const_Reverse_Iterator temp(_string + _length - 1);

	return temp;
}

MyString::Reverse_Iterator MyString::rend() noexcept {
	Reverse_Iterator temp(_string - 1);

	return temp;
}

MyString::Const_Reverse_Iterator MyString::rend() const noexcept {
	Const_Reverse_Iterator temp(_string - 1);

	return temp;
}

MyString::Const_Reverse_Iterator  MyString::crbegin() const noexcept {
	Const_Reverse_Iterator temp(_string + _length - 1);

	return temp;
}

MyString::Const_Reverse_Iterator MyString::crend() const noexcept {
	Const_Reverse_Iterator temp(_string - 1);

	return temp;
}

//---------------------------CAPACITY------------------------------//
size_t MyString::length() const noexcept {
	return _length;
}

size_t MyString::size() const noexcept {
	return _length;
}

size_t MyString::max_size() const noexcept {
	return MAXSIZE;
}

size_t MyString::capacity() const noexcept {
	return _capacity;
}

void MyString::resize(size_t n) {
	if (n >= _length) {
		resize(n, '\0');
		return;
	}

	_length = n;

	char* temp = NULL;

	try {
		temp = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}

	memcpy(temp, _string, n);
	temp[n] = '\0';

	delete[] _string;
	_string = temp;
}

void MyString::resize(size_t n, char c = '\0') {
	if (n < _length) {
		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		memcpy(temp, _string, n);
		temp[n] = '\0';

		delete[] _string;
		_string = temp;

		return;
	}

	size_t len = _length;

	_length = n;
	updateCapacity();

	char* temp = NULL;

	try {
		temp = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}

	memcpy(temp, _string, len);
	for (size_t i = len; i < n; ++i)
		temp[i] = c;
	temp[n] = '\0';

	delete[] _string;
	_string = temp;
}

void MyString::reserve(size_t n = 0) {
	if (n > _capacity) {
		_capacity = (n / BLOCKSIZE) * BLOCKSIZE + BLOCKSIZE;

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		memcpy(temp, _string, _length + 1);

		delete _string;
		_string = temp;
	}
}

void MyString::clear() noexcept {
	_length = 0;
	_capacity = 0;
	
	if (_string != NULL)
		delete[] _string;
	_string = NULL;
}

bool MyString::empty() const noexcept{
	return _length == 0;
}

void MyString::shrink_to_fit() {
	_capacity = _length;

	char* temp = NULL;

	try {
		temp = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}

	memcpy(temp, _string, _length + 1);
	
	delete[] _string;
	_string = temp;
}

//--------------------ELEMENT ACCESS--------------------//
char& MyString::operator[](size_t pos) {
	try {
		if (pos > _length)
			throw exception("Undefined behavior: pos is greater than string's length");

		return _string[pos];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

const char& MyString::operator[](size_t pos) const {
	try {
		if (pos > _length)
			throw exception("Undefined behavior: pos is greater than string's length");

		return _string[pos];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

char& MyString::at(size_t pos) {
	try {
		if (pos > _length)
			throw exception("Undefined behavior: pos is greater than string's length");

		return _string[pos];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

const char& MyString::at(size_t pos) const {
	try {
		if (pos > _length)
			throw exception("Undefined behavior: pos is greater than string's length");

		return _string[pos];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

char& MyString::back() {
	try {
		if (empty())
			throw exception("Undefined Behavior: string is empty string");
		return _string[_length - 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

const char& MyString::back() const {
	try {
		if (empty())
			throw exception("Undefined Behavior: string is empty string");
		return _string[_length - 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

char& MyString::front() {
	try {
		if (empty())
			throw exception("Undefined Behavior: string is empty string");
		return _string[0];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

const char& MyString::front() const {
	try {
		if (empty())
			throw exception("Undefined Behavior: string is empty string");
		return _string[0];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

//----------------------MODIFIERS----------------------//
//---------------------OPERATOR +=---------------------//
MyString& MyString::operator+= (const MyString& otherMyString) {
	 size_t len = _length;
	 _length += otherMyString._length;

	 try {
		 if (_length > MAXSIZE)
			 throw exception("Length error: new length is greater than MAX_SIZE");
		 
		 if (_length > _capacity) {
			 updateCapacity();

			 char* temp = NULL;

			 try {
				 temp = new char[_capacity + 1];
			 }
			 catch (const exception& excep) {
				 cerr << excep.what() << endl;
				 exit(0);
			 }
			 memcpy(temp, _string, len);

			 for (size_t i = len; i < _length; ++i)
				 temp[i] = otherMyString._string[i - len];
			 temp[_length] = '\0';

			 if (_string != NULL)
				 delete[] _string;
			 _string = temp;
		 }
		 else {
			 for (size_t i = len; i < _length; ++i)
				 _string[i] = otherMyString._string[i - len];
			 _string[_length] = '\0';
		 }

		 return *this;
	 }
	 catch (const exception& excep) {
		 cerr << excep.what() << endl;
		 exit(1);
	 }
}

MyString& MyString::operator+= (const char* s) {
	size_t len = _length;
	_length += strlen(s);

	try {
		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");
		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = s[i - len];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = s[i - len];
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::operator+= (char c) {
	++_length;

	try {
		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, _length - 1);

			temp[_length - 1] = c;
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			_string[_length - 1] = c;
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::operator+= (initializer_list<char> il) {
	size_t len = _length;
	_length += il.size();

	try {
		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (auto c : il)
				temp[len++] = c;

			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (auto c : il)
				_string[len++] = c;

			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

//-----------------------APPEND-----------------------//
MyString& MyString::append(const MyString& otherMyString) {
	size_t len = _length;
	_length += otherMyString._length;

	try {
		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = otherMyString._string[i - len];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = otherMyString._string[i - len];
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(const MyString& otherMyString, size_t subpos) {
	size_t len = _length;

	try {
		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		_length += otherMyString._length - subpos;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = otherMyString._string[subpos++];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = otherMyString._string[subpos++];
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}		
}

MyString& MyString::append(const MyString& otherMyString, size_t subpos, size_t sublen) {
	size_t len = _length;

	try {
		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		if (sublen == npos)
			sublen = otherMyString._length;

		if (subpos + sublen > otherMyString._length)
			sublen = otherMyString._length - subpos;

		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = otherMyString._string[subpos++];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = otherMyString._string[subpos++];
			_string[_length] = '\0';
		}
		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t len = _length;
		_length += strlen(s);

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = s[i - len];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = s[i - len];
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(const char* s, size_t n) {
	try {
		if (n > strlen(s))
			throw exception("Undefined behavior: n is greater than the array pointer by s");

		if (n < 0)
			throw exception("Undefined behavior: n is a negative number");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t len = _length;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = s[i - len];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = s[i - len];
			_string[_length] = '\0';
		}
		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(size_t n, char c) {
	try {
		if (n < 0)
			throw exception("Undefined behavior: n is a negative number");

		size_t len = _length;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (size_t i = len; i < _length; ++i)
				temp[i] = c;
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (size_t i = len; i < _length; ++i)
				_string[i] = c;
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(initializer_list<char> il) {
	try {
		size_t len = _length;
		_length += il.size();

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, len);

			for (auto c : il)
				temp[len++] = c;

			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			for (auto c : il)
				_string[len++] = c;

			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(Iterator first, Iterator last) {
	size_t cnt = 0;
	for (Iterator cit = first; cit != last; ++cit)
		++cnt;

	try {
		if (cnt > 0) {
			size_t len = _length;
			_length += cnt;

			if (_length > MAXSIZE)
				throw exception("Length error: new length is greater than MAX_SIZE");

			if (_length > _capacity) {
				updateCapacity();

				char* temp = new char[_capacity + 1];

				memcpy(temp, _string, len);

				for (Iterator cit = first; cit != last; ++cit)
					temp[len++] = *cit;
				temp[_length] = '\0';

				if (_string != NULL)
					delete[] _string;
				_string = temp;
			}

			for (Iterator cit = first; cit != last; ++cit)
				_string[len] = *cit;
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(Reverse_Iterator first, Reverse_Iterator last) {
	size_t cnt = 0;
	for (Reverse_Iterator cit = first; cit != last; ++cit)
		++cnt;

	try {
		if (cnt > 0) {
			size_t len = _length;
			_length += cnt;

			if (_length > MAXSIZE)
				throw exception("Length error: new length is greater than MAX_SIZE");

			if (_length > _capacity) {
				updateCapacity();

				char* temp = NULL;

				try {
					temp = new char[_capacity + 1];
				}
				catch (const exception& excep) {
					cerr << excep.what() << endl;
					exit(0);
				}

				memcpy(temp, _string, len);

				for (Reverse_Iterator cit = first; cit != last; ++cit)
					temp[len++] = *cit;
				temp[_length] = '\0';

				if (_string != NULL)
					delete[] _string;
				_string = temp;
			}

			for (Reverse_Iterator cit = first; cit != last; ++cit)
				_string[len] = *cit;
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(Const_Iterator first, Const_Iterator last) {
	size_t cnt = 0;
	for (Const_Iterator cit = first; cit != last; ++cit)
		++cnt;

	try {
		if (cnt > 0) {
			size_t len = _length;
			_length += cnt;

			if (_length > MAXSIZE)
				throw exception("Length error: new length is greater than MAX_SIZE");

			if (_length > _capacity) {
				updateCapacity();

				char* temp = NULL;

				try {
					temp = new char[_capacity + 1];
				}
				catch (const exception& excep) {
					cerr << excep.what() << endl;
					exit(0);
				}

				memcpy(temp, _string, len);

				for (Const_Iterator cit = first; cit != last; ++cit)
					temp[len++] = *cit;
				temp[_length] = '\0';

				if (_string != NULL)
					delete[] _string;
				_string = temp;
			}

			for (Const_Iterator cit = first; cit != last; ++cit)
				_string[len] = *cit;
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::append(Const_Reverse_Iterator first, Const_Reverse_Iterator last) {
	size_t cnt = 0;
	for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
		++cnt;

	try {
		if (cnt > 0) {
			size_t len = _length;
			_length += cnt;

			if (_length > MAXSIZE)
				throw exception("Length error: new length is greater than MAX_SIZE");

			if (_length > _capacity) {
				updateCapacity();

				char* temp = NULL;

				try {
					temp = new char[_capacity + 1];
				}
				catch (const exception& excep) {
					cerr << excep.what() << endl;
					exit(0);
				}

				memcpy(temp, _string, len);

				for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
					temp[len++] = *cit;
				temp[_length] = '\0';

				if (_string != NULL)
					delete[] _string;
				_string = temp;
			}

			for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
				_string[len] = *cit;
			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

//-------------------------------PUSH_BACK---------------------------------//
void MyString::push_back(char c) {
	try {
		++_length;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, _length - 1);

			temp[_length - 1] = c;
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;
			_string = temp;
		}
		else {
			_string[_length - 1] = c;
			_string[_length] = '\0';
		}
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

//--------------------------------ASSIGN-----------------------------------//
MyString& MyString::assign(const MyString& otherMyString) {
	if (otherMyString._length >= 0) {
		if (_string != NULL)
			delete[] _string;

		_length = otherMyString._length;
		_capacity = otherMyString._capacity;

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(_string, otherMyString._string, _length + 1);
	}

	return *this;
}

MyString& MyString::assign(const MyString& otherMyString, size_t subpos) {
	try {
		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		if (_string != NULL)
			delete[] _string;

		_length = otherMyString._length - subpos;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		for (size_t i = 0; i < _length; ++i)
			_string[i] = otherMyString._string[subpos++];

		_string[_length] = '\0';

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::assign(const MyString& otherMyString, size_t subpos, size_t sublen) {
	try {
		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		if (sublen == npos)
			sublen = otherMyString._length;

		if (subpos + sublen > otherMyString._length)
			sublen = otherMyString._length - subpos;

		if (_string != NULL)
			delete[] _string;

		_length = sublen;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < _length; ++i)
			_string[i] = otherMyString._string[subpos++];
		_string[_length] = '\0';

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::assign(const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		if (strlen(s) >= 0) {
			if (_string != NULL)
				delete[] _string;

			_length = strlen(s);
			updateCapacity();

			try {
				_string = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}

			memcpy(_string, s, _length + 1);
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::assign(const char* s, size_t n) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		if (n > strlen(s))
			throw exception("Undefined behavior: n is greater than the array pointer by s");

		if (n < 0)
			throw exception("Undefined behavior: n is a negative number");

		if (_string != NULL)
			delete[] _string;

		_length = n;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		memcpy(_string, s, _length);
		_string[_length] = '\0';

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::assign(size_t n, char c) {
	if (n > 0) {
		if (_string != NULL)
			delete[] _string;

		_length = n;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < _length; ++i)
			_string[i] = c;
		_string[_length] = '\0';
	}

	return *this;
}

MyString& MyString::assign(initializer_list<char> il) {
	try {
		if (il.size() > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_string != NULL)
			delete[] _string;

		_length = il.size();
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (auto c : il)
			_string[i++] = c;
		_string[_length] = '\0';

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::assign(Iterator first, Iterator last) {
	size_t cnt = 0;
	for (Iterator cit = first; cit != last; ++cit)
		++cnt;

	if (cnt > 0) {
		if (_string != NULL)
			delete[] _string;

		_length = cnt;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;
		_string[_length] = '\0';

	}

	return *this;
}

MyString& MyString::assign(Reverse_Iterator first, Reverse_Iterator last) {
	size_t cnt = 0;
	for (Reverse_Iterator cit = first; cit != last; ++cit)
		++cnt;

	if (cnt > 0) {
		if (_string != NULL)
			delete[] _string;

		_length = cnt;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Reverse_Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;
		_string[_length] = '\0';

	}

	return *this;
}

MyString& MyString::assign(Const_Iterator first, Const_Iterator last) {
	size_t cnt = 0;
	for (Const_Iterator cit = first; cit != last; ++cit)
		++cnt;

	if (cnt > 0) {
		if (_string != NULL)
			delete[] _string;

		_length = cnt;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Const_Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;
		_string[_length] = '\0';

	}

	return *this;
}

MyString& MyString::assign(Const_Reverse_Iterator first, Const_Reverse_Iterator last) {
	size_t cnt = 0;
	for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
		++cnt;

	if (cnt > 0) {
		if (_string != NULL)
			delete[] _string;

		_length = cnt;
		updateCapacity();

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		size_t i = 0;
		for (Const_Reverse_Iterator cit = first; cit != last; ++cit)
			_string[i++] = *cit;
		_string[_length] = '\0';

	}

	return *this;
}

MyString& MyString::assign(MyString&& otherMyString) noexcept {
	if (otherMyString._length >= 0) {
		_length = otherMyString._length;
		_capacity = otherMyString._capacity;

		if (_string != NULL)
			delete[] _string;

		try {
			_string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		memcpy(_string, otherMyString._string, _length + 1);
	}

	return *this;
}

//-----------------------------INSERT--------------------------------//
MyString& MyString::insert(size_t pos, const MyString& otherMyString) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (otherMyString._length > 0) {
			size_t len = _length;
			_length += otherMyString._length;

			if (_length > MAXSIZE)
				throw exception("Length error: new length is greater than MAX_SIZE");

			if (_length > _capacity) {
				updateCapacity();

				char* temp = NULL;

				try {
					temp = new char[_capacity + 1];
				}
				catch (const exception& excep) {
					cerr << excep.what() << endl;
					exit(0);
				}
				memcpy(temp, _string, pos);

				for (size_t i = 0; i < otherMyString._length; ++i)
					temp[pos + i] = otherMyString._string[i];

				for (size_t i = pos; i < len; ++i)
					temp[i + otherMyString._length] = _string[i];
				temp[_length] = '\0';

				if (_string != NULL)
					delete[] _string;

				_string = temp;
			}
			else {
				for (size_t i = _length - 1; i >= pos + otherMyString._length; --i)
					_string[i] = _string[i - otherMyString._length];

				for (size_t i = pos; i < pos + otherMyString._length; ++i)
					_string[i] = otherMyString._string[i - pos];

				_string[_length] = '\0';
			}

		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::insert(size_t pos, const MyString& otherMyString, size_t subpos) {
	try {
		if (pos >_length)
			throw exception("Out of range: pos is greater than string's length");

		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");
	
		size_t len = _length;
		_length += otherMyString._length - subpos;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, pos);

			size_t d = pos;
			for (size_t i = subpos; i < otherMyString._length; ++i)
				temp[d++] = otherMyString._string[i];

			for (size_t i = pos; i < len; ++i)
				temp[i + otherMyString._length - subpos] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= pos + otherMyString._length - subpos; --i)
				_string[i] = _string[i - otherMyString._length + subpos];

			size_t d = subpos;
			for (size_t i = pos; i < pos + otherMyString._length - subpos; ++i)
				_string[i] = otherMyString._string[d++];

			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::insert(size_t pos, const MyString& otherMyString, size_t subpos, size_t sublen) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		if (subpos + sublen >= otherMyString._length)
			return insert(pos, otherMyString, subpos);

		size_t len = _length;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, pos);

			size_t d = pos;
			for (size_t i = subpos; i < subpos + sublen; ++i)
				temp[d++] = otherMyString._string[i];

			for (size_t i = pos; i < len; ++i)
				temp[i + sublen] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= pos + sublen; --i)
				_string[i] = _string[i - sublen];

			size_t d = subpos;
			for (size_t i = pos; i < pos + sublen; ++i)
				_string[i] = otherMyString._string[d++];

			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::insert(size_t pos, const char* s) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");
		
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t slen = strlen(s);
		size_t len = _length;

		_length += slen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, pos);

			for (size_t i = 0; i < slen; ++i)
				temp[pos + i] = s[i];

			for (size_t i = pos; i < len; ++i)
				temp[i + slen] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= pos + slen; --i)
				_string[i] = _string[i - slen];

			for (size_t i = pos; i < pos + slen; ++i)
				_string[i] = s[i - pos];

			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::insert(size_t pos, const char* s, size_t n) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		if (n >= strlen(s))
			return insert(pos, s);

		size_t len = _length;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, pos);

			for (size_t i = 0; i < n; ++i)
				temp[pos + i] = s[i];

			for (size_t i = pos; i < len; ++i)
				temp[i + n] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= pos + n; --i)
				_string[i] = _string[i - n];

			for (size_t i = pos; i < pos + n; ++i)
				_string[i] = s[i - pos];

			_string[_length] = '\0';
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::insert(size_t pos, size_t n, char c) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (n > 0) {
			size_t len = _length;
			_length += n;

			if (_length > MAXSIZE)
				throw exception("Length error: new length is greater than MAX_SIZE");

			if (_length > _capacity) {
				updateCapacity();

				char* temp = NULL;

				try {
					temp = new char[_capacity + 1];
				}
				catch (const exception& excep) {
					cerr << excep.what() << endl;
					exit(0);
				}
				memcpy(temp, _string, pos);

				for (size_t i = 0; i < n; ++i)
					temp[pos + i] = c;

				for (size_t i = pos; i < len; ++i)
					temp[i + n] = _string[i];
				temp[_length] = '\0';

				if (_string != NULL)
					delete[] _string;

				_string = temp;
			}
			else {
				for (size_t i = _length - 1; i >= pos + n; --i)
					_string[i] = _string[i - n];

				for (size_t i = pos; i < pos + n; ++i)
					_string[i] = c;

				_string[_length] = '\0';

			}
		}

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::insert(Const_Iterator p, size_t n, char c) {
	try {
		size_t len = _length;
		size_t cnt = 0;

		for (Const_Iterator cit = cbegin(); cit != p && cit != cend(); ++cit, ++cnt);

		if (cnt == _length)
			if (p != cend())
				throw exception("Undefined behavior: p is not valid");

		size_t d = cnt;

		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, cnt);

			for (size_t i = 0; i < n; ++i)
				temp[cnt++] = c;

			for (size_t i = d; i < len; ++i)
				temp[cnt++] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= d; --i)
				_string[i] = _string[i - n];

			for (size_t i = d; i < d + n; ++i)
				_string[i] = c;

			_string[_length] = '\0';
		}

		Iterator it = _string + d;

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::insert(Const_Iterator p, char c) {
	try {
		size_t cnt = 0;
		for (Const_Iterator cit = cbegin(); cit != p && cit != cend(); ++cit, ++cnt);
		size_t d = cnt;

		if (cnt == _length)
			if (p != cend())
				throw exception("Undefined behavior: p is not valid");

		++_length;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, cnt);

			temp[cnt++] = c;

			for (size_t i = d; i < _length - 1; ++i)
				temp[cnt++] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= d; --i)
				_string[i] = _string[i - 1];

			for (size_t i = d; i < d + 1; ++i)
				_string[i] = c;

			_string[_length] = '\0';
		}

		Iterator it = _string + d;

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}	
}

MyString::Iterator MyString::insert(Iterator p, size_t n, char c) {
	try {
		size_t len = _length;
		size_t cnt = 0;
		for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
		size_t d = cnt;

		if (cnt == _length)
			if (p != end())
				throw exception("Undefined behavior: p is not valid");

		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, cnt);

			for (size_t i = 0; i < n; ++i)
				temp[cnt++] = c;

			for (size_t i = d; i < len; ++i)
				temp[cnt++] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= d; --i)
				_string[i] = _string[i - n];

			for (size_t i = d; i < d + n; ++i)
				_string[i] = c;

			_string[_length] = '\0';
		}

		Iterator it = _string + d;

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::insert(Iterator p, char c) {
	try {
		size_t cnt = 0;
		for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
		size_t d = cnt;

		if (cnt == _length)
			if (p != end())
				throw exception("Undefined behavior: p is not valid");

		++_length;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, cnt);

			temp[cnt++] = c;

			for (size_t i = d; i < _length - 1; ++i)
				temp[cnt++] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= d; --i)
				_string[i] = _string[i - 1];

			for (size_t i = d; i < d + 1; ++i)
				_string[i] = c;

			_string[_length] = '\0';
		}

		Iterator it = _string + d;

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::insert(Iterator p, Iterator first, Iterator last) {
	try {
		size_t len = _length;
		size_t cnt = 0;
		for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
		size_t d = cnt;

		if (cnt == _length)
			if (p != end())
				throw exception("Undefined behavior: p is not valid");

		size_t n = 0;
		for (Iterator it = first; it != last; ++it, ++n);

		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, cnt);

			for (Iterator it = first; it != last; ++it)
				temp[cnt++] = *it;

			for (size_t i = d; i < len; ++i)
				temp[cnt++] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= d; --i)
				_string[i] = _string[i - n];

			for (Iterator it = first; it != last; ++it)
				_string[d++] = *it;

			_string[_length] = '\0';
		}

		Iterator it = _string + d;

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::insert(Iterator p, Const_Iterator first, Const_Iterator last) {
	try {
		size_t len = _length;
		size_t cnt = 0;
		for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
		size_t d = cnt;

		if (cnt == _length)
			if (p != end())
				throw exception("Undefined behavior: p is not valid");

		size_t n = 0;
		for (Const_Iterator it = first; it != last; ++it, ++n);

		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		if (_length > _capacity) {
			updateCapacity();

			char* temp = NULL;

			try {
				temp = new char[_capacity + 1];
			}
			catch (const exception& excep) {
				cerr << excep.what() << endl;
				exit(0);
			}
			memcpy(temp, _string, cnt);

			for (Const_Iterator it = first; it != last; ++it)
				temp[cnt++] = *it;

			for (size_t i = d; i < len; ++i)
				temp[cnt++] = _string[i];
			temp[_length] = '\0';

			if (_string != NULL)
				delete[] _string;

			_string = temp;
		}
		else {
			for (size_t i = _length - 1; i >= d; --i)
				_string[i] = _string[i - n];

			for (Const_Iterator it = first; it != last; ++it)
				_string[d++] = *it;

			_string[_length] = '\0';
		}

		Iterator it = _string + d;

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::insert(Iterator p, Const_Reverse_Iterator first, Const_Reverse_Iterator last) {
	size_t len = _length;
	size_t cnt = 0;
	for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
	size_t d = cnt;

	if (cnt == _length)
		if (p != end())
			throw exception("Undefined behavior: p is not valid");

	size_t n = 0;
	for (Const_Reverse_Iterator it = first; it != last; ++it, ++n);

	_length += n;

	if (_length > MAXSIZE)
		throw exception("Length error: new length is greater than MAX_SIZE");

	if (_length > _capacity) {
		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, cnt);

		for (Const_Reverse_Iterator it = first; it != last; ++it)
			temp[cnt++] = *it;

		for (size_t i = d; i < len; ++i)
			temp[cnt++] = _string[i];
		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;

		_string = temp;
	}
	else {
		for (size_t i = _length - 1; i >= d; --i)
			_string[i] = _string[i - n];

		for (Const_Reverse_Iterator it = first; it != last; ++it)
			_string[d++] = *it;

		_string[_length] = '\0';
	}

	Iterator it = _string + d;

	return it;
}

MyString::Iterator MyString::insert(Iterator p, Reverse_Iterator first, Reverse_Iterator last) {
	size_t len = _length;
	size_t cnt = 0;
	for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
	size_t d = cnt;

	if (cnt == _length)
		if (p != end())
			throw exception("Undefined behavior: p is not valid");

	size_t n = 0;
	for (Reverse_Iterator it = first; it != last; ++it, ++n);

	_length += n;

	if (_length > MAXSIZE)
		throw exception("Length error: new length is greater than MAX_SIZE");

	if (_length > _capacity) {
		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, cnt);

		for (Reverse_Iterator it = first; it != last; ++it)
			temp[cnt++] = *it;

		for (size_t i = d; i < len; ++i)
			temp[cnt++] = _string[i];
		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;

		_string = temp;
	}
	else {
		for (size_t i = _length - 1; i >= d; --i)
			_string[i] = _string[i - n];

		for (Reverse_Iterator it = first; it != last; ++it)
			_string[d++] = *it;

		_string[_length] = '\0';
	}

	Iterator it = _string + d;

	return it;
}

MyString& MyString::insert(Const_Iterator p, initializer_list<char> il) {
	size_t len = _length;
	size_t cnt = 0;
	for (Const_Iterator cit = cbegin(); cit != p && cit != cend(); ++cit, ++cnt);
	size_t d = cnt;

	if (cnt == _length)
		if (p != cend())
			throw exception("Undefined behavior: p is not valid");

	_length += il.size();

	if (_length > MAXSIZE)
		throw exception("Length error: new length is greater than MAX_SIZE");

	if (_length > _capacity) {
		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, cnt);

		for (auto c : il)
			temp[cnt++] = c;

		for (size_t i = d; i < len; ++i)
			temp[cnt++] = _string[i];
		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;

		_string = temp;
	}
	else {
		for (size_t i = _length - 1; i >= d; --i)
			_string[i] = _string[i - il.size()];

		for (auto c : il)
			_string[d++] = c;

		_string[_length] = '\0';
	}

	return *this;
}

MyString& MyString::insert(Iterator p, initializer_list<char> il) {
	size_t len = _length;
	size_t cnt = 0;
	for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);
	size_t d = cnt;

	if (cnt == _length)
		if (p != end())
			throw exception("Undefined behavior: p is not valid");

	_length += il.size();

	if (_length > MAXSIZE)
		throw exception("Length error: new length is greater than MAX_SIZE");

	if (_length > _capacity) {
		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, cnt);

		for (auto c : il)
			temp[cnt++] = c;

		for (size_t i = d; i < len; ++i)
			temp[cnt++] = _string[i];
		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;

		_string = temp;
	}
	else {
		for (size_t i = _length - 1; i >= d; --i)
			_string[i] = _string[i - il.size()];

		for (auto c : il)
			_string[d++] = c;

		_string[_length] = '\0';
	}

	return *this;
}

//--------------------------------ERASE-----------------------------------//
MyString& MyString::erase(size_t pos) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		size_t n = _length - pos;
		_length -= n;
		_string[_length] = '\0';

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::erase(size_t pos, size_t npos) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (pos + npos >= _length)
			return erase(pos);

		size_t d = pos;
		for (size_t i = pos + npos; i < _length; ++i)
			_string[d++] = _string[i];

		_length -= npos;
		_string[_length] = '\0';

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::erase(Const_Iterator p) {
	try {
		size_t cnt = 0;
		for (Const_Iterator cit = cbegin(); cit != p && cit != cend(); ++cit, ++cnt);

		if (cnt == _length)
			if (p != cend())
				throw exception("Undefined behavior: p is not valid");

		Iterator it = _string + cnt;

		for (size_t i = cnt; i < _length - 1; ++i)
			_string[i] = _string[i + 1];

		--_length;
		_string[_length] = '\0';

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::erase(Iterator p) {
	try {
		size_t cnt = 0;
		for (Iterator it = begin(); it != p && it != end(); ++it, ++cnt);

		if (cnt == _length)
			if (p != end())
				throw exception("Undefined behavior: p is not valid");

		Iterator it = _string + cnt;

		for (size_t i = cnt; i < _length - 1; ++i)
			_string[i] = _string[i + 1];

		--_length;
		_string[_length] = '\0';

		return it;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString::Iterator MyString::erase(Const_Iterator first, Const_Iterator last) {
	size_t pos = 0;
	for (Const_Iterator cit = cbegin(); cit != first; ++cit, ++pos);

	size_t npos = 0;
	for (Const_Iterator cit = first; cit != last; ++cit, ++npos);

	for (size_t i = pos + npos; i < _length; ++i)
		_string[i - npos] = _string[i];

	_length -= npos;
	_string[_length] = '\0';

	Iterator it = _string;
	return it;
}

MyString::Iterator MyString::erase(Iterator first, Iterator last) {
	size_t pos = 0;
	for (Iterator it = begin(); it != first; ++it, ++pos);

	size_t npos = 0;
	for (Iterator it = first; it != last; ++it, ++npos);

	for (size_t i = pos + npos; i < _length; ++i)
		_string[i - npos] = _string[i];

	_length -= npos;
	_string[_length] = '\0';

	Iterator it = _string;
	return it;
}

//--------------------------------REPLACE---------------------------------//
MyString& MyString::replace(size_t pos, size_t len, const MyString& otherMyString) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		size_t oldLen = _length;

		if (pos + len >= _length)
			len = _length - pos;

		_length -= len;
		_length += otherMyString._length;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < otherMyString._length; ++i)
			temp[d++] = otherMyString._string[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, const MyString& otherMyString) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		_length -= len;
		_length += otherMyString._length;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < otherMyString._length; ++i)
			temp[d++] = otherMyString._string[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, const MyString& otherMyString) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		_length -= len;
		_length += otherMyString._length;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < otherMyString._length; ++i)
			temp[d++] = otherMyString._string[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& otherMyString, size_t subpos) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		size_t oldLen = _length;

		if (pos + len >= _length)
			len = _length - pos;

		_length -= len;
		_length += otherMyString._length - subpos;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = subpos; i < otherMyString._length; ++i)
			temp[d++] = otherMyString._string[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;

	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& otherMyString, size_t subpos, size_t sublen) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		size_t oldLen = _length;

		if (pos + len >= _length)
			len = _length - pos;

		if (subpos + sublen >= otherMyString._length)
			return replace(pos, len, otherMyString, subpos);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = subpos; i < subpos + sublen; ++i)
			temp[d++] = otherMyString._string[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;

	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(size_t pos, size_t len, const char* s) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t oldLen = _length;

		if (pos + len >= _length)
			len = _length - pos;

		size_t sLen = strlen(s);

		_length -= len;
		_length += sLen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < sLen; ++i)
			temp[d++] = s[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		size_t sLen = strlen(s);

		_length -= len;
		_length += sLen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < sLen; ++i)
			temp[d++] = s[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		size_t sLen = strlen(s);

		_length -= len;
		_length += sLen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < sLen; ++i)
			temp[d++] = s[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t oldLen = _length;

		if (pos + len >= _length)
			len = _length - pos;

		if (n > strlen(s))
			n = strlen(s);

		_length -= len;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < n; ++i)
			temp[d++] = s[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, const char* s, size_t n) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		if (n > strlen(s))
			n = strlen(s);

		_length -= len;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < n; ++i)
			temp[d++] = s[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, const char* s, size_t n) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		if (n > strlen(s))
			n = strlen(s);

		_length -= len;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < n; ++i)
			temp[d++] = s[i];

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(size_t pos, size_t len, size_t n, char c) {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		size_t oldLen = _length;

		if (pos + len >= _length)
			len = _length - pos;

		_length -= len;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < n; ++i)
			temp[d++] = c;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, size_t n, char c) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		_length -= len;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < n; ++i)
			temp[d++] = c;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, size_t n, char c) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		_length -= len;
		_length += n;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (size_t i = 0; i < n; ++i)
			temp[d++] = c;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, Iterator first, Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		size_t sublen = 0;
		for (Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, Const_Iterator first, Const_Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		size_t sublen = 0;
		for (Const_Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Const_Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, Reverse_Iterator first, Reverse_Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		size_t sublen = 0;
		for (Reverse_Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Reverse_Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, Const_Reverse_Iterator first, Const_Reverse_Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		size_t sublen = 0;
		for (Const_Reverse_Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Const_Reverse_Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, Iterator first, Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		size_t sublen = 0;
		for (Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, Const_Iterator first, Const_Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		size_t sublen = 0;
		for (Const_Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Const_Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, Reverse_Iterator first, Reverse_Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		size_t sublen = 0;
		for (Reverse_Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Reverse_Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, Const_Reverse_Iterator first, Const_Reverse_Iterator last) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		size_t sublen = 0;
		for (Const_Reverse_Iterator it = first; it != last; ++it, ++sublen);

		_length -= len;
		_length += sublen;

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (Const_Reverse_Iterator it = first; it != last; ++it)
			temp[d++] = *it;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Const_Iterator i1, Const_Iterator i2, initializer_list<char> il) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Const_Iterator cit = cbegin(); cit != i1; ++cit, ++pos);
		for (Const_Iterator cit = i1; cit != i2; ++cit, ++len);

		_length -= len;
		_length += il.size();

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (auto c : il)
			temp[d++] = c;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString& MyString::replace(Iterator i1, Iterator i2, initializer_list<char> il) {
	try {
		size_t pos = 0, len = 0, oldLen = _length;

		for (Iterator it = begin(); it != i1; ++it, ++pos);
		for (Iterator it = i1; it != i2; ++it, ++len);

		_length -= len;
		_length += il.size();

		if (_length > MAXSIZE)
			throw exception("Length error: new length is greater than MAX_SIZE");

		size_t d = pos;

		updateCapacity();

		char* temp = NULL;

		try {
			temp = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		memcpy(temp, _string, pos);

		for (auto c : il)
			temp[d++] = c;

		for (size_t i = pos + len; i < oldLen; ++i)
			temp[d++] = _string[i];

		temp[_length] = '\0';

		if (_string != NULL)
			delete[] _string;
		_string = temp;

		return *this;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

//--------------------------------------SWAP---------------------------------------//
void MyString::swap(MyString& otherMyString) {
	MyString temp(*this);
	*this = otherMyString;
	otherMyString = temp;
}

//-------------------------------------POP BACK------------------------------------//
void MyString::pop_back() {
	--_length;
	_string[_length] = '\0';
}

//--------------------------------STRING OPERATIONS---------------------------------//
const char* MyString::c_str() const noexcept {
	char* temp = NULL;

	try {
		temp = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}
	memcpy(temp, _string, _length + 1);

	return temp;
}

const char* MyString::data() const noexcept {
	char* temp = NULL;

	try {
		temp = new char[_capacity + 1];
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(0);
	}
	memcpy(temp, _string, _length + 1);

	return temp;
}

allocator<char> MyString::get_allocator() const noexcept {
	allocator<char> temp;
	temp.construct(_string);
	return temp;
}

size_t MyString::copy(char* s, size_t len, size_t pos) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (pos + len >= _length)
			len = _length - pos;

		if (strlen(s) < len)
			throw exception("Undefined behavior: s does not point to an array long enough");

		for (size_t i = 0; i < len; ++i)
			s[i] = _string[pos + i];

		return len;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::copy(char* s, size_t len) const {
	try {
		if (len > _length)
			len = _length;

		if (strlen(s) < len)
			throw exception("Undefined behavior: s does not point to an array long enough");

		for (size_t i = 0; i < len; ++i)
			s[i] = _string[i];

		return len;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find(const MyString& otherMyString) const noexcept {
	if (otherMyString._length > _length)
		return npos;

	for (size_t i = 0; i <= _length - otherMyString._length; ++i) 
		if (_string[i] == otherMyString._string[0]) {
			size_t j = 0;
			size_t temp = i;
			while (j < otherMyString._length && _string[temp] == otherMyString._string[j]) {
				++temp;
				++j;
			}

			if (j == otherMyString._length)
				return i;
		}

	return npos;
}

size_t MyString::find(const MyString& otherMyString, size_t pos) const noexcept {
	if (otherMyString._length > _length)
		return npos;

	if (pos >= _length)
		return npos;

	for (size_t i = pos; i <= _length - otherMyString._length; ++i)
		if (_string[i] == otherMyString._string[0]) {
			size_t j = 0;
			size_t temp = i;
			while (j < otherMyString._length && _string[temp] == otherMyString._string[j]) {
				++temp;
				++j;
			}

			if (j == otherMyString._length)
				return i;
		}

	return npos;
}

size_t MyString::find(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);
		if (sLen > _length)
			return npos;

		for (size_t i = 0; i <= _length - sLen; ++i)
			if (_string[i] == s[0]) {
				size_t j = 0;
				size_t temp = i;
				while (j < sLen && _string[temp] == s[j]) {
					++temp;
					++j;
				}

				if (j == sLen)
					return i;
			}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find(const char* s, size_t pos) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		if (sLen > _length)
			return npos;

		if (pos >= _length)
			return npos;

		for (size_t i = pos; i <= _length - sLen; ++i)
			if (_string[i] == s[0]) {
				size_t j = 0;
				size_t temp = i;
				while (j < sLen && _string[temp] == s[j]) {
					++temp;
					++j;
				}

				if (j == sLen)
					return i;
			}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find(const char* s, size_t pos, size_t n) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		char* temp = NULL;

		try {
			temp = new char[n + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < n; ++i)
			temp[i] = s[i];
		temp[n] = '\0';

		size_t tempLen = strlen(temp);

		if (tempLen > _length)
			return npos;

		if (pos >= _length)
			return npos;

		for (size_t i = pos; i <= _length - tempLen; ++i)
			if (_string[i] == temp[0]) {
				size_t j = 0;
				size_t d = i;
				while (j < tempLen && _string[d] == temp[j]) {
					++d;
					++j;
				}

				if (j == tempLen)
					return i;
			}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find(char c) const noexcept {
	for (size_t i = 0; i < _length; ++i)
		if (_string[i] == c)
			return i;

	return npos;
}

size_t MyString::find(char c, size_t pos) const noexcept {
	if (pos >= _length)
		return npos;

	for (size_t i = pos; i < _length; ++i)
		if (_string[i] == c)
			return i;

	return npos;
}

size_t MyString::rfind(const MyString& otherMyString) const noexcept {
	if (otherMyString._length > _length)
		return npos;

	for (size_t i = _length - otherMyString._length; i >= 0; --i)
		if (_string[i] == otherMyString._string[0]) {
			size_t j = 0;
			size_t temp = i;
			while (j < otherMyString._length && _string[temp] == otherMyString._string[j]) {
				++temp;
				++j;
			}

			if (j == otherMyString._length)
				return i;
		}

	return npos;
}

size_t MyString::rfind(const MyString& otherMyString, size_t pos) const noexcept {
	if (otherMyString._length > _length)
		return npos;

	if (pos >= _length)
		return npos;

	if (_length - otherMyString._length < pos)
		pos = _length - otherMyString._length;

	for (size_t i = pos; i >= 0; --i)
		if (_string[i] == otherMyString._string[0]) {
			size_t j = 0;
			size_t temp = i;
			while (j < otherMyString._length && _string[temp] == otherMyString._string[j]) {
				++temp;
				++j;
			}

			if (j == otherMyString._length)
				return i;
		}

	return npos;
}

size_t MyString::rfind(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);
		if (sLen > _length)
			return npos;

		for (size_t i = _length - sLen; i >= 0; --i)
			if (_string[i] == s[0]) {
				size_t j = 0;
				size_t temp = i;
				while (j < sLen && _string[temp] == s[j]) {
					++temp;
					++j;
				}

				if (j == sLen)
					return i;
			}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::rfind(const char* s, size_t pos) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);
		if (sLen > _length)
			return npos;

		if (pos >= _length)
			return npos;

		if (pos > _length - sLen)
			pos = _length - sLen;

		for (size_t i = pos; i >= 0; --i)
			if (_string[i] == s[0]) {
				size_t j = 0;
				size_t temp = i;
				while (j < sLen && _string[temp] == s[j]) {
					++temp;
					++j;
				}

				if (j == sLen)
					return i;
			}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::rfind(const char* s, size_t pos, size_t n) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		char* temp = NULL;

		try {
			temp = new char[n + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < n; ++i)
			temp[i] = s[i];
		temp[n] = '\0';

		size_t tempLen = strlen(temp);

		if (tempLen > _length)
			return npos;

		if (pos >= _length)
			return npos;

		if (pos > _length - tempLen)
			pos = _length - tempLen;

		for (size_t i = pos; i >= 0; --i)
			if (_string[i] == temp[0]) {
				size_t j = 0;
				size_t d = i;
				while (j < tempLen && _string[d] == temp[j]) {
					++d;
					++j;
				}

				if (j == tempLen)
					return i;
			}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::rfind(char c) const noexcept {
	for (size_t i = _length - 1; i >= 0; --i)
		if (_string[i] == c)
			return i;

	return npos;
}

size_t MyString::rfind(char c, size_t pos) const noexcept {
	if (pos >= _length)
		return pos;

	for (size_t i = pos; i >= 0; --i)
		if (_string[i] == c)
			return i;

	return npos;
}

size_t MyString::find_first_of(const MyString& otherMyString) const noexcept {
	for (size_t i = 0; i < _length; ++i) {
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				return i;
	}
	return npos;
}

size_t MyString::find_first_of(const MyString& otherMyString, size_t pos) const noexcept {
	for (size_t i = pos; i < _length; ++i) {
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				return i;
	}
	return npos;
}

size_t MyString::find_first_of(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		for (size_t i = 0; i < _length; ++i) {
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_first_of(const char* s, size_t pos) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		for (size_t i = pos; i < _length; ++i) {
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_first_of(const char* s, size_t pos, size_t n) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		char* temp = NULL;

		try {
			temp = new char[n + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < n; ++i)
			temp[i] = s[i];
		temp[n] = '\0';

		size_t tempLen = strlen(temp);

		for (size_t i = pos; i < _length; ++i) {
			for (size_t j = 0; j < tempLen; ++j)
				if (_string[i] == temp[j])
					return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_first_of(char c) const noexcept {
	return find(c);
}

size_t MyString::find_first_of(char c, size_t pos) const noexcept {
	return find(c, pos);
}

size_t MyString::find_last_of(const MyString& otherMyString) const noexcept {
	for (size_t i = _length - 1; i >= 0; --i) {
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				return i;
	}
	return npos;
}

size_t MyString::find_last_of(const MyString& otherMyString, size_t pos) const noexcept {
	if (pos >= _length)
		return npos;

	for (size_t i = pos; i >= 0; --i) {
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				return i;
	}
	return npos;
}

size_t MyString::find_last_of(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		for (size_t i = _length - 1; i >= 0; --i) {
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					return i;
		}
		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_last_of(const char* s, size_t pos) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);
		if (pos >= _length)
			return npos;

		for (size_t i = pos; i >= 0; --i) {
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		char* temp = NULL;

		try {
			temp = new char[n + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < n; ++i)
			temp[i] = s[i];
		temp[n] = '\0';

		size_t tempLen = strlen(temp);

		for (size_t i = pos; i >= 0; --i) {
			for (size_t j = 0; j < tempLen; ++j)
				if (_string[i] == temp[j])
					return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_last_of(char c) const noexcept {
	return rfind(c);
}

size_t MyString::find_last_of(char c, size_t pos) const noexcept {
	return rfind(c, pos);
}

size_t MyString::find_first_not_of(const MyString& otherMyString) const noexcept {
	for (size_t i = 0; i < _length; ++i) {
		bool flag = false;
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				flag = true;

		if (!flag)
			return i;
	}

	return npos;
}

size_t MyString::find_first_not_of(const MyString& otherMyString, size_t pos) const noexcept {
	if (pos >= _length)
		return npos;

	for (size_t i = pos; i < _length; ++i) {
		bool flag = false;
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				flag = true;

		if (!flag)
			return i;
	}

	return npos;
}

size_t MyString::find_first_not_of(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		for (size_t i = 0; i < _length; ++i) {
			bool flag = false;
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					flag = true;

			if (!flag)
				return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_first_not_of(const char* s, size_t pos) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		if (pos >= _length)
			return npos;

		for (size_t i = pos; i < _length; ++i) {
			bool flag = false;
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					flag = true;

			if (!flag)
				return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		char* temp = NULL;

		try {
			temp = new char[n + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = 0; i < n; ++i)
			temp[i] = s[i];

		size_t tempLen = strlen(temp);

		if (pos >= _length)
			return npos;

		for (size_t i = pos; i < _length; ++i) {
			bool flag = false;
			for (size_t j = 0; j < tempLen; ++j)
				if (_string[i] == temp[j])
					flag = true;

			if (!flag)
				return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_first_not_of(char c) const noexcept {
	for (size_t i = 0; i < _length; ++i)
		if (_string[i] != c)
			return i;

	return npos;
}

size_t MyString::find_first_not_of(char c, size_t pos) const noexcept {
	for (size_t i = pos; i < _length; ++i)
		if (_string[i] != c)
			return i;

	return npos;
}

size_t MyString::find_last_not_of(const MyString& otherMyString) const noexcept {
	for (size_t i = _length - 1; i >= 0; --i) {
		bool flag = false;
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				flag = true;

		if (!flag)
			return i;
	}

	return npos;
}

size_t MyString::find_last_not_of(const MyString& otherMyString, size_t pos) const noexcept {
	if (pos >= _length)
		return npos;

	for (size_t i = pos; i >= 0; --i) {
		bool flag = false;
		for (size_t j = 0; j < otherMyString._length; ++j)
			if (_string[i] == otherMyString._string[j])
				flag = true;

		if (!flag)
			return i;
	}

	return npos;
}

size_t MyString::find_last_not_of(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		for (size_t i = _length - 1; i >= 0; --i) {
			bool flag = false;
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					flag = true;

			if (!flag)
				return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_last_not_of(const char* s, size_t pos) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		size_t sLen = strlen(s);

		if (pos >= _length)
			return npos;

		for (size_t i = pos; i >= 0; --i) {
			bool flag = false;
			for (size_t j = 0; j < sLen; ++j)
				if (_string[i] == s[j])
					flag = true;

			if (!flag)
				return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		char* temp = NULL;

		try {
			temp = new char[n + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}
		for (size_t i = 0; i < n; ++i)
			temp[i] = s[i];

		size_t tempLen = strlen(temp);

		if (pos >= _length)
			return npos;

		for (size_t i = pos; i >= 0; --i) {
			bool flag = false;
			for (size_t j = 0; j < tempLen; ++j)
				if (_string[i] == temp[j])
					flag = true;

			if (!flag)
				return i;
		}

		return npos;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

size_t MyString::find_last_not_of(char c) const noexcept {
	for (size_t i = _length - 1; i >= 0; --i) {
		if (_string[i] != c)
			return i;
	}

	return npos;
}

size_t MyString::find_last_not_of(char c, size_t pos) const noexcept {
	if (pos >= _length)
		return npos;

	for (size_t i = pos; i >= 0; --i) {
		if (_string[i] != c)
			return i;
	}

	return npos;
}

//----------------------------SUBSTRING---------------------------------//
MyString MyString::substr(size_t pos) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		MyString temp;

		if (pos == _length)
			return temp;

		temp._length = _length - pos;
		temp._capacity = _capacity;

		try {
			temp._string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = pos; i < _length; ++i)
			temp._string[i - pos] = _string[i];
		temp[temp._length] = '\0';

		return temp;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString MyString::substr(size_t pos, size_t len) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		MyString temp;

		if (pos == _length)
			return temp;

		if (pos + len > _length)
			len = _length - pos;

		temp._length = len;
		temp._capacity = _capacity;

		try {
			temp._string = new char[_capacity + 1];
		}
		catch (const exception& excep) {
			cerr << excep.what() << endl;
			exit(0);
		}

		for (size_t i = pos; i < _length; ++i)
			temp._string[i - pos] = _string[i];
		temp[temp._length] = '\0';

		return temp;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}	
}

//-----------------------------COMPARE----------------------------------//
int MyString::compare(const MyString& otherMyString) const noexcept {
	size_t len = _length > otherMyString._length ? otherMyString._length : _length;
	size_t i = 0;

	while (i < len &&_string[i] == otherMyString._string[i])
		++i;

	if (i == len)
		if (_length == otherMyString._length)
			return 0;
		else if (_length < otherMyString._length)
			return -1;
		else
			return 1;
	else
		if (_string[i] < otherMyString._string[i])
			return -1;
		else
			return 1;
}

int MyString::compare(size_t pos, size_t len, const MyString& otherMyString) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		MyString temp = substr(pos, len);

		return temp.compare(otherMyString);
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

int MyString::compare(size_t pos, size_t len, const MyString& otherMyString, size_t subpos) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		MyString temp1 = substr(pos, len);
		MyString temp2 = otherMyString.substr(subpos);

		return temp1.compare(temp2);
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

int MyString::compare(size_t pos, size_t len, const MyString& otherMyString, size_t subpos, size_t sublen) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (subpos > otherMyString._length)
			throw exception("Out of range: subpos is greater than string's length");

		MyString temp1 = substr(pos, len);
		MyString temp2 = otherMyString.substr(subpos, sublen);

		return temp1.compare(temp2);
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

int MyString::compare(const char* s) const {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp(s);
		return compare(temp);
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

int MyString::compare(size_t pos, size_t len, const char* s) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp1 = substr(pos, len);

		MyString temp2(s);
		return temp1.compare(temp2);
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

int MyString::compare(size_t pos, size_t len, const char* s, size_t n) const {
	try {
		if (pos > _length)
			throw exception("Out of range: pos is greater than string's length");

		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp1 = substr(pos, len);

		MyString temp2(s, n);
		return temp1.compare(temp2);
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

//------------------NON MEMBER FUNCTION OVERLOADS------------------------//
//----------------------------OPERATOR +---------------------------------//
MyString operator+ (const MyString& lhs, const MyString& rhs) {
	MyString temp(lhs);
	return temp += rhs;
}

MyString operator+ (MyString&& lhs, MyString&& rhs) {
	MyString temp(lhs);
	return temp += rhs;
}

MyString operator+ (MyString&& lhs, const MyString& rhs) {
	MyString temp(lhs);
	return temp += rhs;
}

MyString operator+ (const MyString& lhs, MyString&& rhs) {
	MyString temp(lhs);
	return temp += rhs;
}

MyString operator+ (const MyString& lhs, const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp(lhs);
		return temp += s;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString operator+ (MyString&& lhs, const char* s) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp(lhs);
		return temp += s;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString operator+ (const char* s, const MyString& rhs) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp(s);
		return temp += rhs;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString operator+ (const char* s, MyString&& rhs) {
	try {
		if (s == NULL)
			throw exception("Undefined behavior: c-string is a null pointer");

		MyString temp(s);
		return temp += rhs;
	}
	catch (const exception& excep) {
		cerr << excep.what() << endl;
		exit(1);
	}
}

MyString operator+ (const MyString& lhs, char c) {
	MyString temp(lhs);
	return temp += c;
}

MyString operator+ (MyString&& lhs, char c) {
	MyString temp(lhs);
	return temp += c;
}

MyString operator+ (char c, const MyString& rhs) {
	MyString temp(1, c);
	return temp += rhs;
}

MyString operator+ (char c, MyString&& rhs) {
	MyString temp(1, c);
	return temp += rhs;
}

//----------------------RELATIONAL OPERATOR-------------------------------//
bool operator== (const MyString& lhs, const MyString& rhs) noexcept {
	if (lhs.compare(rhs) == 0)
		return true;
	return false;
}

bool operator== (const char* lhs, const MyString& rhs) {
	if (rhs.compare(lhs) == 0)
		return true;
	return false;
}

bool operator== (const MyString& lhs, const char* rhs) {
	if (lhs.compare(rhs) == 0)
		return true;
	return false;
}

bool operator!= (const MyString& lhs, const MyString& rhs) noexcept {
	if (lhs.compare(rhs) != 0)
		return true;
	return false;
}

bool operator!= (const char* lhs, const MyString& rhs) {
	if (rhs.compare(lhs) != 0)
		return true;
	return false;
}

bool operator!= (const MyString& lhs, const char* rhs) {
	if (lhs.compare(rhs) != 0)
		return true;
	return false;
}

bool operator<  (const MyString& lhs, const MyString& rhs) noexcept {
	if (lhs.compare(rhs) == -1)
		return true;
	return false;
}

bool operator<  (const char* lhs, const MyString& rhs) {
	if (rhs.compare(lhs) == 1)
		return true;
	return false;
}

bool operator<  (const MyString& lhs, const char* rhs) {
	if (lhs.compare(rhs) == -1)
		return true;
	return false;
}

bool operator<= (const MyString& lhs, const MyString& rhs) noexcept {
	if (lhs.compare(rhs) == -1 || lhs.compare(rhs) == 0)
		return true;
	return false;
}

bool operator<= (const char* lhs, const MyString& rhs) {
	if (rhs.compare(lhs) == 1 || rhs.compare(lhs) == 0)
		return true;
	return false;
}

bool operator<= (const MyString& lhs, const char* rhs) {
	if (lhs.compare(rhs) == -1 || lhs.compare(rhs) == 0)
		return true;
	return false;
}

bool operator>  (const MyString& lhs, const MyString& rhs) noexcept {
	if (lhs.compare(rhs) == 1)
		return true;
	return false;
}

bool operator>  (const char* lhs, const MyString& rhs) {
	if (rhs.compare(lhs) == -1)
		return true;
	return false;
}

bool operator>  (const MyString& lhs, const char* rhs) {
	if (lhs.compare(rhs) == 1)
		return true;
	return false;
}

bool operator>= (const MyString& lhs, const MyString& rhs) noexcept {
	if (lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0)
		return true;
	return false;
}

bool operator>= (const char* lhs, const MyString& rhs) {
	if (rhs.compare(lhs) == -1 || rhs.compare(lhs) == 0)
		return true;
	return false;
}

bool operator>= (const MyString& lhs, const char* rhs) {
	if (lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0)
		return true;
	return false;
}

//--------------------------------SWAP------------------------------------//
void swap(MyString& lhs, MyString& rhs) {
	MyString temp(lhs);
	lhs = rhs;
	rhs = temp;
}

//-----------------------------OPERATOR >>--------------------------------//
istream& operator >> (istream& in, MyString& myString) {
	myString.clear();
	
	MyString temp(" \t\r\v\n\f");

	char ch;
	myString.clear();
	while (in.get(ch) && temp.find(ch) == myString.npos) {
		myString.push_back(ch);
	}

	return in;
}

//-----------------------------OPERATOR <<--------------------------------//
ostream& operator << (ostream& out, const MyString& myString) {
	if (myString._string != NULL)
		out << myString._string;
	else
		out << '\0';

	return out;
}

//------------------------------GETLINE-----------------------------------//
istream& getline(istream& in, MyString& myString, char delim) {
	char ch;
	myString.clear();
	while (in.get(ch) && ch != delim) {
		myString.push_back(ch);
	}
		
	return in;
}

istream& getline(istream&& in, MyString& myString, char delim) {
	char ch;
	myString.clear();
	while (in.get(ch) && ch != delim) {
		myString.push_back(ch);
	}

	return in;
}

istream& getline(istream& in, MyString& myString) {
	char ch;
	myString.clear();
	while (in.get(ch) && ch != '\n') {
		myString.push_back(ch);
	}

	return in;
}

istream& getline(istream&& in, MyString& myString) {
	char ch;
	myString.clear();
	while (in.get(ch) && ch != '\n') {
		myString.push_back(ch);
	}

	return in;
}