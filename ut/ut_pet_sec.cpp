#include "pet_sec.hpp"
#include "mock_pet_door.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

struct UtPetSec : public Test {
  MockTagReader mockReader;
  MockDatabase mockDb;
  MockDoor mockDoor;

  PetSec* sec = nullptr;

  void SetUp() override {
    // Create stubs
    EXPECT_CALL(mockReader, subscribe(_));
    // Create module under test
    sec = new PetSec(mockReader, mockDb, mockDoor);
  }

  void TearDown() override {
    delete sec;
  }
};

TEST_F(UtPetSec, CloseDoorToStrayAnimal) {
  // Prime the mocks
  EXPECT_CALL(mockDb, isMyPet("00000000"))
    .Times(AnyNumber())
    .WillRepeatedly(Return(false));
  EXPECT_CALL(mockDoor, close())
    .Times(1);
  // Run the test
  sec->onTag("00000000:NoSuchCat");
}

TEST_F(UtPetSec, OpenDoorToMyPet) {
  // Prime the mocks
  EXPECT_CALL(mockDb, isMyPet("12345678"))
    .Times(AnyNumber())
    .WillRepeatedly(Return(true));
  EXPECT_CALL(mockDoor, open())
    .Times(1);
  // Run the test
  sec->onTag("12345678:ScruffyDog");
}

