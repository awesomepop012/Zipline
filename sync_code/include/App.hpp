#pragma once

#define DEBUG false

#define UNDERLINE "\033[4m"
#define _UNDERLINE "\033[0m"


#include <string>
#include <locale>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class App final
{
public:
  App(int length=0, const char* arguments[]=0);
  // Explicitly deleting defualt, copy, and move constructor
  App() = delete;
  App(const App& r) = delete;
  App(const App&& r) = delete;

  void Start();

  App& operator=(const App& r) = delete;

  ~App();
private:
  bool isArg(std::vector<std::string> vec, std::string& element);
  void parse_args();
  void idea();
  void commit();
  void help();

  std::vector<std::string> mArgs;
  bool verbose = false;
};
