#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

int game(const char*arg, const char*ar)
{
    int numb=0;
    int veco[75];//vector que contiene numeros ordenados
    int vecb[75];//vector que guarda numeros desordenados
    bool used[75];//vector buleano que guarda true o false si se repite o no
    int cont=0;
    int temp=0;
    int temp_t=0;
    int nu=0;
    std::ifstream text(arg);//toma texto
    std::string lines;
    std::string lin;
     std::ifstream index("index.idx");
     if ( ! index)//error
             {
                   std::cerr << "toc: could not open " << "index.idx" << std::endl;
                   return 1;
              }
    std::vector<std::string> my_vector;//vector de apuntador
    std::vector<std::string> index_vector;
    std::vector<std::string> line_vector;//vector de apuntador
         std::vector<std::string> new_vector;//nuevo vector
          while(std::getline(index,lin))
        {
            index_vector.push_back(lin);
            nu++;
        }
        char matr[nu*25];
         while(std::getline(text,lines))
         {
             my_vector.push_back(lines);
             line_vector.push_back("--");
         }
         if (my_vector.size()<75)
        {
               std::cerr << "error: less than 75 lines" <<endl;
              return 0;
         }else{

                 int k;
                 for(k = 0; k<75; k++)
                     {
                         veco[k]= k;
                         used[k]= false;
                     }
                 for(k = 0; k<75; k++)
                 {
                      do
                        {
                            numb = rand() % 75;
                        }   while(used[numb]);
                      vecb[k]=veco[numb];
                      used[numb]=true;

                 }

        for(int i = 0; i < 75; i++)
        {
                new_vector.push_back(my_vector.at(vecb[i]));//crea vector nuevo
        }
}
    int m=0;
    int k=0;
    while(k<75)
        {
                std::cout << "Press ENTER to continue...";
                std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
                std::cout<<"number: " << new_vector.at(m);
                std::cout<<endl;
                int n=0;
                while(new_vector.at(m)!=my_vector.at(n))
                {
                    n++;
                }
                line_vector.at(n)=new_vector.at(m);
                if(ar=="blackout")
                    {
                         for(int e=0; e<nu; e++)
                         {
                              size_t pos = index_vector.at(e).find(new_vector.at(m));
                              size_t pos_l = index_vector.at(e).find("*****");
                               temp = e+1;
                               cont = 25*temp;
                               temp_t = 25*e;
                               int k;
                 for(k = temp_t; k<cont; k++)
                              {
                                if(matr[k]!='y')
                                {
                                   if(pos==std::string::npos)
                               {
                                   matr[k]='x';
                               }else
                               if(pos_l==std::string::npos)
                               {
                                   matr[k]='x';
                               }else
                               {
                                   matr[k]='y';
                                   pos=std::string::npos;
                                   pos_l=std::string::npos;
                               }
                               }
                          }
                          }
                          temp = 0;
                               cont = 0;
                               temp_t = 0;
                 for (int i=0; i<nu; i++)
               {
                   int winner=i+1;
                 temp = i+1;
                 cont = 25*temp;
                 temp_t = 25*i;
                 /**if(i!=0)
                 {
                     temp_t +=1;
                 }*/
                 int k;
                 for(k = temp_t; k<cont; k++)
                     {
                         if(matr[k]!='y')
                         {
                             k=1000000;
                         }
                     }
                      std::cout<<k;
                      std::cout<<endl;
                     if(k!=1000001)
                     {
                         std::cout<<"winner: card_" << winner;
                          std::cout<<endl;
                          return 0;
                     }

               }
                    }else if(ar=="four-corners")
                    {

                    }else if(ar=="straight-line")
                    {

                    }else if(ar=="diagonal")
                    {

                    }else if(ar=="any-line")
                    {

                    }else if(ar=="roving-L")
                    {

                    }else
                    {
                        std::cout <<ar<< " is not a valid argument";
                        return 1;
                    }
                m++;
                int number=0;
                string letters[5]={"B","I","N","G","O"};
               for(int b=0; b<5; b++)
               {
                   std::cout << letters[b] << " ";
                   for(int c=0; c<15; c++)
                   {

                      {
                          std::cout << line_vector.at(number) << " ";
                      }
                       number++;
                   }
                   std::cout << endl;
               }
           k++;
        }
        return 0;
}
