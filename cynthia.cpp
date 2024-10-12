#include <iostream>

float puissance(float a, int n) {
    float p = 1;
    for (int i = 0; i < n; i++) {
        p *= a;
    }
    return p;
}

int factorielle(unsigned int n) {  // Renommée de facto à factorielle
    int f = 1;
    for (unsigned int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

double cosinus(double angle) {
    double cos = 0;
    for (int n = 0; n < 10; n++) {
        double terme = (puissance(-1, n) * puissance(angle, 2 * n)) / factorielle(2 * n);
        cos += terme;
    }
    return cos;
}

double sinus(double angle) {
    double sin = 0;
    for (int n = 0; n < 10; n++) {
        double terme = (puissance(-1, n) * puissance(angle, 2 * n + 1)) / factorielle(2 * n + 1);
        sin += terme;
    }
    return sin;
}

double tangente(double angle) {
    double sin = sinus(angle);
    double cos = cosinus(angle);
    if (cos == 0) {
        return 0;  // Retourne NAN si le cosinus est 0
    }
    return sin / cos;
}

int main() {
    unsigned int w;
    std::cout << "Pour calculer le cosinus de l'angle entrer 1\nPour calculer le sinus de l'angle entrer 2\nPour calculer la tangente de l'angle entrer 3\n";
    std::cin >> w;

    float angle;
    std::cout << "Entrer la valeur de l'angle en degres: ";
    std::cin >> angle;

    // Conversion de l'angle en degrés en radians
    double angle_rad = angle * 3.14159265358979323846 / 180.0;

    switch (w) {
        case 1:
            std::cout << "Le cosinus est: " << cosinus(angle_rad) << std::endl;
            break;
        case 2:
            std::cout << "Le sinus est: " << sinus(angle_rad) << std::endl;
            break;
        case 3:
            std::cout << "La tangente est: " << tangente(angle_rad) << std::endl;
            break;
        default:
            std::cout << "Choix invalide" << std::endl;
            break;
    }

    return 0;
}
