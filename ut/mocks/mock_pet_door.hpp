#pragma once

#include "i_pet_door.hpp"
#include "gmock/gmock.h"

struct MockTagReader : public ITagReader {
  MOCK_METHOD(void, subscribe, (ISubscriber*), (override));
};

struct MockDisplay : public IDisplay {
  MOCK_METHOD(void, show, (std::string), (override));
};
