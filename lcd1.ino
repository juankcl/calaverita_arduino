/**
   GeekFactory - "INNOVATING TOGETHER"

   EN ESTE EJEMPLO MOSTRAMOS COMO DEFINIR CARACTERES PERSONALIZADOS EN UNA
   PANTALLA LCD 16X2 CON ARDUINO. EL CODIGO MUESTRA COMO DEFINIR LOS MAPAS
   DE BITS Y COMO INDICARLE AL CONTROLADOR DE PANTALLA QUE MUESTRE LOS CARACTERES
   PERSONALIZADOS EN POSICIONES ESPECIFICAS DE LA PANTALLA.

   Modificado por: Juan Carlos Carrasco Lopez (juankcl)
*/

#include  <LiquidCrystal.h>

// CONSTRUCTOR PARA LA PANTALLA LCD 16X2
// AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// DEFINICION DE CARACTERES PERSONALIZADOS
byte smile[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00010001,
  0b00001110,
  0b00000000,
};

byte sad[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00001110,
  0b00010001,
  0b00000000,
};

byte body[8] = {
  0b00001110,
  0b00001110,
  0b00000100,
  0b00011111,
  0b00000100,
  0b00001010,
  0b00010001,
  0b00000000,
};

byte arrowr[8] = {
  0b00001000,
  0b00000100,
  0b00000010,
  0b00011111,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00000000,
};

byte arrowu[8] = {
  0b00000100,
  0b00001110,
  0b00010101,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000000,
};

byte arrowd[8] = {
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00010101,
  0b00001110,
  0b00000100,
  0b00000000,
};

byte arrowl[8] = {
  0b00000010,
  0b00000100,
  0b00001000,
  0b00011111,
  0b00001000,
  0b00000100,
  0b00000010,
  0b00000000,
};

byte heart[8] = {
  0b00000000,
  0b00001010,
  0b00011111,
  0b00011111,
  0b00001110,
  0b00000100,
  0b00000000,
  0b00000000,
};

//Calavera

   byte cuno[8] = {
  0b00000000,
  0b00000001,
  0b00000011,
  0b00000111,
  0b00000111,
  0b00001111,
  0b00001111,
  0b00001110,

};
 byte cdos[8] = {
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00000111,
  0b00000010,

};
   byte ctres[8] = {
  0b00011000,
  0b00011100,
  0b00011110,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00000111,
  0b00000011,
};
byte ccuatro[8] = {
  0b00000111,
  0b00000111,
  0b00000011,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00000000,
  0b00000000,
};
byte ccinco[8] = {
  0b00000101,
  0b00011000,
  0b00011111,
  0b00011111,
  0b00010101,
  0b00001010,
  0b00011111,
  0b00011111,
};
   byte cseis[8] = {
  0b00000111,
  0b00011111,
  0b00011110,
  0b00011100,
  0b00001100,
  0b00011100,
  0b00011000,
  0b00010000,
};


void setup()
{
  // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2
  lcd.begin(16, 2);
  
  // ENVIAR LOS MAPAS DE BITS AL CONTROLADOR DE PANTALLA
  lcd.createChar (0, smile);
  lcd.createChar (1, heart);
  lcd.createChar (2, body);
  lcd.createChar (3, arrowr);
  lcd.createChar (4, arrowu);
  lcd.createChar (5, arrowd);
  lcd.createChar (6, arrowl);
  //personalizados nuevos
  lcd.createChar (7, heart);
  //esqueleto
  lcd.createChar (8, cuno);
  lcd.createChar (9, cdos);
  lcd.createChar (10, ctres);
  lcd.createChar (11, ccuatro);
  lcd.createChar (12, ccinco);
  lcd.createChar (13, cseis);
  
  // LIMPIAR LA PANTALLA Y MOVER EL CURSOR A LA PRIMERA POSICION
  lcd.clear();
  // IMPRIMIR TITULO EN LA PRIMERA LINEA
  lcd.print("HAPPY     ");
  // AHORA ESCRIBIMOS (MOSTRAMOS) LOS CARACTERES A LA PANTALLA
  lcd.write((byte)8);
  lcd.write((byte)9);
  lcd.write((byte)10);
  // MOVER EL CURSOR A LA SEGUNDA LINE
  lcd.setCursor(0, 1);
  lcd.print("HALLOWEEN!");
  lcd.write((byte)11);
  lcd.write((byte)12);
  lcd.write((byte)13);
  // MOVER EL CURSOR A LA SEGUNDA LINEA
  //lcd.setCursor(0, 1);
 
}

void loop()
{
 // EN EL CICLO PRINCIPAL SOLAMENTE RECORREMOS EL MENSAJE DE UN LADO A OTRO
  // VARIABLE PARA CONTROL DE CICLOS
  int i;

  // DESPLAZAR LA PANTALLA A LA DERECHA N VECES
  for ( int i = 0; i < 3; i++ ) {
    lcd.scrollDisplayRight();
    delay (1000);
  }

  // DESPLAZAR LA PANTALLA A LA IZQUIERDA N VECES
  for ( int i = 0; i < 3; i++ ) {
    lcd.scrollDisplayLeft();
    delay (1000);
  }
  
  
}
