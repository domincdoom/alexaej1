#include <ESP8266WiFi.h>

#include <Espalexa.h> // incluimos librería

int Luz1 = 2; // creación de variable LUZ1 para utilizar el pin 2 "D4"

const char* ssid = ".....";  //constante con el nombre del wifi
const char* password = "......";  // constante con el la contraseña del wifi

Espalexa alexa1; // nombre del dispositivo

void FuncionLuz1(uint8_t brightness); // creación de funcion para Luz1

void setup() {
  Serial.begin(115200); // configuramos la velocidad serial
  pinMode(Luz1, OUTPUT); // pin como salida
  digitalWrite(Luz1, 0);  //iniciamos los pines en 0
  ConectarWifi(); // salto a la funcion para contactar el wifi
  alexa1.addDevice("Luz1", FuncionLuz1); // nombramos un dispositivo como Lampara1
  alexa1.begin();  // iniciamos dispositivo general
}

void loop() {// rutina principal
  ConectarWifi(); // verificamos conexión
  alexa1.loop(); // rutina de la librería espalexa
  delay(1); // espera
}

void ConectarWifi() { // funcion para conectar el wifi
  if (WiFi.status() != WL_CONNECTED) {  // si el estado es desconectado
    WiFi.mode(WIFI_STA);  // iniciamos conexión
    WiFi.begin(ssid, password); // utilizamos las constantes de ssid y contraseña
    Serial.println(""); // iniciamos una nueva línea para escritura serial
    Serial.println("Conectando a la red WiFi"); // escribimos que se inicia conexión
    while (WiFi.status() != WL_CONNECTED) {// inicio de bucle hasta el cambio de estado de conexión
      delay(500); // espera necesaria para la conexión
      Serial.print(".");  // se escribe .
    }// fin de bucle
    Serial.print("Conectado a: ");  // indicamos que se realizó la conexión
    Serial.println(ssid); // se escribe el nombre del wifi
    Serial.print("IP address: "); // Se indica la dirección ip
    Serial.println(WiFi.localIP()); //la dirección IP asignada por el router
  }
} // al terminar la conexión retorna

void FuncionLuz1(uint8_t brightness) {// funcion cuando se llama al dispositivo
  Serial.println("Funcion Luz1 ");  // escribimos a que función se llamo

  if (brightness) {// variable de la librería
    digitalWrite(Luz1, 1);  // encendemos
    Serial.println(" Luz1 Encendida "); // escribimos
  }
  else {  // caso contrario
    digitalWrite(Luz1, 0);  // apagamos
    Serial.println(" Luz1 Apagada ");  // escribimos
  }
}
