#pragma once

#include "i_pet_sec.hpp"
#include "gmock/gmock.h"

struct MockTagReader : public ITagReader {
  MOCK_METHOD(void, subscribe, (ISubscriber*), (override));
};

struct MockDatabase : public IDatabase {
  MOCK_METHOD(bool, isMyPet, (std::string), (override));
};

struct MockDoor : public IDoor {
  MOCK_METHOD(void, open, (), (override));
  MOCK_METHOD(void, close, (), (override));
  MOCK_METHOD(bool, isOpen, (), (const, override));
};
