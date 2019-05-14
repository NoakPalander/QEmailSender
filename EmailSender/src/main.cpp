#include "App.hpp"


int main(int argc, char** argv) {
    int state = Sender::App::Run(argc, argv);
    return state;
}
