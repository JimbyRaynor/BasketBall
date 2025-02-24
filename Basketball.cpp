#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int P;
int T; // game time in minutes, max 100 (see line 480)
double D;  // Defense type
int S0=0; // opponent score
int S1=0; // Dartmouth score
int Z;  // type of shot (entered by user)
string opponent; //  opponents name

double RND()
{
     return 1.0*rand()/RAND_MAX;
}

void printscore() // 6010
{
     cout << "Score: " <<  S1 << " to " << S0 << "\n";
}

void ScoreOpponent()
{
  // 6000
  S0 = S0 + 2;
  printscore();
}

 void ScoreDartmouth()
 {
     // 7000
     S1 = S1 + 2;
     printscore();
 }

void EndFirstHalf() // 8000
{
     cout << "\n  **** End of First Half ****\n";
     cout << "Score: Dartmout" << "  " << opponent << "\n";
}

// line 3000
int goOpponent()
{
 int z1;
 P = 1;
 T = T + 1;
 if (T == 50) // 8000
 {
  EndFirstHalf();
  return 0;   
 }
 z1 = 2.5*RND()+1;
 if (z1 > 2) // 3500
 {
     if (z1 > 3) // 3800
     {
          cout << "\n Set Shot" << "\n";
          if (7.0/D*RND() > 0.413) // 3520
          {
               cout << "\n Shot Missed" << "\n"; // 3600
          }
          else
          {
             cout << "Shot is Good" << "\n";
             ScoreOpponent();
             return 0;
          }
     }
     else
     {     // 3510
          cout << "\n Lay up. \n";
          if (7.0/D*RND() > 0.413)
          {
               cout << "\n Shot is missed. \n";
          }
     }
 }
 else
 {
     cout << "\n Jump Shot\n"; // 3040
     if (8.0/D*RND() > 0.35) // 3050
     {    //3100
          if (8.0/D*RND() > 0.75) // 3100
          {
               //3200
              if (8.0/D*RND() > 0.9) // 3200
              {
               //3310
               cout << "\n Offensive Foul. Dartmnouth's Ball. \n";
               return 0; // 425 not quite right, need to fix
              }          
          }
          else
          {
               // 3105
               cout << "\n Shot is off rim. \n";
               if (D/6.0*RND() > 0.5) // 3110
               {
                    //3150
                    cout << opponent << "\n controls the rebound. \n";
                    if (D == 6)
                    {
                         // 5000
                    }
                    return 0; // goto 425 (fix)
               }
               else
               {
                    //3120

               }
          }
     }
     else
     {
          //3060
          cout << "\n Shot is good. \n";
          ScoreOpponent();
          return 0; // 425 not quite right, need to fix
     }
 }
 return 0;
}



int PerformShot()
{
  if ((Z == 1) or (Z == 2)) // 1050
     {
      cout << "\n Jump shot\n"; // 1050
      if (RND() <= 0.341*D/8)
      {
          cout << "\n Shot is good. \n"; // 1070
          ScoreDartmouth(); // 1075
          goOpponent();
          return 1; // 1 is when opponent has had a turn
      }
      if (RND() <= 0.682*D/8) // 1090
      {
          cout << "Airball" << "\n"; // 1100
          if (1.0*D/6*RND() > 0.45) // 1105
          {
               // 1130
               cout << "Rebound to " << opponent << "\n";
               return 0; // goto 3000 (opponents turn)
          }
          else // 1110
          {
            cout << "Dartmouth controls the rebound" << "\n";
            if (RND() > 0.4) // 1145
            { // 1158
              if (D == 6)
              { // 5100
               if (RND() > 0.6)
               {
                  cout << "Pass stolen by " << opponent << ". Easy layup." << "\n";
                  ScoreOpponent();
                  return 1;  // goto start L425
               }            
              }
              cout << "Ball passed back to you" << "\n"; //1160
              return 1; // goto 430, same as 425
            }
           else 
           {
             //1300
             T = T + 1;
             if (Z==0) //1305
             {
                // 2010
                D = 0;
                while (D < 6)
                {
                cout << "Input your new defensive alignment: ";
                cin >> D;
                }
               return 1; // goto 425
             } 
            if (Z > 3) // 1310
            {
              //1700
              cout << "Set Shot.";
              // 1330
              if (7.0/D*RND() <= 0.4)
              { 
               cout << "Shot is off the rim.";
              }

            }
           }

          }
      }
     }
 return 0;
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
 


  // line 425: start of main loop
  // ask copilot about breaking back to start of loop
 T = 0;
 while ( (T < 100 ) or (RND() < 0.5) )
 {
   cout << "\n Centre Jump";
   if (RND() > 0.6)
   {   
     cout << "\n Dartmouth controls the tap. \n";
     Z = -1;
     while ( (Z != int(Z)) or (Z < 0) or (Z > 4))
     {
      cout << "\n Your shot: ";
      cin >> Z;
      P=0;
      if ( (Z != int(Z)) or (Z < 0) or (Z > 4))
      {
          cout << "Incorrect answer. Retype it.";
      }
     }
     // 1000
     T = T + 1;
     if (PerformShot() == 0)
     {
       goOpponent(); //3000   
     }
   } 
   else
   {
    cout  << "\n" << opponent << "controls the tap. \n";
    goOpponent(); //3000
   }
 }

}