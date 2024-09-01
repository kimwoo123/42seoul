#include "Span.hpp"

Span::Span(void) {}

Span::~Span(void) {}

Span::Span(unsigned int size) {
	this->array_.reserve(size);
	this->size_ = size;
}

Span::Span(const Span& s) {
	*this = s;
}

Span& Span::operator=(const Span& s) {
	if (this != &s) {
		this->array_ = s.array_;
		this->size_ = s.size_;
	}
	return *this;
}

void	Span::addNumber(int number) {
	if (this->array_.size() < this->size_)
		this->array_.push_back(number);
	else
		throw ContainerIsFull();
}

void	Span::addNumberIter(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	std::vector<int>	v(first, last);

	for (; first< last; ++first) {
		if (this->size_ <= this->array_.size())
			throw ContainerIsFull();
		this->addNumber(*first);
	}
}

int	Span::shortestSpan(void) {
	if (this->array_.size() < 2)
		throw ContainerIsSmall();
	std::sort(this->array_.begin(), this->array_.end());
	std::vector<int>::iterator	s = this->array_.begin();
	std::vector<int>::iterator	e = this->array_.end();
	int	result = *(s + 1) - *s;
	int diff = 0;
	for (++s; s < e; ++s) {
		diff = *(s) - *(s - 1);
		if (diff < result)
			result = diff;
	}
	return result;
}

int	Span::longestSpan(void) {
	if (this->array_.size() < 2)
		throw ContainerIsSmall();
	
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	
	min = std::min_element(this->array_.begin(), this->array_.end());
	max = std::max_element(this->array_.begin(), this->array_.end());
	return *max - *min;
}
