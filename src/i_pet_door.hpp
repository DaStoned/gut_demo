#pragma once

#include <string>

struct ITagReader {
  struct ISubscriber {
    virtual void onTag(std::string tag) = 0;
  };
  virtual void subscribe(ISubscriber* sub) = 0;
};

struct IDisplay {
  virtual void show(std::string text) = 0;
};
