#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LUZ_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LUZ_H_

namespace adaptadores
{

class ControladorLuz
{
public:
  virtual void PrenderLuzRoja() = 0;
  virtual void ApagarLuzRoja() = 0;
  virtual void PrenderLuzVerde() = 0;
  virtual void ApagarLuzVerde() = 0;
  virtual void PrenderLuzAmarilla() = 0;
  virtual void ApagarLuzAmarilla() = 0;
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LUZ_H_