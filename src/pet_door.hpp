#pragma once

#include "i_pet_door.hpp"
#include <set>

class TagReader : public ITagReader {
public:
  virtual void subscribe(ISubscriber* sub) override;
  void touchTag(std::string tag);
private:
  std::set<ISubscriber*> _subscribers;
};

class Display : public IDisplay {
public:
  virtual void show(std::string text) override;
};

class PetDoor : public ITagReader::ISubscriber {
public:
  PetDoor(ITagReader& tagReader, IDisplay& display);
  bool addPet(std::string myPet);
  // From ItagReader::ISubscriber
  virtual void onTag(std::string tag) override;
private:
  std::set<std::string> _myPets;
  ITagReader& _tagReader;
  IDisplay& _display;
};
