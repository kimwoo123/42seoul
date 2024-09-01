#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

enum levels
{
	LEVEL_DEBUG,
	LEVEL_INFO,
	LEVEL_WARNING,
	LEVEL_ERROR
};

class	Harl
{
	public:
		void	filter( std::string level );
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

typedef void (Harl::*HarlMemFn[])();
#endif
