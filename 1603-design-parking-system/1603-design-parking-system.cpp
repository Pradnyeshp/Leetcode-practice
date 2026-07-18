class ParkingSystem {
public:
    unordered_map<int, int> map;

    ParkingSystem(int big, int medium, int small) {
        map[1] = big;
        map[2] = medium;
        map[3] = small;
    }

    bool addCar(int carType) {
        if (map[carType] > 0) {
            map[carType]--;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */