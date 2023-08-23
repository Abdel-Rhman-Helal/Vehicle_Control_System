/*
 ============================================================================
 Name        : Mini_Project_1_C_Programming.c
 Author      : Abdel Rhman Helal
 Date        : 13/8/2023
 Diploma     : 79
 ============================================================================
 */

#include <stdio.h>

typedef enum{
    off , on
}ON_OFF;

void Sensors_set_menu(void){
	/*
	 function to display a Sensors set menu
	 */
    printf("\n**********System Is ON***********\n\n");
    printf("a. Turn off the engine\n");
    printf("b. Set the traffic light color\n");
    printf("c. Set the room temperature (Temperature Sensor)\n");
    printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
}

void System_State_Display(void){
	/*
	 function to display a System set menu
	 */
    printf("\n**Welcome to Vehicle Control system**\n\n");
    printf("a. Turn on the vehicle engine\n");
    printf("b. Turn off the vehicle engine\n");
    printf("c. Quit the system\n");
}

void vehicle_speed_is_30(int**Vehicle_Speed,int**Room_Temperature,ON_OFF**Ac,int**Engine_Temperature,ON_OFF**Engine_Temperature_Controller_State){
	/*
	 function get a Vehichle speed and compere it if = 30 we -> Ac will be on
	 And Room Temp = room temp *(5/4)+1
	 and if it != 30 , Engine_Temperature_Controller_State will be on
	 and Engine Temperature = (**Engine_Temperature)*((float)5/4)+1
	 (float) -> to cast the value from intger to float.
	 */
	if(**Vehicle_Speed==30){
        if(**Ac==off){
            **Ac=on;
            **Room_Temperature = (**Room_Temperature)*((float)5/4)+1;
        }
        if(**Engine_Temperature_Controller_State==off){
            **Engine_Temperature_Controller_State=on;
            **Engine_Temperature = (**Engine_Temperature)*((float)5/4)+1;
        }
    }
}

void Set_the_traffic_light_color(int*Vehicle_Speed){
	/*
	 This Function to for Traffic light Sensor it get a pointer to integer point to a Vehicle speed
	 to change its value in this Function and its Value change in Turn on function
	 (G,O,R) it is a traffic light colors
	  Vehicle_Speed has a inatial value  = 50 km/hr
	 */
    char traffic_light;
    printf("Enter the traffic_light\n");
    scanf(" %c",&traffic_light);
    if(traffic_light=='G' || traffic_light=='g'){
        *Vehicle_Speed=100;
    }else if(traffic_light=='O' || traffic_light=='o'){
        *Vehicle_Speed=30;
    }else if(traffic_light=='r' || traffic_light=='R'){
        *Vehicle_Speed=0;
    }
}

void Temperature_Sensor(int*Room_Temperature,ON_OFF*Ac){
	/*
	 it is for Temperature Sensor it senes a temperature and modifaie a value get form a turn on
	 function and alse Ac value
	 */
    int t;
    printf("Enter the Room_Temperature\n");
    scanf("%d",&t);
    if(t<10){
        *Room_Temperature = 20;
        *Ac = on;
    }else if(t>30){
        *Room_Temperature = 20;
        *Ac = on;
    }else{
        *Room_Temperature = t;
        *Ac = off;
    }
}

void Engine_Temperature_Sensor(int*Engine_Temperature,ON_OFF*Engine_Temperature_Controller_State){
	/*
	 it is for Engine_Temperature_Sensor it senes a Engine_Temperature and modifaie a value get form a turn on
	 function and alse Engine_Temperature_Controller_State value
	 */
	int Et;
    printf("Enter the value of Engine Temperature \n");
    scanf("%d",&Et);
    if(Et<100){
        *Engine_Temperature_Controller_State=on;
        *Engine_Temperature=125;
    }else if(Et>150){
        *Engine_Temperature=125;
        *Engine_Temperature_Controller_State=on;
    }else{
        *Engine_Temperature_Controller_State=off;
        *Engine_Temperature =Et;
    }
}

void Display_the_current_vehicle_state(int *Vehicle_Speed,int*Room_Temperature,ON_OFF*Ac,int*Engine_Temperature,ON_OFF*Engine_Temperature_Controller_State){
    /*
     this function to display  after modifaing any thing in a Sensor menu
     put before it display it Call a 	vehicle_speed_is_30() function to make the last modify
     before display values
     */
	vehicle_speed_is_30(&Vehicle_Speed,&Room_Temperature,&Ac,&Engine_Temperature,&Engine_Temperature_Controller_State);
    printf("Engine state : ON \n");
    *Ac==on?printf("AC : ON\n"):printf("AC : OFF\n");
    printf("Vehicle Speed : %d KM/hr\n",*Vehicle_Speed);
    printf("Room Temperature : %d c\n",*Room_Temperature);
    *Engine_Temperature_Controller_State==on?printf("Engine Temperature Controller State : ON\n"):printf("Engine Temperature Controller State : OFF\n");
    printf("Engine Temperature : %d c\n",*Engine_Temperature);
}

void Turn_on_the_vehicle_engine(ON_OFF Ac,ON_OFF Engine_Temperature_Controller_State,int Vehicle_Speed ,int Room_Temperature,int Engine_Temperature){
	/*
	 All varibales we will want get by passing by value
	 to reset it in every time we rerun the program
	 */
    char Sensors_State;
    Sensors_set_menu();
    scanf(" %c",&Sensors_State);//to get a Sensore State
    switch (Sensors_State) {
        case 'a':
            break;
        case 'b':
            Set_the_traffic_light_color(&Vehicle_Speed);
            Display_the_current_vehicle_state(&Vehicle_Speed,&Room_Temperature,&Ac,&Engine_Temperature,&Engine_Temperature_Controller_State);
            Turn_on_the_vehicle_engine(Ac,Engine_Temperature_Controller_State,Vehicle_Speed ,Room_Temperature,Engine_Temperature);
            break;
        case 'c':
            Temperature_Sensor(&Room_Temperature,&Ac);
            Display_the_current_vehicle_state(&Vehicle_Speed,&Room_Temperature,&Ac,&Engine_Temperature,&Engine_Temperature_Controller_State);
            Turn_on_the_vehicle_engine(Ac,Engine_Temperature_Controller_State,Vehicle_Speed ,Room_Temperature,Engine_Temperature);
            break;
        case 'd':
            Engine_Temperature_Sensor(&Engine_Temperature,&Engine_Temperature_Controller_State);
            Display_the_current_vehicle_state(&Vehicle_Speed,&Room_Temperature,&Ac,&Engine_Temperature,&Engine_Temperature_Controller_State);
            Turn_on_the_vehicle_engine(Ac,Engine_Temperature_Controller_State,Vehicle_Speed ,Room_Temperature,Engine_Temperature);
            break;
        default:
            break;
    }
    // Call a Function to display function
}

void Turn_off_the_vehicle_engine(void){
	/*function to display that  a System off*/
    printf("\nTurn OFF Vehicle Engine (Press (a) To run System) \n\n\n");
}

int main(void) {
    for(;;){
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        char System_State;
        ON_OFF Ac=off,Engine_Temperature_Controller_State=off;
        int Vehicle_Speed =50,Room_Temperature=25,Engine_Temperature=125;
        System_State_Display();
        scanf(" %c",&System_State);
        if(System_State=='a'){
            Turn_on_the_vehicle_engine(Ac,Engine_Temperature_Controller_State,Vehicle_Speed ,Room_Temperature,Engine_Temperature);
        }else if(System_State=='b'){
            Turn_off_the_vehicle_engine();
        }else{
        	printf("Quit The System");
            return 0;
        }
    }
}

