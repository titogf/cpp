#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <sstream>
# include <climits>
# include <cfloat>
# include <stdint.h>


struct Data {
    int number;
};

class serializer
{
    private:
        serializer();
        serializer(const serializer& src);
        ~serializer(void);
        serializer& operator=(const serializer& src);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif