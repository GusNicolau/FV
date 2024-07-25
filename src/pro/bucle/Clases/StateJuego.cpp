#include "StateJuego.h"


#define kvel 0.25
#define maxSecs 360

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////              INICIALIZACIÓN                  //////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


StateJuego::StateJuego(int lvl, Player* p){
  this->lvl = lvl;
  player=p;
  dialogo=nullptr;

  controles = new Sprite("resources/controles.png", 0, 0, 320, 192, 1, 321, 255);
  map = new Tilemap(lvl);
  player->setX(map->getPlayerX());
  player->setY(map->getPlayerY());
  player->setLastX(map->getPlayerX());
  player->setLastY(map->getPlayerY());
  player->getHitbox()->setPosition(player->getX(), player->getY());
  player->getSprite()->setPosition(player->getX(), player->getY());

  initMap =player->getMapCount();

  botonesPulsados = 0;
  if(lvl==6){
    int puertas = 0;
    for(int i=0; i<map->getObjetos().size(); i++){
      if (map->getObjetos()[i]->getTipo() == 'P'){
        puertas++;
        if(puertas==player->getPuertaFin()){
          map->getObjetos()[i]->setState(salida);
        }
      }
    }
  }

  if(!player->getJugado()){
    switch (lvl) {
    //Tecla ESC para salir
    case 2:
      dialogo = new Sprite("resources/dialogo2.png", 0, 0, 640, 480, 1, 320, 240);
      break;
    case 3:
      dialogo = new Sprite("resources/dialogo3.png", 0, 0, 640, 480, 1, 320, 240);
      break;

    case 6:
      dialogo = new Sprite("resources/dialogo4.png", 0, 0, 640, 480, 1, 320, 240);
      break;
    }
  }

}

StateJuego::~StateJuego(){
  delete map;
  delete dialogo;
  delete controles;
  pinstance = nullptr;
    
}

StateJuego* StateJuego::pinstance=0;

StateJuego* StateJuego::Instance(int lvl, Player* player){
    if(!pinstance) {
      pinstance = new StateJuego(1, player);
    }else if(lvl==-1){
      pinstance = new StateJuego(pinstance->getLvl(), player);
    }else if(pinstance->getLvl()!=lvl){
      delete pinstance;
      pinstance = new StateJuego(lvl, player);
      pinstance->setLvl(lvl);
    }
    return pinstance; //devolvemos la direccion de la instancia
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////                UPDATE                        //////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void StateJuego::update(char accion, State* &estado, float time){
  Fachada *Fachada = Fachada::Instance();
  // Variables para controlar la animación
  int frameActual = 0;
  int framesTotales = 4; // Número total de frames en la animación
  float tiempoFrame = 60; // Tiempo en segundos para cambiar de frame

    // Control de la animación>
  static float tiempoTranscurrido = 0.0f;
  tiempoTranscurrido += time;

  if (tiempoTranscurrido >= tiempoFrame){
  // Cambiar al siguiente frame de la animación
    frameActual = (frameActual + 1) % framesTotales;
    tiempoTranscurrido = 0.0f;
  }

  if(player->getReloj()&& player->getReloj()->comprobarFin(maxSecs)){
    player->getMusica()->stopMusic();
    estado = NULL;
    estado = StateGameOver::Instance(lvl,player);

  }



  switch (accion) {
    //Tecla ESC para salir
    case 'Q':
      StateJuego::~StateJuego();
      delete player;
      Fachada->closeWindow();
      break;
    case 'I':
      if(dialogo){
        delete dialogo;
      }else{
        player->getReloj()->changePause(true); 
        estado = NULL;
        estado = StatePausa::Instance(lvl,player);
      }
      break;

    case 'K':
      player->getReloj()->addTime(10);
      if(initMap!=player->getMapCount()){
        player->mapCountDown();
      }
      estado = NULL;
      estado = StateJuego::Instance(-1, player); 
      break;
    case 'M':
        player->getReloj()->changePause(true); 
        estado = NULL;
        estado = StateMapa::Instance(lvl, player);
        break;

  }



  if(pinstance){
    if (comprobarSuelo()!=3 && comprobarSuelo()!=4 && comprobarSuelo()!=8 && comprobarSuelo()!=9){ //3,4,8 y 9 son los gid de los tiles deslizantes
        player->setVelocidad(0);
    }

    if((player->getMove() == 'U' && player->getVelocidad()>0/*&& comprobarSuelo()==6*/)
    || (Fachada->isPressed('U') && player->getVelocidad()==0)){
      player->setVelocidad(kvel);
      if(colisionPuerta(time)=='U' || !comprobarColisionExt('U') || (comprobarColisionMapa()== 'U' || comprobarColisionMapa()== '1' || comprobarColisionMapa()== '2') )  {
        player->setVelocidad(0);
      }

      player->setLastY(player->getY());
      player->setY(player->getY() +(-player->getVelocidad()*time));
      player->setMove('U');

      if(comprobarSuelo()==3 || comprobarSuelo()==4 || comprobarSuelo()==8 || comprobarSuelo()==9){
        player->getSprite()->setTexture( 105, frameActual *155, 30, 50);//adaptarlo para cualquier movimiento
        player->getSprite()->setOrigin(15,36);

      }else {
        player->getSprite()->setTexture(frameActual * 105, 155, 30, 50); // Ajustar valores player->getSprite()s
        player->getSprite()->setOrigin(15,36);

      }
      
    }else if((player->getMove() == 'D' && player->getVelocidad()>0/*&& comprobarSuelo()==6*/)
    || (Fachada->isPressed('D')&& player->getVelocidad()==0)){

      player->setVelocidad(kvel);
      if(colisionPuerta(time)=='D' || !comprobarColisionExt('D') || (comprobarColisionMapa()== 'D' || comprobarColisionMapa()== '3' || comprobarColisionMapa()== '4') )  {
        player->setVelocidad(0);
      }

      player->setLastY(player->getY());
      player->setY(player->getY() +(player->getVelocidad()*time));
      player->setMove('D');
      
      if(comprobarSuelo()==3 || comprobarSuelo()==4 || comprobarSuelo()==8 || comprobarSuelo()==9){
        player->getSprite()->setTexture(105,frameActual * 155, 30, 50);
        player->getSprite()->setOrigin(15,36);

      }else {
        player->getSprite()->setTexture(frameActual * 105, 0, 30, 50); // Ajustar valores player->getSprite()s
        player->getSprite()->setOrigin(15,36);

      }

    }else if((player->getMove() == 'L' && player->getVelocidad()>0/*&& comprobarSuelo()==6*/)
    || (Fachada->isPressed('L') && player->getVelocidad()==0)){

      player->setVelocidad(kvel);
      if(colisionPuerta(time)=='L' || !comprobarColisionExt('L') || (comprobarColisionMapa()== 'L' || comprobarColisionMapa()== '1' || comprobarColisionMapa()== '3'))  {
        player->setVelocidad(0);
      }


      player->setLastX(player->getX());
      player->setX(player->getX() +(-player->getVelocidad()*time));
      player->setMove('L');
      

      if(comprobarSuelo()==3 || comprobarSuelo()==4 || comprobarSuelo()==8 || comprobarSuelo()==9){
        player->getSprite()->setTexture(105, frameActual *155, 30, 50);
        player->getSprite()->setOrigin(15,36);

      }else {
        player->getSprite()->setTexture(frameActual * 105, 53, 35, 50); // Ajustar valores player->getSprite()s
        player->getSprite()->setOrigin(15,36);

      }

    }else if((player->getMove() == 'R' && player->getVelocidad()>0/*&& comprobarSuelo()==6*/)
    || (Fachada->isPressed('R') && player->getVelocidad()==0)){

      player->setVelocidad(kvel);
      if(colisionPuerta(time)=='R' || !comprobarColisionExt('R') || (comprobarColisionMapa()== 'R' || comprobarColisionMapa()== '2' || comprobarColisionMapa()== '4'))  {
        player->setVelocidad(0);
      }


      player->setLastX(player->getX());
      player->setX(player->getX() +(player->getVelocidad()*time));
      player->setMove('R');


      if(comprobarSuelo()==3 || comprobarSuelo()==4 || comprobarSuelo()==8 || comprobarSuelo()==9){
        player->getSprite()->setTexture( 105, frameActual *155, 30, 50);
        player->getSprite()->setOrigin(15,36);

      }else {
        player->getSprite()->setTexture(frameActual * 105, 105, 30, 50); // Ajustar valores player->getSprite()s
        player->getSprite()->setOrigin(15,36);

      }

    }

    updateObjetos(estado, frameActual);
  }

}

void StateJuego::updateObjetos(State* &estado, float time){

  float tiempoFrame = 30; // Tiempo en segundos para cambiar de frame

    // Control de la animación>
  static float tiempoTranscurrido = 0.0f;
  tiempoTranscurrido += time;



  Objeto* obj = comprobarObjeto();
  if (obj!=NULL && obj->getTipo()=='P'){
    if(obj->getState()==abierta && lvl==6){
      player->getMusica()->stopMusic();
      estado = NULL;
      estado = StateGameOver::Instance(lvl,player);
    }else if(obj->getState()==abierta){ 
      estado = StateJuego::Instance(getLvl()+1, player);
      return;
    }else if(obj->getState()==cerrada || obj->getState()==salida ){
    //StateJuego::~StateJuego();
      obj->setAltSprite();
      if(obj->getState()==salida){
        obj->setState(salidaAbierta); 
      }else{
      obj->setState(abierta); 
      }
    }else if(obj->getState()==salidaAbierta){
      player->getMusica()->stopMusic();
      estado = StateWin::Instance(lvl,player);
    }else{
      player->setVelocidad(0);
    }
  }
  if (obj!=NULL && obj->getTipo()=='M' && obj->getState()==noRecogido){
      //StateJuego::~StateJuego();
      obj->setState(recogido);
      player->mapCountUp();
  }
  if (obj!=NULL && obj->getTipo()=='B'){
      //StateJuego::~StateJuego();
      if(obj->getState()==noPulsado){
        obj->setAltSprite();
        obj->setState(pulsado);
        botonesPulsados++;
      }
      
      //obj->setSprite();
  }
  if (obj!=NULL && obj->getTipo()=='C'){
    //StateJuego::~StateJuego();
    if(obj->getState()==encendidas){
      if(initMap!=player->getMapCount()){
        player->mapCountDown();
      }
      player->getReloj()->addTime(30);
      estado = StateJuego::Instance(-1, player);
    }
    
    //obj->setSprite();
  }

  if (tiempoTranscurrido >= tiempoFrame){
  // Cambiar al siguiente frame de la animación
    for(int i=0; i<map->getObjetos().size(); i++){
      if (map->getObjetos()[i]->getTipo() == 'C'){
        map->getObjetos()[i]->interruptor();
      }
    }
    tiempoTranscurrido = 0.0f;
  }

  if(map->getBotones()==botonesPulsados){
    for(int i=0; i<map->getObjetos().size(); i++){
      if (map->getObjetos()[i]->getState() == bloqueada || map->getObjetos()[i]->getState() == salida ){
        map->getObjetos()[i]->setAltSprite();
        if(map->getObjetos()[i]->getState() != salida){
          map->getObjetos()[i]->setState(cerrada);
        }
      }
    }
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////                RENDER                        //////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void StateJuego::render(float percentTick){
  Fachada *Fachada = Fachada::Instance();
  if(pinstance){
    if(player->getLastX()!=player->getX() || player->getLastY() !=player->getY()){
      float position_x= player->getLastX() * (1-percentTick) + player->getX() * percentTick;
      float position_y= player->getLastY() * (1-percentTick) + player->getY() * percentTick;
      
      player->getHitbox()->setPosition(position_x, position_y);
      player->getSprite()->setPosition(position_x, position_y);


      if(abs(position_x - player->getX()) < 15 &&  abs(position_y - player->getY()) < 15){
        player->setLastX(player->getX());
        player->setLastY(player->getY());
        player->getHitbox()->setPosition(player->getX(), player->getY());
        player->getSprite()->setPosition(player->getX(), player->getY());
      }
    }
    map->setActiveLayer(0);
    drawMap(0);//dibuja suelo

    if (lvl==1){Fachada->draw(controles);}

    drawMap(1);//dibuja colisionables


    //DIBUJAR OBJETOS
    int puerta = -1;
    for(int i=0; i<map->getObjetos().size(); i++){
      if (map->getObjetos()[i]->getState() != recogido && map->getObjetos()[i]->getState() != apagadas){
        Fachada->draw(map->getObjetos()[i]->getSprite());
        if(map->getObjetos()[i]->getTipo() == 'P' && map->getObjetos()[i]->getSprite()->getWidth() == 128 && map->getObjetos()[i]->getSprite()->getPositionY()> 240){
          puerta = i;
        }
      }
    }

    if (lvl==6){    
      Fachada->draw(player->getReloj(), maxSecs,  306, 205);
    }else{
     Fachada->draw(player->getReloj(), maxSecs,  104, 76);
    }
    drawMap(3);//dibuja no colisionables por debajo del personaje
    Fachada->draw(player->getSprite());

    //dibuja puerta por encima del personaje si está por debajo de la mitad del mapa
    if(puerta!=-1){
      Fachada->draw(map->getObjetos()[puerta]->getSprite());
    }

    drawMap(4);//dibuja no colisionables por encima del personaje

   if (dialogo){Fachada->draw(dialogo);}

  }
}

void StateJuego::drawMap(int layer) {
  Fachada *Fachada = Fachada::Instance();
  Sprite**** tilemapSprite= map->getTilemap();
  int numlayers = map->getNumlayers();
  int height = map->getHeight();
  int width = map->getWidth();

    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if(tilemapSprite[layer][y][x]!=NULL)
                Fachada->draw(tilemapSprite[layer][y][x]);
        }
    }
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////                COLISIONES                    //////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int StateJuego::comprobarSuelo(){
  int suelo = 1;
  int playerX = player->getHitbox()->getPositionX();
  int playerY = player->getHitbox()->getPositionY();
  int ** gidMap = map->getTilemapGid()[0];
  suelo = gidMap[playerY/32][playerX/32];
  return suelo;
}

char StateJuego::colisionPuerta (float time) {
  char c = 'Q';
  int puertaX,puertaY;
  int playerX = player->getX();
  int playerW = player->getSprite()->getWidth() / 2;
  int playerY = player->getY();
  int playerUp = 3;
  int playerDown = 9;
  int puertaHorLeft= 16;
  int puertaHorRight= 128-16;
  int puertaHorUp=16-40;
  int puertaHorDown = 96-16;

  int puertaVerLeft= 11;
  int puertaVerRight= 11;
  int puertaVerUp=16;
  int puertaVerDown = 128-16;

  for(int i=0; i<map->getObjetos().size(); i++){
    if (map->getObjetos()[i]->getState() == bloqueada || (map->getObjetos()[i]->getState() == salida && botonesPulsados != map->getBotones())){

      puertaX = map->getObjetos()[i]->getSprite()->getPositionX();
      puertaY = map->getObjetos()[i]->getSprite()->getPositionY();
      if(map->getObjetos()[i]->getSprite()->getWidth()==128){ //puerta horizontal
          //comprobación arriba
          if( playerX + playerW >= puertaX-puertaHorLeft 
          && playerX - playerW <= puertaX+puertaHorRight 
          && playerY -playerUp >= puertaY -puertaHorUp 
          && playerY +(-player->getVelocidad()*time) - playerUp <= puertaY + puertaHorDown){
            c = 'U';
            break;
          }
          //comprobación abajo
          if( playerX + playerW >= puertaX-puertaHorLeft 
          && playerX - playerW <= puertaX+puertaHorRight 
          && playerY + playerDown <= puertaY -puertaHorUp
          && playerY +(player->getVelocidad()*time) + playerDown >= puertaY - puertaHorUp){
            c = 'D';
            break;
          }
          //comprobación left
          if( playerY - playerUp >= puertaY-puertaHorUp 
          && playerY + playerDown <= puertaY+puertaHorDown 
          && playerX - playerW >= puertaX +puertaHorRight
          && playerX +(-player->getVelocidad()*time) - playerW <= puertaX +puertaHorRight){
            c = 'L';
            break;
          }
          //comprobación Right
          if( playerY - playerUp >= puertaY-puertaHorUp 
          && playerY + playerDown <= puertaY+puertaHorDown 
          && playerX + playerW <= puertaX -puertaHorLeft
          && playerX +(player->getVelocidad()*time) + playerW >= puertaX -puertaHorLeft){
            c = 'R';
            break;
          }
      }else{ //puerta vertical
          if( playerX + playerW >= puertaX-puertaVerLeft 
          && playerX - playerW <= puertaX+puertaVerRight 
          && playerY -playerUp >= puertaY -puertaVerUp 
          && playerY +(-player->getVelocidad()*time) - playerUp <= puertaY + puertaVerDown){
            c = 'U';
            break;
          }
          //comprobación abajo
          if( playerX + playerW >= puertaX-puertaVerLeft 
          && playerX - playerW <= puertaX+puertaVerRight 
          && playerY + playerDown <= puertaY -puertaVerUp
          && playerY +(player->getVelocidad()*time) + playerDown >= puertaY - puertaVerUp){
            c = 'D';
            break;
          }
          //comprobación left
          if( playerY - playerUp >= puertaY-puertaVerUp -20
          && playerY + playerDown <= puertaY+puertaVerDown +20
          && playerX - playerW >= puertaX +puertaVerRight
          && playerX +(-player->getVelocidad()*time) - playerW <= puertaX +puertaVerRight){
            c = 'L';
            break;
          }
          //comprobación Right
          if( playerY - playerUp >= puertaY-puertaVerUp -20
          && playerY + playerDown <= puertaY+puertaVerDown +20
          && playerX + playerW <= puertaX -puertaVerLeft
          && playerX +(player->getVelocidad()*time) + playerW >= puertaX -puertaVerLeft){
            c = 'R';
            break;
          }
      }

    }
  }
  return c;
} 

Objeto* StateJuego::comprobarObjeto(){
  Objeto* obj = NULL;
  Fachada *fachada = Fachada::Instance();

  for(int i=0; i<map->getObjetos().size(); i++){
    if(fachada->colision(player->getHitbox(),map->getObjetos()[i]->getSprite())){
      obj = map->getObjetos()[i]; 
    }
  }

  return obj;
}

int StateJuego::getLvl(){
  return this->lvl;
}

void StateJuego::setLvl(int lvl){
  this->lvl=lvl;
}

char StateJuego::comprobarColisionMapa() {
  char direccion = 'Q';
  Fachada *fachada = Fachada::Instance();
  int playerX = player->getHitbox()->getPositionX();
  int playerY = player->getHitbox()->getPositionY();
  Sprite *** colliderMap = map->getTilemap()[1];



  if (playerY/32-1 >=0 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32-1][playerX/32])){
    direccion = 'U';
  } 
  if (playerY/32+1<=14 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32+1][playerX/32])){
    direccion = 'D';
  } 
  if (playerX/32-1>=0 &&
  fachada->colision(player->getHitbox(),colliderMap[playerY/32][playerX/32-1])){
    direccion = 'L';
  } 

  if (playerX/32+1<=19 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32][playerX/32+1])){
    direccion = 'R';
  } 
  if (playerX/32-1>=0 &&
  playerY/32-1 >=0 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32-1][playerX/32])
  && fachada->colision(player->getHitbox(),colliderMap[playerY/32][playerX/32-1])){
    direccion = '1';
  } 
  if (playerX/32+1<=19 && 
  playerY/32-1 >=0 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32-1][playerX/32])
  && fachada->colision(player->getHitbox(),colliderMap[playerY/32][playerX/32+1])){
    direccion = '2';
  } 
  if (playerX/32-1>=0 &&
  playerY/32+1<=14 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32+1][playerX/32])
  && fachada->colision(player->getHitbox(),colliderMap[playerY/32][playerX/32-1])){
    direccion = '3';
  } 
  if (playerX/32+1<=19  && 
  playerY/32+1<=14 && 
  fachada->colision(player->getHitbox(),colliderMap[playerY/32+1][playerX/32])
  && fachada->colision(player->getHitbox(),colliderMap[playerY/32][playerX/32+1])){
    direccion = '4';
  } 

  return direccion;
}


bool StateJuego::comprobarColisionExt(char accion) {

  int playerX = player->getHitbox()->getPositionX();
  int playerY = player->getHitbox()->getPositionY();
  int w = player->getHitbox()->getWidth() / 2 + player->getVelocidad();
  int h = player->getHitbox()->getHeight() / 2 + player->getVelocidad();
  int leftW = 0, rightW = 640, topW = 0, bottomW = 480;
  int contR = 0, contL = 0, contD = 0, contU = 0;

  switch (accion)
  {
    case 'U':
      contU = 1;
      break;
    case 'D':
      contD = 1;
      break;
    case 'L':
      contL = 1;
      break;
    case 'R':
      contR = 1;
      break;
  }
  if( (contR * (playerX + w >= rightW)) ||
      (contL * (playerX - w <= leftW)) || 
      (contU * (playerY - h <= topW)) || 
      (contD * (playerY + h >= bottomW))) {
    return false;
  }
  return true;
}