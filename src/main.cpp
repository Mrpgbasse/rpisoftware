#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <errno.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringPiSPI.h>

#include "/home/pi/Documents/loudspeakerSoftware/src/settings.h" 

using namespace std;

/*
 *  Architecture du code
 * ------------------------
 * Initialisation de wiringPi
 * Initialisation de la liaison I2C avec les deux TDA 7317
 * Initialisation de la liaison SPI avec les deux AD 5204
 * Initialisation de l'ensemble des pin utilisées comme GPIO
 *
 * Boucle while(1)
 * *  
 * * 
 * * 
 * * 
 * ------------------------
 * Fin de l'architecture
 */

// Definition des pin GPIO utilisées
#define RelayPin 29

/* I2C Start condition
* SCL HIGH 
* SDA HIGH -> LOW
*
* I2C Stop condition
* SCL LOW -> HIGH
* SDA LOW -> HIGH
*
* Ne jamais modifier l'état de SCL pendant un changement d'état de SDA
* Modifier SDA que quand SCL est LOW
* 
* Mettre SDA en HIGH au moment du ACKNOWLEDGE. LE TDA passera SDA à LOW si ACK
*
* PULL UP sur SDA et SCL
*/

int TDAVolume(char command)
{
  if(command == '0,375')
}

int main() 
{

  // Définition des variables du programme
  int state = 0; // Niveau du relais: 1 = fermé (contact) 0 = ouvert (pas contact)
  int commandTDA[18];

  commandTDA[0] = 0x00;
  commandTDA[1] = 0x01;
  commandTDA[2] = 0x02;
  commandTDA[3] = 0x03;
  commandTDA[4] = 0x04;
  commandTDA[5] = 0x05;
  commandTDA[6] = 0x06;
  commandTDA[7] = 0x07;
  commandTDA[8] = 0x00;
  commandTDA[9] = 0x08;
  commandTDA[10] = 0x09;
  commandTDA[11] = 0x10;
  commandTDA[12] = 0x11;
  commandTDA[13] = 0x12;
  commandTDA[14] = 0x13;
  commandTDA[15] = ;
  commandTDA[16] = ;
  commandTDA[17] = ;






  }

  // Initialisation de wiringPi
    if(wiringPiSetup() == -1) //when initialize wiringPi failed, print message to screen
    { 
    printf("setup wiringPi failed !\n");
    return -1; 
  }


  // Initialisation des périphériques i2c au moyen de wiringPiI2CSetup
  int devIdTDABass = 0x86;
  int devIdTDATrebble = 0x84;
  // création de l'objet I2C à l'adresse 0x86 (pour TDA bass)
	int I2C_TDABASS = wiringPiI2CSetup(devIdTDABass);
  // test validant la création de l'objet I2C
    if(I2C_TDABASS < 0) cout << "Erreur avec la connexion au TDA bass | Errno is: " << errno << endl;
    else  cout << "Connexion reussie avec TDA bass | "<< I2C_TDABASS << endl;
  /*  
    // création de l'objet I2C à l'adresse 0x82 (pour TDA trebble)
  int I2C_TDATREBL = wiringPiI2CSetup(devIdTDATrebble);
  // test validant la création de l'objet I2C
    if(I2C_TDATREBL < 0) cout << "Error. TDA trebble Errno is: " << errno << endl;
    else  cout << "Init result for TDA trebble: "<< I2C_TDATREBL << endl;

/*
  // Initialisation des périphériques SPI au moyen de wiringPiSPISetup
  int devIdAD1;
  int devIdAD2;
  int speed = 500000;
  // création de l'objet SPI à l'adresse (premier digipot)
  int SPI_AD1 = wiringPiSPISetup(devIdAD1, speed);
  // test validant la création de l'objet SPI
    if(SPI_AD1 < 0) cout << "Error. AD1 creation  Errno is: " << errno << endl;
    else  cout << "Init result for AD1: "<< SPI_AD1 << endl;
    // création de l'objet I2C à l'adresse 0x42 (pour TDA trebble)
  int SPI_AD2 = wiringPiSPISetup(devIdAD2, speed);
  // test validant la création de l'objet I2C
    if(SPI_AD2 < 0) cout << "Error. AD2 Errno is: " << errno << endl;
    else  cout << "Init result for AD2: "<< SPI_AD2 << endl;
*/
    
  // Initialisation de l'ensemble des pin utilisées comme GPIO
  pinMode(RelayPin, OUTPUT);
  //pullUpDnControl(pin, mode) permet de configurer une pin en mode pull-up, pull-down ...

  // Boucle infinie du programme
  do
  {
    cin >> state;
    if(state == 0 || state == 1) digitalWrite(RelayPin, state);

  }
  while(1);
  
    return 0;
}

