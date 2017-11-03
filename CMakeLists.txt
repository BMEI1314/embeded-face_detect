cmake_minimum_required(VERSION 3.1.0)

project(seeta_facedet_lib)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -mcpu=cortex-a17.cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations")

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++11 support has been enabled by default.")
SET(CMAKE_C_COMPILER   arm-hisiv300-linux-g++)
#SET(CMAKE_CXX_COMPILER  g++)

# Use SSE



include_directories(include)

set( src_files
   src/util/nms.cpp
    src/util/image_pyramid.cpp
    src/io/lab_boost_model_reader.cpp
    src/io/surf_mlp_model_reader.cpp
    src/feat/lab_feature_map.cpp
    src/feat/surf_feature_map.cpp
    src/classifier/lab_boosted_classifier.cpp
    src/classifier/mlp.cpp
    src/classifier/surf_mlp.cpp
    src/face_detection.cpp
    src/fust.cpp
    build/test.cpp

    
    )

# Build shared library
add_library(seeta_facedet_lib SHARED ${src_files})
add_library(seeta_facedet_static STATIC ${src_files})
#set_target_properties(seeta_facedet_lib PROPERTIES OUTPUT_NAME "face")
#set(facedet_required_libs seeta_facedet_lib)


   # message(STATUS "Build with examples.")
   # add_executable(facedet_test ${src_files})
        #target_link_libraries(facedet_test ${facedet_required_libs})
