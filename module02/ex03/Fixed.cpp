#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(void){
    this->_value = 0;
}

Fixed::Fixed(const int i){
    this->_value = i * (1 << _fract);
}

Fixed::Fixed(const float i){
    this->_value = i * (1 << _fract);
}

Fixed::Fixed(const Fixed &copy){
    _value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original){
    this->setRawBits(original.getRawBits());
    return *this;
}

Fixed::~Fixed(void){}

std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
    os << number.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& number)
{
    return _value > number.getRawBits();
}

bool Fixed::operator<(const Fixed& number)
{
    return _value < number.getRawBits();
}

bool Fixed::operator>=(const Fixed& number)
{
    return _value >= number.getRawBits();
}

bool Fixed::operator<=(const Fixed& number)
{
    return _value <= number.getRawBits();
}

bool Fixed::operator==(const Fixed& number)
{
    return _value == number.getRawBits();
}

bool Fixed::operator!=(const Fixed& number)
{
    return _value != number.getRawBits();
}

Fixed Fixed::operator+(const Fixed& number)
{
    return Fixed(toFloat() + number.toFloat());
}

Fixed Fixed::operator-(const Fixed& number)
{
    return Fixed(toFloat() - number.toFloat());
}

Fixed Fixed::operator*(const Fixed& number)
{
    return Fixed(toFloat() * number.toFloat());
}

Fixed Fixed::operator/(const Fixed& number)
{
    return Fixed(toFloat() / number.toFloat());
}

Fixed Fixed::operator++(int)
{
    Fixed aux(_value * toFloat());
    _value += 1;
    return aux;
}

Fixed& Fixed::operator++(void)
{
    _value += 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed aux(_value * toFloat());
    _value -= 1;
    return aux;
}


int     Fixed::getRawBits(void) const{
    return (_value);
}

void    Fixed::setRawBits(int const raw){
    _value = raw;
}

float   Fixed::toFloat(void) const{
    return ((float)_value / (1 << _fract));
}

int   Fixed::toInt(void) const{
    return (_value >> _fract);
}

Fixed&  Fixed::min(Fixed& a,Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed&  Fixed::max(Fixed& a,Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}