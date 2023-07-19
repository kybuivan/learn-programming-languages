set( level10
)

foreach(sublevel IN ITEMS ${level10})
    add_subdirectory(${sublevel})
endforeach()