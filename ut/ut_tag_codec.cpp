#include "pet_sec.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(UtTagCodec, DecodeSuccessful) {
  EXPECT_EQ("Foo", TagCodec::decode("Foo:Bar").first);
  EXPECT_EQ("Bar", TagCodec::decode("Foo:Bar").second);
  EXPECT_EQ("", TagCodec::decode(":Foobar").first);
  EXPECT_EQ("Foobar", TagCodec::decode(":Foobar").second);
}
