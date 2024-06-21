//
// Created by rudri on 6/16/2024.
//

#include "demo.h"
#include "test.h"



TEST_CASE( "Suma de matrices", "[matrix]" ) {
  REQUIRE( factorial( 1) == 1 );
  REQUIRE( factorial( 2) == 2 );
  REQUIRE( factorial( 3) == 6 );
  REQUIRE( factorial(10) == 3628800 );
}