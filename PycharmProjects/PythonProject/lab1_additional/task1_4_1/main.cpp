#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

class VectorN {
private:
    vector<double> components;

public:
    VectorN() {}

    VectorN(const vector<double>& comps) : components(comps) {}

    VectorN(const VectorN& other) : components(other.components) {}

    int dimension() const {
        return components.size();
    }

    double length() const {
        double sum = 0;
        for (double x : components) {
            sum += x * x;
        }
        return sqrt(sum);
    }

    double average() const {
        if (components.empty()) return 0;
        double sum = 0;
        for (double x : components) {
            sum += x;
        }
        return sum / components.size();
    }

    double maxComponent() const {
        double mx = components[0];
        for (double x : components) {
            if (x > mx) mx = x;
        }
        return mx;
    }

    double minComponent() const {
        double mn = components[0];
        for (double x : components) {
            if (x < mn) mn = x;
        }
        return mn;
    }

    string toString() const {
        ostringstream out;
        out << "(";
        for (size_t i = 0; i < components.size(); i++) {
            out << components[i];
            if (i + 1 < components.size()) out << ", ";
        }
        out << ")";
        return out.str();
    }
};

VectorN createVectorFromLine(const string& line) {
    stringstream ss(line);
    vector<double> comps;
    double x;

    while (ss >> x) {
        comps.push_back(x);
    }

    return VectorN(comps);
}

vector<VectorN> readVectorsFromFile(const string& filename) {
    ifstream fin(filename);
    vector<VectorN> vectors;
    string line;

    while (getline(fin, line)) {
        if (line.empty()) continue;
        vectors.push_back(createVectorFromLine(line));
    }

    return vectors;
}

int main() {
    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    vector<VectorN> vectors = readVectorsFromFile(filename);

    if (vectors.empty()) {
        cout << "No vectors found." << endl;
        return 0;
    }

    cout << fixed << setprecision(3);

    cout << "All vectors:" << endl;
    for (const auto& v : vectors) {
        cout << v.toString()
             << ", dimension = " << v.dimension()
             << ", length = " << v.length()
             << ", average = " << v.average()
             << ", max = " << v.maxComponent()
             << ", min = " << v.minComponent() << endl;
    }

    int idxMaxDimension = 0;
    for (size_t i = 1; i < vectors.size(); i++) {
        if (vectors[i].dimension() > vectors[idxMaxDimension].dimension()) {
            idxMaxDimension = i;
        } else if (vectors[i].dimension() == vectors[idxMaxDimension].dimension()) {
            if (vectors[i].length() < vectors[idxMaxDimension].length()) {
                idxMaxDimension = i;
            }
        }
    }

    int idxMaxLength = 0;
    for (size_t i = 1; i < vectors.size(); i++) {
        if (vectors[i].length() > vectors[idxMaxLength].length()) {
            idxMaxLength = i;
        } else if (vectors[i].length() == vectors[idxMaxLength].length()) {
            if (vectors[i].dimension() < vectors[idxMaxLength].dimension()) {
                idxMaxLength = i;
            }
        }
    }

    double averageLength = 0;
    for (const auto& v : vectors) {
        averageLength += v.length();
    }
    averageLength /= vectors.size();

    int countGreaterThanAverage = 0;
    for (const auto& v : vectors) {
        if (v.length() > averageLength) {
            countGreaterThanAverage++;
        }
    }

    int idxMaxOfMax = 0;
    for (size_t i = 1; i < vectors.size(); i++) {
        if (vectors[i].maxComponent() > vectors[idxMaxOfMax].maxComponent()) {
            idxMaxOfMax = i;
        } else if (vectors[i].maxComponent() == vectors[idxMaxOfMax].maxComponent()) {
            if (vectors[i].minComponent() < vectors[idxMaxOfMax].minComponent()) {
                idxMaxOfMax = i;
            }
        }
    }

    int idxMinOfMin = 0;
    for (size_t i = 1; i < vectors.size(); i++) {
        if (vectors[i].minComponent() < vectors[idxMinOfMin].minComponent()) {
            idxMinOfMin = i;
        } else if (vectors[i].minComponent() == vectors[idxMinOfMin].minComponent()) {
            if (vectors[i].maxComponent() > vectors[idxMinOfMin].maxComponent()) {
                idxMinOfMin = i;
            }
        }
    }

    cout << endl;
    cout << "Vector with maximum dimension: " << vectors[idxMaxDimension].toString()
         << ", dimension = " << vectors[idxMaxDimension].dimension()
         << ", length = " << vectors[idxMaxDimension].length() << endl;

    cout << "Vector with maximum length: " << vectors[idxMaxLength].toString()
         << ", dimension = " << vectors[idxMaxLength].dimension()
         << ", length = " << vectors[idxMaxLength].length() << endl;

    cout << "Average length of vectors: " << averageLength << endl;

    cout << "Count of vectors with length greater than average: "
         << countGreaterThanAverage << endl;

    cout << "Vector with maximum max component: " << vectors[idxMaxOfMax].toString()
         << ", max component = " << vectors[idxMaxOfMax].maxComponent()
         << ", min component = " << vectors[idxMaxOfMax].minComponent() << endl;

    cout << "Vector with minimum min component: " << vectors[idxMinOfMin].toString()
         << ", min component = " << vectors[idxMinOfMin].minComponent()
         << ", max component = " << vectors[idxMinOfMin].maxComponent() << endl;

    return 0;
}