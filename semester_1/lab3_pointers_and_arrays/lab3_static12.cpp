#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>

 const int MAX_LENGTH = 1000;



void input_size_of_arr(int& n) {
 std::cout << "Ведите количество элементов массива, не больше " << MAX_LENGTH << std::endl;

  if (!(std::cin >> n)) {
        std::cout << "Ошибка: введите целое число" << std::endl;
        std::exit(1);
    }
      else if (n > MAX_LENGTH || n <= 0) {
    std::cout << "Ошибка: количество элементов должно быть от 1 до " << MAX_LENGTH << std::endl;
    std::exit(1);
    }
    
   }

   void input_random_borders(int& a, int& b){
 
        std::cout << "Введите рандомные границы a и b : " << std::endl;
        if (!(std::cin >> a >> b)) {
            std::cout << "Введите числа";
            std::exit(1);
        }
        if (a > b) {
            std::swap(a, b);
        }
      }
   void filing_arr_with_random_number(int* arr, int n) {
        int a, b;
        input_random_borders(a, b); 

        std::mt19937 gen(1337);
        std::uniform_int_distribution<int> dist(a, b);

        for (int i = 0; i < n; i++) {
            arr[i] = dist(gen);
          }
          
        } 

   void manual_input(int* arr, int n) {
        std::cout << "Введите " << n << " целых чисел" << std::endl;
  
  
        for (int i = 0; i < n; ++i) {
        std::cout << "Элемент " << i + 1 << ":" ;

        if (!(std::cin >> arr[i])) {
        std::cout << "Ошибка: введите целое число" << std::endl;
        std::exit(1);
      }
    }
   }

   void printArr(int* arr, int n) {
        for(int i = 0; i < n; i++) {
         std::cout << arr[i] << " " ;
       }
       std::cout << std::endl;
   }



    void choosing_type_of_input(int* arr, int n) {
      int variant;
 std::cout << "Рандомно(1) или вручную(2)" << std::endl;
    if(!(std::cin >> variant)) {
      std::cout << "Ошибка " << std::endl;
      std::exit(1);
    }
        

      if(variant == 1) {
     filing_arr_with_random_number(arr, n);
     printArr(arr, n);
      }

      else if (variant == 2){
      manual_input(arr, n);
      printArr(arr, n);
      }

      else{
         std::cout << "Такого варианта нет" << std::endl;
         std::exit(1);
      }
   }



     void num_of_positive_elements(int* arr, int n) {
       int positive_count = 0;
       for (int i = 0; i < n; ++i) {
       if (arr[i] > 0) {
          positive_count++;
    }
  }
  std::cout << "Количество положительных элементов: " << positive_count << std::endl;
  std::cout << "Введенный массив: " << std::endl;
  printArr(arr, n);
    std::cout << std::endl;
}

  
 void sum_after_last_zero(int* arr, int n) {
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
   std::cout << "Сумма после последнего нуля: " << sum_after_zero << std::endl;

}


void sorting_arr(int* arr, int n) {
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
    std::cout << "Отсортированный массив по возрастанию/убыванию: " << std::endl;
}
 
int main() {
 int arr[MAX_LENGTH];
 int n; 
 input_size_of_arr(n);

 choosing_type_of_input(arr, n);

 num_of_positive_elements(arr, n);
 
 sum_after_last_zero(arr, n);
 std::cout << "Результат: " << std::endl;

 sorting_arr(arr, n);
 printArr(arr, n);

return 0;
}










 


 