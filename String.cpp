#include"String.h"

String::String() : capacity(1), size(0), data(new char[1]) { data[0] = '\0'; }
String::~String() { delete[]data; }
String::String(const char* str) : capacity(strlen(str) + 1), size(strlen(str)), data(new char[size + 1]) { strcpy(data, str); }
String::String(char ch) : capacity(2), size(1), data(new char[size + 1])
{
	this->data[0] = ch;
	this->data[1] = '\0';
}
String::String(const String& s)
{
	this->size = s.size;
	this->capacity = s.capacity;
	this->data = new char[capacity + 1];
	strcpy(data, s.data);
}

String& String::operator=(const String& s)
{
	if (this != &s)
	{
		delete[]this->data;
		this->size = s.size;
		this->capacity = s.capacity;
		this->data = new char[this->size + 1];
		strcpy(this->data, s.data);
	}
	return *this;
}
String& String::operator=(const char ch)
{	
	if (*this != ch)
	{
		delete[]this->data;
		this->size = 1;
		this->capacity = 2;
		this->data = new char[this->size + 1];
		memcpy(this->data, &ch, 1);
		this->data[1] = '\0';
	}
	return *this;
}
String& String::operator=(const char* str)
{
	delete[]data;
	size = strlen(str);
	data = new char[size + 1];
	strcpy(data, str);

	return *this;
}

String String::operator+(const String& s) const
{
	char* temp = new char[this->size + s.size];

	strcpy(temp, this->data);
	strcat(temp, s.data);

	return String(temp);
}
String& String::operator+=(const String& s)
{
	this->size += s.size;

	if (checkMem())
	{
		this->capacity = this->size * 2;
		char* temp = new char[this->capacity];
		strcpy(temp, this->data);
		strcat(temp, s.data);

		delete[]this->data;

		this->data = temp;
	}
	else
	{
		strcat(this->data, s.data);
	}

	return *this;
}

bool String::operator!=(const String& s) const
{
	if (this->size != s.size)
		return true;
	for (size_t i = 0; i < s.size; i++)
	{
		if (this->data[i] != s.data[i])
			return true;
	}

	return false;
}

char& String::operator[](size_t position)
{
	if (position > size)
	{
		std::cout << "Wrong index.\n";
		exit(0);
	}
	for (size_t i = 0; i < size; i++)
	{
		if (i == position)
			return data[i];
	}
}
const char& String::operator[](size_t position) const
{
	if (position > size)
	{
		std::cout << "Wrong index.\n";
		exit(0);
	}
	for (size_t i = 0; i < size; i++)
	{
		if (i == position)
			return data[i];
	}
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.data;
	return out;
}
std::istream& operator>>(std::istream& in, String& s)
{
	char str[255];
	in >> str;

	s.size = strlen(str) + 1;
	delete[]s.data;
	s.data = new char[s.size];
	strcpy(s.data, str);

	return in;
}

String& String::erase(size_t pos, size_t count)
{
	if (pos > this->size)
	{
		std::cout << "Wrong position.\n";
		return *this;
	}
	if (pos + count - this->size >= 0)
	{
		this->data[pos] = '\0';
		this->size = pos;
		return *this;
	}
	memcpy(this->data + pos, this->data + pos + count, this->size - count - pos + 1);
	this->size -= count;

	return *this;
}

bool String::checkMem()
{
	if (getSize() + 1 < getCapacity())
		return false;

	return true;
}