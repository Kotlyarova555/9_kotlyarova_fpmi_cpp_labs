#include <iostream>
#include <algorithm>

int sum_of_div(int n) {

    int sum = 0;
    for (int i = 1; i < n; i++) {
        if ((n % i) == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int a, b;

    std::cout << "Введите a и b: " << std::endl;

    if (!(std::cin >> a >> b)) {
        std::cout << "Ошибка: введите целое число" << std::endl;
        return 1;
    }

    if (a > b) {
        std::swap(a, b);
    }
   
         bool found = false;
        std::cout << "Результат: " << std::endl;

    for (int i = a; i <= b; i++) {
       int sum_a = sum_of_div(i);
        
    for (int j = i + 1; j <= b; j++) {
       int sum_b = sum_of_div(j);

            if (i == sum_b && j == sum_a) {
                std::cout << i << " и " << j << " - дружественные числа " << std::endl;
                found = true;
            }
        }
    }
     if (!found) {
        std::cout << " Дружественные числа не найдены " << std::endl;
     }

	return 0;
}
