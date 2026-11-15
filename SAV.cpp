#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "SAV.h"

void DrawArrLines(unsigned int ab, unsigned int ba, unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> arr){
  if(arr.size() > x){
    std::cout << "Error, arr size wider than x" << "\n";
    return;
  }
  SDL_RenderClear(renderer);
  unsigned int j = 0;
  for(auto x : arr){
    if(x != arr[ab] && x != arr[ba]) SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    else SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, j, y - 1, j, y - 1 - x);
    j++;
  }
}
void swap(int &a, int &b){
  int temp = b;
  b = a;
  a = temp;
}
void EverythingThatsGoodFromTheWorld(unsigned int ab, unsigned int ba, unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  DrawArrLines(ab, ba, x, y, renderer, arr);
  SDL_RenderPresent(renderer);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
void InsertionSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  for(size_t i = 0; i < arr.size(); i++){
    for(size_t j = i; j > 0; j--){
      EverythingThatsGoodFromTheWorld(j, j - 1, x, y, renderer, arr);
      if(arr[j] < arr[j - 1]){
        swap(arr[j], arr[j - 1]);
      }
      else {
        break;
      }
    }
  }
}
void Mergeration(unsigned int begenn, unsigned int middie, unsigned int enned, unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  unsigned int ll = 1 + middie - begenn;
  unsigned int sizie = enned - begenn + 1;
  unsigned int rl = sizie - ll;
  std::vector<int> reft(ll);
  std::vector<int> right(rl);
  std::vector<int> mommy(arr.size());
  for(size_t sigmaboy = begenn; sigmaboy < enned + 1; sigmaboy++){
    if(sigmaboy <= middie){
      reft[sigmaboy - begenn] = arr[sigmaboy];
    }
    else{
      right[sigmaboy - middie - 1] = arr[sigmaboy];
    }
  }
  size_t l = 0;
  size_t r = 0;
  size_t i = 0;
  while(l < ll && r < rl){
    if(reft[l] <= right[r]){
      mommy[i] = reft[l];
      EverythingThatsGoodFromTheWorld(l + begenn, r + middie + 1, x, y, renderer, arr);
      i++;
      l++;
    }
    else{
      mommy[i] = right[r];
      EverythingThatsGoodFromTheWorld(l + begenn, r + middie + 1, x, y, renderer, arr);
      i++;
      r++;
    }
  }
  while(l < ll){
    mommy[i] = reft[l];
    EverythingThatsGoodFromTheWorld(l + begenn, r + middie + 1, x, y, renderer, arr);
    i++;
    l++;
  }
  while(r < rl){
    mommy[i] = right[r];
    EverythingThatsGoodFromTheWorld(l + begenn, r + middie + 1, x, y, renderer, arr);
    i++;
    r++;
  }
  for(size_t w = begenn; w < enned + 1; w++){
    arr[w] = mommy[w - begenn];
    EverythingThatsGoodFromTheWorld(0, 0, x, y, renderer, arr);
  }
}
void MergeSortSigmaMafiaBossFromMuhammad(unsigned int begenn, unsigned int enned, unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  if(begenn >= enned) return;
  unsigned int meddie = begenn + (enned - begenn) / 2;
  MergeSortSigmaMafiaBossFromMuhammad(begenn, meddie, x, y, renderer, arr);
  MergeSortSigmaMafiaBossFromMuhammad(meddie + 1, enned, x, y, renderer, arr);
  Mergeration(begenn, meddie, enned, x, y, renderer, arr);
}
void MergeSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  MergeSortSigmaMafiaBossFromMuhammad(0, arr.size() - 1, x, y, renderer, arr);
}
