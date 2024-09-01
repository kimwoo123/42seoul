#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <string>
# include <iostream>

struct Data {
	int	id_;
	std::string	name_;
};

class Serializer {
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer& s);
		Serializer& operator=(const Serializer& s);
		~Serializer(void);
};
#endif
