#include <LiquidCrystal_I2C.h>//Libreria para LCD I2C
#include <Wire.h>//libreria requrida para usar SDA y SCL
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Declaracion de variables
int Humedad=0;//Variable utilizada para calcular la humedad
int Lectura_Analogica=0;//variable para leer el valor del pin analogico
void setup() 
{
  lcd.begin(20, 4);//Inicializar la LCD 20x4
  lcd.backlight();//Encender la luz de fondo
}
 
void loop() 
{
  char buffer[10];//Variable para crear una cadena
  Lectura_Analogica = analogRead(A0);//Leer el valor del potenciometro 
  Humedad = map(Lectura_Analogica, 0, 1023, 100, 0);//Escala para utilizarlo con el servo 
  //Mostrar mensajes en la LCD
  lcd.setCursor(1, 1); //posicionar el cursor fila 1 columna 1
  lcd.print("Sensor de humedad");
  lcd.setCursor(3, 2); //posicionar el cursor fila 2 columna 3
  lcd.print("Humedad=");
  sprintf(buffer,"%03d",Humedad);//crear una cadena para mostrar siempre 3 digitos
  lcd.print(buffer);//Mostrar el % de humedad
  lcd.print("%");
  delay(250);//Esperar 250 ms
}
