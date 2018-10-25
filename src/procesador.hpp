#ifndef BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_
#define BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_

namespace dominio
{

class Procesador
{
public:
  enum Estados
  {
    kDesconocido = 0
  };

  Estados Estado();
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_