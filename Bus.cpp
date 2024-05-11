#include "Bus.h"

Bus::Bus(): Transport() {}

Bus::Bus(Point start, Point end, size_t time, double price): Transport(start, end, time, price) {}

Move* Bus::clone() const {
	return new Bus(*this);
}

void Bus::print() const {
	std::cout << "Bus" << std::endl;
        std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
        std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;
	std::cout << "Price: " << _price << " rub" << std::endl;
        std::cout << "Route time: " << _time << " minutes" << std::endl;
}

std::string Bus::get_fields() const {
        std::string info = "Bus"; 
        info += '\n' + std::to_string(_start._x) + ' ' + std::to_string(_start._y) + '\n'; 
        info += std::to_string(_end._x) + ' ' + std::to_string(_end._y) + '\n'; 
        info += std::to_string(_time) + '\n';
        info += std::to_string(_price) + '\n';
        
        return info;
}
