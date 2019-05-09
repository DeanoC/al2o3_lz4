cmake_minimum_required(VERSION 3.13)
set(LibName al2o3_lz4)
project(${LibName})

include(FetchContent)
FetchContent_Declare( al2o3 GIT_REPOSITORY https://github.com/DeanoC/al2o3 GIT_TAG master )
FetchContent_GetProperties(al2o3)
if(NOT al2o3_POPULATED)
	FetchContent_Populate(al2o3)
	add_subdirectory(${al2o3_SOURCE_DIR} ${al2o3_BINARY_DIR})
endif()

FetchContent_Declare(
		lz4_lz4
		GIT_REPOSITORY https://github.com/lz4/lz4.git
		GIT_TAG master
)
FetchContent_GetProperties(lz4_lz4)
if(NOT lz4_lz4_POPULATED)
	FetchContent_Populate(lz4_lz4)
endif()

set(Interface
		lz4.h
		)
set(Src
		lz4.c
		)

set(Deps
		al2o3_platform
		)

ADD_LIB(${LibName} "${Interface}" "${Src}" "${Deps}")
target_include_directories(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR})
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/lz4.c)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/lz4.h)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/lz4frame.c)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/lz4frame.h)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/lz4hc.c)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/lz4hc.h)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/xxhash.c)
target_sources(${LibName} PRIVATE ${lz4_lz4_SOURCE_DIR}/lib/xxhash.h)
