# Proyecto Final del curso de Quark de C++
## Descripción
Este programa tiene la finalidad de ser usado por un vendedor en una tienda de ropa mayorista para realizar cotizaciones de sus productos.

La interfaz del programa es de consola, donde el usuario navega mediante la selección de opciones usando números como entrada, y donde también dicho usuario puede introducir precio y cantidad.

El programa valida los datos de entrada del usuario, mostrando un mensaje de error en caso de que se introduzca un número incorrecto o se utilicen letras o símbolos. De esta forma se evita que el flujo se rompa o sea interrumpido.

Nota: Las características de las prendas afectan al precio final. 
<br/>
<br/>
## Instrucciones de Uso
- El usuario navega por el programa eligiendo opciones numéricas y presionando Enter.
- En cada pantalla se muestran las opciones y cada una corresponde a un número, el cual se usa por el usuario para seleccionar dicha opción.

### Pantalla Principal
En la Pantalla pirncipal, en el encabezado se tiene la información de la tienda y del vendedor. En el contenido se muestran las opciones de "Historial de Cotizaciones", "Realizar Cotización" y la opción para salir del programa.

### Pantalla Historial de Cotizaciones
Se puede acceder a esta vista desde cualquier parte del programa. Desde la pantalla principal se accede presionando "1" y desde las demás pantallas se puede acceder introduciendo "-1". Una vez en esta vista, se vuelve a la pantalla anterior presionando "0".

En esta pantalla se muestra la lista de todas las cotizaciones realizadas por el usuario, con la correspondiente información.

### Flujo para Realizar una Cotización
Se empieza el flujo para realizar una cotización seleccionando "2" en la pantalla principal. En cualquier vista de este flujo se puede volver a la pantalla principal utilizando la opción "0".

En la primera vista del flujo, se escoge el tipo de prenda: Camisa o Pantalón.

En caso de que se quiera cotizar una **Camisa**, el flujo es el siguiente:
  - Se define si es de Manga corta o Manga larga. 
  - Se define el tipo de Cuello.
  - Se define la calidad de la prenda (Standard o Premium).
  - Se define el precio unitario de la prenda.
  - Se define la cantidad de unidades a cotizar. El programa controla que dicha cantidad no sea mayor al stock de la tienda.
  - Se muestra el resultado final de la cotización.
  
En caso de que se quiera cotizar un **Pantalón**, el flujo es el siguiente:
  - Se define si el tipo de pantalón es Chupín.
  - Se define la calidad de la prenda (Standard o Premium).
  - Se define el precio unitario de la prenda.
  - Se define la cantidad de unidades a cotizar. El programa controla que dicha cantidad no sea mayor al stock de la tienda.
  - Se muestra el resultado final de la cotización.
  
