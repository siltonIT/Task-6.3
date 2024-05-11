#include "Car.h"

Car::Car(): Transport(), _path(nullptr) {}

Car::Car(Point start, Point end, size_t time, double price, char* path): Transport(start, end, time, price), _path(nullptr) {
	size_t size = 0;
	while(path[size++] != 0);

	_path = new char[size];
	for(size_t i = 0; i < size; ++i)
		_path[i] = path[i];
}

Car::Car(const Car& other): Transport(other._start, other._end, other._time, other._price), _path(nullptr) {
	size_t size = 0;
	while(other._path[size++] != 0);

	_path = new char[size];
	for(size_t i = 0; i < size; ++i)
		_path[i] = other._path[i];
}

Car::~Car() {
	delete[] _path;
}

Move* Car::clone() const {
        return new Car(*this); 
}

void Car::print() const {
        std::cout << "Car" << std::endl;
	std::cout << "Website: " << _path << std::endl;
        std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
        std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;                                                                                                        
        std::cout << "Price: " << _price << " rub" << std::endl;                  
        std::cout << "Route time: " << _time << " minutes" << std::endl; 
}

std::string Car::get_fields() const {
        std::string info = "Car"; 
        info += '\n' + std::to_string(_start._x) + ' ' + std::to_string(_start._y) + '\n'; 
        info += std::to_string(_end._x) + ' ' + std::to_string(_end._y) + '\n'; 
        info += std::to_string(_time) + '\n';
        info += std::to_string(_price) + '\n';
 
	for(size_t i = 0; _path[i] != 0; ++i)
		info += _path[i];
	
	info += '\n';

        return info;
}

char* Car::get_path() const {
	return _path;
}

void Car::set_path(char*& path) {
	_path = path;
}
