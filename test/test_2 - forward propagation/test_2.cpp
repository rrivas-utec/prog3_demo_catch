//
// Created by rudri on 6/16/2024.
//

#include <iostream>
#include "demo.h"
#include "test.h"

static void test_2() {
  std::cout << "10";
}

TEST_CASE( "Factorials are computed", "[forward]" ) {
  execute_test("test_2.in", test_2);
}