#include "random.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

int card(long long int nums, char*ar, const char*arg)
{
     int cont=0;
     int temp=0;
     int temp_t=0;
     int j =0;
     int* vec= mat(nums);
     int n= nums*25;
     int matr[n];
     for(int i = 0; i < n; i++)
        {
                matr[i]=*(vec+i);
        }

     //semilla
     for(int l=0;l<nums;l++)
    {
         std::ifstream text(arg);//toma texto
         std::string lines;//lineas de texto
         std::string str= "</tspan></text>";
         std::string center= "*****";
         std::vector<std::string> my_vector;//vector de apuntador
         std::vector<std::string> new_vector;//nuevo vector
         while(std::getline(text,lines))
         {
             my_vector.push_back(lines);
         }
         if (my_vector.size()<75)
        {
               std::cerr << "error: less than 75 lines" <<endl;
              return 1;
         }else{
                 if(l==0)
                 {
                     int z=0;
                     int nu=12;
                     std::ofstream index;
                     index.open("index.idx", std::ifstream::out);
                     for(int a=0; a<nums; a++)
                     {
                         std::string lin;
                         for(int b=0; b<25; b++)
                         {
                             if (z!=nu){

                             lin.append(my_vector.at(matr[z]));
                             lin.append(" ");
                            }else{
                                lin.append(center);
                                lin.append(" ");
                            }
                            z++;
                         }
                            nu+=25;
                           index<<lin<<endl;
                     }
                    index.close();
                 }
                 temp = j+1;
                 cont = 25*temp;
                 temp_t = 25*j;
        for(int i = temp_t; i <cont; i++)
        {
                matr[i]=*(vec+i);
                new_vector.push_back(my_vector.at(matr[i]));//crea vector nuevo
        }
        j++;

        char nom[l];
        char card[l];
        int n=l+1;
        std::ifstream file(ar);
        std::ofstream cards;
        sprintf(nom,"card_%d.svg", n);//nombre del archivo nuevo
        cards.open(nom, std::ifstream::out);
        std::string line;
        int h = 0;
        sprintf(card,"card %d", n);//ombre de carta
        while(std::getline(file,line))
       {
           size_t pos = line.find('$');
           size_t pos_t = line.find('}');
           size_t pos_l = pos-pos_t;
            size_t pos_f = line.rfind('\n');
            if(pos!= pos_f&&h<26)
            {
                if(h<25)
                {
                    if(h==12)
                   {
                       line.replace(pos,pos_l,center);//cambia el centro
                   }else
                   {
                       line.replace(pos,pos_l,new_vector.at(h));//cambia por el vector nuevo
                   }
                       line.append(str);
                   }
            if(h==25)
            {
                line.replace(pos,pos_l,card);//nombre abajo
                line.append(str);
            }
            h++;
    }
           cards<<line<<endl;//lineas en el nuevo archivo
       }
       file.close();
       cards.close();
    }
}

   return 0;
}

