#include <stdio.h>

#include <fstream>
#include <string>
using namespace std;
const int MAX_BLUE = 14;
const int MAX_GREEN = 13;
const int MAX_RED = 12;

bool isInt(char c) {
    int x = (c - '0');
    return (x >= 48 && x <= 57);
}

bool legal(string game) {
  string delimiter = ",";
  string play;
  size_t pos = 0;
  bool bLegal = false;
  while ((pos = game.find(delimiter)) != string::npos) {
    play = game.substr(0, pos);


    game.erase(0, pos + delimiter.length());
  }
  return true;
}

int main() {
  int sum = 0;
  ifstream f("input.txt");
  if (f.is_open()) {
    string line;
    while (getline(f, line)) {
      bool bLegalCount = true;
      // get game ID
      int gameIdStartPos = 5;
      int colonPos = line.find(":");
      string strGameId =
          line.substr(gameIdStartPos, (colonPos - gameIdStartPos));
      long iGameId = strtol(strGameId.c_str(), nullptr, 10);
      string inputValues = line.substr((colonPos + 2));
      string delimiter = ";";
      string game;
      size_t pos = 0;
      bool bLegal = false;
      while ((pos = inputValues.find(delimiter)) != string::npos) {
        game = inputValues.substr(0, pos);
        bLegal = legal(game);
        if (!bLegal) {
          break;
        }
        inputValues.erase(0, pos + delimiter.length());
      }
      if (bLegal) {
        sum += iGameId;
      }
    }
  }
  printf("sum: %d\n", sum);

  return 0;
}