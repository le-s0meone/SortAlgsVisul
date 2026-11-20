#include <iostream>
#include <SDL2/SDL.h>
#include "SAV.h"
#include <random>
#include <vector>
void coi(std::vector<int> &ars, std::vector<int> arr){
  if(ars.size()){
    ars.clear();
  }
  for(size_t i = 0; i < arr.size(); i++){
    ars.push_back(arr[i]);
  }
}
int main(){
  SDL_Window *window = nullptr; 
  SDL_Renderer *renderer = nullptr; 
  SDL_Init(SDL_INIT_VIDEO);
  unsigned int x = 320;
  unsigned int y = x;
  window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, 0);
  renderer = SDL_CreateRenderer(window, 0, 0);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  std::vector<int> arr, ara;
  int lenny = x - 20;
  for(unsigned int into = 0; into < 5; into++){
    arr.clear();
    for(int i = 0; i < lenny; i++){
      arr.push_back(i + 1);
    }
    for(int i = 0; i < lenny; i++){
      std::random_device special;
      std::mt19937 gen(special());
      std::uniform_int_distribution<int> dist(0, lenny - 1);
      swap(arr[i], arr[dist(gen)]);
    }
    SDL_SetWindowTitle(window, "RadixSort");
    coi(ara, arr);
    RadixSort(x, y, renderer, ara);
    SDL_SetWindowTitle(window, "MergeSort");
    coi(ara, arr);
    MergeSort(x, y, renderer, ara);
    SDL_SetWindowTitle(window, "QuickSort");
    coi(ara, arr);
    QuickSort(x, y, renderer, ara);
  }
	return 0;
}
