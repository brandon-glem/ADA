#include <iostream>

using namespace std;

float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Division por cero" << endl;
        return 0;
    }
}

typedef float (*lpfnOperation)(float, float);

lpfnOperation vpf[4] = { &Addition, &Subtraction, &Multiplication, &Division };

int main() {
    float a, b, c;
    int opt;

    cout << "Ingresa los operandos a y b: ";
    cin >> a >> b;

    cout << "Ingresa la operacion (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
    cin >> opt;


    if (opt >= 0 && opt < 4) {
        c = (*vpf[opt])(a, b);
        cout << "El resultado es: " << c << endl;
    }
    else {
        cout << "Operacion invalida" << endl;
    }

    return 0;
}
