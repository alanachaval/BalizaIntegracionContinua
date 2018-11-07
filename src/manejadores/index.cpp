#include "index.hpp"

using namespace manejadores;

std::string Index::Responder(std::map<std::string, std::string> datos)
{
    return "\
<!DOCTYPE html>\
<html>\
 <head>\
  <meta charset=\"utf-8\">\
  <title>Configuracion Baliza</title>\
  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/>\
  <link rel=\"icon\" href=\"data:,\"/>\
  <style>\
   html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }\
   .button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }\
   .button2 { background-color: #555555; }\
  </style>\
  <script>\
   function httpPostAsync(url, payload, callback)\
   {\
    var xmlHttp = new XMLHttpRequest();\
    xmlHttp.onreadystatechange = function()\
    { \
     if (xmlHttp.readyState == 4 && xmlHttp.status == 200)\
     {\
      callback(xmlHttp.responseText);\
     }\
    };\
    xmlHttp.open(\"POST\", url, true);\
    xmlHttp.send(payload);\
   }\
   function setWifi()\
   {\
    httpPostAsync(\"/\", \"\", function(response)\
    {\
     window.alert(response);\
     document.getElementById(\"red_modificada\").style.visibility = \"visible\";\
    });\
   }\
   function setRepositorio()\
   {\
    repositorio = document.getElementById(\"repositorio\").value;\
    token = document.getElementById(\"token\").value;\
    payload = \"repositorio=\" + repositorio + \"&token=\" + token;\
    //window.alert(payload);\
    httpPostAsync(\"/repositorio\", payload, function(response)\
    {\
     window.alert(response);\
     document.getElementById(\"repositorio_modificado\").style.visibility = \"visible\";\
    });\
   }\
  </script>\
 </head>\
 <body>\
  <h1>\
   Configuracion Baliza\
  </h1>\
  <table border=\"2\">\
   <tr>\
    <td>\
     Red WiFi:\
    </td>\
    <td>\
     <input type=\"text\" name=\"red_wifi\">\
    </td>\
   </tr>\
   <tr>\
    <td>\
     Clave red WiFi:\
    </td>\
    <td>\
     <input type=\"text\" name=\"clave_red_wifi\">\
    </td>\
   </tr>\
   <tr>\
    <td id=\"red_modificada\" style=\"visibility:hidden\" colspan=\"2\">\
     Red Modificada\
    </td>\
   </tr>\
   <tr>\
    <td colspan=\"2\">\
     <button onClick=\"setWifi();\">\
      Aceptar\
     </button>\
    </td>\
   </tr>\
  </table>\
  <br/>\
<form action=\"/repositorio\" method=\"post\">\
  <table border=\"2\">\
   <tr>\
    <td>\
     Repositorio:\
    </td>\
    <td>\
     <input id=\"repositorio\" type=\"text\" name=\"repositorio\">\
    </td>\
   </tr>\
   <tr>\
    <td>\
     Token:\
    </td>\
    <td>\
     <input id=\"token\" type=\"text\" name=\"token\">\
    </td>\
   </tr>\
   <tr>\
    <td id=\"repositorio_modificado\" style=\"visibility:hidden\" colspan=\"2\">\
     Repositorio Modificado\
    </td>\
   </tr>\
   <tr>\
    <td colspan=\"2\">\
     <input type=\"submit\" value=\"Submit\"/>\
     <button onClick=\"setRepositorio();\">\
      Aceptar\
     </button>\
    </td>\
   </tr>\
  </table>\
</form>\
 </body>\
</html>\
    ";
}