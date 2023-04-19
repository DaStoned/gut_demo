#include "pet_sec.hpp"
#include <iostream>
#include <ranges>

using namespace std;

void TagReader::subscribe(ISubscriber* sub) {
  _subscribers.insert(sub);
}

void TagReader::simulateScan(string tag) {
  for (auto sub : _subscribers) {
    sub->onTag(tag);
  }
}

bool Database::isMyPet(std::string id) {
  return id == "DEADBEEF";
}

void Door::open() {
  cout << "Open door" << endl;
}

void Door::close() {
  cout << "Close door" << endl;
}

pair<string, string> TagCodec::decode(string tag) {
  auto it = views::split(tag, ':').begin();
  string id {(*it).begin(), (*it).end()};
  it++;
  string name {(*it).begin(), (*it).end()};
  return pair(id, name);
}

PetSec::PetSec(ITagReader& reader, IDatabase& db, IDoor& door)
: _reader(reader)
, _db(db)
, _door(door)
{
  _reader.subscribe(this);
}

void PetSec::onTag(string tag) {
  auto id = TagCodec::decode(tag).first;
  auto name = TagCodec::decode(tag).second;

  if (_db.isMyPet(id)) {
    cout << name << ": is my pet, welcome" << endl;
    _door.open();
  } else {
    cout << name << ": unknown pet, shooo!" << endl;
    _door.close();
  }
}
