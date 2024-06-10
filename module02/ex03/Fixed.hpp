#ifndef FIXED_CPP
#define FIXED_CPP

#include <iostream>
#include <cmath>

class Fixed{

    private :
        int     _value;
        static const int _fract;

    public :
        Fixed(void);
        Fixed(const int);
        Fixed(const float);
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed& original);
        ~Fixed(void);
        bool operator>(const Fixed& number);
        bool operator<(const Fixed& number);
        bool operator>=(const Fixed& number);
        bool operator<=(const Fixed& number);
        bool operator==(const Fixed& number);
        bool operator!=(const Fixed& number);
        Fixed operator+(const Fixed& number);
        Fixed operator-(const Fixed& number);
        Fixed operator*(const Fixed& number);
        Fixed operator/(const Fixed& number);
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        int getRawBits( void ) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        
};

std::ostream &operator<<(std::ostream &os, const Fixed &number);

#endif