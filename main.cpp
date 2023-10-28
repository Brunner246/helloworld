#include <iostream>
import MyModule;


class Person
{
public:
  Person(std::string&& name)
    : name(std::move(name))
  {
  }
  std::string getName()
  {
    return name;
  }

private:
  std::string name;
};

template<typename T>
concept Dividable = requires(T a, T b) {
  {
    a / b
  } -> std::convertible_to<T>;
};

template<Dividable T>
T divide(T a, T b)
{
  return a / b;
}

int main()
{
  std::cout << "Hello World!" << std::endl;
  [] { std::cout << "This is a Lambda =)\n"; }();
  std::cout << add(1, 2) << std::endl; // add is imported from MyModule (see above)

  auto lPerson = Person("John Doe");
  std::cout << lPerson.getName() << std::endl;

  std::cout << divide<int>(10, 2) << std::endl;

  return EXIT_SUCCESS;
}