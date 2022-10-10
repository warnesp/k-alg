
find_package(Catch2 2 REQUIRED)

add_executable(UnitTest-kalg
    src/UnitTest.kalg.cpp
    )

set_property(TARGET UnitTest-kalg PROPERTY CXX_STANDARD 17)

target_link_libraries (UnitTest-kalg
    PRIVATE
    KAlg
    Catch2::Catch2WithMain
    )

include(Catch)
catch_discover_tests(UnitTest-kalg)
