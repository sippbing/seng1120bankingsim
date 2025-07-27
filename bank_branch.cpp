/**
 * bank_branch.cpp
 * Written by: Chi Tai Nguyen (c3444339)
 * Modified: 24/09/2024
 */
#include "bank_branch.h"

bank_branch::bank_branch(int num_tells)
{
    if (num_tells < 1) throw std::out_of_range("Bank branch needs to have at least 1 Teller");

    tellers = std::vector<teller>();

    for (int i = 0 ; i < num_tells ; i++)
    {
        teller new_teller(i);
        tellers.push_back(new_teller);
    }
}

bank_branch::~bank_branch()
{

}

void bank_branch::allocate_customer_to_queue(const customer& cust)
{
    // Finding the teller with the shortest queue
    std::vector<teller>::iterator shortest = tellers.begin();   // Iterator to the teller with the shortest queue (by default the first Teller)
    int min = shortest->get_queue_length();                     // Length of shortest teller queue (by default the first Teller's queue)

    for (std::vector<teller>::iterator it = tellers.begin();   
         it != tellers.end(); 
         it++) // Loop through all tellers
    {
        if (it->get_queue_length() < min)
        {
            min = it->get_queue_length();   // Update shortest discovered queue length
            shortest = it;                  // Point to current teller
        }
    }

    shortest->add_to_queue(cust); // Allocate customer to teller with shortest queue
    display_customer_allocated(cust.get_customer_id(), shortest->get_teller_id()); // Allocation successful, display a message
}

void bank_branch::update_tellers(int time)
{
    std::vector<teller>* copy = new std::vector<teller>(); // Teller Vector to store modified tellers
    for (std::vector<teller>::const_iterator it = tellers.begin();   
         it != tellers.end(); 
         it++) // Loop through all tellers
    {
        teller current = *it;       // Copy of current Teller by dereferencing iterator
        current.update(time);       // Update the current teller
        copy->push_back(current);   // Add the update teller to copy
    }   

    tellers.clear();    // Clear the original Teller vector
    tellers = *copy;    // Replace the original vector with the modified version

    delete copy;        // Release associated memory from pointer
    copy = nullptr;     // Nullify pointer
}

void bank_branch::display_queues() const
{
    for (std::vector<teller>::const_iterator it = tellers.begin();   
         it != tellers.end(); 
         it++) // Loop through all tellers
    {
        const teller& current = *it; // Teller object obtained after dereferencing iterator
        std::cout << "Teller " << current.get_teller_id() << ": " << current.get_queue() << std::endl;
    }

}