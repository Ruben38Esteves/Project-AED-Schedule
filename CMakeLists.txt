
project(ProjetoAEDSchedule_master)
include_directories(src)
set(SOURCE
src/main.cpp
src/read.h
src/read.cpp
src/horario_turmas.h
src/horario_turmas.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
