#include "Metro.h"

Metro::Metro(): Transport() {}

Metro::Metro(Point start, Point end, size_t time, double price): Transport(start, end, time, price) {}

Move* Metro::clone() const {
        return new Metro(*this); 
}

void Metro::print() const {
	std::cout << "Metro" << std::endl;                                                                
        std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
        std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;                                                                                                        
        std::cout << "Price: " << _price << " rub" << std::endl;                  
        std::cout << "Route time: " << _time << " minutes" << std::endl; 
}

std::string Metro::get_fields() const {
        std::string info = "Metro"; 
        info += '\n' + std::to_string(_start._x) + ' ' + std::to_string(_start._y) + '\n'; 
        info += std::to_string(_end._x) + ' ' + std::to_string(_end._y) + '\n'; 
        info += std::to_string(_time) + '\n';
        info += std::to_string(_price) + '\n';
        
        return info;
}
