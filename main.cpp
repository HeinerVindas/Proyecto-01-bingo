#include "cards.cpp"
#include "game.cpp"
#include "checker.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;
int print_help();
int print_version();
long long int num;
char*files;
char*check;
const char* texts="numbers.txt";
const char* win="blackout";

int analyze_params(int argc, char* argv[])
{
    srand( time(0) );
    int i;
    for (i = 1; i < argc; ++i )
		if ( strcmp( argv[i], "--help" ) == 0 )
			return print_help();//imprime help

	for (i = 1; i < argc; ++i )
		if ( strcmp( argv[i], "--version" ) == 0 )
			return print_version();//imprime version

    for (i = 1; i < argc; ++i )
   {
      if ( strcmp(argv[i], "generate") == 0 )
         {
             num = atoll(argv[i+1]);//veces que se repite
             std::ifstream file(argv[i+2]);
             if ( ! file )//error
             {
                   std::cerr << "toc: could not open " << argv[i+2] << std::endl;
                   return 1;
              }
             files = argv[i+2];//toma archivo

                  card(num,files,texts);

         }
      else if ( strcmp(argv[i], "-s") == 0 ){
        std::ifstream text(argv[i+1]);
        if ( ! text )//error
        {
              std::cerr << "toc: could not open " << argv[i+1] << std::endl;
              return 1;
         }
         texts=argv[i+1];//toma texto


        card(num,files,texts);
      }
      else if ( strcmp(argv[i], "-c") == 0 ){
        std::ifstream checke(argv[i+1]);
        if ( ! checke )//error
        {
              std::cerr << "toc: could not open k " << argv[i+1] << std::endl;
              return 1;
         }
         check=argv[i+1];
          checker(check, texts);
      }else if(strcmp(argv[i], "-t") == 0){
          win=(argv[i+1]);
      }else if ( strcmp(argv[i], "call") == 0 ){
         /**if ( strcmp(argv[i+1], "-s") == 0 ){
        std::ifstream cal(argv[i+2]);
        if ( ! cal )//error
        {
              std::cerr << "toc: could not open " << argv[i+2] << std::endl;
              return 1;
         }
         texts=argv[i+2];
         } */
           game(texts,win);
         }
   }
    return 0;
}

int print_help()
{
	printf("%s",
		   "Create Bingo cards and simulate game sessions. Usage:\n"
           "bingo action [options]\n"
           "\n"
           "bingo generate NUMBER card.svg [-s symbols.txt]\n"
           "bingo simulate [card.idx] [-t type] [-s symbols.txt]\n");

	return 0;
}

int print_version()
{
	printf("%s",
		"bingo v1.0 [2014-Nov-07] Fernando González-Flores <fergo1207@gmail.com>\n"
		"Heiner Vindas-Chinchilla <heiner94_v@hotmail.com>\n"
		"\n"
		"This is free software distributed under Creative Commons Attribution 4.0\n"
		"International (CC BY 4.0) license.\n");

	return 0;
}

int main(int argc, char* argv[])
{

   if ( ! analyze_params(argc, argv) )//si parametros no se cumple no hacer nada
      return 1;
}
