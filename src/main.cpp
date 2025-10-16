#include "../include/logic.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

// g++ main.cpp logic.cpp -o main.exe -I../include
// .\main
int main()
{
  std::fstream file("../data/01.07.2016.csv");
  std::fstream file_all_ships("../data/ships.csv");

  Ships ships = getShipsFromFile(file);
  fakeids fake_ids = getFakeIDsFromFile(file_all_ships);

  std::cout << ships.size() << std::endl;
  ships.clearFake(fake_ids);
  std::cout << ships.size() << std::endl;

  ships.removeDuplicates();

  file.close();
  file_all_ships.close();

  return 0;
}