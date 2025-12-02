#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept> 
 
bool IsEmptyFile(std::ifstream& file) {
    return file.peek() == std::ifstream::traits_type::eof() ;
}


std::vector<std::string> splitWords(const std::string& line) {
    std::vector<std::string> words;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

void processLine(std::string& line) {
    std::vector<std::string> words = splitWords(line);
    if (words.empty()) return;

    int minLen = static_cast<int>(words[0].size());
    int maxLen = static_cast<int>(words[0].size());
    int minIndex = 0;
    int maxIndex = 0;

    for (size_t i = 0; i < words.size(); i++) {
        int len = static_cast<int>(words[i].size());
        if (len <= minLen) { 
            minLen = len;
            minIndex = static_cast<int>(i);
        }
        if (len >= maxLen) { 
            maxLen = len;
            maxIndex = static_cast<int>(i);
        }
    }
    if(minIndex != maxIndex)
    std::swap(words[minIndex], words[maxIndex]);

    std::ostringstream oss;
    for (size_t i = 0; i < words.size(); i++) {
        if (i) oss << " ";
        oss << words[i];
    }
    line = oss.str();
}

void solve(const std::string& input_file, const std::string& output_file) {
    std::ifstream in(input_file);

    if (!in.is_open()) 
    throw std::string("Ne otkryvaetsa vhodnoy fail");

    if (IsEmptyFile(in))
    throw std::string("Fail pystoi") ;

    std::ofstream out(output_file);

    if (!out.is_open()) 
    throw std::string("Ne otkryvaetsa vyhodnoy fail");

    std::string line;
    while (std::getline(in, line)) {
        processLine(line);
        out << line << "\n";
    }

    in.close();
    out.close();
}


int main() {
    const std::string input_file = "IN12.TXT" ;
    const std::string output_file = "OUT12.TXT" ;
    try {
        solve(input_file, output_file);
        std::cout << "Результат сохранён в OUT12.TXT" << std::endl;
    } catch (const std::string& message) {
        std::cerr << message << std::endl;
        return 1;
    }
    return 0;
}

