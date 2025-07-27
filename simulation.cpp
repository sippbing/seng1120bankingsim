/**
 * simulation.h
 * Written by: Chi Tai Nguyen (c3444339)
 * Modified: 24/09/2024
 */

#include "simulation.h"

simulation::simulation(int simulation_time, int num_of_tellers, int avg_time_between_arrivals)
{
    sim_time = simulation_time;
    num_tellers = num_of_tellers;
    time_between_arrivals = avg_time_between_arrivals;
    customers_arrived = 0;
    bank = bank_branch(num_of_tellers);
}

simulation::~simulation()
{

}

void simulation::run_simulation()
{
    int cust_id = 0;    // Incrementing ID for new Customers
    for (int time = 0 ; time < sim_time ; time++)
    {
        if (time % 10 == 0) bank.display_queues(); // Display all tellers and respective queues every 10 iterations
        if (has_customer_arrived(time_between_arrivals))
        {
            display_customer_arrived(cust_id, time); // Display a message informing a new Customer's arrival
            customer new_cust(cust_id, time, generate_random_service_time()); // Initialise new Customer
            bank.allocate_customer_to_queue(new_cust); // Automatically allocate new Customer to appropriate Teller queue
            cust_id++;  // Increment Customer ID
        }
        bank.update_tellers(time);  // Update all Tellers in the Bank Branch
    }
    bank.display_queues(); // Display all tellers and respective queues one last time
}