#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

/// Implementation for complex numbers in C++
/// https://en.wikipedia.org/wiki/Complex_number

// Used for operator>> & operator<<
#include <iostream>
// Used for M_PI, sqrt & atan
#include <cmath>

// Incapsulation of the complex number ( real part , imaginary part )
class complex
{
    long double re; // re: real part of the complex number
    long double im; // im: imaginary part of the complex number

public:

    // By convention, I chose that the real and imaginary part of the
    // complex number to be 0 in the default constructor
    complex():re(0),im(0){}

    // By convention, I chose for the real part of the complex number
    // to be initialized with the value x, and the imaginary part of
    // the complex number to be initialized with 0 through the one-parameter constructor (x)
    complex(const long double&x):re(x),im(0){}

    // By convention, I chose for the real part of the complex number
    // to be initialized with the value of x, and the imaginary part
    // of the complex number to be initialized with the value of y through the constructor with two parameters (x,y)
    complex(const long double &x, const long double &y):re(x),im(y){}

    // Through the copy constructor we initialized the value of the current object with the value of the complex number n
    complex(const complex &n):re(n.re),im(n.im){}

    // Similar procedures were applied for the move constructor
    complex(complex &&n):re(n.re),im(n.im){}

    // The destructor is default due to no dynamic allocation
    ~complex()=default;

    // The current complex number is set equal to complex number n using the operator=
    complex &operator=(const complex &n)
    {
        re = n.re;
        im = n.im;
        return *this;
    }

    // Subtract complex number n from the current complex number using the operator-
    complex operator-(const complex &n) const
    {
        return complex(re - n.re,im - n.im);
    }

    // Subtract complex number n from the current complex number using the operator-=
    complex& operator-=(const complex &n)
    {
        re = re - n.re;
        im = im - n.im;
        return *this;
    }

    // Using the operator+, add the current complex number to complex number n
    complex operator+(const complex &n) const
    {
        return complex(re+n.re,im+n.im);
    }

    // Using the operator+=, add the current complex number to complex number n
    complex& operator+=(const complex &n)
    {
        re = re + n.re;
        im = im + n.im;
        return *this;
    }

    // Using the operator*, multiply the current complex number by complex number n
    complex operator*(const complex &n) const
    {
        return complex(re * n.re - im * n.im,re * n.im + im * n.re);
    }

    // Using the operator*=, multiply the current complex number by complex number n
    complex &operator*=(const complex &n)
    {
        long double i = re * n.im + im * n.re; // i: Calculation of the imaginary part
        re = re * n.re - im * n.im;
        im = i;
        return *this;
    }

    // Using the operator/, divide the current complex number by complex number n
    complex operator/(const complex &n) const
    {
        return complex( ( re*n.re + im*n.im ) / ( n.re*n.re + n.im*n.im ) , ( im*n.re - re*n.im ) / ( n.re*n.re + n.im*n.im ) );
    }

    // Using the operator/, divide the current complex number by complex number n
    complex &operator/=(const complex &n)
    {
        long double i = ( im*n.re - re*n.im ) / ( n.re*n.re + n.im*n.im ); // i: Calculation of the imaginary part
        re = ( re*n.re + im*n.im ) / ( n.re*n.re + n.im*n.im );
        im = i;
        return *this;
    }

    // Using the operator~, conjugate the current complex number
    complex operator~() const
    {
        return complex(re,-im);
    }

    /// Operations with real constants (using class operators)
    // Real numbers are complex numbers with the imaginary part equal to 0

    // The current complex number is assigned (is equated to) the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z=c
    complex &operator=(const long double &c)
    {
        re = c;
        im = 0;
        return *this;
    }

    // Multiplication between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z*c
    complex operator*(const long double &c) const
    {
        return complex(re*c,im*c);
    }

    // Multiplication between the real constant c and the current complex number
    // For example: Let n be a complex number and c be a real number, resulting in the operation c*n
    friend complex operator*(const long double &c, const complex &n)
    {
        return n*c;
    }

    // Multiplication between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z*=c
    complex &operator*=(const long double &c)
    {
        re = c * re;
        im = c * im;
        return *this;
    }

    // Division between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z/c
    complex operator/(const long double &c) const
    {
        return complex(re/c,im/c);
    }

    // Division between the real constant c and the current complex number
    // For example: Let n be a complex number and c be a real number, resulting in the operation c/n
    friend complex operator/(const long double &c, const complex &n)
    {
        return complex( ( c*n.re ) / ( n.re*n.re + n.im*n.im ) , ( -n.im*c ) / ( n.re*n.re + n.im*n.im ) );
    }

    // Division between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z/=c
    complex &operator/=(const long double &c)
    {
        re = re / c;
        im = im / c;
        return *this;
    }

    // Addition between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z+c
    complex operator+(const long double &c) const
    {
        return complex(re+c,im);
    }

    // Addition between the real constant c and the current complex number
    // For example: Let n be a complex number and c be a real number, resulting in the operation c+n
    friend complex operator+(const long double &c,const complex &n)
    {
        return complex(n.re+c,n.im);
    }

    // Addition between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z+=c
    complex &operator+=(const long double &c)
    {
        re = re + c;
        return *this;
    }

    // Subtraction between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z-c
    complex operator-(const long double &c) const
    {
        return complex(re-c,im);
    }

    // Subtraction between the real constant c and the current complex number
    // For example: Let n be a complex number and c be a real number, resulting in the operation c-n
    friend complex operator-(const long double &c,const complex &n)
    {
        return complex(c-n.re,-n.im);
    }

    // Subtraction between the current complex number and the real constant c
    // For example: Let z be a complex number and c be a real number, resulting in the operation z-=c
    complex &operator-=(const long double &c)
    {
        re = re - c;
        return *this;
    }

    // Displaying a complex number
    friend std::ostream& operator<<(std::ostream&,const complex&);

    // Reading a complex number
    // Example: 11 12 | where 11 represents the real part of the complex number, and 12 represents the imaginary part
    friend std::istream& operator>>(std::istream&, complex&);

    // The modulus of the current complex number
    const long double abs() const
    {
        return std::sqrt(re*re+im*im);
    }

    // The argument of the current complex number
    const long double arg() const
    {
        if( im != 0 || re > 0 )
            return 2*std::atan( im / ( re + std::sqrt( re*re+im*im ) ) );
        if( re < 0 )
            return M_PI;
        std::cout<<"undefined";
        return 0;
    }

    // The conjugation of the current complex number
    void conjugate()
    {
        im = -im;
    }

    // Modify the real part of the current complex number using a setter
    void setReal(const long double &real)
    {
        re = real;
    }

    // Modify the imaginary part of the current complex number using a setter
    void setImaginary(const long double &imaginary)
    {
        im = imaginary;
    }

    // Receive the real part of the current complex number through a getter
    long double getReal() const
    {
        return re;
    }

    // Receive the imaginary part of the current complex number through a getter
    long double getImaginary() const
    {
        return im;
    }

    // The square root of the current complex number
    complex sqrt() const
    {
        return complex( std::sqrt( (re + abs())/2 ) , std::sqrt( (re + abs())/2 ));
    }

    /// Implementing logical operators for addition, multiplication, comparison, etc.
    /// between two complex numbers

    // Compare the current complex number with complex number n, resulting in the logical operation ==
    bool operator==(const complex &n) const
    {
        return ( re == n.re ) && ( im == n.im );
    }

    // Compare the current complex number with complex number n, resulting in the logical operation !=
    bool operator!=(const complex &n) const
    {
        return ( re != n.re ) || ( im != n.im );
    }

    // Compare the current complex number with complex number n, resulting in the logical operation >
    bool operator>(const complex &n) const
    {
        long double absValueThis = abs();
        long double absValueN = n.abs();
        if( absValueThis > absValueN )
            return true;
        if( absValueThis == absValueN )
        {
            if( re > n.re )
                return true;
            if( re == n.re )
            {
                if( im > n.im )
                    return true;
            }
        }
        return false;
    }

    // Compare the current complex number with complex number n, resulting in the logical operation >=
    bool operator>=(const complex &n) const
    {
        return abs() >= n.abs();
    }

    // Compare the current complex number with complex number n, resulting in the logical operation <
    bool operator<(const complex &n) const
    {
        long double absValueThis = abs();
        long double absValueN = n.abs();
        if( absValueThis < absValueN )
            return true;
        if( absValueThis == absValueN )
        {
            if( re < n.re )
                return true;
            if( re == n.re )
            {
                if( im < n.im )
                    return true;
            }
        }
        return false;
    }

    // Compare the current complex number with complex number n, resulting in the logical operation <=
    bool operator<=(const complex &n) const
    {
        return abs() <= n.abs();
    }

    /// Implementation of logical operators for addition, multiplication, comparison, etc.
    /// between a complex number and a real number
    //  For example: Let z be a complex number and c be a real number, resulting in operations
    //  like z==c, z!=c, z>c, etc.

    // z == c
    bool operator==(const long double &c) const
    {
        return ( re == c ) && ( im == 0 );
    }

    // z != c
    bool operator!=(const long double &c) const
    {
        return ( re != c ) || ( im != 0 );
    }

    // z > c
    bool operator>(const long double &c) const
    {
        long double absValue = abs();
        long double absValueC = c>0?c:-c;
        if( absValue > absValueC )
            return true;
        if( absValue == absValueC )
        {
            if( re > c )
                return true;
            if( re == c )
            {
                if( im > 0)
                    return true;
            }
        }
        return false;
    }

    // z >= c
    bool operator>=(const long double &c) const
    {
        return ( re >= c ) && ( im >= 0 );
    }

    // z < c
    bool operator<(const long double &c) const
    {
        long double absValue = abs();
        long double absValueC = c>0?c:-c;
        if( absValue < absValueC )
            return true;
        if( absValue == absValueC )
        {
            if( re < c )
                return true;
            if( re == c)
            {
                if( im < 0)
                    return true;
            }
        }
        return false;
    }

    // z <= c
    bool operator<=(const long double &c) const
    {
        return ( re <= c ) && ( im <= 0 );
    }

    /// Implementation of logical operators for addition, multiplication, comparison, etc.
    /// between a real number and a complex number
    //  For example: Let n be a complex number and c be a real number, resulting in operations
    //  like c==n, c!=n, c>n, etc.

    // c == n
    friend bool operator==(const long double &c, const complex &n)
    {
        return ( n.re == c ) && ( n.im == 0 );
    }

    // c != n
    friend bool operator!=(const long double &c, const complex &n)
    {
        return ( n.re != c ) || ( n.im != 0 );
    }

    // c > n
    friend bool operator>(const long double &c, const complex &n)
    {
        long double absValueN = n.abs();
        long double absValueC = c>0?c:-c;
        if( absValueC > absValueN )
            return true;
        if( absValueC == absValueN )
        {
            if( c > n.re )
                return true;
            if( c == n.re )
            {
                if( 0 > n.im )
                    return true;
            }
        }
        return false;
    }

    // c >= n
    friend bool operator>=(long double c, const complex &n)
    {
        c = c > 0 ? c : -c;
        return ( c >= n.abs() );
    }

    // c < n
    friend bool operator<(const long double &c, const complex &n)
    {
        long double absValueN = n.abs();
        long double absValueC = c>0?c:-c;
        if( absValueC < absValueN )
            return true;
        if( absValueC == absValueN )
        {
            if( c < n.re )
                return true;
            if( c == n.re )
            {
                if( 0 < n.im )
                    return true;
            }
        }
        return false;
    }

    // c <= n
    friend bool operator<=(long double c, const complex &n)
    {
        c = c > 0 ? c : -c;
        return ( c <= n.abs() );
    }
};

std::ostream& operator<<(std::ostream& os, const complex &n)
{
    if( n.re == 0 )
    {
        if( n.im == -1 )
        {
            os<<"-j";
            return os;
        }
        if( n.im == 1 )
        {
            os<<"j";
            return os;
        }
        if( n.im == 0 )
        {
            os<<0;
            return os;
        }
        os<<n.im<<"j";
        return os;
    }
    if( n.im == 0 )
    {
        os<<n.re;
        return os;
    }
    if( n.im > 0)
    {
        if( n.im == 1 )
        {
            os<<n.re<<"+j";
            return os;
        }
        os<<n.re<<"+"<<n.im<<"j";
        return os;
    }
    if( n.im == -1 )
    {
        os<<n.re<<"-j";
        return os;
    }
    os<<n.re<<n.im<<"j";

    return os;
}

std::istream& operator>>(std::istream& is, complex &n)
{
    is>>n.re>>n.im;

    return is;
}

#endif // COMPLEX_H_INCLUDED
