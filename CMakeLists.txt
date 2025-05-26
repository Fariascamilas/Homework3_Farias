# Definición de la versión mínima a utilizar
cmake_minimum_required(VERSION 3.28.3)

project(Mediciones_de_vuelo)

# Definición de standard
set(CMAKE_CXX_STANDARD 20)

# Los archivos fuente, todos en la misma variable
set(ARCHIVES 
    "source/MedicionBase.cpp" 
    "source/Posicion.cpp" 
    "source/Presion.cpp" 
    "source/SaveFlightData.cpp" 
    "main/main1.cpp")

add_executable(medicionesExe ${ARCHIVES})

target_include_directories(medicionesExe PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(medicionesExe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

"""
Para ejecutar el archivo, sigue estos pasos:

1. **Compila el proyecto:**  
   Si aún no lo has compilado, crea un directorio de compilación (si no lo tienes) y compila el proyecto. Por ejemplo:

   -----------------
   mkdir build
   cd build
   cmake ..
   make
   -----------------

2. **Navega al directorio de salida:**  
   En tu configuración, el ejecutable se genera en `${CMAKE_BINARY_DIR}/bin`. Si usaste un directorio `build` para la compilación, la ruta será similar a `build/bin`:

   -----------------
   cd bin
   -----------------

3. **Ejecuta el ejecutable:**  
   Una vez dentro del directorio de salida, ejecuta el archivo:

   -----------------
   ./medicionesExe
   -----------------


Con esto se debería iniciar el ejecutable generado.
"""