#include <iostream>
int main() {
  int n;
  int even = 0;
  int odd = 1;
    std::cout << "Введите n" << std::endl;
    std::cin >> n;

     if(n < 1) {
      std::cout << "n должно быть не меньше 1" << std::endl;
      return 1;
     } 
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        even = even +i;
      }
      else {
        odd = odd * i;
      }
    }

    std::cout << "Сумма четных чисел:" << even << std::endl;
    std::cout << "Произведение нечетных чисел:" << odd << std::endl;

    return 0;

}
