#include <iostream>

int main() {
    int number;
    
    std::cout << "Введите четырёхзначное натуральное число: " << std::endl;
    std::cin >> number;
    
    
    if (number < 1000 || number > 9999) {
        std::cout << "Ошибка: число должно быть четырёхзначным!" << std::endl;
        return 1;
    }
    
    
    int digit1 = number / 1000;        
    int digit2 = (number / 100) % 10;    
    int digit3 = (number / 10) % 10;   
    int digit4 = number % 10;          
    
    
    if (digit1 == digit4 && digit2 == digit3) {
        std::cout << number << " - это палиндром" << std::endl;
    } else {
        std::cout << number << " - это не палиндром" << std::endl;
    }
    
    return 0;
}