/** 
* Point d'entré du programme
*/
//printf("\033[]60,10H🚘\n");


#include "../headers/main.h"


int main()
{

  char map[NBCOL][NBLIN];
  srand(time(NULL));
  map_loading (map);
  /*char c = menu ();
  if (c == 'f')
    run (0, map);
  else if (c == 'd')
    run (1, map);*/

  run (false, map);
  
  exit (1);
}
