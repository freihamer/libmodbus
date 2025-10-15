cmake_minimum_required(VERSION 3.16)
project(libmodbus LANGUAGES C)

# ===========================
# Options
# ===========================
option(BUILD_SHARED_LIBS "Build shared instead of static" OFF)
option(LIBMODBUS_BUILD_EXAMPLES "Build example programs" OFF)
option(LIBMODBUS_BUILD_TESTS "Build unit tests" OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ===========================
# Sources
# ===========================
file(GLOB LIBMODBUS_SOURCES
    src/modbus.c
    src/modbus-data.c
    src/modbus-tcp.c
    src/modbus-rtu.c
)

file(GLOB LIBMODBUS_HEADERS
    src/modbus.h
    src/modbus-private.h
    src/modbus-tcp.h
    src/modbus-rtu.h
    src/modbus-version.h
)

# ===========================
# Target
# ===========================
add_library(modbus STATIC ${LIBMODBUS_SOURCES} ${LIBMODBUS_HEADERS})

target_include_directories(modbus
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Always define MODBUS_STATIC for both build & use
target_compile_definitions(modbus PUBLIC MODBUS_STATIC)

# ===========================
# Platform-specific linking
# ===========================
if (WIN32)
    target_link_libraries(modbus PUBLIC ws2_32)
else()
    target_link_libraries(modbus PUBLIC m)
endif()

# ===========================
# Install rules
# ===========================
include(GNUInstallDirs)

install(TARGETS modbus
    EXPORT modbusTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# install headers into include/modbus/
install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modbus.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modbus-tcp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modbus-rtu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modbus-version.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/modbus
)

install(EXPORT modbusTargets
    NAMESPACE modbus::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/modbus
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/modbusConfigVersion.cmake"
    VERSION 3.1.11
    COMPATIBILITY AnyNewerVersion
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modbusConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/modbusConfig.cmake"
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/modbusConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/modbusConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/modbus
)