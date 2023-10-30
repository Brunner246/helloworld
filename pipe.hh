#pragma once

#include <cmath>
#include <concepts>
#include <ranges>
#include <algorithm>
#include "CwAPI3D.h"


auto compare_with_tolerance = [](auto x, auto y)
  {
    // return x < y &&
    return std::abs(x - y) < 1e-4;
  };

template <typename T>
struct Proxy
{
  T const& aValue;
};

template <typename Range, typename T>
auto operator|(Range const& aRange, Proxy<T> const& aProxy)
{
  return aRange | std::views::filter([&](auto const& aElement)
    { return compare_with_tolerance(aElement, aProxy.aValue); });
}

template <typename T>
auto filterTolerance(T const& aTolerance)
{
  return Proxy<T>{aTolerance};
}


void operator<<(CwAPI3D::Interfaces::ICwAPI3DUtilityController& aController, std::wstring const& aValue)
{
  aController.printToConsole(aValue.data());
}