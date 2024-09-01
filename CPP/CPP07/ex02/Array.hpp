#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstring>

template <typename T>
class Array {
	public:
		Array(void);
		Array(size_t size);
		~Array(void);
		Array(Array<T> const&);
		Array<T>&	operator=(const Array<T>& a);
		T&	operator[](size_t i);
		const T&	operator[](size_t i) const;

		size_t	size(void) const;
		void	printArray(void) const;
	
	private:
		size_t	size_;
		T*	array_;
};

template <typename T>
Array<T>::Array(void) {
	this->array_ = new T[0];
	this->size_ = 0;
}

template <typename T>
Array<T>::Array(size_t size) {
	T*	init = new T();

	this->array_ = new T[size];
	this->size_ = size;
	for (size_t i = 0; i < size; ++i) {
		this->array_[i] = *init;	
	}
	delete init;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] this->array_;
}

template <typename T>
Array<T>::Array(const Array& a) {
	this->size_ = a.size_;
	this->array_ = new T[this->size_];
	for (size_t i = 0; i < this->size_; ++i) {
		this->array_[i] = a.array_[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& a) {
	if (this != &a) {
		if (this->array_ != NULL)
			delete[] this->array_;
		this->size_ = a.size_;
		this->array_ = new T[this->size_];
		for (size_t i = 0; i < this->size_; ++i) {
			this->array_[i] = a.array_[i];
		}
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](size_t i) {
	if (i >= this->size_)
		throw std::out_of_range("Index is out of range.");
	return this->array_[i];
}

template <typename T>
const T&	Array<T>::operator[](size_t i) const {
	if (i >= this->size_)
		throw std::out_of_range("Index is out of range.");
	return this->array_[i];
}

template <typename T>
size_t	Array<T>::size(void) const {
	return this->size_;
}

template <typename T>
void	Array<T>::printArray(void) const {
	for (size_t i = 0; i < this->size_; ++i) {
		if (i != this->size_ - 1)
			std::cout << this->array_[i] << " - ";
		else
			std::cout << this->array_[i];
	}
}

template <typename T>
std::ostream&	operator<<(std::ostream& o, const Array<T>& a) {
	a.printArray();
	return o;
}

#endif
