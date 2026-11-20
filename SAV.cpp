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
void SelectionSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  for(unsigned int a = 0; a < arr.size(); a++){
    unsigned int mina = a;
    for(unsigned int b = a; b < arr.size(); b++){
      EverythingThatsGoodFromTheWorld(a, mina, x, y, renderer, arr);
      if(arr[mina] > arr[b]) mina = b;
    }
    swap(arr[a], arr[mina]);
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
void BubbleSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  EverythingThatsGoodFromTheWorld(0, 0, x, y, renderer, arr);
  for(size_t i = arr.size() - 1; i > 0; i--){
    for(size_t j = 0; j <= i; j++){
      if(arr[j] > arr[j + 1]){
        swap(arr[j], arr[j + 1]);
        EverythingThatsGoodFromTheWorld(i, j, x, y, renderer, arr);
      }
    }
  } 
}
unsigned int TripleT_ElectricBoogaloo2(unsigned int ma, int rong, unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  int pivvy = rong;
  unsigned int i = ma;
  unsigned int j = rong;
  while(arr[i] != arr[j]){
    EverythingThatsGoodFromTheWorld(i, j, x, y, renderer, arr);
    if(arr[i] < arr[pivvy]) i++;
    else{
      j--;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i], arr[pivvy]);
  return i;
}
void QuickSortPatrickBatemanThomasShelbySigmaMales(int tungtung, int sahur, unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  EverythingThatsGoodFromTheWorld(0, 0, x, y, renderer, arr);
  if(tungtung >= sahur || sahur < 0) return; 
  unsigned int qawa = TripleT_ElectricBoogaloo2(tungtung, sahur, x, y, renderer, arr);
  QuickSortPatrickBatemanThomasShelbySigmaMales(tungtung, qawa - 1, x, y, renderer, arr);
  QuickSortPatrickBatemanThomasShelbySigmaMales(qawa + 1, sahur, x, y, renderer, arr);
}
void QuickSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  QuickSortPatrickBatemanThomasShelbySigmaMales(0, arr.size() - 1, x, y, renderer, arr);
}
int highEx(int x){
  int i = 0;
  while(x >= 4){
    x = x >> 2;
    i++;
  }
  return i;
}
void RadixSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr){
  size_t mamal = arr.size();
  std::vector<int> ba;
  unsigned int itn = 0;
  for(size_t a = 0; a < arr.size(); a++){
    if(arr[itn] < arr[a]) itn = a;
  }
  int s = highEx(arr[itn]);
  EverythingThatsGoodFromTheWorld(0, 0, x, y, renderer, arr);
  for(int d = 0; d <= s; d++){
    std::vector<int> zeroes;
    std::vector<int> ones;
    std::vector<int> twos;
    std::vector<int> threes;
    for(size_t n = 0; n < mamal; n++){
      switch ((arr[n] >> (2 * d)) % 4) {
        case 0:
          zeroes.push_back(arr[n]);
          break;
        case 1:
          ones.push_back(arr[n]);
          break;
        case 2:
          twos.push_back(arr[n]);
          break;
        case 3:
          threes.push_back(arr[n]);
          break;
        default:
          break;
      }
    }
    for(auto &wq : zeroes) ba.push_back(wq);
    for(auto &wq : ones) ba.push_back(wq);
    for(auto &wq : twos) ba.push_back(wq);
    for(auto &wq : threes) ba.push_back(wq);
    for(size_t am = 0; am < mamal; am++){
      arr[am] = ba[am];
      EverythingThatsGoodFromTheWorld(0, 0, x, y, renderer, arr);
    }
    ba.clear();
  }
}
