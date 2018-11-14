#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_

#include "../manejadores/manejador.hpp"
#include "cliente_wifi.hpp"
#include "../dominio/estado_del_build.hpp"
#include "../dominio/procesador.hpp"
#include <vector>
#include <map>

namespace adaptadores
{

class ServidorWiFi
{
public:
  ServidorWiFi(Procesador *procesador, ClienteWiFi *cliente_wifi);
  virtual void Iniciar(const char *ssid, const char *password);
  virtual const char *ObtenerIP();
  virtual void AtenderCliente();

private:
  void LeerRequest(WiFiClient *cliente, std::vector<std::string> *request, int *fin_header, bool *es_post);
  void AnalizarPayload(int fin_header, std::vector<std::string> *request, std::map<std::string, std::string> *datos);
  void EnviarRespuesta(WiFiClient *cliente, std::vector<std::string> *request, std::map<std::string, std::string> *datos);
  std::map<std::string, manejadores::Manejador *> manejadores_;
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_