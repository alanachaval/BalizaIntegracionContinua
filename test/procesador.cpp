#include "gtest/gtest.h"
#include "procesador.hpp"

TEST(Procesador, inicializa_en_estado_desconocido)
{
    dominio::Procesador *procesador = new dominio::Procesador();

    ASSERT_EQ(dominio::Procesador::Estados::kDesconocido, procesador->Estado());
}
