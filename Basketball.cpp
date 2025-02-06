#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int P;
int T; // game time in minutes?
int D;
string opponent; //  opponents name

double RND()
{
     return 1.0*rand()/RAND_MAX;
}


void goOpponent()
{
 P = 1;
 T = T + 1;
 if (T == 50)
 {
     cout << "  **** End of First Half ****";
     cout << "Score: Dartmout" << "  " << opponent;
 }
}

int main()
{
   srand(time(NULL));
   cout << "This program was originally written (in BASIC) by \n"
        << "Charles Bacheller of Dartmouth College shortly after 1963. \n"
        << "It appears in the book BASIC Computer Games by David Ahl (1978). \n\n"
        << "* BASIC was created by John G. Kemeny and Thomas E. Kurtz at Dartmouth College (1963). \n"
        << "* C was created by Dennis Ritchie at Bell Labs (1972-73). \n"
        << "* C++ was created by Bjarne Stroustrup at Bell Labs (1979-1985).\n"
        << "* Python was created by Guido van Rossum in the Netherlands (1989).\n"
        << "* The oldest high-level language is FORTRAN (1956). "
        << "  It was developed by a team led by John Backus at IBM. \n";
   cout << "**************************************************\n\n"
        << "This is Dartmouth College basketball.\n"
        << "You will be Dartmouth "
        << "captain and playmaker. \n"
        << "Call shots as follows:\n"
        << "1. Long (30 ft.) jump shot; \n"
        << "2. Short (15 ft.) jump shot; \n"
        << "3. Lay up; \n"
        << "4. Set shot. \n\n";
   cout << "Both teams will use the same defense. \n"
        << "Call defense as follows:\n"
        << "6. Press;\n"
        << "6.5 Man-To-man;\n"
        << "7 Zone; 7.5 None.\n"
        << " To change defense, just type 0 as your next shot.\n\n";
 
  cout  << "Your starting defense will be: ";
  cin   >> D;
  while (D < 6)
   {
     cout << "\nYour new defensive alignment is ";
     cin  >>  D;
   } 
  cout << "\n Choose your opponents name: ";
  cin  >> opponent;
  cout << "\n Centre Jump";
 if (RND() > 0.6)
  {   
     cout << "\n Dartmouth controls the tap.";
     goOpponent();
  } 
 else
  {
    cout << opponent << "controls the tap.";
  }

}