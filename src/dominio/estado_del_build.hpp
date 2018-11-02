#ifndef BALIZAINTEGRACIONCONTINUA_DOMINIO_ESTADO_DEL_BUILD_H_
#define BALIZAINTEGRACIONCONTINUA_DOMINIO_ESTADO_DEL_BUILD_H_

namespace dominio
{

enum EstadoDelBuild
{
  kEstadoDesconectado = 0,
  kEstadoCorrecto = 1,
  kEstadoIncorrecto = 2,
  kEstadoEjecutando = 3
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_DOMINIO_ESTADO_DEL_BUILD_H_
