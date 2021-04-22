#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace ariel {

    NumberWithUnits::NumberWithUnits(double amount, const std::string& unit){ //constructor
        this->amount=amount;
        this->unit=unit;
    }

    void NumberWithUnits::read_units(ifstream& units_file){}

    //Input & Output operators
    std::ostream& operator<<(std::ostream& out, const NumberWithUnits& u){
       return out << u.amount << "[" << u.unit << "]";
    }

    std::istream& operator>>(std::istream& in, NumberWithUnits& u){
        string str;
        return in >> u.amount >> str >> u.unit;
    }

    //Arithmetic operation:
    //Plus & Minus operators
    NumberWithUnits operator+(const NumberWithUnits& u1, const NumberWithUnits& u2){ 
        return u1;
    }

    NumberWithUnits operator+(const NumberWithUnits& u1, double n){ 
        return u1;
    }        

    NumberWithUnits operator-(const NumberWithUnits& u1, const NumberWithUnits& u2){ 
        return u1;
    }

    NumberWithUnits operator-(const NumberWithUnits& u1, double n){ 
        return u1;
    }

    //Unary
    NumberWithUnits operator+(const NumberWithUnits& u1){ 
        return u1;
    }

    NumberWithUnits operator-(const NumberWithUnits& u1){ 
        return u1;
    }

    //Compound operators
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& u1){
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& u1){
        return *this;
    }

    NumberWithUnits operator*=(NumberWithUnits& u1, double n){ 
        return u1;
    }

    NumberWithUnits operator*=(double n, NumberWithUnits& u1){ 
        return u1;
    }

    //Mul operator
    NumberWithUnits operator*(NumberWithUnits& u1, double n){ 
        return u1;
    }

    NumberWithUnits operator*(double n, NumberWithUnits& u1){ 
        return u1;
    }

    //Increase & Decrease operators
    NumberWithUnits& NumberWithUnits::operator++(){ //prefix ++a
        return *this;
    } 

    NumberWithUnits& NumberWithUnits::operator--(){ //prefix --a
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int){ //postfix a++ 
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator--(int) { //postfix a--
        return *this;
    }

    //Comparison operators
    bool operator>(const NumberWithUnits& u1, const NumberWithUnits& u2){
        return true;
    }

    bool operator<(const NumberWithUnits& u1, const NumberWithUnits& u2){
        return true;
    }

    bool operator>=(const NumberWithUnits& u1, const NumberWithUnits& u2){
        return true;
    }

    bool operator<=(const NumberWithUnits& u1, const NumberWithUnits& u2){
        return true;
    }

    bool operator==(const NumberWithUnits& u1, const NumberWithUnits& u2){
        return true;
    }

    bool operator!=(const NumberWithUnits& u1, const NumberWithUnits& u2){
        return true;
    }
}