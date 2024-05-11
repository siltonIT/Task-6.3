#pragma once

#include <utility>
#include <fstream>
#include "Move.h"
#include "Walk.h"
#include "Bus.h"
#include "Taxi.h"
#include "Trolley.h"
#include "Car.h"
#include "Metro.h"

#define size_t unsigned int

class Array {
public:
	Array();

	Array(const Array&);

	Array& operator=(Array);

	Array(Array&&) noexcept;

	Array& operator=(Array&&) noexcept;

	void swap(Array&) noexcept;

	~Array();
	
	template<typename T>
	void push_back(const T& data) {
		if(_size >= _capacity)
			resize();
		
		if(_seq == nullptr)
			_seq = new Move*[_capacity];

		Move* move = new T(data);
		_seq[_size++] = move;
	}

	void export_to_file(const std::string&) const;

	void import_from_file(const std::string&);

	void pop_back();

	void print() const;

	void clear();

	Move*& operator[](const size_t&);

	size_t size() const;

	size_t capacity() const;

private:
	void resize();

	size_t _capacity;
	size_t _size;
	Move** _seq;
};
