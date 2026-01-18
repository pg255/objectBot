cmake_minimum_required(VERSION 3.19)

project(objectBotSoulution)

# Here we can set some values for botcraft options
# They will still appear in cmake_gui in windows
set(BOTCRAFT_GAME_VERSION "1.21.1" CACHE STRING "" FORCE)
set(BOTCRAFT_BUILD_EXAMPLES OFF CACHE BOOL "")
set(BOTCRAFT_BUILD_DOC OFF CACHE BOOL "")

# Download Botcraft repo and add it to this cmake project
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
    Botcraft
    GIT_REPOSITORY https://github.com/adepierre/Botcraft.git
    GIT_TAG master
)
FetchContent_MakeAvailable(Botcraft)

# Add my-project to this cmake project
add_subdirectory(objectBot)
