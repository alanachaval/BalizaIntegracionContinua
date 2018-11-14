#ifndef BALIZAINTEGRACIONCONTINUA_DOMINIO_ESTADO_DEL_BUILD_H_
#define BALIZAINTEGRACIONCONTINUA_DOMINIO_ESTADO_DEL_BUILD_H_

namespace dominio
{

enum EstadoDelBuild
{
  kEstadoDesconectado = 0b1,
  kEstadoCorrecto = 0b10,
  kEstadoIncorrecto = 0b100,
  kEstadoEjecutando = 0b1000
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_DOMINIO_ESTADO_DEL_BUILD_H_
