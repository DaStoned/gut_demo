#pragma once

#include <string>

struct ITagReader {
  struct ISubscriber {
    virtual void onTag(std::string petTag) = 0;
  };
  virtual void subscribe(ISubscriber* sub) = 0;
};

struct IDatabase {
  virtual bool isMyPet(std::string id) = 0;
};

struct IDoor {
  virtual void open() = 0;
  virtual void close() = 0;
};
