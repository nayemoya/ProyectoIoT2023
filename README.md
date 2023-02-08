# ProyectoIoT2023
GDS0453 - Documentación proyecto IoT 
# ProjectsIoT2022

## Integrantes

- Cristian Emmanuel Gutiérrez Díaz
- Nayeli Moya Díaz
- Nayeli Jaqueline Padrón Velázquez
- Oscar Iván Pérez Mejía

## Objetivo general
Se pretende elaborar un dispositivo el cual cumpla la función de proveer de alimento a nuestra mascota por medio de sensores los cuales permitan la interacción entre la mascota y el dispositivo, esto con la principal razón de alimentar a nuestra mascota en caso de olvido o por falta de presencia en el hogar. El dispositivo contara con un dashboard de control en tiempo real para poder monitorear el comportamiento del mismo.

### Objetivos específicos
\- Se requiere poder monitorear el dispositivo de manera remota por medio de una red wi fi y con ayuda de un dashboard

\- Se requiere el monitoreo de la temperatura y humedad de la comida por medio de sensores

\- Monitoreo de la cantidad de alimento que se deposita en el contenedor

\- Depositar alimento en el contenedor de manera remota, si es el caso de que el usuario no se encuentre en casa

## Tabla de Software utilizado
|Id|Software|Versión|Tipo|
| :-: | :-: | :-: | :-: |
|1|Visual Studio Code|17.2|IDE|
|2|Arduino|2.0.0|IDE|

## Tabla con el hardware utilizado
|Id|Componente|Descripción|Imagen|Cantidad |Costo Total|
| :- | :- | :- | :- | :- | :- |
|1|ESP32|El módulo ESP32 es una solución de Wi-Fi/Bluetooth todo en uno, integrada y certificada que proporciona no solo la radio inalámbrica, sino también un procesador integrado con interfaces para conectarse con varios periféricos.|![HiLetgo ESP-WROOM-32 ESP32 ESP-32S - Placa de Desarrollo de 2,4 GHz de Modo  Dual WiFi + Bluetooth Dual Core Procesador Microcontrolador Integrado con  Antena RF AMP Filtro Ap STA para Arduino IDE :](Aspose.Words.c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c.001.jpeg)|1|$220|
|2|DHT22|El DHT22 (AM2302) es un sensor digital de temperatura y humedad relativa de buen rendimiento y bajo costo. Integra un sensor capacitivo de humedad y un termistor para medir el aire circundante, y muestra los datos mediante una señal digital en el pin de datos.|![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 002](https://user-images.githubusercontent.com/107650526/217643056-c386284d-a99a-44d8-85a4-c3543f0ee7f5.png)|1|$135|
|3|Sensor ultrasónico|los sensores ultrasónicos miden la distancia mediante el uso de ondas ultrasónicas. El cabezal emite una onda ultrasónica y recibe la onda reflejada que retorna desde el objeto. Los sensores ultrasónicos miden la distancia al objeto contando el tiempo entre la emisión y la recepción.|![Sensor de Distancia Ultrasónico HC-SR04 | 330ohms](Aspose.Words.c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c.003.png)|1|$42|
|4|Servomotor|Un servomotor es un actuador rotativo o motor que permite un control preciso en términos de posición angular, aceleración y velocidad, capacidades que un motor normal no tiene.|![Servomotor SG90 RC 9g - UNIT Electronics Arduino Micro Servo](Aspose.Words.c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c.004.jpeg)|1|$45|
|5|Raspberry Pi|La Raspberry Pi es una computadora de bajo costo y con un tamaño compacto, del porte de una tarjeta de crédito, puede ser conectada a un monitor de computador o un TV, y usarse con un mouse y teclado estándar.|![Raspberry Pi - Wikipedia, la enciclopedia libre](Aspose.Words.c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c.005.jpeg)|1|$3000|

## Epicas del proyecto (Minimo debe de haber una épica por integrante de equipo)
\-	Quiero un dispositivo que alimente a mi mascota en caso de que no me encuentre en casa

\-	Quiero que el dispositivo alimente a mi mascota sin la necesidad de que yo tenga que alimentarlo.

\-	Que a través del dispositivo pueda monitorear la temperatura del agua y la humedad de la comida

\-	Quiero que a través del dispositivo revisar cuantas veces se ha servido comida a mi mascota.

## Tabla de historias de usuario
|Id|Historia de usuario|Prioridad|Estimación|Como probarlo|Responsable|
| :-: | :-: | :-: | :-: | :-: | :-: |
|1|Quiero un dispositivo que pueda controlar por medio de wi-fi |Media|3 semanas|Verificando que el dispositivo se conecte a la red en el dashboard|Cristian Emmanuel Gutiérrez Díaz|
|2|Quiero que el dispositivo alimente a mi mascota sin la necesidad de que yo tenga que alimentarlo.|Alta|2 semanas|Acercando mi mascota al dispositivo y verificando su funcionamiento |Nayeli Jaqueline Padrón Velázquez |
|3|Quiero que a través del dispositivo pueda monitorear la temperatura del agua y la humedad de la comida|Media|3 semanas|Verificando el dashboard y con la ayuda de un termómetro |Nayeli Moya Díaz |
|4|Quiero que a través del dispositivo revisar cuantas veces se ha servido comida a mi mascota.|Baja|3 semanas|Con la ayuda del dashboard y con una estimación del alimento sobrante|Oscar Iván Pérez Mejía|

## Prototipo en dibujo
![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 006](https://user-images.githubusercontent.com/107650526/217642875-0c6262e4-34b8-4484-9b81-54537164564c.jpeg)


