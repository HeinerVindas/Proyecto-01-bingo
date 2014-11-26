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

int game(long long int ns, const char*arg, string ar)
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
    std::string li;
     std::ifstream index("index1.idx");
     std::ifstream ind("index2.idx");
     if ( ! index)//error
             {
                   std::cerr << "toc: could not open " << "index1.idx" << std::endl;
                   return 1;
              }
              if ( ! ind)//error
             {
                   std::cerr << "toc: could not open " << "index2.idx" << std::endl;
                   return 1;
              }
    std::vector<std::string> my_vector;//vector de apuntador
    std::vector<std::string> index_vector;
    std::vector<std::string> ind_vector;
    std::vector<std::string> line_vector;//vector de apuntador
         std::vector<std::string> new_vector;//nuevo vector
          while(std::getline(index,lin))
        {
            index_vector.push_back(lin);
            nu++;
        }
        while(std::getline(ind,li))
        {
            ind_vector.push_back(li);
            }
        char matr[nu*24];
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
    int y=0;
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
               if(ar=="blackout")
                    {
                         for(int e=0; e<nu; e++)
                         {
                              size_t pos = index_vector.at(e).find(new_vector.at(m));
                               temp = e+1;
                               cont = 24*temp;
                               temp_t = 24*e;
                               int h;
                 for(h = temp_t; h<cont; h++)
                              {
                                if(matr[h]!='x')
                                {
                                   if(pos==std::string::npos)
                               {
                                   matr[h]='-';
                               }else
                               {
                                   matr[h]='x';
                                   pos=std::string::npos;
                               }
                               }
                               std::cout<<matr[h];
                          }
                          std::cout<<endl;
                          }
                          temp = 0;
                               cont = 0;
                               temp_t = 0;
                 for (int i=0; i<nu; i++)
               {
                   int winner=i+1;
                 temp = i+1;
                 cont = 24*temp;
                 temp_t = 24*i;
                 /**if(i!=0)
                 {
                     temp_t +=1;
                 }*/
                 int h;
                 for(h = temp_t; h<cont; h++)
                     {
                         if(matr[h]!='x')
                         {
                             h=1000000;
                         }
                     }
                     if(h!=1000001)
                     {
                         std::cout<<"winner: card_" << winner;
                          std::cout<<endl;
                          if(y==ns)
                          {
                              return 0;
                              }
                              y++;
                     }

               }
                    }else if(ar=="four-corners")
                    {
                        int corner1=0;
                        int corner2=4;
                        int corner3=19;
                        int corner4=23;
                         for(int e=0; e<nu; e++)
                         {
                               temp = e+1;
                               cont = 24*temp;
                               temp_t = 24*e;
                               int h;
                 for(h = temp_t; h<cont; h++)
                              {
                                  if(matr[h]!='x')
                                {
                                    if(ind_vector.at(corner1)==new_vector.at(m))
                                {
                                   matr[corner1]='x';
                               }else if(ind_vector.at(corner2)==new_vector.at(m))
                               {
                                   matr[corner2]='x';
                               }else if(ind_vector.at(corner3)==new_vector.at(m))
                               {
                                   matr[corner3]='x';
                               }else if(ind_vector.at(corner4)==new_vector.at(m))
                               {
                                   matr[corner4]='x';
                               }else
                               {
                                   matr[h]='-';
                               }
                               }
                               std::cout<<matr[h];
                          }
                          corner1+=24;
                               corner2+=24;
                               corner3+=24;
                               corner4+=24;
                          std::cout<<endl;
                          }
                               corner1=0;
                        corner2=4;
                        corner3=19;
                        corner4=23;
                 for (int i=0; i<nu; i++)
               {
                   int winner=i+1;
                 int h=2;
                 if(matr[corner1]!='x'||matr[corner2]!='x'||matr[corner3]!='x'||matr[corner4]!='x')
                 {
                     h=1;
                 }
                     if(h==2)
                     {
                         std::cout<<"winner: card_" << winner;
                          std::cout<<endl;
                          if(y==ns)
                          {
                              return 0;
                              }
                              y++;
                     }
                     corner1+=24;
                               corner2+=24;
                               corner3+=24;
                               corner4+=24;
                     }
                    }else if(ar=="straight-line")
                    {

                    }else if(ar=="diagonal")
                    {
                                                 int corner1=0;
                        int corner2=6;
                        int corner3=17;
                        int corner4=23;
                         for(int e=0; e<nu; e++)
                         {
                               temp = e+1;
                               cont = 24*temp;
                               temp_t = 24*e;
                               int h;
                 for(h = temp_t; h<cont; h++)
                              {
                                  if(matr[h]!='x')
                                {
                                    if(ind_vector.at(corner1)==new_vector.at(m))
                                {
                                   matr[corner1]='x';
                               }else if(ind_vector.at(corner2)==new_vector.at(m))
                               {
                                   matr[corner2]='x';
                               }else if(ind_vector.at(corner3)==new_vector.at(m))
                               {
                                   matr[corner3]='x';
                               }else if(ind_vector.at(corner4)==new_vector.at(m))
                               {
                                   matr[corner4]='x';
                               }else
                               {
                                   matr[h]='-';
                               }
                               }
                               std::cout<<matr[h];
                          }
                          corner1+=24;
                               corner2+=24;
                               corner3+=24;
                               corner4+=24;
                          std::cout<<endl;
                          }
                               corner1=0;
                        corner2=6;
                        corner3=17;
                        corner4=23;
                 for (int i=0; i<nu; i++)
               {
                   int winner=i+1;
                 int h=2;
                 if(matr[corner1]!='x'||matr[corner2]!='x'||matr[corner3]!='x'||matr[corner4]!='x')
                 {
                     h=1;
                 }
                     if(h==2)
                     {
                         std::cout<<"winner: card_" << winner;
                          std::cout<<endl;
                          if(y==ns)
                          {
                              return 0;
                              }
                              y++;
                     }
                     corner1+=24;
                               corner2+=24;
                               corner3+=24;
                               corner4+=24;
                     }
                         corner1=4;
                         corner2=8;
                         corner3=15;
                         corner4=19;
                         for(int e=0; e<nu; e++)
                         {
                               temp = e+1;
                               cont = 24*temp;
                               temp_t = 24*e;
                               int h;
                 for(h = temp_t; h<cont; h++)
                              {
                                  if(matr[h]!='x')
                                {
                                    if(ind_vector.at(corner1)==new_vector.at(m))
                                {
                                   matr[corner1]='x';
                               }else if(ind_vector.at(corner2)==new_vector.at(m))
                               {
                                   matr[corner2]='x';
                               }else if(ind_vector.at(corner3)==new_vector.at(m))
                               {
                                   matr[corner3]='x';
                               }else if(ind_vector.at(corner4)==new_vector.at(m))
                               {
                                   matr[corner4]='x';
                               }else
                               {
                                   matr[h]='-';
                               }
                               }
                               std::cout<<matr[h];
                          }
                          corner1+=24;
                               corner2+=24;
                               corner3+=24;
                               corner4+=24;
                          std::cout<<endl;
                          }
                               corner1=4;
                        corner2=8;
                        corner3=15;
                        corner4=19;
                 for (int i=0; i<nu; i++)
               {
                   int winner=i+1;
                 int h=2;
                 if(matr[corner1]!='x'||matr[corner2]!='x'||matr[corner3]!='x'||matr[corner4]!='x')
                 {
                     h=1;
                 }
                     if(h==2)
                     {
                         std::cout<<"winner: card_" << winner;
                          std::cout<<endl;
                          if(y==ns)
                          {
                              return 0;
                              }
                              y++;
                     }
                     corner1+=24;
                               corner2+=24;
                               corner3+=24;
                               corner4+=24;
                     }
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
           k++;
        }
        return 0;
}
