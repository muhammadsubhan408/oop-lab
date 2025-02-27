#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Blend {
public:
    void blend() {
        for (int i = 0; i < 5; ++i) {
            cout << "Blending... " << i + 1 << " seconds." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Blending finished!" << endl;
    }
};

class Grind {
public:
    void grind() {
        for (int i = 0; i < 5; ++i) {
            cout << "Grinding... " << i + 1 << " seconds." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Grinding finished!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;
public:
    void blendJuice() {
        blender.blend();
    }
    void grindJuice() {
        grinder.grind();
    }
    void makeJuice() {
        cout << "Starting the juice-making process..." << endl;
        blendJuice();
        grindJuice();
        cout << "Juice is ready!" << endl;
    }
};

int main(int argc, char* argv[]) {
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}
