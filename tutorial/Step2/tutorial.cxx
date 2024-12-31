// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

// 根据参数，决定使用什么函数计算平方
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
  std::cout << "if USE_MYMATH" << std::endl;
#else
  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "else USE_MYMATH" << std::endl;
#endif

  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl; 
  return 0;
}
