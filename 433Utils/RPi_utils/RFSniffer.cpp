/*
  RFSniffer

  Usage: ./RFSniffer [<pulseLength>]
  [] = optional

  Hacked from http://code.google.com/p/rc-switch/
  by @justy to provide a handy RF code sniffer
*/

#include "../rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

unsigned int microseconds;

RCSwitch mySwitch;
 
int main(int argc, char *argv[]) {
  
     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
     int PIN = 2;
     
     if(wiringPiSetup() == -1) {
       printf("wiringPiSetup failed, exiting...");
       return 0;
     }

     int pulseLength = 0;
     if (argv[1] != NULL) pulseLength = atoi(argv[1]);

     mySwitch = RCSwitch();
     if (pulseLength != 0) mySwitch.setPulseLength(pulseLength);
     mySwitch.enableReceive(PIN);  // Receiver on interrupt 0 => that is pin #2
     

     int terminate = 1;
     int run = 0;

     time_t start, end;
     double elapsed;
     start = time(NULL);

     while(1) {

      usleep(1000);

      if (mySwitch.available()) {
    
        int value = mySwitch.getReceivedValue();
    
        if (value == 0) {
          printf("Unknown encoding\n");
        } else {    

          time_t ltime;
          ltime=time(NULL);

          printf("%s",asctime( localtime(&ltime)));

          value = mySwitch.getReceivedValue();

          std::string newvalue;
          std::stringstream newstreamvalue;

          newstreamvalue << value;
          newvalue = newstreamvalue.str();

          std::string tmp = "/home/pi/433mhz_decoder/script.sh " + newvalue;

          end = time(NULL);

          elapsed = difftime(end, start);

          if (elapsed <= 5.0 /* seconds */) {
            terminate = 0;

            if(run==0) {
              printf("== RESET ==");
              printf("elapsed %i\n", start);

              start = time(NULL);
              system(tmp.c_str()); // Run bash file

              run++;
            }
          }  else  {
            run = 0;
            start = time(NULL);

            printf("elapsed %i \n", end);
          }

          printf("Received %i\n", mySwitch.getReceivedValue() );
        }
    
        mySwitch.resetAvailable();
    
      }
      
  
  }

  exit(0);


}

