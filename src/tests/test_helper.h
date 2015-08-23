#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <iostream>
#include <string>

/**
 * This is header-only implementations of test helper class,
 * it provides some basic stuff to be used in tests.
 */

using namespace std;

class TestHelper
  {
    protected:
      int exit_code;                  ///< exit code to be returned by the program
      unsigned int number_of_errors;  ///< records number of errors
      
    public:
      TestHelper()
        {
          this->exit_code = 0;   // all OK
          this->number_of_errors = 0;
        }
        
      /**
       * Gets the exit code that should be returned by the program.
       */
      int get_exit_code()
        {
          return this->exit_code;
        }
        
      /**
       * Prints info of the testing.
       */
      void print()
        {
          cout << "testing info:" << endl;
          cout << "  number of errors: " << this->number_of_errors << endl;
          cout << "  status: " << (this->exit_code == 0 ? "OK" : "NOT OK") << endl;
        }
        
      /**
       * Checks if given condition is satisfied. If not, the exit
       * code will be changed and error message will be written
       * (if enabled).
       */
      bool check_condition(bool condition, string info_string="testing", bool silent=false)
        {
          if (!silent)
            cout << info_string << ": ";
          
          if (condition)
            {
              if (!silent)
                cout << "OK" << endl;
            
              return true;
            }
          else
            {
              if (!silent)
                cout << "Error" << endl;
              
              this->exit_code = 1;
              this->number_of_errors++;
            }
            
          return false;
        }
  };

#endif