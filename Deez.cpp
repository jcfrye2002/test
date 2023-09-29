TEST(BackEndTests, Test3A){
    Airport AirA("AAA");
    Airport AirB("BBB");
    Airport AirC("CCC");

    Flight NFAC(10,0,AirA,AirC);

    vector<Flight*> allFlights = {&NFAC};

    vector<Booking> bookings = flightBookingQuery(allFlights, AirA, AirC);

    int temp = bookings.at(0).getFlights().at(0)->getCapacity();
    temp--;

    purchaseBooking(bookings.at(0));

    ASSERT_EQ(bookings.at(0).getFlights().at(0)->getCapacity(),temp);
}

TEST(BackEndTests, Test3B){
    Airport AirA("AAA");
    Airport AirB("BBB");
    Airport AirC("CCC");

    Flight NFAB(10,0,AirA,AirB);
    Flight NFAC(11,2,AirB,AirC);

    vector<Flight*> allFlights = {&NFAC, &NFAB};

    vector<Booking> bookings = flightBookingQuery(allFlights, AirA, AirC);

    int flight1 = bookings.at(0).getFlights().at(0)->getCapacity();
    int flight2 = bookings.at(0).getFlights().at(1)->getCapacity();

    purchaseBooking(bookings.at(0));

    bool temp = false;

    if(bookings.at(0).getFlights().at(0)->getCapacity() == (flight1 - 1) && bookings.at(0).getFlights().at(0)->getCapacity() == (flight2 - 1)){
        temp = true;
    }

    ASSERT_EQ(true, temp);
}
