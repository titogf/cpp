#include "serializer.hpp"

int main() {
	Data* data = new Data;

	std::cout << "Data             : " << data << std::endl;

	uintptr_t rawData = serializer::serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;

	Data* retData = serializer::deserialize(rawData);
	std::cout << "Deserialized data: " << retData << std::endl;

	delete data;

	return 0;
}