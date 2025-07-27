/**
 * customer.cpp
 * 
 * Written by: Chi Tai Nguyen (c3444339)
 * Modified: 23 September 2024
 * 
 * This class represents a bank customer, with an integer ID, time of arrival, time elapsed in waiting and time left to serve
 */
#include "customer.h"

customer::customer(int cust_id, int arrive_time, int serve_time)
{
    customer_id = cust_id;
    arrival_time = arrive_time;
    service_time = serve_time;
    waiting_time = 0;
}

customer::~customer()
{

}

int customer::get_waiting_time() const
{
    return waiting_time;
}

void customer::increment_waiting_time()
{
    waiting_time++;
}

int customer::get_arrival_time() const
{
    return arrival_time;
}

int customer::get_service_time() const
{
    return service_time;
}

int customer::get_customer_id() const
{
    return customer_id;
}

std::ostream& operator << (std::ostream& out, const customer& cust)
{
    out << "Customer" << "(" << cust.get_customer_id() << ")";
    return out;
}