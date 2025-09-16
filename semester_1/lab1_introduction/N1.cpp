 #include <iostream>
int main ()  {
  int a, b, d;
  std::cout << "Enter a, b, d" << std::endl;
  std::cin >> a >> b >> d;
  if (a > b) std::swap(a,b);

      for (int i = a; i <= b; i+= d) {
      if ( i % 3 == 0);
      std::cout << i << " ";
      }
      return 0;


}