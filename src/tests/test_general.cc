#include "test_helper.h"
#include "../general.h"

int main ()
{
  TestHelper test_helper;
 
  vector<string> result;

  cout << "testing string split function..." << endl;
  string test_string = "hello, this is a test.";
  cout << test_string << endl;
  result = string_split(test_string);
  
  test_helper.check_condition(result.size() == 5,"split size == 5?");
  test_helper.check_condition(result[0].compare("hello,") == 0,"split[0] == 'hello,'?");
  test_helper.check_condition(result[1].compare("this") == 0,"split[1] == 'this'?");
  test_helper.check_condition(result[2].compare("is") == 0,"split[2] == 'is'?");
  test_helper.check_condition(result[3].compare("a") == 0,"split[3] == 'a'?");
  test_helper.check_condition(result[4].compare("test.") == 0,"split[4] == 'test.'?");
    
  cout << "testing trim functions..." << endl;
  
  string trimmed;
  test_string = "  hello ";
  
  trimmed = string_trim_left(test_string);
  test_helper.check_condition(trimmed.compare("hello ") == 0,"trim left == 'hello '?");
  
  trimmed = string_trim_right(test_string);
  test_helper.check_condition(trimmed.compare("  hello") == 0,"trim right == '  hello'?");
  
  trimmed = string_trim(test_string);
  test_helper.check_condition(trimmed.compare("hello") == 0,"trim == 'hello'?");
  
  test_helper.print();
  return test_helper.get_exit_code();
}