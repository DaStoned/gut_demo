#include "pet_sec.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

struct UtDoor : public Test {
  Door door;
};

TEST_F(UtDoor, DoorOpensAndCloses) {
  EXPECT_FALSE(door.isOpen());
  door.open();
  EXPECT_TRUE(door.isOpen());
  door.close();
  EXPECT_FALSE(door.isOpen());
}
