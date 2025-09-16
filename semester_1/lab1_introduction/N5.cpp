#include <iostream>
int main () {
 int n, m;
   std::cout << "Введите два натуральных числа n и m:" << std::endl;
   std::cin >> n >> m;

   if(n <= 0 || m <= 0) {
    std::cout << "Ошибка: числа должны быть натуральными" << std::endl;
    return 1;
   } 
    std::cout << "Общие делители чисел " << n << " и " << m << ": " << std::endl;

   int min;
     if (n < m) {
        min = n;
     }

     else {
        min = m;
     }

     for (int i = 1; i <= min; i++) {
        if (n % i == 0 && m % i == 0) {
            std::cout << i << " " << std::endl;
        }
     }

}