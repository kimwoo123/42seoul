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
		void	setRawBits(const int raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float 	toFloat(void) const;

	private:
		int					number_;
		static const int	fraction_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
