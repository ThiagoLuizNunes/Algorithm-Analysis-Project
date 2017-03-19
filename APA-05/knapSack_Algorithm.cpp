#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const static string PATH = "instancias_mochila/";

int max(int a, int b) {
  return (a > b)? a : b;
}
int knapSack(int W, int wt[], int val[], int n){

  int K[n+1][W+1];

  for (size_t i = 0; i < n; i++) {
    K[i][0] = 0;
  }
  for (size_t i = 0; i < W; i++) {
    K[0][i] = 0;
  }
  for (size_t i = 1; i <= n; i++) {
    for (size_t x = 1; x <= W; x++) {
      if(wt[i-1] <= x){
        K[i][x] = max(val[i-1] + K[i-1][x-wt[i-1]],  K[i-1][x]);
      }
      else{
          K[i][x] = K[i-1][x];
      }
    }
  }
  //Print table
  for(size_t i = 0; i <= n; i++) {
    for(size_t j = 0; j <= W; j++) {
        cout << "|" << K[i][j] <<"|";
    }
    cout << endl;
  }
  //Number´print sequence
  int w = W;
  std::vector<int> v;

  for (size_t i = n; i > 0; i--) {
    if(K[i][w] != K[i-1][w]){
      v.push_back(wt[i]);
      w = w - wt[n];
    }
  }

  cout << endl;
  cout << "Size of itemns in the bag: ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << " " << v.at(i);
  }
  cout << endl;
  return K[n][W];
}

int main(int argc, char const *argv[]) {

  std::vector<string> vFile;
  string line;

  for (size_t i = 0; i < 2; i++) {

    int number = i+1;
    //Open file from directory
    ifstream file(PATH + "mochila0"+ to_string(number) + ".txt");

    //Pushing all lines from .text to Vector
    while(std::getline(file, line)){
      vFile.push_back(line);
    }

    for (size_t i = 0; i < vFile.size(); i++) {
      cout << vFile.at(i) << endl;
    }
    cout << endl;
  }
  int val[] = {3,6,9};
  int wt[] = {2, 3, 6};
  int  W = 10;
  int n = sizeof(val)/sizeof(val[0]);

  cout << "Maximum bag value: "<< knapSack(W, wt, val, n) << endl;
  cout << endl;

  return 0;
}
