#include <iostream>
int main () {
 int n;
   std::cout << "Введите количество нечетных чисел n:" << std::endl;
   std::cin >> n;

   if(n <= 0) {
    std::cout << "Ошибка:  число n должно быть положительным" << std::endl;
    return 1;
   }
  int sum = 0;
  int current = 1;
  for (int i = 0; i < n; i++) {
    sum += current;
    current += 2;
  }
  std::cout << "Сумма первых" << " n " << "нечетных чисел: " << sum << std::endl;
 return 0;
}