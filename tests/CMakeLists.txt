if(ENABLE_TESTING)
    set(TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")
    set(TEST_HEADERS "")

    add_executable(unit_tests ${TEST_SOURCES} ${TEST_HEADERS})

    target_link_libraries(unit_tests PRIVATE Catch2::Catch2)

    target_set_warnings(
        TARGET
        unit_tests
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()
