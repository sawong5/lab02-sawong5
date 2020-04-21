/* starC.cpp 
April 20, 2020
Sam Wong (Perm 6723316)
using an if statement to conditions, then a series of for statements to create the top line, center, then bottom line of the letter "C"
*/ 


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

//creating the top line, center, then bottom line of C
string starC(int width, int height)
{
  string result="";
  //checking conditions (width 2, height 3)
  if ((width<2) || (height<3)){
    return result;
  } 
  int i,j;
  if (height>2){
    //top line of C. tally less than width we put a star
    for (j=0; j<width; j++){
      result += "*";
    }
    result += "\n";
    //using i=2 (factor out top and bottom of height) make a line of *'s, followed by space and \n
    for (i=2; i<height; i++){
      result += "*";
      for (int col=2; col<=width; col++){
        result += " ";
      }
      result += "\n";
    }
    //last line of C. same concept as top
    for (j=0; j<width; j++){
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

  string starC34Expected = 
    "***\n"
    "*  \n"
    "*  \n"
    "***\n";
  
  assertEquals(starC34Expected,starC(3,4),"starC(3,4)");

  string starC53Expected =     
    "*****\n"
    "*    \n"
    "*****\n";

  
  assertEquals(starC53Expected,starC(5,3),"starC(5,3)");

  assertEquals("",starC(2,1),"starC(2,1)");
  assertEquals("",starC(2,2),"starC(2,2)");

  string starC23Expected =     
    "**\n"
    "* \n"
    "**\n";
  
  assertEquals(starC23Expected,starC(2,3),"starC(2,3)");
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
  if(argc!=3)
  {
    cerr << "Usage: " << argv[0] << " width height" <<endl;
    exit(1);
  }

  int width = stoi(argv[1]);
  int height = stoi(argv[2]);
  
  // TODO: Add code to get width and height from command line args
  // code that checks if they are both -1; if so, call runTests()
  // then exit.

  if (width==-1 && height==-1){
    runTests();
    exit(0);
  }

  // TODO: Add code that calls the starT function and prints
  // the result on cout (without an extra newline)

  cout << starC(width, height);
  return 0;
}

