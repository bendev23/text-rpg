#include "../general.h"

using namespace std;

int main ()
{
  int return_code = 0;
 
  vector<string> result;

  cout << "testing string split function..." << endl;
  string test_string = "hello, this is a test.";
  cout << test_string << endl;
  result = string_split(test_string);
  
  if (result.size() != 5)
    {
      cout << "ERROR: wrong result size" << endl;
      return_code = 1;
    }
  else
    {
      cout << result[0] << endl;
      cout << result[1] << endl;
      cout << result[2] << endl;
      cout << result[3] << endl;
      cout << result[4] << endl;
      
      if (result[0].compare("hello,") != 0 ||
          result[1].compare("this") != 0 ||
          result[2].compare("is") != 0 ||
          result[3].compare("a") != 0 ||
          result[4].compare("test.") != 0)
        {
          cout << "ERROR: wrong result content" << endl;
          return_code = 1;
        }
    }
    
  cout << "testing trim functions..." << endl;
    
  string trimmed;
  test_string = "  hello ";
  
  trimmed = string_trim_left(test_string);
  
  if (trimmed.compare("hello ") != 0)
    {
      cout << "ERROR: wrong left trim result: " << trimmed << endl;
      return_code = 1;
    }
    
  trimmed = string_trim_right(test_string);
  
  if (trimmed.compare("  hello") != 0)
    {
      cout << "ERROR: wrong right trim result: " << trimmed << endl;
      return_code = 1;
    }
  
  trimmed = string_trim(test_string);
  
  if (trimmed.compare("hello") != 0)
    {
      cout << "ERROR: wrong trim result: " << trimmed << endl;
      return_code = 1;
    }
  
  return return_code;
}