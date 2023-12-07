file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${queuetest} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${queuetest}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${queuetest} ${queuelib} gtest) #Подключаем к проекту с именем ${queue} библиотеки с именами ${queuelib} и gtest
