#pragma once

#include "i_pet_sec.hpp"
#include <set>
#include <utility>

class TagReader : public ITagReader {
public:
  virtual void subscribe(ISubscriber* sub) override;
  void simulateScan(std::string petTag);
private:
  std::set<ISubscriber*> _subscribers;
};

class Database : public IDatabase {
public:
  virtual bool isMyPet(std::string id) override;
};

class Door : public IDoor {
public:
  virtual void open() override;
  virtual void close() override;
};

class TagCodec {
public:
  static std::pair<std::string, std::string> decode(std::string tag);
};

class PetSec : public ITagReader::ISubscriber {
public:
  PetSec(ITagReader& reader, IDatabase& db, IDoor& door);
  // From ItagReader::ISubscriber
  virtual void onTag(std::string tag) override;
private:
  ITagReader& _reader;
  IDatabase& _db;
  IDoor& _door;
};
