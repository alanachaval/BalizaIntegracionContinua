#include "index.hpp"

using namespace manejadores;

std::string Index::Responder(std::map<std::string, std::string> *datos)
{
    return "\
<!DOCTYPE html>\r\n\
<html>\r\n\
 <head>\r\n\
  <meta charset=\"utf-8\">\r\n\
  <title>Configuracion Baliza</title>\r\n\
  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>\r\n\
  <link rel=\"icon\" href=\"data:,\"/>\r\n\
  <script>\r\n\
   function httpPostAsync(url, payload, callback)\r\n\
   {\r\n\
    var xmlHttp = new XMLHttpRequest();\r\n\
    xmlHttp.onreadystatechange = function()\r\n\
    { \r\n\
     if (xmlHttp.readyState == 4 && xmlHttp.status == 200)\r\n\
     {\r\n\
      callback(xmlHttp.responseText);\r\n\
     }\r\n\
    };\r\n\
    xmlHttp.open(\"POST\", url, true);\r\n\
    xmlHttp.send(payload);\r\n\
   }\r\n\
   function actualizar()\r\n\
   {\r\n\
    httpPostAsync(\"/estado\", \"\\n\\n\", function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
     datos = response.split(/\\r?\\n/g);\r\n\
     document.getElementById(\"estado_conexion\").innerHTML = datos[0].split(\": \")[1];\r\n\
     document.getElementById(\"estado_integracion_continua\").innerHTML = datos[1].split(\": \")[1];\r\n\
    });\r\n\
   }\r\n\
   function setWifi()\r\n\
   {\r\n\
    red_wifi = document.getElementById(\"red_wifi\").value;\r\n\
    clave_red_wifi = document.getElementById(\"clave_red_wifi\").value;\r\n\
    payload = \"red_wifi:\" + red_wifi + \"\\nclave_red_wifi:\" + clave_red_wifi + \"\\n\\n\";\r\n\
    httpPostAsync(\"/red\", payload, function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
     document.getElementById(\"red_modificada\").style.visibility = \"visible\";\r\n\
    });\r\n\
   }\r\n\
   function setRepositorioTravis()\r\n\
   {\r\n\
    repositorio = document.getElementById(\"repositorio_travis\").value;\r\n\
    token = document.getElementById(\"token_travis\").value;\r\n\
    payload = \"repositorio:\" + repositorio + \"\\ntoken:\" + token + \"\\n\\n\";\r\n\
    httpPostAsync(\"/repositorio_travis\", payload, function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
     document.getElementById(\"repositorio_modificado_travis\").style.visibility = \"visible\";\r\n\
    });\r\n\
   }\r\n\
   function setRepositorioJenkins()\r\n\
   {\r\n\
    url = document.getElementById(\"url_jenkins\").value;\r\n\
    repositorio = document.getElementById(\"repositorio_jenkins\").value;\r\n\
    usuario = document.getElementById(\"usuario_jenkins\").value;\r\n\
    token = document.getElementById(\"token_jenkins\").value;\r\n\
    payload = \"url:\" + url + \"\\nrepositorio:\" + repositorio + \"\\nusuario:\" + usuario + \"\\ntoken:\" + token + \"\\n\\n\";\r\n\
    httpPostAsync(\"/repositorio_jenkins\", payload, function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
     document.getElementById(\"repositorio_modificado_jenkins\").style.visibility = \"visible\";\r\n\
    });\r\n\
   }\r\n\
   function showTravis(){\r\n\
       document.getElementById('tabla_travis').style.display = 'table';\r\n\
       document.getElementById('tabla_jenkins').style.display = 'none';\r\n\
   }\r\n\
   function showJenkins(){\r\n\
       document.getElementById('tabla_jenkins').style.display = 'table';\r\n\
       document.getElementById('tabla_travis').style.display = 'none';\r\n\
   }\r\n\
 </script>\r\n\
 </head>\r\n\
 <body>\r\n\
  <h1>\r\n\
   Configuracion Baliza\r\n\
  </h1>\r\n\
  <table border=\"2\">\r\n\
   <tr>\r\n\
    <td>\r\n\
     Estado Conexion:\r\n\
    </td>\r\n\
    <td id=\"estado_conexion\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Estado Integracion Continua:\r\n\
    </td>\r\n\
    <td id=\"estado_integracion_continua\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td colspan=\"2\">\r\n\
     <button onClick=\"actualizar();\">\r\n\
      Actualizar\r\n\
     </button>\r\n\
    </td>\r\n\
   </tr>\r\n\
  </table>\r\n\
  <br/>\r\n\
  <table border=\"2\">\r\n\
   <tr>\r\n\
    <td>\r\n\
     Red WiFi:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"red_wifi\" type=\"text\" name=\"red_wifi\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Clave red WiFi:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"clave_red_wifi\" type=\"text\" name=\"clave_red_wifi\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td id=\"red_modificada\" style=\"visibility:hidden\" colspan=\"2\">\r\n\
     Red Modificada\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td colspan=\"2\">\r\n\
     <button onClick=\"setWifi();\">\r\n\
      Aceptar\r\n\
     </button>\r\n\
    </td>\r\n\
   </tr>\r\n\
  </table>\r\n\
  <br/>\r\n\
  <table border=\"1\">\r\n\
   <tr>\r\n\
    <td>\r\n\
     <button onClick=\"showTravis();\">\r\n\
      Travis\r\n\
     </button>\r\n\
     <button onClick=\"showJenkins();\">\r\n\
      Jenkins\r\n\
     </button>\r\n\
    </td>\r\n\
   </tr>\r\n\
  </table>\r\n\
  <table id=\"tabla_travis\" border=\"2\">\r\n\
   <tr>\r\n\
    <td>\r\n\
     Repositorio:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"repositorio_travis\" type=\"text\" name=\"repositorio_travis\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Token:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"token_travis\" type=\"text\" name=\"token_travis\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td id=\"repositorio_modificado_travis\" style=\"visibility:hidden\" colspan=\"2\">\r\n\
     Repositorio Modificado\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td colspan=\"2\">\r\n\
     <button onClick=\"setRepositorioTravis();\">\r\n\
      Aceptar\r\n\
     </button>\r\n\
    </td>\r\n\
   </tr>\r\n\
  </table>\r\n\
  <table id=\"tabla_jenkins\" border=\"2\" style=\"display:none\">\r\n\
   <tr>\r\n\
    <td>\r\n\
     URL (con puerto):\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"url_jenkins\" type=\"text\" name=\"url_jenkins\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Repositorio:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"repositorio_jenkins\" type=\"text\" name=\"repositorio_jenkins\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Usuario:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"usuario_jenkins\" type=\"text\" name=\"usuario_jenkins\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Token:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"token_jenkins\" type=\"text\" name=\"token_jenkins\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td id=\"repositorio_modificado_jenkins\" style=\"visibility:hidden\" colspan=\"2\">\r\n\
     Repositorio Modificado\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td colspan=\"2\">\r\n\
     <button onClick=\"setRepositorioJenkins();\">\r\n\
      Aceptar\r\n\
     </button>\r\n\
    </td>\r\n\
   </tr>\r\n\
  </table>\r\n\
 </body>\r\n\
</html>";
}