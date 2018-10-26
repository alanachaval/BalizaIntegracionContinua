add_library(dominio "")

target_sources(
    dominio
    PRIVATE
        dominio/procesador.cpp
        dominio/visualizador_de_estado.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/adaptadores/controlador_led.hpp
        ${CMAKE_CURRENT_LIST_DIR}/adaptadores/request.hpp
        ${CMAKE_CURRENT_LIST_DIR}/dominio/estado_del_build.hpp
        ${CMAKE_CURRENT_LIST_DIR}/dominio/procesador.hpp
        ${CMAKE_CURRENT_LIST_DIR}/dominio/visualizador_de_estado.hpp
    )

target_include_directories(
    dominio
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
