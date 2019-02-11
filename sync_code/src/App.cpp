#include "App.hpp"

App::App(int length, const char* arguments[])
{
  if(arguments && !length)
    throw std::invalid_argument("You must pass in the length of the argument array!");
  std::vector<std::string> result = std::vector<std::string>(length);
  for (size_t i = 1; i < length; i++)
  {
    result.push_back(arguments[i]);
  }
  mArgs=result;
}

void App::Start()
{
  using namespace std;
#if DEBUG
  cout << "Arguments:";
  for( std::string str : mArgs )
  {
    cout << "\t" << str << endl;
  }
#endif
  if(!mArgs.empty())
    parse_args();

  cout << "Thank you for choosing " << UNDERLINE << "Zipline Sync(C)" << _UNDERLINE << " for all of your ziplining needs!" << endl;
  bool ans = false;
  char answer[20] = {'\0'};
  cout << "Would you like to:\n\ta) Create a new idea\n\tb) Commit your changes and push them to github\n\tc) Eat a sandwich" << endl;
  locale loc;
  while(!ans)
  {
    cin >> answer;
    answer=tolower(answer, loc);

    if(answer == 'a')
      idea();
    case 'b':
      commit();
      break;
    case 'c':
      cout << "No U!";
    defualt:
      cout << "Please input a valid answer: ";
      continue;
  }
    ans = true;
  }

  cout << "Thank you for choosing " << UNDERLINE << "Zipline Sync(C)" << _UNDERLINE << " for all of your ziplining needs!" << endl;
  cout << "Goodbye!" << endl;
}

void App::parse_args()
{
  using namespace std;
  locale loc;
  for(auto it : mArgs)
  {
    for(string::size_type i = 0; i<it.length(); ++i)
    {
      it[i] = tolower(it[i], loc);
    }
    if(it == "-help" || it == "help")
      help();
    if(it == "-v" || it == "v")
      verbose=true;
  }
}

bool App::isArg(std::vector<std::string> vec, std::string& item)
{
  return (std::find(vec.begin(), vec.end(), item) != vec.end());
}

void App::idea()
{

}

void App::commit()
{
  using namespace std;
  const char message[50];
  cout << "What did you do? ";
  cin << message;
  system("git add .");
  system("git commit -m \"" + message + "\"");
  system("git push origin master");
}

void App::help()
{
  using namespace std;

  cout << "Hello!" << std::endl;
}
