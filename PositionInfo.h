struct PositionInfo {
    struct TotalLiquidPosition{
        int totalPosition{0};
        int liquidPosition{0};
    };
    struct PreLongShortPosition {
        int preLong{0};
        int preShort{0};
    };
    std::atomic<TotalLiquidPosition> longPosition;
    std::atomic<TotalLiquidPosition> shortPosition;
    std::atomic<PreLongShortPosition> preLongShortPosition;
    
    void print() {
        std::cout << longPosition.load().totalPosition << " " << longPosition.load().liquidPosition << " "
                   << shortPosition.load().totalPosition << " " << shortPosition.load().liquidPosition << " "
            << preLongShortPosition.load().preLong << " " << preLongShortPosition.load().preShort << std::endl;
    }
    
    void updateTotalLiquidPosition(std::atomic<TotalLiquidPosition> &totalLiquidPosition, 
                                   const int diffTotal, const int diffLiquid) {
        TotalLiquidPosition expected = totalLiquidPosition.load();
        TotalLiquidPosition desired;
        do {
            desired = expected;
            desired.totalPosition += diffTotal;
            desired.liquidPosition += diffLiquid;
        } while(!totalLiquidPosition.compare_exchange_weak(expected, desired));
    }
    
    void updatePreLongShortPosition(const int diffPreLong, const int diffPreShort) {
        PreLongShortPosition expected = preLongShortPosition.load();
        PreLongShortPosition desired;
        do {
            desired = expected;
            desired.preLong += diffPreLong;
            desired.preShort += diffPreShort;
        } while(!preLongShortPosition.compare_exchange_weak(expected, desired));
    }
};
