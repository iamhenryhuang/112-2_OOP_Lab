#include <iostream>
using namespace std;

class App {
public:
    App(int d = 0) : download(d) {}

    virtual ~App() {}

    int getDownload() const {
        return download;
    }

    void increaseDownload() {
        ++download;
    }

private:
    int download;
};

class JJBox : public App {
public:
    JJBox(int d = 0) : App(d) {}

    int getSongs() const {
        return getDownload() * 5;
    }
};

class Nosebook : public App {
public:
    Nosebook(int d = 0) : App(d) {}

    int getFriends() const {
        return getDownload() * 3 + 5;
    }
};


void updateJJBox(JJBox& jjbox, int& tempJJSongs) {
    jjbox.increaseDownload();
    tempJJSongs = jjbox.getSongs();
}

void updateNosebook(Nosebook& nosebook, int& tempNbFriends) {
    nosebook.increaseDownload();
    tempNbFriends = nosebook.getFriends();
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    JJBox jjbox(n1);
    Nosebook nosebook(n2);

    int jjSongs = jjbox.getSongs();
    int nbFriends = nosebook.getFriends();
    int tempJJSongs = jjSongs;
    int tempNbFriends = nbFriends;

    int operation;
    while (cin >> operation && operation != -1) {
        switch (operation) {
            case 1:
                updateJJBox(jjbox, tempJJSongs);
                break;
            case 2:
                updateNosebook(nosebook, tempNbFriends);
                break;
            case 3:
                updateJJBox(jjbox, tempJJSongs);
                updateNosebook(nosebook, tempNbFriends);
                break;
            case 4:
                jjSongs = tempJJSongs; // Update jjSongs to the latest temp value               
                break;
            case 5:
                nbFriends = tempNbFriends; // Update nbFriends to the latest temp value
                break;
        }

        cout << "JJBox now has " << jjSongs << " songs." << endl;
        cout << "NoseBook now has " << nbFriends << " friends." << endl;
        cout << "==========" << endl;

    }
    
    return 0;
}
