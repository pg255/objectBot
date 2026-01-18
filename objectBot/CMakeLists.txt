project(objectBot)

# Declaring source files
set(SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Declaring my headers (this is not strictly
# necessary, but this will add them to the file
# structure in visual on windows)
set(HDR_FILES
    # ${PROJECT_SOURCE_DIR}/include/header.hpp
)

# Create my target
add_executable(${PROJECT_NAME} ${HDR_FILES} ${SRC_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add my include folder to the include path
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Linking my code to botcraft, cmake will handle all the dependencies automatically
target_link_libraries(${PROJECT_NAME} botcraft)

# All this stuff is not really necessary, we just set the output folder
# to be the same as botcraft so we don't need to manually copy the shared
# library next to the executable
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${PROJECT_NAME} PROPERTIES RELWITHDEBINFO_POSTFIX "_rd")
if(MSVC)
    # To avoid having one subfolder per configuration when building with Visual
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BOTCRAFT_OUTPUT_DIR}/bin")
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BOTCRAFT_OUTPUT_DIR}/bin")
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${BOTCRAFT_OUTPUT_DIR}/bin")
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${BOTCRAFT_OUTPUT_DIR}/bin")

    set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${BOTCRAFT_OUTPUT_DIR}/bin")
    set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded")
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BOTCRAFT_OUTPUT_DIR}/bin")
endif(MSVC)
