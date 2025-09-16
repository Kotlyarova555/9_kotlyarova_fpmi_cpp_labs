#include <iostream>

int main() {
    int number;
    std::cout << "Введите шестизначное число: " << std::endl;
    std::cin >> number;
    
    if (number < 100000 || number > 999999) {
        std::cout << "Ошибка: число должно быть шестизначным!" << std::endl;
        return 1;
    }
    int digit1 = (number / 100000);        
    int digit2 = (number / 10000) % 10;  
    int digit3 = (number / 1000) % 10;   
    int digit4 = (number / 100) % 10;    
    int digit5 = (number / 10) % 10;    
    int digit6 = (number % 10);            
    
    int sum_first = digit1 + digit2 + digit3;
    int sum_last = digit4 + digit5 + digit6;
    
    if (sum_first == sum_last) {
        std::cout << number << " - счастливое число! (" << digit1 << "+" << digit2 << "+" << digit3 << " = " 
             << digit4 << "+" << digit5 << "+" << digit6 << " = " 
             << sum_first << ")" << std::endl;
    } else {
        std::cout << number << " - не счастливое число. (" 
             << digit1 << "+" << digit2 << "+" << digit3 << " = " << sum_first
             << " ≠ " 
             << digit4 << "+" << digit5 << "+" << digit6 << " = " << sum_last 
             << ")" << std::endl;
    }
    
    return 0;
}