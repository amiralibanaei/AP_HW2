#include<iostream>
#include<fstream>
#include<string>

int main(){
    
  std::ifstream MyFile;
  MyFile.open("Error_find.txt");

  char c{};
  std::string err{};
  bool err_flag{false};
  bool vowel_check{true};
  size_t cntr{};


  while ( !MyFile.eof() ){

    MyFile.get(c);
    vowel_check = c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y';

    if ( c>=97 && c<=122 && !vowel_check ){
      err += c;
      cntr++;
      
      if (cntr > 4)
	err_flag = true;
    }
    else {
      
      if (err_flag)
	std::cout << err << " ";
      
      err = "";
      cntr = 0;
      err_flag = false;
    }
  }
    
  std::cout << std::endl;
  MyFile.close();
  return 0;
}
