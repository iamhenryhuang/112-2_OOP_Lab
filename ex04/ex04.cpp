#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Computer {
public:
    class Component {
    public:
        string name; // GPU, CPU, etc.
        int quality, price;

        Component(string n, int q, int p) : name(n), quality(q), price(p) {}
    };

    string name; // computer0, computer1, etc.
    vector<Component> components;
    double ratio = 0;

    Computer(string n) : name(n) {}

    void addComponent(const string& name, int quality, int price) {
        components.emplace_back(name, quality, price);
    }

    void calculateRatio() {
        int sumQuality = 0, sumPrice = 0;
        int gpuQuality = 0, monitorQuality = 0;
        bool hasGPU = false, hasMonitor = false;

        for (const auto& component : components) {
            if (component.name == "GPU") {
                hasGPU = true;
                gpuQuality = component.quality;
            } else if (component.name == "Monitor") {
                hasMonitor = true;
                monitorQuality = component.quality;
            }
        }

        int minQuality = 0;
        if (hasGPU && hasMonitor) {
            minQuality = min(gpuQuality, monitorQuality);
        }

        for (const auto& component : components) {
            if (component.name == "GPU" || component.name == "Monitor") {
                if (hasGPU && hasMonitor) {
                    sumQuality += minQuality;
                }
            } else {
                sumQuality += component.quality;
            }
            sumPrice += component.price;
        }

        if (sumPrice != 0) {
            ratio = static_cast<double>(sumQuality) / sumPrice;
        } else {
            ratio = 0;
        }
    }

    void sortComponents() {
        sort(components.begin(), components.end(), [](const Component& a, const Component& b) {
            if (a.quality == b.quality) {
                return a.name < b.name;
            } else {
                return a.quality > b.quality;
            }
        });
    }
};

void main_block() {
    int total;
    cin >> total;
    vector<Computer> computers;

    for (int i = 0; i < total; i++) {
        string computerName;
        cin >> computerName;
        Computer computer(computerName);

        for (int j = 0; j < 5; j++) {
            string componentName;
            int quality, price;
            cin >> componentName >> quality >> price;
            computer.addComponent(componentName, quality, price);
        }

        computer.calculateRatio();
        computer.sortComponents();
        computers.push_back(computer);
    }

    sort(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        if (a.ratio == b.ratio) {
            return a.name < b.name;
        } else {
            return a.ratio > b.ratio;
        }
    });

    // for testing Ratio
    /*for (const auto& computer : computers) {
        cout << computer.name << " Ratio: " << computer.ratio << endl;
    }*/

    for (const auto& computer : computers) {
        cout << computer.name << endl;
        for (const auto& component : computer.components) {
            cout << component.name << endl;
        }
    }
}

// for testing this code
/*
int main() {
    main_block();
    return 0;
}
*/
