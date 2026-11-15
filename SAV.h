#ifndef SAV_H
#define SAV_H
#include <vector>
#include <SDL2/SDL.h>
void swap(int &a, int &b);
void InsertionSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);
void MergeSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);

#endif  // SAV_H
