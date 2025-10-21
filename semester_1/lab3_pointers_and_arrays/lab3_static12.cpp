

#include <iostream>
#include <algorithm>
#include <random>

int main() {
 const int MAX_LENGTH = 1000;
 int arr[MAX_LENGTH];
 int n;
 int variant;

 std::cout << "Ведите количество элементов массива, не больше " << MAX_LENGTH << std::endl;

  if (!(std::cin >> n)) {
        std::cout << "Ошибка: введите целое число" << std::endl;
        return 1;
    }
      else if (n > MAX_LENGTH || n <= 0) {
    std::cout << "Ошибка: количество элементов должно быть от 1 до " << MAX_LENGTH << std::endl;
    return 1;
    }


 std::cout << "Рандомно(1) или вручную(2)" << std::endl;
    std::cin >> variant;
    if (variant == 1) {
        int a, b;
        std::cout << "Введите рандомные границы a и b : " << std::endl;
        if (!(std::cin >> a >> b)) {
            std::cout << "Введите числа";
            return 1;
        }

        if (a > b) {
            std::swap(a, b);
        }

        std::mt19937 gen(1337);
        std::uniform_int_distribution<int> dist(a, b);

        for (int i = 0; i < n; i++) {
            arr[i] = dist(gen);
          
        
      }
   } else if (variant == 2) { 
  std::cout << "Введите " << n << " целых чисел" << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout << "Элемент " << i + 1 << ":" ;

    if (!(std::cin >> arr[i])) {
   std::cout << "Ошибка: введите целое число" << std::endl;
        return 1;
      }
    }

   } else {
      std::cout << "Неверный выбор" << std::endl;
      return 1;
   }

int positive_count = 0;
 for (int i = 0; i < n; ++i) {
    if (arr[i] > 0) {
      positive_count++;
    }
  }
 
  std::cout << "Введенный массив: " << std::endl;
   for (int i = 0; i < n; ++i) {
     std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
  
 
int last_index_zero = -1;
  for(int i = n-1; i >= 0; i--) {
   if (arr[i] == 0) {
      last_index_zero = i;
      break;
   }
  }
  
  int sum_after_zero = 0;
   if (last_index_zero != -1 && last_index_zero < n-1) {
      for (int i = last_index_zero + 1; i < n; i++) {
         sum_after_zero += arr[i];
      }
   }

    for ( int i = 0; i < n-1; i++) {
      if (arr[i] == 0) continue;

      for (int j = i + 1; j < n; j++) {
         if (arr[j] == 0) continue;
      
            if(arr[i] > 0 && arr[j] > 0) {
               if (arr[i] > arr[j]) {
                   std::swap(arr[i], arr[j]);
      }
    }
    else if (arr[i] < 0 && arr[j] < 0) {
      if (arr[i] < arr[j]) {
         std::swap(arr[i], arr[j]);
      }
    }
   }
}
   


std::cout << "Результат: " << std::endl;
std::cout << "Количество положительных элементов: " << positive_count << std::endl;
std::cout << "Сумма после последнего нуля: " << sum_after_zero << std::endl;
std::cout << "Отсортированный массив по возрастанию/убыванию: " << std::endl;
 for (int i = 0; i < n; i++) {
   std::cout << arr[i] << " " << std::endl;
 }
    return 0;
}





 