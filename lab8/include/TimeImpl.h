#include "Time.h"

#include <chrono>
#include <thread>

class TimeImpl : public Time {
public:
    void create(bool endless) override ;
    long long now() const override;

    void flow() override;

private:
    long long year;
    bool endless;
};