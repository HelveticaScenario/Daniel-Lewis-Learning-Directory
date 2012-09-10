# Install script for directory: /Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Box2D.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision" TYPE FILE FILES
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/b2BroadPhase.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/b2Collision.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/b2Distance.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/b2DynamicTree.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/b2TimeOfImpact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision/Shapes" TYPE FILE FILES
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/Shapes/b2CircleShape.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/Shapes/b2EdgeShape.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/Shapes/b2ChainShape.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/Shapes/b2PolygonShape.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Collision/Shapes/b2Shape.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Common" TYPE FILE FILES
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2BlockAllocator.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2Draw.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2GrowableStack.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2Math.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2Settings.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2StackAllocator.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Common/b2Timer.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics" TYPE FILE FILES
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2Body.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2ContactManager.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2Fixture.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2Island.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2TimeStep.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2World.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/b2WorldCallbacks.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Contacts" TYPE FILE FILES
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2CircleContact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2Contact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2ContactSolver.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Contacts/b2PolygonContact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Joints" TYPE FILE FILES
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2DistanceJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2FrictionJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2GearJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2Joint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2MouseJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2PrismaticJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2PulleyJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2RevoluteJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2RopeJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2WeldJoint.h"
    "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Dynamics/Joints/b2WheelJoint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Rope" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Rope/b2Rope.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Debug/libBox2D.a")
    IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
      EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
    ENDIF()
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Release/libBox2D.a")
    IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
      EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
    ENDIF()
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/MinSizeRel/libBox2D.a")
    IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
      EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
    ENDIF()
  ELSEIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/RelWithDebInfo/libBox2D.a")
    IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
      EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
    ENDIF()
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake")
    FILE(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake"
         "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
    IF(EXPORT_FILE_CHANGED)
      FILE(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets-*.cmake")
      IF(OLD_CONFIG_FILES)
        MESSAGE(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        FILE(REMOVE ${OLD_CONFIG_FILES})
      ENDIF(OLD_CONFIG_FILES)
    ENDIF(EXPORT_FILE_CHANGED)
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-debug.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-minsizerel.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-relwithdebinfo.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-release.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/contrarian/github/local/Daniel-Lewis-Learning-Directory/C++/LearnC++/Box2D_v2.2.1/Box2D/Box2DConfig.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

