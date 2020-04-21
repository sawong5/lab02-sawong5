/* starZ.cpp 
April 20, 2020
Sam Wong (Perm 6723316)
standard if statement to check if conditions met
for statement for line of *'s for top of Z. 
*/ 

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);

// Write starZ per specifictions at 
// https://foo.cs.ucsb.edu/16wiki/index.php/F14:Labs:lab04
// and so that internal tests pass, and submit.cs system tests pass

string starZ(int width)
{
  string result="";
  if (width >= 3)
  {
    int i, j;
    //top of "Z"
    for (i=0; i<width; i++)
    {
      result += "*"; 
    }
    result += "\n";
    for (i=width-1; i>=2; i--)
    {
      //left portion of the diagonal. spaces -> *
      for (j=1; j<i; j++)
      result += " ";
      result += "*";
      //spaces after * into the \n
      for (j=i+1; j<=width; j++)
      result += " ";
      result += "\n";
    }
    //bottom part of letter "Z"
    for (i=0; i<width; i++)
    {
      result += "*";
    }
    result += "\n";
  }
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected = 
    "***\n"
    " * \n"
    "***\n";
  
  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

  string starZ4Expected = 
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";
  
  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{
  
  if (argc!=2) {
    cerr << "Usage: " << argv[0] << " width" << endl;
    exit(1);
  }
  
  int width = stoi(argv[1]);
  
  // If the program is executed with parameters -1 -1 unit test
  // the starL() function using our automated test framework
  if (width==-1) {
    runTests();
    exit(0);
  }

  cout << starZ(width);
  return 0;

}

