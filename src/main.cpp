#include "pet_sec.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  TagReader tagReader;
  Database db;
  Door door;
  PetSec sec(tagReader, db, door);

  if (argc >= 2) {
    tagReader.simulateScan(argv[1]);
  }
  return 0;
}
