#include <iostream>
#include <cstdlib>  
#include <random>   

void fill_Arr(int* arr, int n) {
    int variant;
    std::cout << "Рандомно(1) или вручную(2)" << std::endl;
    std::cin >> variant;
    
    if (variant == 1) {
        int a, b;
        std::cout << "Введите рандомные границы a и b: " << std::endl;
        if (!(std::cin >> a >> b)) {
            std::cout << "Ошибка: введите целые числа" << std::endl;
            return;
        }

        
        if (a > b) {
            std::swap(a, b);
        }
        
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(a, b);
        
    
        for (int i = 0; i < n; i++) {
            arr[i] = dist(gen);
        }
        
        std::cout << "Массив заполнен случайными числами из интервала [" 
                  << a << ", " << b << "]\n";
    } else if (variant == 2) {
        std::cout << "Введите " << n << " целых чисел массива" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "Элемент " << i + 1 << ": ";
            if (!(std::cin >> arr[i])) {
                std::cout << "Ошибка: введите целое число" << std::endl;
                return;
            }
        }
    } else {
        std::cout << "Неверный выбор! Программа завершена.\n";
        exit(1);
    }
}


void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int findMinElementABS(int* arr, int n) {
    int MinElementABS = std::abs(arr[0]);
      for (int i = 1; i < n; i++) {
        int currentElementABS = std::abs(arr[i]);
           if (currentElementABS < MinElementABS) {
            MinElementABS = currentElementABS;
        }
        
    }
    
    
    return MinElementABS;
}


int sumBeforeLastZero(int* arr, int n) {
    int lastZeroIndex = -1;
    
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            lastZeroIndex = i;
        }
    }
    
    
    if (lastZeroIndex == -1) {
        std::cout << "В массиве нет нулевых элементов " << std::endl;
        return 0;
    }
    
    
    int sum = 0;
    for (int i = 0; i < lastZeroIndex; i++) {
        sum += arr[i];
    }
    
    return sum;
}

void resultArr(int* arr, int n) {
    int* temp = new int[n];
    int index = 0;  
    
    
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {  
            temp[index] = arr[i];
            index++;
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {  
            temp[index] = arr[i];
            index++;
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    
    
    delete[] temp;
}

int main() {
    int n;
    
    
    std::cout << "Введите число элементов массива: " << std::endl;
    if (!(std::cin >> n)) {
        std::cout << "Ошибка: введите целое число" << std::endl;
        return 1;
    }
    

    if (n <= 0) {
        std::cout << "Число должно быть положительным" << std::endl;
        return 1;
    }
    
    
    int* arr = new int[n];
    
    
    fill_Arr(arr, n);
    
    
    std::cout << std::endl << "Исходный массив: " << std::endl;
    printArr(arr, n);
    
    
    int MinElementABS = findMinElementABS(arr, n);
    std::cout << "1. Минимальный по модулю элемент: " << MinElementABS << std::endl;
    
    
    int sum = sumBeforeLastZero(arr, n);
    std::cout << "2. Сумма элементов до последнего нулевого: " << sum << std::endl;
    
    resultArr(arr, n);
    std::cout << "3. Полученный массив: " << std::endl;
    printArr(arr, n);
    
    delete[] arr;
    
    return 0;
}