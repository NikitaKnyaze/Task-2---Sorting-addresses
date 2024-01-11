#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using std::string;

class Address {
private:
   string city;
   string street;
   string num_of_house;
   string num_of_flat;

public:
   Address() {};
   void set_f(string, string, string, string);
   string complex_addr();
   string get_addr();
};

string Address::complex_addr() {
   string new_str;
   new_str += city;
   new_str += ", ";
   new_str += street;
   new_str += ", ";
   new_str += num_of_house;
   new_str += ", ";
   new_str += num_of_flat;
   new_str += "\n";
   return new_str;
};

void Address::set_f(string word1, string word2, string word3, string word4) {
   for (int i = 0; i < 1; ++i) {
      city = word1;
      street = word2;
      num_of_house = word3;
      num_of_flat = word4;
   }
};

string Address::get_addr() {
   return city;
};

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   std::ifstream file_in("in.txt");
   std::ofstream file_out("out.txt");
   std::string number_of_addresses;
   short number_of_addresses_int;
   const short number_of_colums = 4;

   if (!(file_in.is_open())) {
      std::cout << "File was not open\n";
      return -1;
   }

   if (!(file_out.is_open())) {
      std::cout << "File was not open\n";
      return -1;
   }

   // сколько адресов
   file_in >> number_of_addresses;

   // из стринг в инт
   number_of_addresses_int = stoi(number_of_addresses);

   int words_number = number_of_addresses_int * 4;
   //выделение памяти для объектов
   Address* arr = new Address[number_of_addresses_int];

   //считывание слов и установка в поля класса
   for (int i = 0; i < number_of_addresses_int; ++i) {
      arr[i] = Address();
      string word1, word2, word3, word4;
      file_in >> word1;
      file_in >> word2;
      file_in >> word3;
      file_in >> word4;
      arr[i].set_f(word1, word2, word3, word4);
   }

   for (int j = 0; j < number_of_addresses_int - 1; ++j) {
      for (int i = 0; i < number_of_addresses_int - 1; ++i) {
         Address collect;

         if (arr[i].get_addr() > arr[i + 1].get_addr()) {
            collect = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = collect;
         }

      }
   }

   //ввод данных в файл
   for (int i = 0; i < number_of_addresses_int; ++i) {
      file_out << arr[i].complex_addr();
   }

   file_in.close(); // закрытие файла
   file_out.close();// закрытие файла

   //Освобождение памяти
   delete[] arr;

   return 0;
}