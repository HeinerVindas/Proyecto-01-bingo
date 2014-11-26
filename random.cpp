#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>

int* mat(long long nums)
{
        int numbs=nums*25;
        int veco[75];//vector que contiene numeros ordenados
        int vecb[75];//vector que guarda numeros desordenados
        bool used[75];//vector buleano que guarda true o false si se repite o no
        int cont=0;
        int temp=0;
        int temp_t=0;
        int temp_f=0;
        int numb=0;
        int *vec_m= new int [numbs];//vector que guarda todos los numeros que se van a usar
        int s = 0;
        for(int l=0;l<nums;l++)
    {
        for (int i=0; i<5; i++)
        {
             temp = i+1;
                 cont = 15*temp;
                 temp_t = 15*i;
                 temp_f = cont-temp_t;
                 int k;
                 for(k = temp_t; k<cont; k++)
                     {
                         veco[k]= k;
                         used[k]= false;
                     }
                 for(k = temp_t; k<cont; k++)
                 {
                      do
                        {
                            numb = (rand() % temp_f)+ temp_t;
                        }   while(used[numb]);
                      vecb[k]=veco[numb];
                      used[numb]=true;
                 }
            for (int j=0; j<5; j++)
            {
                  vec_m[s]=vecb[temp_t+j];//guarda los numeros desordenados en el vec_m
                  s++;
            }
        }
    }
    return vec_m;//devuelve apuntador al vector
}

