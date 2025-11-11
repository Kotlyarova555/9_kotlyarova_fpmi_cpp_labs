#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

bool isValidDate(const std::string& dateStr) {
    if (dateStr.length() != 10) return false;
    
    if (dateStr[2] != '/' || dateStr[5] != '/') return false;
    
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(dateStr[i])) {
            return false;
        }
    }
    
    int day = std::stoi(dateStr.substr(0, 2));
    int month = std::stoi(dateStr.substr(3, 2));
    int year = std::stoi(dateStr.substr(6, 4));
    

    if (year < 1000 || year > 9999) return false;
    
    
    if (month < 1 || month > 12) return false;
    
    
    int daysInMonth;
    switch (month) {
        case 2:
            
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }
    
    return (day >= 1 && day <= daysInMonth);
}


bool compareDates(const std::string& date1, const std::string& date2) {
    
    int year1 = std::stoi(date1.substr(6, 4));
    int year2 = std::stoi(date2.substr(6, 4));
    if (year1 != year2) return year1 < year2;
    
    
    int month1 = std::stoi(date1.substr(3, 2));
    int month2 = std::stoi(date2.substr(3, 2));
    if (month1 != month2) return month1 < month2;
    
    
    int day1 = std::stoi(date1.substr(0, 2));
    int day2 = std::stoi(date2.substr(0, 2));
    return day1 < day2;
}

int main() {
    std::string input;
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    
    std::vector<std::string> dates;
    std::stringstream ss(input);
    std::string word;
    
    while (ss >> word) {
        if (isValidDate(word)) {
            dates.push_back(word);
        }
    }
    
  
    std::sort(dates.begin(), dates.end(), compareDates);
    
    
    if (dates.empty()) {
        std::cout << "В строке не найдено корректных дат." << std::endl;
    } else {
        std::cout << "Найденные даты (отсортированные по возрастанию):" << std::endl;
        for (const auto& date : dates) {
            std::cout << date << std::endl;
        }
    }
    
    return 0;
}
