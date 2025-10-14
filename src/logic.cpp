#include "../include/logic.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

float convertToFloat(std::string str)
{
  size_t comma_pos = str.find(',');
  if (comma_pos != std::string::npos)
  {
    str[comma_pos] = '.';
  }
  return strtof(str.c_str(), nullptr);
}

std::string removeQuotes(const std::string str)
{
  return str.substr(1, str.length() - 2);
}

bool isShipExist(ShipCell ship, std::vector<int> not_allowed_ids)
{
  for (int i = 0; i < not_allowed_ids.size(); i++)
  {
    if (ship.id_marine == not_allowed_ids[i])
      return false;
  }
  return true;
};

void handleFileOpening(std::fstream &file)
{
  // TODO: Нужно добавить логику выхода из программы при соблюдении этого
  // условия
  if (!file.is_open())
  {
    std::cout << "File is not exits.Please check path to File." << std::endl;
  }
}

Ships getShipsFromFile(std::fstream &file)
{
  handleFileOpening(file);

  Ships result;
  std::string line;
  std::string token;
  bool is_init = false;

  while (std::getline(file, line))
  {
    if (!is_init)
    {
      is_init = true;
      continue;
    }

    std::vector<std::string> tokens;
    std::istringstream tokenStream(line);
    ShipCell ship;

    while (std::getline(tokenStream, token, ';'))
    {
      tokens.push_back(removeQuotes(token));
    }

    if (tokens.size() >= 8)
    {
      ship.id_track = std::stoi(tokens[0]);
      ship.id_marine = std::stoi(tokens[1]);
      ship.lat = convertToFloat(tokens[2]);
      ship.lon = convertToFloat(tokens[3]);
      ship.speed = std::stoi(tokens[4]);
      ship.course = std::stoi(tokens[5]);
      ship.age = std::stoi(tokens[6]);
      ship.date_add = tokens[7];
    }

    result.push_back(ship);
  }

  return result;
};

std::vector<int> getFakeIDsFromFile(std::fstream &file)
{
  handleFileOpening(file);

  std::vector<int> result;
  std::string line;
  std::string token;
  bool is_init = false;

  while (std::getline(file, line))
  {
    if (!is_init)
    {
      is_init = true;
      continue;
    }

    std::vector<std::string> tokens;
    std::istringstream tokenStream(line);

    while (std::getline(tokenStream, token, ';'))
    {
      tokens.push_back(removeQuotes(token));
    }

    if (tokens[6] == "0" || tokens[6] == "")
    {
      result.push_back(std::stoi(tokens[0]));
    }
  }

  return result;
}

void Ships::clearFake(const std::vector<int> &fake_ids)
{
  ships.erase(
      std::remove_if(
          ships.begin(),
          ships.end(),
          [&fake_ids](const ShipCell &cell)
          {
            return !isShipExist(cell, fake_ids);
          }),
      ships.end());
}