#include <iostream>
#include <any>

int main()
{
  std::any an_object{ std::string("hello world") };
  if (an_object.has_value()) {
    std::cout << std::any_cast<std::string>(an_object) << '\n';
  }

  try {
    std::any_cast<int>(an_object);
  } catch(std::bad_any_cast&) {
    std::cout << "Wrong type\n";
  }
  
  std::any_cast<std::int32_t&>(an_object) = 42;
  std::cout << std::any_cast<std::string>(an_object) << '\n';
}