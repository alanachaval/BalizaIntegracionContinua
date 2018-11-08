#include "index.hpp"

using namespace manejadores;

std::string Index::Responder(std::map<std::string, std::string> datos)
{
    return "\
<!DOCTYPE html>\r\n\
<html>\r\n\
 <head>\r\n\
  <meta charset=\"utf-8\">\r\n\
  <title>Configuracion Baliza</title>\r\n\
  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>\r\n\
  <link rel=\"icon\" href=\"data:,\"/>\r\n\
  <style>\r\n\
   html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }\r\n\
   .button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }\r\n\
   .button2 { background-color: #555555; }\r\n\
  </style>\r\n\
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
    httpPostAsync(\"/estado\", \"\", function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
    });\r\n\
   }\r\n\
   function setWifi()\r\n\
   {\r\n\
    red_wifi = document.getElementById(\"red_wifi\").value;\r\n\
    clave_red_wifi = document.getElementById(\"clave_red_wifi\").value;\r\n\
    payload = \"red_wifi:\" + red_wifi + \"\\n\" + \"clave_red_wifi:\" + clave_red_wifi;\r\n\
    httpPostAsync(\"/red\", payload, function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
     document.getElementById(\"red_modificada\").style.visibility = \"visible\";\r\n\
    });\r\n\
   }\r\n\
   function setRepositorio()\r\n\
   {\r\n\
    repositorio = document.getElementById(\"repositorio\").value;\r\n\
    token = document.getElementById(\"token\").value;\r\n\
    payload = \"repositorio:\" + repositorio + \"\\n\" + \"token:\" + token;\r\n\
    httpPostAsync(\"/repositorio\", payload, function(response)\r\n\
    {\r\n\
     window.alert(response);\r\n\
     document.getElementById(\"repositorio_modificado\").style.visibility = \"visible\";\r\n\
    });\r\n\
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
    <td>\r\n\
     <input id=\"estado_conexion\" type=\"text\" name=\"estado_conexion\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Estado Integracion Continua:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"estado_integracion_continua\" type=\"text\" name=\"estado_integracion_continua\">\r\n\
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
  <table border=\"2\">\r\n\
   <tr>\r\n\
    <td>\r\n\
     Repositorio:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"repositorio\" type=\"text\" name=\"repositorio\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td>\r\n\
     Token:\r\n\
    </td>\r\n\
    <td>\r\n\
     <input id=\"token\" type=\"text\" name=\"token\">\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td id=\"repositorio_modificado\" style=\"visibility:hidden\" colspan=\"2\">\r\n\
     Repositorio Modificado\r\n\
    </td>\r\n\
   </tr>\r\n\
   <tr>\r\n\
    <td colspan=\"2\">\r\n\
     <button onClick=\"setRepositorio();\">\r\n\
      Aceptar\r\n\
     </button>\r\n\
    </td>\r\n\
   </tr>\r\n\
  </table>\r\n\
 </body>\r\n\
</html>";
}