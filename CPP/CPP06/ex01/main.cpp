#include "Serializer.hpp"

int main() {
	Data*	data = new Data;

	data->id_ = 10021049;
	data->name_ = "Wooseok";

	std::cout << "Before" << std::endl;
	std::cout << "id: " <<  data->id_ << " name: " << data->name_ << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	Data*	newData = Serializer::deserialize(raw);

	std::cout << "After" << std::endl;
	std::cout << "id: " <<  newData->id_ << " name: " << newData->name_ << std::endl;
	delete data;
	return 0;
}
