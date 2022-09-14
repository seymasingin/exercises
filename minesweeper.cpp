#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
   srand (time(NULL));

   int first;
   int second;

   

  char mine [8] [8];
  char user [8] [8];

     for (int i=0; i<8; i++)
     {
         for (int j=0; j<8; j++)
         {
             mine [i] [j]= ' ';
             user [i] [j]= ' ';
         }
     }

    for (int i=0; i<10; i++)
    {
        first=rand() % 8;
        second=rand() % 8;
        mine [first] [second] ='*';
       
    }


    




/*
   for (int i=0; i<8; i++)

   {
       for(int j=0; j<8; j++)
       {
           cout<<mine [i] [j];
       }

       cout<< endl;
   }
*/

    char vertical=179;
    char left_edge=218;
    char horizantal_line=196;
    char top_t =194;
    char right_edge=191;
    char left_t= 195;
    char plus=197;
    char right_t=180;
    char left_under_edge= 192;
    char reverse_t = 193;
    char right_under_edge= 217;

    


    
   bool game_over= false;



    while(game_over== false)
    {
        cout<< left_edge;
        for(int i=0; i<7; i++)
        {
            cout<< horizantal_line<< top_t;
        }
        cout<<horizantal_line<<right_edge<<endl;


        for (int i=0; i<7; i++)
        {
            for (int j=0; j<8; j++)
            {
                cout<< vertical<<mine [i] [j];
            }
            cout<<vertical<< endl;


            cout<< left_t; 
            for(int i=0; i<7; i++)
            {
                cout<<horizantal_line<< plus;
            }
            cout<<horizantal_line<<right_t<< endl;
        }

        for (int j=0; j<8; j++)
        {
            cout<< vertical<<mine [7] [j];
        }
        cout<<vertical<< endl;


        cout<< left_under_edge;
        for(int i=0; i<7; i++)

        {
            cout<< horizantal_line<< reverse_t;

        }

        cout<< horizantal_line<<right_under_edge<<endl;

        /* burdan sil*/



        cout<< left_edge;
        for(int i=0; i<7; i++)
        {
            cout<< horizantal_line<< top_t;
        }
        cout<<horizantal_line<<right_edge<<endl;


        for (int i=0; i<7; i++)
        {
            for (int j=0; j<8; j++)
            {
                cout<< vertical<<user [i] [j];
            }
            cout<<vertical<< endl;


            cout<< left_t; 
            for(int i=0; i<7; i++)
            {
                cout<<horizantal_line<< plus;
            }
            cout<<horizantal_line<<right_t<< endl;
        }

        for (int j=0; j<8; j++)
        {
            cout<< vertical<<user [7] [j];
        }
        cout<<vertical<< endl;


        cout<< left_under_edge;
        for(int i=0; i<7; i++)

        {
            cout<< horizantal_line<< reverse_t;

        }

        cout<< horizantal_line<<right_under_edge<<endl;


        

        cout<< "koordinat girin";
        int ilk;
        int ikinci;
        char secim;
        int mine_number;

    

        cin>> ilk>> ikinci;

        cout << "left or right(a,d)?"<<endl;
        cin>> secim;
        if(secim=='a')
        {
            if (mine[ilk] [ikinci]== '*')
            {
                cout<< "game over";
                game_over = true;
            }
            else
            {
               //hesapla
               mine_number=0;
               for(int i=(ilk-1); i<=ilk+1; i++)
               {
                   for(int j=ikinci-1; j<=ikinci+1; j++)
                   {
                       if(mine[i] [j]== '*')
                       {
                           mine_number=mine_number+1;   
                       }
                   }
               } 

               user[ilk] [ikinci] = mine_number+48;

            }

        }
        else if(secim == 'd')
        {
            user [ilk] [ikinci] = 244;
        }
    
    }

}
