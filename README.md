# Taller 1 - Estructura de Datos

## Integrante

| Nombre                         | RUT          | GitHub                            | Carrera                     |
| ------------------------------ | ------------ | --------------------------------- | --------------------------- |
| Victor Manuel Gonzalez Morales | 22.061.552-9 | VictorgGonzalezMorales-1 | Ingeniería Civil Industrial |

## Descripción

Este proyecto corresponde al Taller 1 de la asignatura **Estructura de Datos**.

El programa simula el sistema de atención de pacientes del **Hospital Marmaja**, un recinto con diversos servicios a los cuales cada paciente debe ser derivado según corresponda. Los pacientes son cargados desde un archivo de texto y posteriormente administrados mediante estructuras de datos implementadas manualmente.

## Estructuras utilizadas

El sistema utiliza las siguientes estructuras y conceptos:

* **Nodo (Node):** Clase genérica utilizada como elemento fundamental para construir las estructuras enlazadas. Cada nodo almacena un dato y un puntero hacia el siguiente nodo.


* **Lista enlazada (List):** Estructura genérica implementada manualmente mediante nodos y punteros. Se utiliza para almacenar y organizar distintos tipos de datos dentro del programa. Entre sus usos se encuentra el manejo de datos obtenidos al separar las líneas del archivo, el almacenamiento de los pacientes correspondientes a cada servicio y el registro de IDs utilizados para controlar pacientes duplicados.

* **Cola (Queue):** Estructura implementada manualmente mediante nodos y punteros. Almacena los pacientes pendientes de atención respetando el orden de llegada.

* **Pila (Stack):** Estructura implementada manualmente mediante nodos y punteros. Almacena el historial de pacientes atendidos, manteniendo el orden de las últimas atenciones realizadas.

* **Arreglo de servicios:** Almacena los nombres de los 8 servicios disponibles. La posición de cada servicio en el arreglo se utiliza como índice para relacionarlo con su correspondiente lista de pacientes dentro de **hospital**.

* **Punteros y memoria dinámica:** Utilizados para administrar los nodos, pacientes y estructuras creadas dinámicamente.

* **Programación Orientada a Objetos:** Implementada mediante clases, encapsulamiento e herencia.


## Estructura del proyecto

```text
Taller-1-Estructura-main/
│
├── dominio/
│   ├── Paciente.h
│   └── Paciente.cpp
│
├── estructuras/
│   ├── Node.h
│   ├── List.h
│   ├── Queue.h
│   └── Stack.h
│
├── logica/
│   ├── Sistema.h
│   ├── SistemaImplementado.h
│   └── SistemaImplementado.cpp
│
├── main.cpp
└── Pacientes.txt
```

## Archivo de pacientes

Los pacientes se cargan desde el archivo `Pacientes.txt`.

Cada línea debe contener los siguientes datos en orden, separados por `;`:

```text
ID;Nombre;Edad;Servicio
```

**Ejemplo:**

```text
001;Juan Perez;35;Urgencias
002;Maria Gonzalez;28;Pediatria
```

**El programa valida las líneas de la siguiente manera:**

* Que Tengan los cuatro datos correspondientes.
* Que los campos no estén vacíos.
* Que el servicio exista.
* Que no se repita el ID de un paciente.

## Requisitos
* Tener un compilador de C++ instalado.\
  (como g++ mediante MinGW en Windows) compatible con el estándar C++17.

## Instrucciones de Compilación (Windows)

### Paso 1: Descargar el proyecto desde GitHub

1. Entra al repositorio de **GitHub** del proyecto.
2. Haz clic en el botón verde **Code**.
3. Selecciona la opción **Download ZIP**.
4. El archivo comprimido se guardará en tu carpeta de **Descargas** con el nombre:\
 `Taller-1-Estructura-main.zip`.

### Paso 2: Extraer el archivo .zip

1. Ve a tu carpeta de **Descargas** en el Explorador de Archivos de Windows.
2. Haz clic derecho sobre `Taller-1-Estructura-main.zip` y selecciona **Extraer todo...**.
3. Deja la ruta por defecto `(Descargas)` y haz clic en **Extraer**.\
(Esto creará la estructura de carpetas necesaria para los siguientes pasos).

### Paso 3: Abrir la Consola y Navegar al Código Fuente

1. Abre el menú de inicio de Windows, escribe **cmd** (Símbolo del sistema) y ábrelo.

2. Copia y pega el siguiente comando para ingresar a la carpeta del proyecto que acabas de extraer:
``
cd Downloads\Taller-1-Estructura-main\Taller-1-Estructura-main
``
3. **(Opcional)** Si quieres verificar que estás en el lugar correcto, escribe ``dir`` y luego presiona Enter. Deberías ver en la lista el archivo ``main.cpp``, ``Pacientes.txt`` y las carpetas ``dominio``, ``logica`` y ``estructuras``.

### Paso 4: Crear el Entorno de Compilación (``build``)

Para respetar la ruta del archivo de texto sin modificar el código fuente, creamos la carpeta de ejecución con estos comandos:

**(Por cada uno escríbelo y presiona Enter)**

1. ``mkdir build``
2. ``cd build``


### Paso 5: Compilar el Proyecto con ``g++``

Como ahora nos encontramos dentro de la carpeta ``build``, ejecutamos el compilador apuntando hacia los archivos del nivel superior (``..\``) usando el estándar C++17:

```text
g++ -std=c++17 ..\main.cpp ..\dominio\Paciente.cpp ..\logica\SistemaImplementado.cpp -o programa.exe
```

### Paso 6: Ejecutar el Programa "Hospital Marmaja"

Una vez finalizada la compilación sin errores, arranca la aplicación escribiendo: ``programa.exe``


## Ejecución y Flujo del Sistema

Al iniciar el programa (``programa.exe``), el sistema ejecuta de forma automática el flujo inicial de carga, dejando el procesamiento y derivación bajo el control directo del usuario a través del menú:

```text
[Archivo de Texto] --> [Cola de Espera (Queue)] --(Acción del Usuario)--> [Derivación (Lists)] + [Historial (Stack)]
```

### 1. Robustez y Validación en la Carga de Datos
Antes de desplegar la interfaz, el sistema analiza el archivo `Pacientes.txt` bajo las siguientes reglas de control de errores:
* **Validación de campos:** Rechaza líneas que no contengan los 4 datos obligatorios separados por punto y coma (`;`).

* **Control de existencia:** Verifica que el departamento asignado corresponda a uno de los 8 servicios oficiales.

* **Pacientes duplicados:** Comprueba los IDs registrados para evitar cargar pacientes con un ID repetido.

* **Estructura inicial:** Los pacientes que superan las validaciones son almacenados **únicamente en la Cola Dinámica de Espera (`Queue`)**, manteniendo el orden de llegada mediante el principio **FIFO**. Ningún paciente ingresa directamente a un servicio médico al iniciar, eso es responsabilidad del usuario.


### 2. Menú de Interacción y Flujos de Control

Una vez rellenada la cola de espera, se habilita el menú principal. El usuario es el encargado de dictar las instrucciones para procesar y derivar a los pacientes, solicitándose parámetros adicionales según la opción elegida:

```text
=== HOSPITAL MARMAJA ===

1. Atender pacientes
2. Ver departamento
3. Revisar historial de atencion
4. Salir
Seleccionar opcion:
```

#### Opciones y Parámetros Solicitados:

* **Opción 1: Atender pacientes (Instrucción de Derivación):**
  * **Datos solicitados:** Muestra en pantalla el listado de personas que esperan en la cola y solicita ingresar la **cantidad de pacientes a atender**.

  * **Operación:** El programa remueve secuencialmente de la `Queue` el número de pacientes indicado. En ese instante, los deriva hacia la **Lista Enlazada de Pacientes** de su respectivo servicio médico y registra la atención en el historial.

* **Opción 2: Ver departamento (Listas Enlazadas de Servicios):**
  * **Datos solicitados:** Despliega la lista de los 8 servicios habilitados y solicita ingresar el **índice numérico del departamento** (del 1 al 8) que se desea inspeccionar.

  * **Operación:** Obtiene el servicio seleccionado y muestra los pacientes que ya han sido derivados allí mediante la opción 1.

* **Opción 3: Revisar historial de atención (Flujo LIFO):**
  * **Operación:** Muestra de forma directa la estructura de la **Pila (`Stack`)**, mostrando primero al paciente atendido más recientemente y luego los anteriores, respetando el principio **LIFO**.

* **Opción 4: Salir (Liberación de Memoria Dinámica):**
  * **Operación:** Finaliza la ejecución y libera la memoria dinámica utilizada por las estructuras, los pacientes y el Sistema Implementado.


## Servicios disponibles

El **Hospital Marmaja** considera los siguientes servicios:

1. Urgencias
2. Medicina General
3. Cardiologia
4. Neurologia
5. Traumatologia
6. Cirugia
7. Pediatria
8. Hospitalizacion

## Organización del código

El proyecto se encuentra dividido en diferentes módulos:

* **`dominio/`**: Contiene la clase `Paciente`.
* **`estructuras/`**: Contiene las implementaciones manuales de `Node`, `List`, `Queue` y `Stack`.
* **`logica/`**: Contiene la interfaz `Sistema` y su implementación `SistemaImplementado`.
* **`main.cpp`**: Contiene el flujo principal del programa, la lectura del archivo y el menú de interacción.
