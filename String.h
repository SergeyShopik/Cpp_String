#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class String
{
public:
	String();
	String(const char*);
	String(char);
	String(const String&);
	~String();

	size_t getSize() { return size; };
	size_t getCapacity() { return capacity; };

	String& operator=(const String&);
	String& operator=(const char);
	String& operator=(const char*);

	String operator+(const String&) const;
	String& operator+=(const String&);

	bool operator<(const String&) const;
	bool operator<=(const String&) const;
	bool operator>(const String&) const;
	bool operator>=(const String&) const;
	bool operator==(const String&) const;
	bool operator!=(const String&) const;

	char& operator[](size_t);
	const char& operator[](size_t) const;

	String& erase(size_t, size_t);

	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);

private:
	size_t capacity;
	size_t size;
	char* data;

	bool checkMem();
};