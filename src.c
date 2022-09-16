#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Structures section



struct Race{
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[10];
    char firstPlaceRaceCarColor[10];
};

struct RaceCar{
    char driverName[10];
    char raceCarColor[10];
    int totalLapTime;
};

// Print functions section

void printIntro(){
    printf("----------------------------------------------------------------------\n");
    printf("Bienvenue à notre événement principal, les fans de course numérique\nJ'espère que tout le monde a pris son goûter car nous allons commencer !");
    printf("\n----------------------------------------------------------------------\n");
}
void printCountDown(){
    printf(" _____Coureurs prêts ! Dans......\n");
  sleep(1);
  printf("%d \n",5);
  sleep(1);
  printf("%d\n",4);
  sleep(1);
  printf("%d \n",3);
  sleep(1);
  printf("%d \n",2);
  sleep(1);
  printf("%d \n",1);
  sleep(2);
  printf("Course !");

}


// Logic functions section
//fonctions d'impression
void printFirstPlaceAfterLap(struct Race *race){
    printf("Après le tour numéro:  %d \n",race->currentLap);
    printf("La première place est occupée par : %s  dans la voiture de course: %s ",race->firstPlaceDriverName,race->firstPlaceRaceCarColor);
}

void printCongratulation(struct Race *race){
    printf("Félicitons tous %s, dans la voiture de course %s, pour son incroyable performance.",race->firstPlaceDriverName,race->firstPlaceRaceCarColor);
    printf("\nC'était vraiment une belle course et bonne nuit à tous !");
}
int calculateTimeToCompleteLap(){

    int vitesse = (rand() % 3)+ 1; 
    int acceleration = (rand() % 3)+ 1;
    int nerves = (rand() % 3)+ 1;
    return (vitesse + acceleration + nerves);

    
 
}
void updateRaceCar(struct RaceCar* raceCar){
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race,struct RaceCar *raceCar1,struct RaceCar* raceCar2 ){
    printf("%d",raceCar1->totalLapTime);
    printf("%d",raceCar2->totalLapTime);
    if((raceCar1->totalLapTime)<(raceCar2->totalLapTime)){
        strcpy(race->firstPlaceDriverName,raceCar1->driverName );
        strcpy(race->firstPlaceRaceCarColor,raceCar1->raceCarColor);
        
    }
    else{
        strcpy(race->firstPlaceDriverName,raceCar2->driverName );
        strcpy(race->firstPlaceRaceCarColor,raceCar2->raceCarColor );
    }
     race->currentLap++;
}

  void startRace(struct RaceCar* raceCar1,struct RaceCar* raceCar2 ){
        
        struct Race race;
        race.numberOfLaps=10;
        strcpy(race.firstPlaceDriverName,"");
        race.currentLap=0;
        strcpy(race.firstPlaceRaceCarColor,"");
        int i;
        while(race.currentLap < race.numberOfLaps) {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race,raceCar1,raceCar2);
        printFirstPlaceAfterLap(&race);
        
        
    }
      printCongratulation(&race);
  }
// main function
int main()
{ 
 srand(time(0));
    
    struct RaceCar raceCar1;
    struct RaceCar raceCar2;
  
    strcpy(raceCar1.driverName,"karim");
    strcpy(raceCar1.raceCarColor,"red");
    
    
    strcpy(raceCar2.driverName,"siham");
    strcpy(raceCar2.raceCarColor,"green");
    
    
    

    printIntro();
    printCountDown();
    startRace(&raceCar1,&raceCar2);
}
