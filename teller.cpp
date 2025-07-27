/**
 * teller.cpp
 * Written by: Chi Tai Nguyen (c3444339)
 * Modified: 24/09/2024
 */

#include "teller.h"

teller::teller(int tell_id)
{
    teller_id = tell_id;
    is_free = true;
    remaining_service_time = 0;
    current_customer_id = -1;
    customers = queue<customer>();
}

teller::~teller()
{

}

bool teller::is_teller_free() const
{
    return is_free;
}

int teller::get_remaining_service_time() const
{
    return remaining_service_time;
}

void teller::update(int time)
{
    if (!is_free) remaining_service_time--;
    
    if (remaining_service_time <= 0 && current_customer_id != -1)
    {
        is_free = true; // Teller is now free
        display_customer_done(current_customer_id, time); // Service for current customer is now complete
        current_customer_id = -1; // Teller is now not serving any Customer
    }

    if (is_free)
    {
        if (!customers.empty())
        {
            const customer& next_customer = customers.front(); // Get information of the next customer in queue
            customers.dequeue(); // Remove the selected customer from queue

            is_free = false;    // The teller is now busy serving the next customer
            current_customer_id = next_customer.get_customer_id(); // Get next customer's ID 
            remaining_service_time = next_customer.get_service_time(); // and service time
            
            display_customer_served(next_customer, time);
        }
    }

    // Update waiting time of all customers in queue
    int looptime = customers.size();
    for (int i = 0 ; i < looptime ; i++) // In this loop, customers are modified and added to the back of the queue with the original removed
    {
        customer current = customers.front();   // Mutable copy of the next Customer in queue
        current.increment_waiting_time();       
        customers.dequeue();                    // Remove the original, unmutated Customer from the queue
        customers.enqueue(current);             // Add the mutated copy to the back of the queue
    }
}

int teller::get_queue_length() const
{
    return customers.size();
}

void teller::add_to_queue(const customer& cust)
{
    customers.enqueue(cust);
    }

int teller::get_teller_id() const
{
    return teller_id;
}

const queue<customer>& teller::get_queue() const
{
    return customers;
}