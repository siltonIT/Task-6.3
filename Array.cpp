#include "Array.h"

Array::Array(): _capacity(1), _size(0), _seq(nullptr) {}

Array::Array(const Array& other): _capacity(other._capacity), _size(other._size), _seq(new Move*[_capacity]) {	
	for(size_t i = 0; i < other._size; ++i)
		_seq[i] = other._seq[i]->clone();
}

Array& Array::operator=(Array other) {
	Array res(other);
	swap(res);

	return *this;
}

Array::Array(Array&& other) noexcept: _capacity(other._capacity), _size(other._size), _seq(other._seq) {
	other._capacity = 1;
	other._size = 0;
	other._seq = nullptr;
}

Array& Array::operator=(Array&& other) noexcept {
	Array res(std::move(other));
	swap(res);

	return *this;
}	

void Array::swap(Array& other) noexcept {
	std::swap(_capacity, other._capacity);
	std::swap(_size, other._size);
	std::swap(_seq, other._seq);
}

Array::~Array() {
	clear();
}

void Array::export_to_file(const std::string& export_path) const {
	std::ofstream out(export_path, std::ios::out);
	if(!out.is_open())
		return;

	out << _size << '\n';
	for(size_t i = 0; i < _size; ++i)
		out << _seq[i]->get_fields();

	out.close();
}

void Array::import_from_file(const std::string& import_path) {
	std::ifstream in(import_path, std::ios::in);
	if(!in.is_open())
		return;

	in >> _capacity;
	delete[] _seq;
	_size = 0;
	_seq = new Move*[++_capacity];


	double x = 0, y = 0;
	size_t time = 0;
	double price = 0;
	while(!in.eof()) {
		std::string object_type;
		in >> object_type;

		if(object_type == "Walk") {
			in >> x >> y;
			Point start(x, y);
			in >> x >> y;
			Point end(x, y);
			in >> time;

			Move* move = new Walk(start, end, time);
			_seq[_size++] = move;
		} else if(object_type == "Bus") {
			in >> x >> y;
			Point start(x, y);
			in >> x >> y;
			Point end(x, y);
			in >> time >> price;

			Move* move = new Bus(start, end, time, price);
			_seq[_size++] = move;
		} else if(object_type == "Metro") {
			in >> x >> y;
			Point start(x, y);
			in >> x >> y;
			Point end(x, y);
			in >> time >> price;

			Move* move = new Metro(start, end, time, price);
			_seq[_size++] = move;
		} else if(object_type == "Trolley") {
			in >> x >> y;
			Point start(x, y);
			in >> x >> y;
			Point end(x, y);
			in >> time >> price;

			Move* move = new Trolley(start, end, time, price);
			_seq[_size++] = move;
		} else if(object_type == "Taxi") {
			in >> x >> y;
			Point start(x, y);
			in >> x >> y;
			Point end(x, y);
			in >> time >> price;

			Move* move = new Taxi(start, end, time, price);
			_seq[_size++] = move;
		} else if (object_type == "Car") {
			in >> x >> y;
			Point start(x, y);
			in >> x >> y;
			Point end(x, y);
			std::string website;
			in >> time >> price >> website;
			
			char* path = new char[website.size()];
			for(size_t i = 0; i < website.size(); ++i) 
				path[i] = website[i];
			
			Move* move = new Car(start, end, time, price, path);
			_seq[_size++] = move;
		}
	}
}

void Array::pop_back() {
	--_size;
}

void Array::print() const {
	for(size_t i = 0; i < _size; ++i) {
		_seq[i]->print();
		std::cout << std::endl;
	}
}

void Array::clear() {
	if(_seq != nullptr)
		delete[] _seq;

	_seq = nullptr;
	_capacity = 1;
	_size = 0;
}

Move*& Array::operator[](const size_t& ind) {
	return _seq[ind];
}

size_t Array::size() const {
	return _size;
}

size_t Array::capacity() const {
	return _capacity;
}

void Array::resize() {
	size_t new_capacity = _capacity * 2;
	Move** new_seq = new Move*[_capacity];
	
	for(size_t i = 0; i < _capacity; ++i) {
		new_seq[i] = _seq[i];
		_seq[i] = nullptr;
		delete _seq[i];
	}

	delete[] _seq;
	_capacity = new_capacity;
	_seq = new_seq;
}
