#include <iostream>
#include "CwAPI3D.h"
#include <memory>
#include <functional>
#include <concepts>
#include <ranges>
#include <algorithm>
#include "pipe.hh"

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

namespace Strategy
{
  template<typename T>
  concept Invokable = requires(T a) {
    std::is_invocable_v<T>;
  };
  template<Invokable T>
  class Strategy
  {
  public:
    explicit Strategy(T&& aStrategy)
      : mStrategy(std::forward<T>(aStrategy))
    {
    }
    void execute()
    {
      mStrategy();
    }
  private:
    T mStrategy;
  };
}




CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);


bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
  if (!aFactory)
  {
    return EXIT_FAILURE;
  }
  aFactory->getUtilityController()->printToConsole(L"Hello World Plugin");

  using consolePrinter = CwAPI3D::Interfaces::ICwAPI3DUtilityController&;
  consolePrinter lCout = *(*aFactory).getUtilityController();

  std::cout << "Hello World!" << std::endl;
  [&lCout] { lCout << L"This is a Lambda =)\n"; }();
  lCout << std::to_wstring(add(1, 2)); // add is imported from MyModule (see above)

  auto lPerson = Person("John Doe");
  std::cout << lPerson.getName() << std::endl;

  lCout << std::to_wstring(divide<int>(10, 2));

  Strategy::Strategy lStrategy([] { std::cout << "This is a Lambda =)\n"; });
  lStrategy.execute();
  std::function<void()> lambdaFunction = [] { std::cout << "This is a Lambda =)\n"; };
  auto lStrategy2 = std::make_unique<Strategy::Strategy<decltype(lambdaFunction)>>(std::move(lambdaFunction));
  lStrategy2->execute();

  std::vector lVector{ 1.2, 2.3, 3.4, 4.5, 5.6 };
  auto lFilteredVector = lVector | filterTolerance(1.2);
  if (!lFilteredVector.empty())
  {
    std::ranges::for_each(lFilteredVector, [&aFactory](auto const& aElement) { aFactory->getUtilityController()->printToConsole(std::to_wstring(aElement).data()); });
  }


  return EXIT_SUCCESS;
}