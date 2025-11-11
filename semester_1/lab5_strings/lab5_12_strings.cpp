#include <iostream>
#include <string>

void filling_line(std::string& line) {
 std::cout << "Введите любую дату" << std::endl;
 std::getline(std::cin, line);
 if(line.empty()) {
   throw "Ошибка: строчка должна быть не пустая\n" ;
 }

}

bool cheking_if_is_date(std::string word){
   if(word.length() == 10 && word[2] == "/" && word[5] == "/" && std::isdigit(word[0]) && std::isdigit(word[1]) && std::isdigit(word[3]) && std::isdigit(word[4]) && std::isdigit(word[6]) && std::isdigit(word[7]) && std::isdigit(word[8]) && std::isdigit(word[9])){
      return True;
   }

   return False;
}

std::vector<std::string> finding_dates(std::string line){
   std::vector<std::string> dates;

   std::string::size_type begin = line.find_first_not_of(" ", 0);
   std::string::size_type end = line.find_first_of(" ", begin);

   while (begin != std::string::npos){
      std::string word = line.substr(begin, end - begin);

      if(!word.empty()){
         if (cheking_if_is_date(word)){
            dates.push_back(word);
         }
      }

      std::string::size_type begin = line.find_first_not_of(" ", end);
      std::string::size_type end = line.find_first_of(" ", begin);
   }


}



int main(){
   std::string line;

   try{
      filling_line(line);

      std::vector<std::string> dates = finding_dates(line);

      

   } 
   catch (const char* message){
      std::cout << message;
   }


   return 0;
}