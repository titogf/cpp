#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <climits>
# include <cfloat>

class ScalarConverter
{
	public:
		static void convert(std::string);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter(void);
		ScalarConverter& operator=(ScalarConverter const& src);
};

#endif