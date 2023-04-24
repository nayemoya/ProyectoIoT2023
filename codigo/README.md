#include <DHT.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"


// Configuración de WiFi
const char* ssid = "Redmi Note 10S";
const char* password = "Qwerty090903";
const char* mqtt_server = "broker.emqx.io";
const char* mqtt_topic = "temperatura-y-luz";
const char* mqtt_topic2 = "humedad-y-luz";
const char* mqtt_topic3 = "luz";
const char* mqtt_topic4 = "servo";

// Configuración del pin del LED RGB y del fotoresistor
const int pin_led_rojo = 23;
const int pin_led_verde = 22;
const int pin_led_azul = 21;
const int pin_fotoresistor = 34;

// Configuración del pin del ventilador y del DHT22
const int pin_ventilador = 19;
const int pin_dht = 18;
const int dht_tipo = DHT22;

// Configuración del pin del servomotor y del mini módulo MP3
const int pin_servomotor = 25;
const int pin_mp3_rx = 16;
const int pin_mp3_tx = 17;
const int baudrate_serial_mp3 = 9600;
const int duracion_melodia = 2000;
const char* melodia = "El azul.mp3";

//configuracion del sensor ultrasonico
const int pin_trig = 26;
const int pin_echo = 27;

// Configuración de objetos de biblioteca
DHT dht(pin_dht, dht_tipo);
Servo servomotor;
HardwareSerial mySoftwareSerial(1);
DFRobotDFPlayerMini myDFPlayer;
WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

// Función para encender el LED RGB
void encender_led(int rojo, int verde, int azul) {
  analogWrite(pin_led_rojo, rojo);
  analogWrite(pin_led_verde, verde);
  analogWrite(pin_led_azul, azul);
}

// Función para medir la distancia por el sensor ultrasónico
long medir_distancia_ultrasonico() {
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);

  long duracion = pulseIn(pin_echo, HIGH);
  long distancia = duracion * 0.034 / 2;

  return distancia;
}


void setup() {
  // Inicialización de los pines
  pinMode(pin_led_rojo, OUTPUT);
  pinMode(pin_led_verde, OUTPUT);
  pinMode(pin_led_azul, OUTPUT);
  pinMode(pin_ventilador, OUTPUT);
  pinMode(pin_servomotor, OUTPUT);
  pinMode(pin_fotoresistor, INPUT);

  // Inicialización del serial MP3
  mySoftwareSerial.begin(9600, SERIAL_8N1, 16, 17);  // speed, type, RX, TX
  Serial.begin(115200);
  // Conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  // Conexión MQTT
  mqtt_client.setServer(mqtt_server, 1883);
  mqtt_client.setCallback(callback);

  // Inicialización del DHT
  dht.begin();
}

void loop() {
  // Medición de la temperatura y la humedad
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Encendido/apagado del ventilador
  if (temperatura >= 30.0)
  {
analogWrite(pin_ventilador, 255);
} else {
analogWrite(pin_ventilador, 0);
}

// Medición de la intensidad de la luz
int intensidad_luz = analogRead(pin_fotoresistor);

// Encendido/apagado del LED RGB
if (intensidad_luz <= 200) { // ajusta el valor de este umbral según tus necesidades
encender_led(255, 0, 0); // enciende el LED en rojo
} else {
encender_led(0, 0, 255); // enciende el LED en azul
}

// Accionamiento del servomotor y el mini módulo MP3
if (digitalRead(pin_servomotor) == HIGH) {
servomotor.write(90);
  Serial.println(F("myDFPlayer.play(1)"));

} else {
servomotor.write(0);
}

// Publicación de datos en el broker MQTT
if (mqtt_client.connect("ESP32-cliente")) {
mqtt_client.publish(mqtt_topic, String(temperatura).c_str());
mqtt_client.publish(mqtt_topic2, String(humedad).c_str());
mqtt_client.publish(mqtt_topic3, String(intensidad_luz).c_str());
mqtt_client.publish(mqtt_topic4, String(digitalRead(pin_servomotor)).c_str());
}

// Medición de la distancia por el sensor ultrasónico
long distancia = medir_distancia_ultrasonico();

// Ajuste de la posición del servomotor
if (distancia <= 10) {
  // Si la distancia es menor o igual a 10 cm, el servomotor se mueve a 0 grados
  servomotor.write(0);
} else if (distancia >= 30) {
  // Si la distancia es mayor o igual a 30 cm, el servomotor se mueve a 90 grados
  servomotor.write(90);
}

// Espera antes de volver a empezar el ciclo loop
delay(1000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  if (strcmp(topic, mqtt_topic4) == 0) {
    // Convierte el payload a un string
    String mensaje = "";
    for (int i = 0; i < length; i++) {
      mensaje += (char)payload[i];
    }
    // Verifica si el mensaje es "1"
    if (mensaje == "1") {
      // Cambia el estado del servo a 90 grados
      servomotor.write(90);
    } else {
      // Cambia el estado del servo a 0 grados
      servomotor.write(0);
    }
  }
}
