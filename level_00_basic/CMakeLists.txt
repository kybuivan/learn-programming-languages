set( level_00
    "syntax_and_first_program"
    "input_and_output"
)

foreach(sublevel IN ITEMS ${level_00})
    add_subdirectory(${sublevel})
endforeach()