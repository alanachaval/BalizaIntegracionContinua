#ifndef BALIZAINTEGRACIONCONTINUA_ESTADO_DEL_BUILD_H_
#define BALIZAINTEGRACIONCONTINUA_ESTADO_DEL_BUILD_H_

namespace dominio
{

enum EstadoDelBuild
{
  kEstadoDesconocido = 0,
  kEstadoCorrecto = 1,
  kEstadoIncorrecto = 2
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_ESTADO_DEL_BUILD_H_