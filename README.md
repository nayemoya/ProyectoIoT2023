# ProyectoIoT2023

Grupo: GDS0453  
5 Cuatrimestre  
Aplicaciones de IoT  
Documentación proyecto IoT  

## Nombre del proyecto
Comedor Bélico
## Integrantes

- Cristian Emmanuel Gutiérrez Díaz
- Nayeli Moya Díaz
- Nayeli Jaqueline Padrón Velázquez
- Oscar Iván Pérez Mejía

## Objetivo General
Se pretende elaborar un dispositivo el cual cumpla la función de proveer de alimento a nuestra mascota por medio de sensores los cuales permitan la interacción entre la mascota y el dispositivo, esto con la principal razón de alimentar a nuestra mascota en caso de olvido o por falta de presencia en el hogar. El dispositivo contara con un dashboard de control en tiempo real para poder monitorear el comportamiento del mismo.

### Objetivos Específicos
\- Se requiere poder monitorear el dispositivo de manera remota por medio de una red wi fi y con ayuda de un dashboard.

\- Se requiere el monitoreo de la temperatura y humedad del circuito por medio de sensores.

\- Funcionamiento de sensores para accionar los distintos actuadores para el correcto funcionamiento del sistema.

\- Poder verificar un historial con los cambios en el circuito y el mismo prototipo.

\- Depositar alimento en el contenedor de manera remota, si es el caso de que el usuario no se encuentre en casa.

## Tabla de Software Utilizado
|Id|Software|Versión|Tipo|
| :-: | :-: | :-: | :-: |
|1|Visual Studio Code|17.2|IDE|
|2|Arduino|2.0.0|IDE|

## Tabla con el Hardware Utilizado
|Id|Componente|Descripción|Imagen|Cantidad |Costo Total|
| :-: | :-:| :- | :-: | :-: | :-: |
|1|ESP32|El módulo ESP32 es una solución de Wi-Fi/Bluetooth todo en uno, integrada y certificada que proporciona no solo la radio inalámbrica, sino también un procesador integrado con interfaces para conectarse con varios periféricos.|![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 001](https://user-images.githubusercontent.com/107650526/217643833-2a3555c5-2952-46cf-814e-397453742464.jpeg)|1|$220|
|2|DHT22|El DHT22 (AM2302) es un sensor digital de temperatura y humedad relativa de buen rendimiento y bajo costo. Integra un sensor capacitivo de humedad y un termistor para medir el aire circundante, y muestra los datos mediante una señal digital en el pin de datos.|![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 002](https://user-images.githubusercontent.com/107650526/217643056-c386284d-a99a-44d8-85a4-c3543f0ee7f5.png)|1|$135|
|3|Sensor ultrasónico|los sensores ultrasónicos miden la distancia mediante el uso de ondas ultrasónicas. El cabezal emite una onda ultrasónica y recibe la onda reflejada que retorna desde el objeto. Los sensores ultrasónicos miden la distancia al objeto contando el tiempo entre la emisión y la recepción.|![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 003](https://user-images.githubusercontent.com/107650526/217643646-a4d1d4d1-0b68-49a1-ba3e-3b5110804ea9.png)|1|$42|
|4|Servomotor|Un servomotor es un actuador rotativo o motor que permite un control preciso en términos de posición angular, aceleración y velocidad, capacidades que un motor normal no tiene.|![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 004](https://user-images.githubusercontent.com/107650526/217643550-267eca20-f819-4b53-a030-13fddb7b23e9.jpeg)|1|$45|
|5|Buzzer Pasivo|Un buzzer pasivo es un tipo de zumbador que no tiene circuitos internos para generar sonido por sí solo. En su lugar, requiere que una señal eléctrica externa lo active para producir un tono o un sonido determinado.|![image](https://user-images.githubusercontent.com/107650526/234452510-d27d20c4-06e3-4cbf-82bc-7d61b1bf46bf.png)|1|$39|
|6|Photoresistor|Un fotoresistor es un componente electrónico que varía su resistencia eléctrica en función de la cantidad de luz que recibe. Es decir, su resistencia disminuye cuando se expone a la luz y aumenta en la oscuridad.|![image](https://user-images.githubusercontent.com/107650526/234452928-eb43798c-7b36-4ae7-9a4c-9d3310af0da7.png)|1|$69|
|7|RGB SMD|Un LED RGB es un tipo de diodo emisor de luz que puede emitir luz en tres colores diferentes: rojo (R), verde (G) y azul (B). Al combinar diferentes intensidades de cada uno de estos colores, se pueden crear una amplia variedad de colores en el espectro visible.|![image](https://user-images.githubusercontent.com/107650526/234453729-841f4bc8-70cf-4068-8e59-c3fb4d739e2f.png)|1|$49|
|8|Ventilador PMW|Un ventilador PWM (Pulse Width Modulation) es un tipo de ventilador que utiliza una señal eléctrica pulsante para controlar su velocidad. En lugar de simplemente variar la tensión eléctrica que se aplica al motor, como en los ventiladores convencionales, el ventilador PWM ajusta la duración de los pulsos eléctricos para controlar la velocidad de las aspas. |![image](https://user-images.githubusercontent.com/107650526/234454347-af84dee8-16a0-4d12-978d-064c74474846.png)|1|$80|
|9|Modulo MOSFET|Es un tipo de transistor que se utiliza comúnmente en electrónica de potencia y en circuitos digitales. A diferencia de los transistores bipolares, los MOSFET no requieren corriente de base para funcionar, lo que los hace más eficientes en términos energéticos.|![image](https://user-images.githubusercontent.com/107650526/234456786-06ecc652-d9ea-40d2-b326-f528f991f2fa.png)|1|$66|
|10|Raspberry Pi|La Raspberry Pi es una computadora de bajo costo y con un tamaño compacto, del porte de una tarjeta de crédito, puede ser conectada a un monitor de computador o un TV, y usarse con un mouse y teclado estándar.|![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 005](https://user-images.githubusercontent.com/107650526/217643461-162a8340-858d-44ec-846c-71d76e0cf938.jpeg)|1|$3000|

## Epicas del Proyecto
\-	Quiero un dispositivo que alimente a mi mascota en caso de que no me encuentre en casa.

\-	Quiero que el dispositivo alimente a mi mascota sin la necesidad de que yo tenga que alimentarlo.

\-	Que a través del dispositivo pueda monitorear la temperatura del circuito en caso de un ambiente muy caluroso para poder regular el mismo con la ayuda de un ventilador.

\-	Quiero que a través del dispositivo pueda llamar la atención de mi mascota con alguna melodía para mantenerlo controlado.

## Tabla de Historias de Usuario
|Id|Historia de usuario|Prioridad|Estimación|Como probarlo|Responsable|
| :-: | :-: | :-: | :-: | :-: | :-: |
|1|Quiero un dispositivo que pueda controlar por medio de wi-fi |Media|3 semanas|Verificando que el dispositivo se conecte a la red en el dashboard|Cristian Emmanuel Gutiérrez Díaz|
|2|Quiero que el dispositivo alimente a mi mascota sin la necesidad de que yo tenga que alimentarlo.|Alta|2 semanas|Acercando mi mascota al dispositivo y verificando su funcionamiento |Nayeli Jaqueline Padrón Velázquez |
|3|Quiero que a través del dispositivo pueda monitorear la temperatura del circuito y la regule en caso de ser muy alta|Media|3 semanas|Verificando el dashboard y con la ayuda de un termómetro y un ventilador |Nayeli Moya Díaz |
|4|Quiero que a través del dispositivo revisar cuantas veces se ha cambiado el funcionamiento de mi sistema.|Baja|3 semanas|Con la ayuda del dashboard y con una base de datos|Oscar Iván Pérez Mejía|

## Prototipo en Dibujo
![Aspose Words c0a6ef2d-04fd-41d4-a1ce-ebc52d1e014c 006](https://user-images.githubusercontent.com/107650526/217642875-0c6262e4-34b8-4484-9b81-54537164564c.jpeg)


