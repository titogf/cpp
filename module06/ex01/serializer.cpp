#include "serializer.hpp"

serializer::serializer(){}
serializer::serializer(const serializer& src){(void) src;}
serializer::~serializer(){}
serializer& serializer::operator=(const serializer& src){(void) src; return *this;}

uintptr_t serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}