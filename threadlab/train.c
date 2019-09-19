
// Matthew Lowery

#include "thread.h"

struct station {
        // # of waiting passengers
        int pass_waiting;
        // # of seats occupied
        int taken_seats;
        // # of seats open
        int seats_left;
        // lock
        struct lock mutex;
        // cond where there's an open seat
        struct condition wait_for_open_seat;
        // cond where train is able to leave
        struct condition train_leave;
};

    // initialize everything
void
station_init(struct station *station)
{
        station->pass_waiting = 0;
        station->seats_left = 0;
        station->taken_seats = 0;
        cond_init(&station->train_leave);
        cond_init(&station->wait_for_open_seat);
        lock_init(&station->mutex);

}

    // function must not return until train is satisfactorily loaded
    // (all passengers are in their seats, and either the train is full or all waiting
            // passengers have boarded)

void
station_load_train(struct station *station, int count)
{
        // count initially represents the amount of seats left
        station->seats_left = count;
        lock_acquire(&station->mutex);
        // the amount of seats taken is initially zero
        station->taken_seats = 0;
        // awaken passengers that are waiting for a seat
        cond_broadcast(&station->wait_for_open_seat, &station->mutex);
        // train waits until either there are no waiting passengers
        // or all the seats are taken (the loop will break)
        while((station->pass_waiting > 0) && (station->taken_seats < count)) {
                cond_wait(&station->train_leave, &station->mutex);
        }
        station->seats_left = 0;
        lock_release(&station->mutex);
        }

// when a passenger thread arrives in a station it invokes this function
// function won't return until a train is in the station &
// there are enough free seats on the train for the passenger to board
void
station_wait_for_train(struct station *station)
{
        lock_acquire(&station->mutex);
        // increment passengers waiting per the passenger thread that calls this function
        station->pass_waiting++;
        // wait until there is a seat available
        while(station->seats_left == 0) {
                cond_wait(&station->wait_for_open_seat, &station->mutex);
        }
        // decrement seats left
        station->seats_left--;
        ///station->pass--;
        lock_release(&station->mutex);
}

    // when seated, the passenger thread will call this to let the train know that they are on board
void
    station_on_board(struct station *station)
{
        lock_acquire(&station->mutex);
        // decrement passengers waiting
        station->pass_waiting--;
        // increment the amount of seats taken
        station->taken_seats++;
        // train should leave once there are no waiting passengers or there are no seats left
        //while()

        if((station->pass_waiting == 0 )|| (station->seats_left==0)) {
                cond_signal(&station->train_leave, &station->mutex);
        }
        lock_release(&station->mutex);
}
