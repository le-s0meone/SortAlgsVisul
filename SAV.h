#ifndef SAV_H
#define SAV_H
#include <vector>
#include <SDL2/SDL.h>
void swap(int &a, int &b);
void InsertionSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);
void SelectionSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);
void MergeSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);
void BubbleSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);
void QuickSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);
void RadixSort(unsigned int x, unsigned int y, SDL_Renderer *renderer, std::vector<int> &arr);

#endif  // SAV_H
