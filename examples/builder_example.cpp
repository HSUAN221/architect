// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>

int main(int argc, char **argv) {
// ------------------------------- //
//           TripDirector          //
// ------------------------------- //
    architect::JapanTripBuilder jt_builder1;
    architect::TripDirector td;
    td.constructExpensiveTrip(jt_builder1);
    jt_builder1.showTripInfo();
    /// output product
    auto jt_ptr1 = jt_builder1.getProduct();

// ------------------------------- //
//            TripBuilder          //
// ------------------------------- //
    architect::JapanTripBuilder jt_builder;
    jt_builder.setPrice(100);
    jt_builder.setMaxParticipants(15);
    jt_builder.showTripInfo();
    /// output product
    auto jt_ptr = jt_builder.getProduct();

    return 0;
}
