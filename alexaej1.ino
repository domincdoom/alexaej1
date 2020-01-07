#include <ESP8266WiFi.h>

#include <Espalexa.h> // incluimos librería

int Luz10 = 0; 
int Luz11 = 1;
int Luz12 = 2;
int Luz13 = 3;

const char* ssid = "WubbaLubbaDubDub";  //constante con el nombre del wifi
const char* password = "PickleRick";  // constante con el la contraseña del wifi

Espalexa alexa2; // nombre del dispositivo

void FuncionLuz10(uint8_t brightness); // creación de funcion para Luz10
void FuncionLuz11(uint8_t brightness);
void FuncionLuz12(uint8_t brightness);
void FuncionLuz13(uint8_t brightness);

void setup() {
  pinMode(Luz10, OUTPUT); // pin como salida
  pinMode(Luz11, OUTPUT); // pin como salida
  pinMode(Luz12, OUTPUT); // pin como salida
  pinMode(Luz13, OUTPUT); // pin como salida
  digitalWrite(Luz10, 1);  //iniciamos los pines en 0
  digitalWrite(Luz11, 1);  //iniciamos los pines en 0
  digitalWrite(Luz12, 1);  //iniciamos los pines en 0
  digitalWrite(Luz13, 1);  //iniciamos los pines en 0
  ConectarWifi(); // salto a la funcion para contactar el wifi
  alexa2.addDevice("Luz10", FuncionLuz10); // nombramos un dispositivo como Lampara10
  alexa2.addDevice("Luz11", FuncionLuz11); // nombramos un dispositivo como Lampara10
  alexa2.addDevice("Luz12", FuncionLuz12); // nombramos un dispositivo como Lampara10
  alexa2.addDevice("Luz13", FuncionLuz13); // nombramos un dispositivo como Lampara10
  alexa2.begin();  // iniciamos dispositivo general
}

void loop() {// rutina principal
  ConectarWifi(); // verificamos conexión
  alexa2.loop(); // rutina de la librería espalexa
  delay(1); // espera
}

void ConectarWifi() { // funcion para conectar el wifi
  if (WiFi.status() != WL_CONNECTED) {  // si el estado es desconectado
    WiFi.mode(WIFI_STA);  // iniciamos conexión
    WiFi.begin(ssid, password); // utilizamos las constantes de ssid y contraseña
    while (WiFi.status() != WL_CONNECTED) {// inicio de bucle hasta el cambio de estado de conexión
      delay(500); // espera necesaria para la conexión
    }// fin de bucle
  }
} // al terminar la conexión retorna

void FuncionLuz10(uint8_t brightness) {// funcion cuando se llama al dispositivo

  if (brightness) {// variable de la librería
    digitalWrite(Luz10, 0);  // encendemos
  }
  else {  // caso contrario
    digitalWrite(Luz10, 1);  // apagamos
  }
}

void FuncionLuz11(uint8_t brightness) {// funcion cuando se llama al dispositivo

  if (brightness) {// variable de la librería
    digitalWrite(Luz11, 0);  // encendemos
  }
  else {  // caso contrario
    digitalWrite(Luz11, 1);  // apagamos
  }
}
void FuncionLuz12(uint8_t brightness) {// funcion cuando se llama al dispositivo

  if (brightness) {// variable de la librería
    digitalWrite(Luz12, 0);  // encendemos
  }
  else {  // caso contrario
    digitalWrite(Luz12, 1);  // apagamos
  }
}
void FuncionLuz13(uint8_t brightness) {// funcion cuando se llama al dispositivo

  if (brightness) {// variable de la librería
    digitalWrite(Luz13, 0);  // encendemos
  }
  else {  // caso contrario
    digitalWrite(Luz13, 1);  // apagamos
  }
}
