// Copyright (c) 2016-2019, Mathias Lüdtke, AutonomouStuff
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <gtest/gtest.h>

#include <string>

#include "socketcan_interface/string.hpp"

TEST(StringTest, stringconversion)
{
  const std::string s1("123#1234567812345678");
  can::Frame f1 = can::toframe(s1);
  EXPECT_EQ(s1, can::tostring(f1, true));

  const std::string s2("1337#1234567812345678");
  can::Frame f2 = can::toframe(s2);
  EXPECT_FALSE(f2.isValid());

  const std::string s3("80001337#1234567812345678");
  can::Frame f3 = can::toframe(s3);
  EXPECT_EQ(s3, can::tostring(f3, true));
}

// Run all the tests that were declared with TEST()
int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
