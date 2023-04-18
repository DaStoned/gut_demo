#include "pet_door.hpp"
#include "mock_pet_door.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

struct UtPetDoor : public Test {
  MockTagReader mockTagReader;
  MockDisplay mockDisplay;

  PetDoor door = {mockTagReader, mockDisplay};

  void SetUp() override {
    // Prime the mocks
    EXPECT_CALL(mockTagReader, subscribe(_))
      .Times(1);
  }
};

TEST_F(UtPetDoor, SomePetting) {
  EXPECT_CALL(mockDisplay, show(StrEq("Shaggy: is my pet, welcome")))
    .Times(1);
  door.addPet("Shaggy");
  door.onTag("Shaggy");
}

