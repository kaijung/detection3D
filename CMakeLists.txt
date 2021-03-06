
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(PROJECT_NAME "detection3D")
PROJECT("${PROJECT_NAME}")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add opencv package to the project
FIND_PACKAGE( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} ) 

SUBDIRS(vivalib detectionlib)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/vivalib ${CMAKE_SOURCE_DIR}/detectionlib) 

FILE(GLOB files
  "*.h"
  "*.cpp"
)
FILE(GLOB hidden
	".*"
)
FILE(GLOB resources
  "*.*"
)

MESSAGE(STATUS "Project Name: ${PROJECT_NAME}")
MESSAGE(STATUS "    OpenCV version: ${OpenCV_VERSION} ")
MESSAGE(STATUS "    libraries: ${OpenCV_LIBS}")
MESSAGE(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

ADD_EXECUTABLE(${PROJECT_NAME} ${files})
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${OpenCV_LIBS} vivalib detectionlib)

FILE(WRITE ${CMAKE_SOURCE_DIR}/input.txt "${CMAKE_SOURCE_DIR}/input/" )

LIST(REMOVE_ITEM resources ${files} ${hidden} "${CMAKE_SOURCE_DIR}/CMakeLists.txt")
FILE(COPY ${resources} DESTINATION "Debug")
FILE(COPY ${resources} DESTINATION "Release")





