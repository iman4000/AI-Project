#include <iostream> //header for input and output in program

using namespace std; //namespace for standard library for c++ headers 

/*define functions*/
int cal_cost(int [], const int); //function for calculate cost of hill-climbing for array 
void swap_elements(int [], int, int); //swap 2 city for changing situation

/*implante cal_cost function*/
int cal_cost(int city_array[], const int cities){
    int c = 0; //counter for cost of change
    for(int i = 0; i < cities; i++){ // loop for counting cities
        for(int j = i+1; j < cities; j++){ //loop counting cities from where i is there until end
            if(city_array[j] > city_array[i]) { c++; } //if distance of city[j] is bigger than city[i] it has cost for our algorithm so 
        }                                               //increase c one more!
    }
    return c; // return c as cost of city_array that pass to function
}

/*implante swap_elements function*/
void swap_elements(int city_array[], int i, int j){
    int temp = city_array[i];  //assign content of city_array[i] to temp variable
    city_array[i] = city_array[j]; //assign content of city_array[j] to city_array[i] 
    city_array[j] = temp; //assign content of temp which contains content of city_array[i] to city_array [j]
}

/*main function*/
int main(){  
    int cities; // number of cities
    int counter = 1; // counter for show user which city he is working with
    int city_array[cities]; // array of cities' distances

    cout << "enter number of cities you have: " << endl; // tell user to assign cities variable
    cin >> cities;  // give user a number for to assign cities

    for(int i = 0; i < cities; i++){ // loop for fill city_array array
        cout << "Enter Distance for city " << counter << endl; //notice to user to fill distance for specefic city
        cin >> city_array[i]; // give number for distance of city
        counter++; //plus one counter for next city
    }

    int best_cost = cal_cost(city_array, cities);// assign best cost for first time which is basic format how user fill it
    int new_cost = 0, swaps = 0; // new_cost is temp for cost of how array change # swaps for counting how many swaps need for reaching final route

    while(best_cost > 0){ // while loop for reaching to best route
        for(int i = 0; i < cities -1; i++){ // for loop that do stuff to give best distance array
            swap_elements(city_array, i, i+1); // swap 2 city for knowing is it good or not
            new_cost = cal_cost(city_array, cities); // cost of new array of city_array

            if(best_cost > new_cost){ // if new_cost is less than our best_cost then...
                swaps++; //plus one swaps to reach count of final best route
                /*print routes for user to see*/
                cout << "performing swap: " << swaps << endl;
                for(int i = 0; i < cities; i++){ cout << city_array[i] << "->";}
                cout << "\n";
                best_cost = new_cost; // then assign new_cost to best cost 
            }
            else{
                swap_elements(city_array, i, i+1);  // if new_cost is more than best_cost then it is not a good array so just go for next swap!
            }
        }  
    }
    /*print final best route for user*/
    cout << "\n Final Route: \n";
    for(int i = 0; i < cities; i++){
        cout << city_array[i] << endl;
    }
return 0;
}