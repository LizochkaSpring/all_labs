cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME All_labs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(stack stack) #Переменная с именем приложения
set(stacklib stacklib) #Переменная с именем библиотеки
set(stacktest stacktest)

set(postf postf) #Переменная с именем приложения
set(postflib postflib) #Переменная с именем библиотеки
set(postftest postftest)

set(queue queue) #Переменная с именем приложения
set(queuelib queuelib) #Переменная с именем библиотеки
set(queuetest queuetest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/stacklib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(stack) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(stacklib)
add_subdirectory(stacktest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/postflib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/postflib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(postf) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(postflib)
add_subdirectory(postftest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/queuelib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/postflib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(queue) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(queuelib)
add_subdirectory(queuetest)


#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp

#include_directories(lib1)
#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}


 #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}


add_subdirectory(Graph)
add_subdirectory(Gpaf)
