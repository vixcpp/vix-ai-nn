cmake_minimum_required(VERSION 3.20)

#[[
Vix.AI NN — assert-based tests
]]

add_executable(vix_ai_nn_test_layers layers_tests.cpp)
target_link_libraries(vix_ai_nn_test_layers PRIVATE Vix::AI::nn)
target_compile_features(vix_ai_nn_test_layers PRIVATE cxx_std_20)
add_test(NAME nn_layers COMMAND vix_ai_nn_test_layers)

add_executable(vix_ai_nn_test_optimizers optimizers_tests.cpp)
target_link_libraries(vix_ai_nn_test_optimizers PRIVATE Vix::AI::nn)
target_compile_features(vix_ai_nn_test_optimizers PRIVATE cxx_std_20)
add_test(NAME nn_optimizers COMMAND vix_ai_nn_test_optimizers)

add_executable(vix_ai_nn_test_network network_tests.cpp)
target_link_libraries(vix_ai_nn_test_network PRIVATE Vix::AI::nn)
target_compile_features(vix_ai_nn_test_network PRIVATE cxx_std_20)
add_test(NAME nn_network COMMAND vix_ai_nn_test_network)
