//
//  main.cpp
//  1с_task141
/*
    для простоты будем считать что
    валет   11
    дама    12
    король  13
    туз     14
 
 
 */
//
//  Created by Михаил Возняк on 14.04.2021.
//  Copyright © 2021 Михаил Возняк. All rights reserved.
//

#include <set>
#include <string>
#include <iostream>

const int total_cards = 72;
const int number_of_heeps = 8;
const int set_of_cards [9] = {6, 7, 8, 9, 10, 11, 12, 13, 14};

bool checkPegs_solitaire(int solitaire[number_of_heeps][2 * total_cards/number_of_heeps])
{
    int check = false;
    for (int i = 0; i < number_of_heeps; i++)
    {
        for (int j = 0; j < 2 * total_cards/number_of_heeps; j++) {
            if(solitaire[i][j] != 0)
            {
                break;
            }
            check = true;
        }
      
    }
  return check;
}

bool checkMinus_place(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
      if(array[i] != -1)
      {
        return false;
      }
  }
  return true;
}

bool first_check(int solitaire[number_of_heeps][2 * total_cards/number_of_heeps]){
    
    int right_place_of_cards [total_cards/number_of_heeps] = {0};
    int i = 0;
    bool check = false;
    for (i = 0; i < number_of_heeps; i++) {
        if( solitaire[i][0] == 14){
            right_place_of_cards [total_cards/number_of_heeps - 1] = 1;
            check = true;
            break;
        }
       }
    if(check == false ){
        return false;
    }
    
    for (int number_of_card = 13; number_of_card < 6; number_of_card--) {
        
        for (i = 0; i < number_of_heeps; i++) {
            for (int j = 8; j > -1; j--) {
                bool find = false;
                if (solitaire[i][0] == number_of_card){
                    right_place_of_cards [0] = 1;
                    break;
                }
                if(solitaire[i][j] == 14 && find == false){
                    break;
                }
                if (solitaire[i][j] == number_of_card){
                    right_place_of_cards [number_of_card - 6] = 1;
                    break;
                }
                
            }
            if (right_place_of_cards [number_of_card - 6] == 1) break;
        }

         if (right_place_of_cards [number_of_card - 6] == 0) return false;
    }
    
    return true;
}

bool smart_force(int solitaire[number_of_heeps][2 * total_cards/number_of_heeps]){
    // массив в каждой ячейке хранится соответсвующее карте место куда ее можно переложить
    int temporary_solitaire [number_of_heeps][2 * total_cards/number_of_heeps];
    for (int i = 0; i < number_of_heeps; i++) {
        for (int j = 0; j < 2 * total_cards/number_of_heeps ; j ++) {
            temporary_solitaire[i] [j] = solitaire[i] [j];
        }
    }
    
    
    
    int top_element [9] = {8};
    for(;;){
        int place_for_release[9] = {-1};
        int place_what_put[9] = {-1};
        for(int i = 0; i < number_of_heeps; i++){
            if (temporary_solitaire[i][top_element[i]] - 6 > 0){
                place_for_release [temporary_solitaire[i][top_element[i]] - 7] = i;
                place_what_put [temporary_solitaire[i][top_element[i]] - 6] = i;
            }
        }

        for(int k = 0; k < 9; k++){
            if (place_for_release [k]!= -1){
                temporary_solitaire[place_for_release [k]] [top_element[place_for_release [k]] + 1] = k;
                top_element[place_for_release [k]] ++;
                temporary_solitaire[place_for_release [k]] [top_element[place_what_put [k]]] = 0;
                top_element[place_what_put [k]] --;
            }
        }

        
        
        if(checkPegs_solitaire(solitaire) == true){
            return true;
        }
        if(checkMinus_place(place_for_release, 9) == true){
            return false;
        }
        
        
            
    }
}

int main() {
    const int total_cards = 72;
    const int number_of_heeps = 8;
    int solitaire[number_of_heeps][2 * total_cards/number_of_heeps] = {0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < total_cards/number_of_heeps; j++) {
            std::cin >> solitaire[i][j];
        }
    }
    if (first_check(solitaire) == false){
      std::cout << "не сходится";
    }
    
    if (smart_force(solitaire) == false){
      std::cout << "не сходится";
    }
    
    // here goes brute force
    return 0;
}
 

