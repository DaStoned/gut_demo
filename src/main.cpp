#include "pet_door.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  TagReader tagReader;
  Display display;
  PetDoor door(tagReader, display);

  door.addPet("PussyCat");
  door.addPet("Doggy");

  tagReader.touchTag("StrayCat");
  tagReader.touchTag("Doggy");

  return 0;
}
