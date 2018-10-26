add_library(dominio "")

target_sources(
    dominio
    PRIVATE
        procesador.cpp
        visualizador_de_estado.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/controlador_led.hpp
        ${CMAKE_CURRENT_LIST_DIR}/estado_del_build.hpp
        ${CMAKE_CURRENT_LIST_DIR}/procesador.hpp
        ${CMAKE_CURRENT_LIST_DIR}/request.hpp
        ${CMAKE_CURRENT_LIST_DIR}/visualizador_de_estado.hpp
    )

target_include_directories(
    dominio
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
