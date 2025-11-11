#include <iostream>
#include <algorithm>
#include <iomanip>
#include <random>

void input_length(int& n){
    std::cout << "Введите число элементов матрицы" << std::endl;
    
    if (!(std::cin >> n) || n < 1) {
        std::cout << "Ошибка: введите целое число" << std::endl;
        std::exit(1);
    }
}

void deleting_matrix(int** matrix, int n){
 for( int i = 0; i < n; i++) {
    delete[] matrix[i];
 }
 delete[] matrix;
}

void create_matrix(int**& matrix, int n){
matrix = new int* [n];
for (int i=0; i<n; i++){
matrix[i] = new int [n];
}
}

void print_matrix(int** matrix, int n){
    std::cout << "Начальная матрица: " << n << "x" << n << ":" << std::endl;
     for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
    std::cout << std::setw(5) << matrix[i][j];
  }
  std::cout << std::endl;
 }
}

void input_random_borders(int& a, int& b){
    
 std::cout << "Введите рандомные границы a и b: " << std::endl;
 if(!(std::cin >> a >> b)) {
    std::cout << "Ошибка: введите целые числа" << std::endl;
    std::exit(1);;
 }
 if(a > b) {
   std::swap(a, b);
 }
}

void random_input(int** matrix, int n, std::mt19937& gen){
  int a, b;
   input_random_borders(a, b);
    
    std::uniform_int_distribution<int> dist(a, b);
  
    std::cout << "Рандомное заполнение из промежутка " << "[" << a << "," <<  b << "] :" << std::endl;

 for(int i = 0; i < n; i++) {
   for( int j = 0; j < n; j++) {
      matrix[i][j] = dist(gen);
   }
 }

}

void manual_input(int** matrix, int n){
   std::cout << "Введите элементы матрицы: " ;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         std::cout << "[" << i << "][" << j << "]: " ;
         if(!(std::cin >> matrix[i][j])) {
            std::cout << "Ошибка: vvedite целые числа" << std::endl;
            deleting_matrix(matrix, n);
            std::exit(1);
         
           }
        }
    }
}

void choosing_type_of_input(int** matrix, int n, std::mt19937& gen){
    int variant;

 std::cout << "Выберите заполнение массива: Рандомно(1) или Вручную(2)" << std::endl;
 if(!(std::cin >> variant)) {
      std::cout << "Ошибка " << std::endl;
      std::exit(1);
    }
   
 if(variant == 1){
    random_input(matrix, n, gen);
    print_matrix(matrix, n);
 } else if(variant == 2){
std::cout << "Заполнение вручную:" << std::endl;
   manual_input(matrix, n);
   print_matrix(matrix, n);
 } else {
    std::cout << "Ошибка: такого варинта нет " << std::endl;
    exit(1);
 } 
}


void sum_in_lines(int** matrix, int n) {
   std::cout << "Суммa в строках без отрицательных элементов: " << std::endl;
   bool foundAny = false;
   for (int i = 0; i < n ; i++) {
       bool hasNegativeElements = false; 
         for( int j = 0; j < n; j++) {
            if(matrix[i][j] < 0) {
               hasNegativeElements = true;
               break;
            }
         }

    if(!hasNegativeElements) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
         sum += matrix[i][j];
      }
    std::cout << "Сумма элементов в " << i + 1 << " строке: " << sum << std::endl;
    foundAny = true;
    }
   } 

   if(!foundAny) {
      std::cout << "Нет строк без отрицательных элементов" << std::endl;
   }
}

void find_min_in_parallel_diagonals(int** matrix, int n) {
 std::cout << "Минимальные элементы в диагоналях:" << std::endl;
 std::cout << "Всего диагоналей: " << 2 * n - 1 << std::endl;
 
 for(int diag = -(n - 1); diag <= (n - 1); diag++) {
   int min_element;
   int count = 0;
   bool has_elements = false;

   if(diag >= 0) {
      for(int i = 0; i < n - diag; i++) {
      int current_element = matrix[i][i + diag];

      if(!has_elements) {
         min_element = current_element;
         has_elements = true ;
      } else {
         if (current_element < min_element) {
            min_element = current_element;
            }
      }
      count++; 
   }

  } else {
   for (int i = 0; i < n + diag; i++) {
      int current_element = matrix[i - diag][i] ;


      if(!has_elements) {
         min_element = current_element;
         has_elements = true;
      } else {
         if(current_element < min_element) {
            min_element = current_element;
            }
         }
         count++;
       } 
     }
  if (has_elements) {
   std::cout << "Диагональ ";
   if(diag < 0) {

      std::cout << diag << " ";

   } else if (diag > 0) {

   std::cout << diag << " "; 

 } else {
   std::cout << "0 ";
 }

     std::cout << "минимум = " << min_element << std::endl;
     

  }
 }
}


int main(){
int n;
input_length(n);

int** matrix;
create_matrix(matrix, n);

std::random_device rd;
std::mt19937 gen(rd());

choosing_type_of_input(matrix, n, gen);
  
sum_in_lines(matrix, n);

find_min_in_parallel_diagonals(matrix, n);

deleting_matrix(matrix, n);
    return 0;
}