#include "SAV.h"
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

void DrawArrLines(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> arr){
  if(arr.size() > x){
    std::cout << "Error, arr size wider than x" << "\n";
    return;
  }
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  unsigned int j = 0;
  for(auto x : arr){
    SDL_RenderDrawLine(renderer, j, y - 1, j, y - 1 - x);
    j++;
  }
}
void swap(int &a, int &b){
  int temp = b;
  b = a;
  a = temp;
}
void InsertionSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  for(size_t i = 0; i < arr.size(); i++){
    for(size_t j = i; j > 0; j--){
//      DrawArrLines(x, y, renderer, arr);
//      SDL_RenderPresent(renderer);
      if(arr[j] < arr[j - 1]){
        swap(arr[j], arr[j - 1]);
      }
      else {
        break;
      }
    }
  }
}
