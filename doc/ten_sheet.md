# Game Design Document/ Ten Sheet

Proyecto J

1.- 

 Título del juego: Proyecto J

-Sistema de juego: El jugador debe moverse por el nivel pulsando una serie de botones para poder activar la puerta que no le deja pasar de nivel.

-Público al que va dirigido: Jugadores entre 10 y 25 años. 

-Resumen de la historia del juego orientada a la jugabilidad: Un científico pulsa sin querer el botón de autodestrucción del laboratorio y tiene que escapar.

-Distintos modos de juego:
Hay que superar una serie de niveles pulsando todos los botones para poder activar la puerta, en algunos niveles aparecerán elementos como el hielo o puertas eléctricas para complicar al jugador el nivel.

-Puntos únicos de vuestro juego: cinco mínimo que destacan a vuestro juego del resto:
-Contrarreloj
-Rejugabilidad
-Estilo visual pixelado.
-Puzzles desafiantes.
-Obtener el mejor tiempo posible.

-Juegos parecidos:
The Binding of Isaac 
Pokemon (minijuego de hielo)
Slender
Saw

2.-

Jugabilidad

-Cómo se progresa en el juego: avanzando por un mapa en el que hay salas con puzzles, recogiendo notas y pulsando una serie de botones para desbloquear la puerta y poder pasar de nivel.

-Misiones y estructura de retos: La misión es escapar del laboratorio pasando todas las salas. En las diferentes salas del juego aparecerán puzzles con un incremento de dificultad.

-Estructuras de puzzle: Habrá diferentes tipos de puzzles. En uno de ellos se podrá limitar la movilidad del jugador, haciendo que avance en una dirección hasta que colisione con un obstáculo. En el otro puzzle tendremos que activar botones para abrir una puerta.

Objetivos del juego: resolver puzzles para avanzar por el mapa y conseguir salir del laboratorio obteniendo las diferentes notas repartidas por el mapa.

Cuantificación

-Lugares en los que se desarrolla el juego: un laboratorio de pruebas.

-Número de niveles: 6

-Número de NPCs: 0

-Número de armas: 0

-Flujos de juego: empieza el juego -> sala de tutorial -> nivel 1-> bucle (entras en una sala -> resuelves el puzzle -> consigues la nota (optativo) -> pasamos de nivel -> bucle (resuelves el puzzle -> consigues la nota -> pasamos de nivel) -> completar todas las salas y tener todas las notas.

3.-

Sistema visual

-HUD y controles: Se juega con ←, ↑, ↓, → para poder moverse, M para mostrar las notas que has conseguido, R para reiniciar el mapa, ENTER para avanzar en los diálogos y para modo PAUSA y ESCAPE para cerrar el juego.

-Menús: menú principal (iniciar partida, salir), menú de pausa (reanudar, salir del juego), mapa de notas.

-Características Motor 2D: la mitad superior del mapa se dibuja por debajo del jugador y la mitad inferior se dibuja por encima, para simular un falso picado.

-Cámara: falso picado.

-Controles: movimiento con ←, ↑, ↓, →.

-Sonido: Música para menú y juego.

-Sistema de ayuda: tutorial inicial con mensajes en pantalla y con notas.

4.-

Reglas de juego explícitas e implícitas

-Física: Colisiones del personaje con elementos del mapa.

-Movimiento: el personaje se podrá mover en todas las direcciones.

-Objetos: notas que se pueden coger (opcionalmente se pueden leer a través del menú), puertas que se pueden abrir para entrar en salas o salir de ellas. Para coger un objeto y para cruzar una puerta habrá que pasar a través de ellos.

-Acciones: interruptores, coger objetos, entrar en una sala.


Transición de pantallas

-Diagrama de transición de pantallas: Menú de inicio → (Primer diálogo → Nivel 0 → Cuadro de diálogo del nivel 1 + Nivel 1 → Cuadro de diálogo del nivel 2 + Nivel 2 → Nivel 3 → Nivel 4 → Cuadro de diálogo del nivel 5 + Nivel 5 → Pantalla de Game Over/Win).

-Descripción de las pantallas:
· Nivel 0: presentación del layout del juego y sus controles, así como su personaje.
· Nivel 1: primer nivel con puzzles, en el que existirá la posibilidad de recuperar una nota, y habrá que pulsar 3 botones para avanzar por la puerta de salida.
· Nivel 2: un nivel en el que no hay botones, que tiene una nota en medio de la pantalla, que está llena de líquido resbaladizo, con el objetivo de presentar la mecánica del movimiento deslizante.
· Nivel 3: nivel lleno de líquido deslizante, con 3 botones y 1 nota.
· Nivel 4: nivel con 5 botones, 1 nota, el suelo lleno de líquido deslizante y la introducción de unas chispas que pueden matar al personaje y bajar el tiempo restante para completar el nivel.
· Nivel 5: nivel en el que se explica cómo usar el mapa, control necesario para decidir por qué puerta de las 8 disponibles se cruzará y así completar el juego.

-Pantallas del juego: 6

-Menús: Tendremos menú principal para iniciar y salir del juego, además del menú para ver los mapas que hemos recogido.

-Rejugar: En la rejugabilidad la siguiente vez que juegas desaparecen los diálogos del tutorial y la puerta final se genera aleatoriamente y los mapas que coges muestran un trozo del mapa de manera aleatoria.


5.-

Historia, características y personaje

Historia de fondo: Un científico pulsa sin querer el botón de autodestrucción del laboratorio y tiene que escapar.

Elementos principales: Un laboratorio con diversos botones para abrir puertas, mapas para poder escapar.

Progresión del juego: Avanzar de nivel en nivel cruzando puertas.

Mundo del juego

Apariencia general: El juego se ambienta en un laboratorio.

Área 1
Descripción Mapa introductorio del tutorial para saber moverse.
Conexión con otras áreas Tiene dos puertas para comunicarse con los niveles.

Área 2
Descripción Mapa con botones que hay que pulsar para activar la puerta.
Características físicas: Aparecen muros con los que puedes colisionar.
Conexión con otras áreas Tiene una puerta para pasar de nivel.


Área 3
Descripción Mapa con la novedad de añadir una sustancia del laboratorio cuando surge algún problema dentro de este, esta sustancia hace resbalar a nuestro personaje.
Conexión con otras áreas Tiene una puerta para pasar de nivel.


Área 4
Descripción Mapa con la misma sustancia añadiendo colisiones para que el jugador tenga que pulsar los botones resolviendo un puzzle.
Conexión con otras áreas: Tiene una puerta para pasar de nivel.


Área 5
Descripción Mapa como el anterior pero añadiendo la novedad de unos postes eléctricos que hacen que el cronómetro avance más rápido..
Conexión con otras áreas Tiene una puerta para pasar de nivel.

Área 6
Descripción Mapa con 8 puertas, solo una de ellas es la correcta y la sabes recogiendo las notas por el mapa.

Personaje: Juanjo

Historia de fondo:  Un científico pulsa sin querer el botón de autodestrucción del laboratorio y tiene que escapar.

Personalidad: Travieso

Apariencia: Gafas y bata de laboratorio


6.-

Nivel 0
Resumen: presentación del layout del juego y sus controles, así como su personaje
Material de introducción: Diálogo al principio.
Objetivos: Pulsar los botones de la habitación.

Nivel 1
Resumen:  primer nivel con puzzles, en el que existirá la posibilidad de recuperar una nota, y habrá que pulsar 3 botones para avanzar por la puerta de salida.
Material de introducción: Diálogo al principio.
Objetivos: Pulsar los botones de la habitación.

Nivel 2
Resumen: un nivel en el que no hay botones, que tiene una nota en medio de la pantalla, que está llena de líquido resbaladizo, con el objetivo de presentar la mecánica del movimiento deslizante.

Nivel 3
Resumen: nivel lleno de líquido deslizante, con 3 botones y 1 nota.
Objetivos: Pulsar los botones de la habitación.

Nivel 4
Resumen: nivel con 5 botones, 1 nota, el suelo lleno de líquido deslizante y la introducción de unas chispas que pueden matar al personaje y bajar el tiempo restante para completar el nivel.
Objetivos: Pulsar los botones de la habitación.

Nivel 5
Resumen: nivel en el que se explica cómo usar el mapa, control necesario para decidir por qué puerta de las 8 disponibles se cruzará y así completar el juego.
Material de introducción: Diálogo al principio.
Objetivos: Salir por la puerta correcta.



7.- No hay ningún tipo de IA implementada.

8 y 9.-

Diagramas de clase de alto nivel: 



Patrones de diseño: Fachada, State y Singleton


10.-

Ejecutables a entregar

-Funcionalidades básicas por entregable: 

Hito 1: generar mapa, colisiones apropiadas, elementos del puzzle funcionan correctamente, las notas se pueden recoger, el jugador se puede mover de la forma deseada y bucle del juego.

Hito 2: control adecuado del personaje, diversidad de puzzles que funcionen correctamente, colisiones que funcionan bien, mapa completo, el bucle del juego funciona bien y versión alfa del juego jugable.

Hito 3: menús, contrarreloj, añadir elementos en el mapa y entrega final

-Funcionalidades opcionales: 

Añadir un cronómetro para dificultar el juego y poder generar la puerta final de manera aleatoria.


