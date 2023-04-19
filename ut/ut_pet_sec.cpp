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
    // Prime the mocks
    EXPECT_CALL(mockReader, subscribe(_))
      .Times(AnyNumber());
    sec = new PetSec(mockReader, mockDb, mockDoor);
  }

  void TearDown() override {
    delete sec;
  }
};

TEST_F(UtPetSec, CloseDoorToStrayAnimal) {
  EXPECT_CALL(mockDb, isMyPet("00000000"))
    .Times(AnyNumber())
    .WillRepeatedly(Return(false));
  EXPECT_CALL(mockDoor, close())
    .Times(1);
  sec->onTag("00000000:NoSuchCat");
}

TEST_F(UtPetSec, OpenDoorToMyPet) {
  EXPECT_CALL(mockDb, isMyPet("12345678"))
    .Times(AnyNumber())
    .WillRepeatedly(Return(true));
  EXPECT_CALL(mockDoor, open())
    .Times(1);
  sec->onTag("12345678:ScruffyDog");
}

