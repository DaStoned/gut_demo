#include "pet_sec.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(UtTagCodec, DecodeSuccessful) {
  auto idNamePair = TagCodec::decode("Foo:Bar");
  EXPECT_EQ("Foo", idNamePair.first);
  EXPECT_EQ("Bar", idNamePair.second);
  idNamePair = TagCodec::decode(":Foobar");
  EXPECT_EQ("", idNamePair.first);
  EXPECT_EQ("Foobar", idNamePair.second);
}
