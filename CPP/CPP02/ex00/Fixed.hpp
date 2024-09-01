#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& fixed);
		~Fixed(void);
		Fixed& operator=(const Fixed& fixed);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					number_;
		static const int	fraction_ = 8;
};
#endif
