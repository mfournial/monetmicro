cmake_minimum_required(VERSION 3.10)
link_directories(${Project_BINARY_DIR}/deps/lib)
include(ExternalProject)
add_executable(MicroMonet MicroMonet.cpp)
set_property(TARGET MicroMonet PROPERTY CXX_STANDARD 17)
ExternalProject_Add(googlebenchmark
	URL "https://github.com/google/benchmark/archive/v1.4.1.tar.gz"
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${Project_BINARY_DIR}/deps -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_BUILD_TYPE=Release
  )
add_dependencies(MicroMonet googlebenchmark)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(MicroMonet Threads::Threads)
target_link_libraries(MicroMonet ${Project_BINARY_DIR}/deps/lib/${CMAKE_SHARED_LIBRARY_PREFIX}benchmark.a)
target_link_libraries(MicroMonet ${Project_BINARY_DIR}/deps/lib/${CMAKE_SHARED_LIBRARY_PREFIX}benchmark_main.a)
target_link_libraries(MicroMonet ${Project_SOURCE_DIR}/libittnotify.a)
target_link_libraries(MicroMonet dl)
target_include_directories(MicroMonet SYSTEM PUBLIC ${Project_BINARY_DIR}/deps/include)
