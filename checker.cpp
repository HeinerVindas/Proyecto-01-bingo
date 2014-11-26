#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

int checker(char*ar, const char*arg)
{
         std::ifstream text(arg);//toma texto
        std::ifstream che(ar);
        std::ofstream checkers;
         std::string li;//lineas de texto
         std::string str= "</tspan></text>";
         std::vector<std::string> my_vec;//vector de apuntador
         string temp[75];
         int j = 0;
         while(std::getline(text,li))
         {
             temp[j]=li;
                 j++;
         }
         if (j<75)
        {
               std::cerr << "error: less than 75 lines" <<endl;
              return 0;
         }
        char nom[0];
        int n=1;

        sprintf(nom,"checker_%d.svg", n);//nombre del archivo nuevo
        checkers.open(nom, std::ifstream::out);
        std::string l;
        int h = 0;
        while(std::getline(che,l))
       {
           size_t pos = l.find("${symbol}");
          // size_t pos_t = l.find('}');
           //size_t pos_l = pos-pos_t;
            size_t pos_f = l.rfind('\n');
             //
           if(pos!=pos_f&&h<75)
            {
                   // hola = my_vec.at(h);
                    l.replace(pos,pos,temp[h]);//cambia por el vector nuevo
                    l.append(str);
            h++;
    }
           checkers<<l<<endl;//lineas en el nuevo archivo
       }
       checkers.close();

    che.close();

   return 0;
}

