add_library(dominio "")

target_sources(
    dominio
    PRIVATE
        procesador.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/procesador.hpp
    )

target_include_directories(
    dominio
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
