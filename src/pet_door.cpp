#include "pet_door.hpp"
#include <set>
#include <iostream>

using namespace std;

void TagReader::subscribe(ISubscriber* sub) {
  _subscribers.insert(sub);
}

void TagReader::touchTag(string tag) {
  for (auto sub : _subscribers) {
    sub->onTag(tag);
  }
}

void Display::show(std::string text) {
  cout << text << endl;
}

PetDoor::PetDoor(ITagReader& tagReader, IDisplay& display)
: _tagReader(tagReader)
, _display(display)
{
  _tagReader.subscribe(this);
  _display.show("Pet Door v1.0");
}

bool PetDoor::addPet(string petTag) {
  if (0 == _myPets.count(petTag)) {
    _myPets.insert(petTag);
    return true;
  }
  return false;
}

void PetDoor::onTag(string tag) {
  if (0 == _myPets.count(tag)) {
    _display.show(tag + ": unknown pet, shooo!");
  } else {
    _display.show(tag + ": is my pet, welcome");
  }
}

