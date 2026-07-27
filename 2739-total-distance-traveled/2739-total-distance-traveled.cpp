class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int gal = 0;

        while (mainTank-- > 0) {
            gal++;
            if (gal % 5 == 0 && additionalTank > 0) {
                additionalTank--;
                gal++;
            }
        }

        return gal * 10;
    }
};