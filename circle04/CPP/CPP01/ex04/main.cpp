#include <iostream>
#include <fstream>
#include <string>

std::string replace_all(const std::string& str, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = str.find(s1, start)) != std::string::npos) {
        result.append(str, start, pos - start);
        result.append(s2);
        start = pos + s1.length();
    }

    result.append(str, start, std::string::npos);
    return result;
}

int main(int ac, char* av[]) {
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream input_file(filename);
    if (!input_file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(input_file, line)) {
        content += line + '\n';
    }

    std::string replaced_content = replace_all(content, s1, s2);


    std::ofstream output_file(filename + ".replace");
    if (!output_file) {
        std::cerr << "Error: Cannot create file " << filename + ".replace" << std::endl;
        return 1;
    }

    output_file << replaced_content;
 
    return 0;
}