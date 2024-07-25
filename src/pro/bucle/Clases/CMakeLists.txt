#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/State.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StateJuego.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StateMenu.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StatePausa.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Fachada.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Objeto.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Reloj.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tilemap.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StateDialogo1.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StateGameOver.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StateWin.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StateMapa.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Musica.cpp"

)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

