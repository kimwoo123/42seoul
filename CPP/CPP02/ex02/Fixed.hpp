#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& fixed);
		~Fixed(void);
		Fixed& operator=(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		static const Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
		void	setRawBits(const int raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float 	toFloat(void) const;

	private:
		int					number_;
		static const int	fraction_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
