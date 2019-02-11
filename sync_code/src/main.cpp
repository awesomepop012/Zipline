#include "App.hpp"

std::vector<int> range(int num);

int main(int argc, const char *argv[])
{
  App* application = new App(argc, argv);

  application->Start();

  return 0;
}
