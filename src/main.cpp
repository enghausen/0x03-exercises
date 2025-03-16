#include <iostream>
#include <limits>
#include <map>
#include <vector>

enum class VehicleType {
    Takst1,  // Personbiler, motorcykler, busser under 3.500 kg
    Takst2,  // Personbiler og motorcykler paa motorveje
    Takst3   // Lastbiler, busser over 3.500 kg, biler med trailer
};

// Struktur for boedetakster
struct FineTable {
    int lower_bound;
    int upper_bound;
    int takst1;
    int takst2;
    int takst3;
};

// Boedetabel for motorveje
const std::vector<FineTable> highway_fines = {
    {101, 119, 1200, 1200, 1800}, {120, 129, 1800, 1800, 1800},
    {130, 139, 2400, 2400, 2400}, {140, 149, 3000, 3000, 3000},
    {150, 159, 3600, 3600, 3600}, {160, 169, 4200, 4200, 4200},
    {170, 179, 5400, 5400, 5400}, {180, 189, 6000, 6000, 6000},
    {190, 199, 7800, 7800, 7800}, {200, std::numeric_limits<int>::max(), 9000, 9000, 9000}
};

// Ekstra boeder for meget hoeje hastigheder
const std::map<int, int> base_extra_fines = {
    {140, 1200}, {150, 1800}, {160, 2400}, {170, 3000}, {180, 3600},
    {190, 4200}, {200, 4800}, {210, 5400}, {220, 6000}
};

// Beregn ekstra boede for meget hoej hastighed
int calculate_extra_fine(int measured_speed) {
    if (measured_speed < 140) return 0;
    
    auto it = base_extra_fines.upper_bound(measured_speed);
    if (it != base_extra_fines.begin()) {
        --it;
    }
    int base_fine = it->second;
    int extra_steps = (measured_speed - it->first) / 10;
    return base_fine + (extra_steps * 600);
}

// Validering af hastighedsgraenser
bool is_valid_speed_limit(int speed_limit) {
    return speed_limit == 100 || speed_limit == 110 || speed_limit == 120 || speed_limit == 130;
}

// Bestem boedetakst
int calculate_fine(int speed_limit, int measured_speed, VehicleType vehicle_type) {
    if (measured_speed <= speed_limit) return 0; // Ingen boede hvis indenfor graensen
    
    for (const auto& fine : highway_fines) {
        if (measured_speed >= fine.lower_bound && measured_speed <= fine.upper_bound) {
            switch (vehicle_type) {
                case VehicleType::Takst1: return fine.takst1;
                case VehicleType::Takst2: return fine.takst2;
                case VehicleType::Takst3: return fine.takst3;
            }
        }
    }
    return 0;
}

// Haandter brugerinput
int get_valid_int(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ugyldigt input, proov igen.\n";
        } else {
            return value;
        }
    }
}

VehicleType get_vehicle_type() {
    int choice;
    while (true) {
        std::cout << "Vaelg koeretoejstype:\n1. Personbil/motorcykel\n2. Personbil paa motorvej\n3. Lastbil/bil med trailer\nIndtast valg (1-3): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= 3) {
            return static_cast<VehicleType>(choice - 1);
        }
        std::cout << "Ugyldigt valg, proov igen.\n";
    }
}

int main() {
    while (true) {
        int speed_limit;
        do {
            speed_limit = get_valid_int("Indtast hastighedsbegraensning (100, 110, 120, 130 km/t): ");
            if (!is_valid_speed_limit(speed_limit)) {
                std::cout << "Ugyldig hastighedsgraense. Proov igen.\n";
            }
        } while (!is_valid_speed_limit(speed_limit));
        
        int measured_speed = get_valid_int("Indtast maalt hastighed: ");
        VehicleType vehicle_type = get_vehicle_type();
        
        int fine = calculate_fine(speed_limit, measured_speed, vehicle_type);
        int extra_fine = calculate_extra_fine(measured_speed);
        
        std::cout << "Beregnet boede: " << fine << " kr.\n";
        if (extra_fine > 0) {
            std::cout << "Ekstra hoej hastighedsboede: " << extra_fine << " kr.\n";
        }
        std::cout << "Total boede: " << fine + extra_fine << " kr.\n\n";
    }
    return 0;
}
