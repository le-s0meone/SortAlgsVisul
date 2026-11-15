#include <iostream>
#include <SDL2/SDL.h>
#include "SAV.h"
#include <random>
#include <vector>
int main(){
  SDL_Window *window = nullptr; 
  SDL_Renderer *renderer = nullptr; 
  SDL_Init(SDL_INIT_VIDEO);
  unsigned int x = 120;
  unsigned int y = x;
  SDL_CreateWindowAndRenderer(x, y, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  std::vector<int> arr;
  int lenny = x - 20;
  for(int i = 0; i < lenny; i++){
    arr.push_back(i + 1);
  }
  for(int i = 0; i < lenny; i++){
    std::random_device special;
    std::mt19937 gen(special());
    std::uniform_int_distribution<int> dist(0, lenny - 1);
    swap(arr[i], arr[dist(gen)]);
  }
  MergeSort(x, y, renderer, arr);
	return 0;
}
