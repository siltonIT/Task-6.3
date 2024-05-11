#include "Taxi.h"

Taxi::Taxi(): Transport() {}

Taxi::Taxi(Point start, Point end, size_t time, double price): Transport(start, end, time, price) {}

Move* Taxi::clone() const {
        return new Taxi(*this); 
}

void Taxi::print() const {
        std::cout << "Taxi" << std::endl;                                                                
        std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
        std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;                                                                                                        
        std::cout << "Price: " << _price << " rub" << std::endl;                  
        std::cout << "Route time: " << _time << " minutes" << std::endl; 
}

std::string Taxi::get_fields() const {
        std::string info = "Taxi"; 
        info += '\n' + std::to_string(_start._x) + ' ' + std::to_string(_start._y) + '\n'; 
        info += std::to_string(_end._x) + ' ' + std::to_string(_end._y) + '\n'; 
        info += std::to_string(_time) + '\n';
        info += std::to_string(_price) + '\n';
        
        return info;
}
