#include "serializer.hpp"

int main() {
	Data* data = new Data;
	uintptr_t rawData;
	Data* retData;

	std::cout << "Data             : " << data << std::endl;
	rawData = serializer::serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;
	retData = serializer::deserialize(rawData);
	std::cout << "Deserialized data: " << retData << std::endl;

	delete data;

	return 0;
}