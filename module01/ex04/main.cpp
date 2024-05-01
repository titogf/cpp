#include <iostream>
#include <fstream>

std::string    replace(std::string line, std::string s1, std::string s2);

int main(int argc, char **argv)
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     name;
    std::string     line;

    if (argc != 4){
        std::cout << "Four parameters are spected: <./replace> <filename> <s1> <s2>" << std::endl;
        return (0);
    }
    infile.open(argv[1]);
    if (!infile.is_open())
        std::cout << "Error opening file: " << argv[1] << std::endl;
    name.assign(argv[1]);
    name += ".replace";
    outfile.open(name);
    if (!outfile.is_open())
        std::cout << "Error creating file: " << name << std::endl;
    while (std::getline(infile, line)){
        line = replace(line, argv[2], argv[3]);
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return (0);
}

std::string    replace(std::string line, std::string s1, std::string s2)
{
    size_t pos;

    pos = line.find(s1);
    while (pos != std::string::npos) {
        line.replace(pos, s1.length(), s2);
        pos = line.find(s1, pos + s2.length());
    }
    return (line);
}
