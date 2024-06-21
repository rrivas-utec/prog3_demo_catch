//
// Created by rudri on 6/16/2024.
//

#include <iostream>
#include "demo.h"
#include "test.h"

static void test_3() {
  std::cout << "10";
}

TEST_CASE( "Demo 3", "[back]" ) {
  execute_test("test_3.in", test_3);
}