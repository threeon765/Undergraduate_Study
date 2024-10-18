#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <fstream>
#define PI 3.14159265358979323846
using namespace std;

class Signal {
private:
    double amplitude;  
    double frequency;  
    double phase;      
public:
    Signal(double amp, double freq, double ph) : amplitude(amp), frequency(freq), phase(ph) {}
    double calculatesin(double t) const {
        double singraph = amplitude * sin(2 * PI * frequency * t + phase);
        return singraph;
    }
    double calculatecos(double t) const {
        double cosgraph = amplitude * cos(2 * PI * frequency * t + phase);
        return cosgraph;
    }
    Signal operator+(Signal& x) {
        if (this->frequency == x.frequency) {
            double amp1 = this->amplitude;
            double amp2 = x.amplitude;
            double ph1 = this->phase;
            double ph2 = x.phase;
            double NewAmp = sqrt(pow((amp1 * cos(ph1) + amp2 * cos(ph2)), 2) + pow((amp1 * sin(ph1) + amp2 * sin(ph2)), 2));
            double NewPh = atan2((amp1 * sin(ph1) + amp2 * sin(ph2)), (amp1 * cos(ph1) + amp2 * cos(ph2)));
            Signal Add(NewAmp, this->frequency, NewPh);
            return Add;
        }
    }
};

int main() {
    Signal x1(5, 15, 0.5 * PI);
    Signal x2(5, 15, - 0.25 * PI);
    Signal x3(5, 15, 0.4 * PI);
    Signal x4(5, 15, -0.9 * PI);
    Signal x5 = x1 + x2 + x3 + x4;

    vector<double> time_values;
    vector<double> x1_values, x2_values, x3_values, x4_values, x5_values;
    
    
    double T = 1.0 / 15.0;  // 주기
    double time_end = 3 * T; // 3주기
    double time_step = 0.1; // 시간 간격

    
    for (double t = 0; t <= time_end; t += time_step) {
        time_values.push_back(t);
        x1_values.push_back(x1.calculatecos(t));
        x2_values.push_back(x2.calculatecos(t));
        x3_values.push_back(x3.calculatecos(t));
        x4_values.push_back(x4.calculatecos(t));
        x5_values.push_back(x5.calculatecos(t));
    }

    for (size_t i = 0; i < time_values.size(); ++i) {
        cout << "t: " << time_values[i] << "\t x1: " << x1_values[i] << "\t x2: " << x2_values[i] 
            << "\t x3: " << x3_values[i] << "\t x4: " << x4_values[i] << "\t x5: " << x5_values[i] << endl;
    }


    ofstream outfile("signals.txt");
    for (size_t i = 0; i < time_values.size(); ++i) {
        outfile << time_values[i] << "\t"
            << x1_values[i] << "\t" << x2_values[i] << "\t"
            << x3_values[i] << "\t" << x4_values[i] << "\t"
            << x1_values[i] << endl;
            
    }
    outfile.close();

    cout << "\n signals.txt 완료" << endl;

    return 0;
}
