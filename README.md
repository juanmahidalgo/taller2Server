# taller2Server

Instalamos CMake

Ejecutar el siguiente comando a partir de una nueva terminal

a. sudo su

b. apt-get install cmake

Instalación de la librería RocksDB

Descargamos los fuentes del RocksDB desde el siguiente link

a. https://github.com/facebook/rocksdb/archive/master.zip

Descomprimir el archivo "rocksdb-master.zip"

Ingresar a la carpeta "rocksdb-master" a partir de una nueva terminal

Ejecutar el siguiente comando para tener permisos de administrador

a. sudo su

Ejecutar el siguiente comando

a. make all

b. make install

Ejecutar los siguientes comandos

a. apt-get install libgflags-dev

b. apt-get install libsnappy-dev

c. apt-get install zlib1g-dev

d. apt-get install libbz2-dev

Instalación de la librería jsoncpp

Descargamos los fuentes de jsoncpp desde el siguiente link

a. https://github.com/open-source-parsers/jsoncpp/archive/master.zip

Descomprimir el archivo "jsoncpp-master"

Ingresar a la carpeta "jsoncpp-master" a partir de una nueva terminal

Ejecutar el siguiente comando a partir de una nueva terminal

a. sudo su

Ejecutar los siguientes comandos

a. mkdir -p build/debug

b. cd build/debug

c. cmake -DCMAKE_BUILD_TYPE=debug -DJSONCPP_LIB_BUILD_STATIC=ON -DJSONCPP_LIB_BUILD_SHARED=OFF -G "Unix Makefiles" ../..

d. make

Ingresar a la carpeta "/src/lib_json"

Ejecutar el siguiente comando

a. cp -a libjsoncpp.a /usr/local/lib

