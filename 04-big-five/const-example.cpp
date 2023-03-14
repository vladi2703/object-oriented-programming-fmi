#include <cstring> 
#include <iostream> 

class Person {
private:
  char* name;
  int age;
public:
  char* getName() {
    return name; 
  }
  void setName(const char* other_name){
    const int len = strlen(other_name);
    name = new char[len]; 
    strcpy(name, other_name); 
  }
};
int main() {
    Person chovek; 
    chovek.setName("Harry");
    std::cout << chovek.getName() << std::endl;
    char* ime = chovek.getName(); 
    ime[0] = 'G';
    std::cout << chovek.getName() << std::endl;
    return 0;
}
