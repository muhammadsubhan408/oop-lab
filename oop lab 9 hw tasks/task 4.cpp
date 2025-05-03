#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual float getTuition(string status, int creditHours) = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    float getTuition(string status, int creditHours) {
        if (status == "undergraduate") {
            return 200 * creditHours;
        } else if (status == "graduate") {
            return 300 * creditHours;
        } else if (status == "doctoral") {
            return 400 * creditHours;
        } else {
            cout << "Invalid status!" << endl;
            return 0.0;
        }
    }
};

int main() {
    GraduateStudent s;
    s.setResearchTopic("Artificial Intelligence");

    string status;
    int creditHours;

    cout << "Enter student status (undergraduate/graduate/doctoral): ";
    getline(cin, status);
    cout << "Enter number of credit hours: ";
    cin >> creditHours;
    cin.ignore();

    float tuition = s.getTuition(status, creditHours);

    cout << "Research Topic: " << s.getResearchTopic() << endl;
    cout << "Tuition: " << tuition << endl;

    return 0;
}
