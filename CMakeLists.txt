# Minimalus CMake versijos reikalavimas
cmake_minimum_required(VERSION 3.10)

# Nustatome projekto pavadinimą ir versiją
project(v1.0 VERSION 0.1)

# Nurodome, kur yra šaltinio failai (main.cpp ir Stud.cpp)
set(SOURCE_FILES
    main.cpp
    Stud.cpp
)

# Nurodome, kur yra antraščių failai, kad CMake žinotų, kur jų ieškoti
include_directories(${CMAKE_SOURCE_DIR})

# Sukuriame programą (tai, ką sukursime iš šaltinio failų)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Jei naudojate papildomas bibliotekas (jei reikia), galite jas pridėti čia
# target_link_libraries(${PROJECT_NAME} kokia_nors_biblioteka)
