cmake_minimum_required(VERSION 2.6)

project(SUSYMassInsertion)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "-Wall ${GSL_CFLAGS} ${ROOT_CFLAGS} -DBOOST_NO_CXX11_RVALUE_REFERENCES")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../gslpp/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../StandardModel/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../boost)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Observables/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Flavour/src)
include_directories(${BOOST_INC})

file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(SUSYMassInsertion ${LIBTYPE} ${srcs})

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
INSTALL(FILES ${headers} DESTINATION include/HEPfit COMPONENT header)

