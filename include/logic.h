#ifndef LOGIC_H
#define LOGIC_H
#include <fstream>
#include <string>
#include <vector>

using fakeids = std::vector<int>;

struct ShipCell
{
  int id_track;
  int id_marine;
  float lat;
  float lon;
  int speed;
  int course;
  int age;
  std::string date_add;
  bool operator<(ShipCell b) const;
};

class Ships
{
private:
  std::vector<ShipCell> ships;

public:
  Ships() = default;
  Ships(const std::vector<ShipCell> &initial_ships)
  {
    ships = initial_ships;
  }
  Ships(size_t size) : ships(size) {};

  // std::vector methods
  void push_back(const ShipCell &cell)
  {
    ships.push_back(cell);
  }
  size_t size() const
  {
    return ships.size();
  }

  auto begin() { return ships.begin(); };
  auto end() { return ships.end(); };

  ShipCell &operator[](size_t index) { return ships[index]; };

  void clearFake(const fakeids &fake_ids);
  void removeDuplicates();
};

float convertToFloat(std::string str);
std::string removeQuotes(const std::string str);

bool isShipExist(ShipCell ship, fakeids not_allowed_ids);

Ships getShipsFromFile(std::fstream &file);
std::vector<int> getFakeIDsFromFile(std::fstream &file);

#endif // LOGIC_H