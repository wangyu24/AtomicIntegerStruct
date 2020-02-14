int main()
{
    PositionInfo pi;
    std::cout << pi.longPosition.is_lock_free() << " " << pi.shortPosition.is_lock_free()
        << " " << pi.preLongShortPosition.is_lock_free() << std::endl;
    pi.print();
    pi.updateTotalLiquidPosition(pi.longPosition, 10, -3);
    pi.print();
    pi.updateTotalLiquidPosition(pi.longPosition, 0, -3);
    pi.print();
    pi.updateTotalLiquidPosition(pi.shortPosition, 1, -2);
    pi.print();
    pi.updateTotalLiquidPosition(pi.shortPosition, 1, -2);
    pi.print();
    pi.updatePreLongShortPosition(1,2);
    pi.print();
    pi.updatePreLongShortPosition(-1,-2);
    pi.print();
}
