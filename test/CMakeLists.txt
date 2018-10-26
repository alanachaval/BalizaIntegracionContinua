add_executable(
    unit_tests
    procesador.cpp
    mocks/mock_controlador_led.cpp
    mocks/mock_request.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    gmock_main
    dominio
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
