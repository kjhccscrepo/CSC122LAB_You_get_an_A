#include "id_maker.hpp"

char ID_maker::intToAlphabet(const int &i) {
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
}
ID_maker::ID_maker() {
    srand(time(nullptr));
}
std::string ID_maker::generateID() {
    std::stringstream ID;
    ID << "H00";
    int p = 0;
    int num = 0;
    int L = 0;
    for (int i = 0; i < 7; i++) {
        p = rand() % 9 + 1;
        if (p < 4) {
            L = ((rand() % 25) + 1);
            ID << intToAlphabet(L);
        } else {
            num = (rand() % 9);
            ID << std::to_string(num);
        }
    }
    for (int i = 0; i < takenID.size(); i++) {
        if (ID.str() == takenID[i]) {
            return generateID();
        }
    }
    takenID.push_back(ID.str());
    return ID.str();
}