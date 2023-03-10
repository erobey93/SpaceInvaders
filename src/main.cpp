#include "config.h"
#include "game.h"


using std:: cout;
using std:: endl;

int main(int argc, char* argv[]) {

    Config& c = Config::Instance();

    Game game;

    game.run();
}

