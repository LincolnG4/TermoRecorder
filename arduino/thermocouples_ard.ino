/***************************************************************************
Criador: Gabriel Espinola
Email: g97santos@gmail.com
****************************************************************************/
/***************************************************************************

****************************************************************************/
#include <LiquidCrystal.h>
#include "max6675.h"
#include <SD.h>
#include <SPI.h>

                                                                                      /*Configurações de */// pino SD e Arquivo de dados SD
File dadosT1;
File dadosT2;
File dadosT3;
File dadosT4;
int pinCS = 53;                                                                         // PINO DO ARDUINO MEGA 
                                                                                      /*-------------------------------------*/
                                                                                        /* TIMER*/
float Te=0;                                                                             // tempo salvo no SD
//unsigned long timer=0;
float Te2=0;                                                                            // tempo salvo no SD
//unsigned long timer2=0; 
float Te3=0;                                                                             // tempo salvo no SD
//unsigned long timer=0;
float Te4=0;                                                                            // tempo salvo no SD
//unsigned long timer2=0;                                                               //Armazena os segundos transcorridos e inicia no 0 
 
unsigned long t1=0; 
unsigned long t2=0; 
unsigned long t3=0; 
unsigned long t4=0; 
unsigned long t5=0; 
unsigned long t6=0; 
unsigned long t7=0; 
unsigned long t8=0; 

//Botao1                                                                                /*Configurações do  */// Botao START
const int botao=46;
int var=0;                                                                              // valor instantaneo enviado pelo botão
int var2=0;                                                                             // valor guardado
int estado=0;
//Botao2                                                                               
const int botao2=49;
int var3=0;                                                                             
int var4=0;                                                                             
int estado2=0;                                                                          /*-------------------------------------*/
//Botao3                                                                              
const int botao3=48;
int var5=0;                                                                             
int var6=0;                                                                             
int estado3 =0; 
//Botao4                                                                              
const int botao4=47;
int var7=0;                                                                             
int var8=0;                                                                             
int estado4 =0; 

                                                                                        /*Configurações dos Pinos para o  */ //Módulo de Temperatura
//Termopar 1                                                                                      
int ktcSO=34;
int ktcCS=35;
int ktcCLK=33;
MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
//Termopar 2                                                                                      
int ktcSO2=27;
int ktcCS2=29;
int ktcCLK2=31;
MAX6675 ktc2(ktcCLK2, ktcCS2, ktcSO2);
//Termopar 3                                                                                      
int ktcSO3=28;
int ktcCS3=30;
int ktcCLK3=32;
MAX6675 ktc3(ktcCLK3, ktcCS3, ktcSO3);
//Termopar 4                                                                                     
int ktcSO4=24;
int ktcCS4=22;
int ktcCLK4=26;
MAX6675 ktc4(ktcCLK4, ktcCS4, ktcSO4);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
                                                                                        /*-------------------------------------*/
void setup() {                                                                          
Serial.begin(9600);                                                                                        /*Inicialização do*/// Botao START
pinMode(botao, INPUT);
pinMode(botao2, INPUT);                                                                 
pinMode(botao3, INPUT);
pinMode(botao4, INPUT);                                                                 /*-------------------------------------*/
                                                                                        /*Configurações para o*/// LCD 
lcd.begin(16, 2);
                                                                                        /*-------------------------------------*/
int ligasd=0;                                                                           /*Inicialização do*///  SD
pinMode(pinCS, OUTPUT);
  
if (SD.begin())                                                                         //Reconhecimento do cartao
  {
    ligasd=1;
  } else
  {   
    lcd.print("SD not found");
    delay(5000);
    lcd.clear();
    return;
  }
                                                                                        /*-------------------------------------*/                                                                                       /*-------------------------------------*/ 
}

void loop() {        
                                                                                        /*Inicialização do*///  COMANDO DO BOTAO LIGA/DELISG
delay(170);
var = digitalRead(botao);

if (var && !var2) 
    {
        var2 = 1;
        estado = 1 - estado;
        lcd.setCursor(3,0); 
        lcd.print("     ");
        //timer=0; 
        t1 = millis();
        Te=0;
    }
else if (!var){
    var2 = 0;
    }
    
if (estado == 0) 
    {
    lcd.setCursor(0,0); 
    lcd.print("A:OFF");
    }                                                                                   
    else 
    {

    t2 = millis();
    Te = t2 - t1; 
    Te = (Te/1000);                                                                                                                                                                                                                                    
    dadosT1 = SD.open("Dados1.csv", FILE_WRITE);                                         
    String dataString1 = String(Te) + ", " + ktc.readCelsius() ;
  
    lcd.setCursor(0,0);                                                            
    lcd.print("A:");                                                                                 
   
    if (dadosT1)                                                                       
       {                                                                                
       dadosT1.println(dataString1);
       dadosT1.close();                                                   
       }                                                                   
     
                                                                                     
    lcd.setCursor(2,0);             
    lcd.print(ktc.readCelsius());
    }                           
//________________________________________________________________________________________________________________________________________

var3 = digitalRead(botao2);

if (var3 && !var4) 
    {
        var4 = 1;
        estado2 = 1 - estado2;
        lcd.setCursor(3,1); 
        lcd.print("     ");
        //timer=0;
        t3 = millis(); 
        Te2=0;
    }
else if (!var3){
    var4 = 0;
}

if (estado2 == 0) 
    {
    lcd.setCursor(0,1); 
    lcd.print("B:OFF");
    }                                                                                   
    else 
    {
    t4 = millis();
    Te2 = t4 - t3; 
    Te2 = Te2/1000; 
                                                                     
    lcd.setCursor(0,1);                                                            
    lcd.print("B:");                                                                                    
                                                                                       
    dadosT2 = SD.open("Dados2.csv", FILE_WRITE);                                         
    String dataString2 = String(Te2) + ", " + ktc2.readCelsius() ;
                                                                                     
    if (dadosT2)                                                                       
       {                                                                                
       dadosT2.println(dataString2);
       dadosT2.close();                                                   
       }                                                                   
                                                                                     
    lcd.setCursor(2,1);             
    lcd.print(ktc2.readCelsius());
    }                                                                                 


//________________________________________________________________________________________________________________________________________

var5 = digitalRead(botao3);

if (var5 && !var6) 
    {
        var6 = 1;
        estado3 = 1 - estado3;
        lcd.setCursor(8,0); 
        lcd.print("                ");
        //timer=0; 
        t5 = millis();
        
        Te3=0;
    }
else if (!var5){
    var6 = 0;
}


if (estado3 == 0) 
    {
    lcd.setCursor(8,0); 
    lcd.print("C:OFF");
    }                                                                                   
    else 
    {
    
 
    t6 = millis();
     Serial.println(t6);
     Serial.println(t5); 
    Te3 = t6 - t5; 
    Te3 = Te3/1000;                                                                    
    lcd.setCursor(8,0);                                                            
    lcd.print("C:");                                                                                    
                                                                                     
    dadosT3 = SD.open("Dados3.csv", FILE_WRITE);                                         
    String dataString3 = String(Te3) + ", " + ktc3.readCelsius() ;
                                                                                        
    lcd.setCursor(10,0);             
    lcd.print(ktc3.readCelsius());                                                 
    Serial.println(dataString3);                                                                                  
    if (dadosT3)                                                                       
       {                                                                                
       dadosT3.println(dataString3);
       dadosT3.close();                                                   
       }                                                                   
       {
        }
    }   
    //________________________________________________________________________________________________________________________________________

var7 = digitalRead(botao4);

if (var7 && !var8) 
    {
        var8 = 1;
        estado4 = 1 - estado4;
        lcd.setCursor(8,1); 
        lcd.print("            ");
        //timer=0; 
        t7 = millis();
        Te4=0;
    }
else if (!var7){
    var8 = 0;
    }


if (estado4 == 0) 
    {
    lcd.setCursor(8,1); 
    lcd.print("D:OFF");
    }                                                                                   
    else 
    {
    t8 = millis();
    Te4 = t8 - t7; 
    Te4 = Te4/1000;
                                                                       
    lcd.setCursor(8,1);                                                            
    lcd.print("D:");                                                                                    
                                                                                       
    dadosT4 = SD.open("Dados4.csv", FILE_WRITE);                                         
    String dataString4 = String(Te4) + ", " + ktc4.readCelsius() ;
                                                                                     
    if (dadosT4)                                                                       
       {                                                                                
       dadosT4.println(dataString4);
       dadosT4.close();                                                   
       }                                                                   
                                                                                       
    lcd.setCursor(10,1);             
    lcd.print(ktc4.readCelsius());                                                 
             
    }    
    
                                                                  
} 
