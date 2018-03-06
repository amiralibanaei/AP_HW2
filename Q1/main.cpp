#include <iostream>

int main() {

  char a{'a'};
  const char* name{"Amir Jahanshahi"};
  const char* p1{name};
  std::cout << *p1 << *(p1+1) << *(p1+2) << std::endl;
  p1 = &a;
  std::cout << *p1 << *(p1+1) << *(p1+2) << std::endl;
  p1 = name;
  //*p1 = 'b';
  //char* p2{name};


  return 0;
}
