#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ghost {
protected:
    string workerName;
    int scareLevel;
public:
    Ghost(string name, int level) : workerName(name), scareLevel(level) {}
    virtual ~Ghost(){}
    virtual void haunt()const=0;
    int getScareLevel()const { return scareLevel; }
    friend ostream& operator<<(ostream& os,const Ghost& ghost) {
        os <<"Ghost:"<<ghost.workerName<<"(Scare Level:"<<ghost.scareLevel<<")";
        return os;
    }
    Ghost operator+(const Ghost& other) {
        return Ghost(workerName +" & "+ other.workerName, scareLevel + other.scareLevel);
    }
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string name, int level) : Ghost(name, level) {}
    void haunt() const override {
        cout<<workerName<<"is moving objects around!"<<endl;
    }
};

class Banshee : public Ghost {
public:
    Banshee(string name,int level) : Ghost(name,level) {}
    void haunt() const override {
        cout<<workerName<<" is screaming loudly!"<< endl;
    }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string name, int level) : Ghost(name, level) {}
    void haunt() const override {
        cout << workerName << " is whispering creepily..." << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost {
public:
    ShadowPoltergeist(string name, int level)
        : Poltergeist(name, level), ShadowGhost(name, level), Ghost(name, level) {}
    void haunt() const override {
        Poltergeist::haunt();
        ShadowGhost::haunt();
    }
};

class Visitor {
    string name;
    int bravery;
public:
    Visitor(string n, int b) : name(n), bravery(b) {}
    void reactToScare(int scareLevel) const {
        if (scareLevel < bravery) {
            cout << name << " laughs and taunts the ghost!" << endl;
        } else if (scareLevel > bravery) {
            cout << name << " screams and runs away!" << endl;
        } else {
            cout << name << " gets a shaky voice but stays." << endl;
        }
    }
    int getBravery() const { return bravery; }
};

class HauntedHouse {
    string name;
    vector<shared_ptr<Ghost>> ghosts;
public:
    HauntedHouse(string n) : name(n) {}
    void addGhost(shared_ptr<Ghost> ghost) {
        ghosts.push_back(ghost);
    }
    void visit(const vector<Visitor>& visitors) const {
        cout << "\nVisiting " << name << " Haunted House..." << endl;
        for (const auto& ghost : ghosts) {
            ghost->haunt();
        }
        for (const auto& visitor : visitors) {
            int totalScare = 0;
            for (const auto& ghost : ghosts) {
                totalScare += ghost->getScareLevel();
            }
            visitor.reactToScare(totalScare);
        }
    }
};

int main() {
    srand(time(0));
    
    HauntedHouse house1("Spooky Manor");
    house1.addGhost(make_shared<Poltergeist>("Geor", rand() % 10 + 1));
    house1.addGhost(make_shared<Banshee>("Lind", rand() % 10 + 1));
    house1.addGhost(make_shared<ShadowGhost>("Edward", rand() % 10 + 1));
    
    HauntedHouse house2("Phantom Castle");
    house2.addGhost(make_shared<ShadowPoltergeist>("Mysterious Duo", rand() % 10 + 1));
    house2.addGhost(make_shared<Banshee>("Cassandra", rand() % 10 + 1));
    
    vector<Visitor> visitors = {
        Visitor("Alice", 3),
        Visitor("Bob", 6),
        Visitor("Charlie", 9)
    };
    
    house1.visit(visitors);
    house2.visit(visitors);
    
    return 0;
}

