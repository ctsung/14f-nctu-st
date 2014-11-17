#include "commission.h"

double calculateCommission(int locks, int stocks, int barrels) {
    double commission = 0.0;
    if (-1 == locks) {
        return 0;
    } else if ((locks < -1) || (locks == 0) || (locks > 70)
            || (stocks < 1) || (stocks > 80)
            || (barrels < 1) || (barrels > 90)) {
        commission = -1;
    } else {
        double sales = 45 * locks + 30 * stocks + 25 * barrels;

        if (sales <= 1000) {
            commission = sales * 0.1;
        } else if (sales <= 1800) {
            commission = 1000 * 0.1;
            commission += (sales - 1000) * 0.15;
        } else {
            commission = 1000 * 0.1;
            commission += 800 * 0.15;
            commission += (sales - 1800) * 0.2;
        }
    }

    return commission;
}
