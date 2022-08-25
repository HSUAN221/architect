// Copyright (c)
/// Using the builder pattern only makes sense when the product is
/// complex and requires detailed configuration. The two products below are
/// related to each other, although they do not have the same interface.
#ifndef SRC_ARCHITECT_BUILDER_HPP_
#define SRC_ARCHITECT_BUILDER_HPP_
namespace architect {

// ------------------------------- //
//              Trip               //
// ------------------------------- //
/// Describe the "method" of how to set value
class Trip {
 protected:
    double price_{0.0};
    size_t num_max_participants_{0};
 public:
    virtual void setPrice(double) = 0;

    virtual void showPrice() = 0;

    virtual void setMaxParticipants(size_t) = 0;

    virtual void showMaxParticipants() = 0;
};

class JapanTrip : public Trip{
 public:
    JapanTrip() = default;

    ~JapanTrip() = default;

    void setPrice(double price) {
        price_ = price;
    }

    void showPrice() {
        std::cout << "Japan Trip price: " << price_ << std::endl;
    }

    void setMaxParticipants(size_t num_max_participants) {
        num_max_participants_ = num_max_participants;
    }

    void showMaxParticipants() {
        std::cout << "Japan Max Participants: " << num_max_participants_ << std::endl;
    }
};


// ------------------------------- //
//             functions           //
// ------------------------------- //
void showInfo(Trip& trip) {
    trip.showPrice();
    trip.showMaxParticipants();
}


// ------------------------------- //
//            TripBuilder          //
// ------------------------------- //
/// set the "value" by the trip objects
class TripBuilder {
 public:
    virtual void reset() = 0;

    virtual void setPrice(double) = 0;

    virtual void setMaxParticipants(size_t) = 0;

    virtual void showTripInfo() = 0;
};

class JapanTripBuilder : public TripBuilder {
 private:
    std::shared_ptr<JapanTrip> jt_{nullptr};

 public:
    JapanTripBuilder() {
        reset();
    }

    ~JapanTripBuilder() = default;

    void reset() {
        jt_ = std::make_shared<JapanTrip>();
    }

    void setPrice(double price) {
        jt_->setPrice(price);
    }

    void setMaxParticipants(size_t num_max_participants) {
        jt_->setMaxParticipants(num_max_participants);
    }

    void showTripInfo() {
        showInfo(*jt_);
    }

    std::shared_ptr<JapanTrip> getProduct() {
        return jt_;
    }
};

// ------------------------------- //
//           TripDirector          //
// ------------------------------- //

class TripDirector {
 public:
    TripDirector() = default;
    ~TripDirector() = default;

    void constructExpensiveTrip(TripBuilder& builder) {
        builder.reset();
        builder.setPrice(10000000000);
        builder.setMaxParticipants(1);
    }

    void constructCheapTrip(TripBuilder& builder) {
        builder.reset();
        builder.setPrice(10);
        builder.setMaxParticipants(100);
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_BUILDER_HPP_
