//
// Created by rudri on 6/16/2024.
//

#include <iostream>
#include "demo.h"
#include "test.h"

static void test_2() {
  std::cout << "Test 2";
}

TEST_CASE( "Factorials are computed", "[demo]" ) {
  execute_test("test_2.in", test_2);
}