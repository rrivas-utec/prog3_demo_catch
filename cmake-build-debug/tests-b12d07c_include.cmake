if(EXISTS "C:/Users/rudri/CLionProject/test_demo/cmake-build-debug/tests-b12d07c_tests.cmake")
  include("C:/Users/rudri/CLionProject/test_demo/cmake-build-debug/tests-b12d07c_tests.cmake")
else()
  add_test(tests_NOT_BUILT-b12d07c tests_NOT_BUILT-b12d07c)
endif()
