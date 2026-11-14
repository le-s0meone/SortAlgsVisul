#include <iostream>
#include <SDL2/SDL.h>
#include "SAV.h"
#include <random>
#include <vector>
int main(){
  SDL_Window *window = nullptr; 
  SDL_Renderer *renderer = nullptr; 
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  std::vector<int> arr;
  for(int i = 0; i < 400; i++){
    arr.push_back(i + 1);
  }
  for(int i = 0; i < 400; i++){
    std::random_device special;
    std::mt19937 gen(special());
    std::uniform_int_distribution<int> dist(0, 399);
    swap(arr[i], arr[dist(gen)]);
  }
  for(auto s : arr) std::cout << s << " ";
  DrawArrLines(640, 480, renderer, arr);
  SDL_RenderPresent(renderer);
  InsertionSort(640, 480, renderer, arr);
  for(auto s : arr) std::cout << s << " ";
  DrawArrLines(640, 480, renderer, arr);
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
	return 0;
}
