#include <DHT.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>

// Configuración de WiFi
const char* ssid = "Redmi Note 10S";
const char* password = "Qwerty090903";
const char* mqtt_server = "broker.emqx.io";
const char* mqtt_topic = "temperatura-y-luz";
const char* mqtt_topic2 = "humedad-y-luz";
const char* mqtt_topic3 = "luz";
const char* mqtt_topic4 = "actuadores";

// Configuración del pin del LED RGB y del fotoresistor
const int pin_led_rojo = 23;
const int pin_led_verde = 22;
const int pin_led_azul = 21;
const int pin_fotoresistor = 34;

// Configuración del pin del ventilador y del DHT22
const int pin_ventilador = 19;
const int pin_dht = 18;
const int dht_tipo = DHT22;

//Configuración del pin del sensor ultrasonico, buzzer y servo
const int trigPin = 26;
const int echoPin = 27;
const int servoPin = 25;
const int buzzerPin = 4; 

// Configuración de objetos de biblioteca
DHT dht(pin_dht, dht_tipo);
WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);
Servo myservo;

bool buzzerState = false;

// Función para encender el LED RGB
void encender_led(int rojo, int verde, int azul) {
  analogWrite(pin_led_rojo, rojo);
  analogWrite(pin_led_verde, verde);
  analogWrite(pin_led_azul, azul);
}

void setup() {
  // Inicialización de los pines
  pinMode(pin_led_rojo, OUTPUT);
  pinMode(pin_led_verde, OUTPUT);
  pinMode(pin_led_azul, OUTPUT);
  pinMode(pin_ventilador, OUTPUT);
  pinMode(pin_fotoresistor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  myservo.attach(servoPin);

  // Conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }


  // Conexión MQTT
  mqtt_client.setServer(mqtt_server, 1883);

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

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) { //Si el objeto esta a menos de 20cm de distancia
    myservo.write(180); // mueve el servo a 180 grados
    digitalWrite(buzzerPin, LOW); // activa el buzzer
    buzzerState = true; // actualiza el estado del buzzer
    delay(5000); // espera 5 segundos
    myservo.write(0); // mueve el servo a 0 grados
    digitalWrite(buzzerPin, HIGH); // desactiva el buzzer
    buzzerState = false; // actualiza el estado del buzzer
  }

// Publicación de datos en el broker MQTT
if (mqtt_client.connect("ESP32-cliente")) {
mqtt_client.publish(mqtt_topic, String(temperatura).c_str());
mqtt_client.publish(mqtt_topic2, String(humedad).c_str());
mqtt_client.publish(mqtt_topic3, String(intensidad_luz).c_str());
mqtt_client.publish(mqtt_topic4, String(buzzerState).c_str());
}

// Espera antes de volver a empezar el ciclo loop
delay(1000);
}