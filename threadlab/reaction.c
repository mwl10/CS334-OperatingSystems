// Matthew Lowery


#include "thread.h"
void
make_water();

struct reaction {
           // cond to wait for an oxygen
           struct condition waiting_for_oxygen;
           // lock
           struct lock mutex;
           // cond to wait for a hydrogen
           struct condition waiting_for_hydrogen;

           // # of:
   	       int hydrogen_atoms;
           int oxygen_atoms;
};
// initialize
void reaction_init(struct reaction *reaction)
{
        reaction->hydrogen_atoms = 0;
        reaction->oxygen_atoms = 0;
        cond_init(&reaction->waiting_for_oxygen);
        cond_init(&reaction->waiting_for_hydrogen);
        lock_init(&reaction->mutex);
}
// each hydrogen atom thread calls this function
void reaction_h(struct reaction *reaction)
{
        lock_acquire(&reaction->mutex);
        // increment hydrogen atoms as per the thread that called this function
        reaction->hydrogen_atoms++;
        // awaken an oxygen to let it know that now have another hydrogen
        cond_signal(&reaction->waiting_for_hydrogen, &reaction->mutex);
        // now have this hydrogen wait for the oxygen to work its magic
        cond_wait(&reaction->waiting_for_oxygen, &reaction->mutex);
        lock_release(&reaction->mutex);
}
// each oxygen atom thread calls this function
void reaction_o(struct reaction *reaction)
{
        lock_acquire(&reaction->mutex);
        // increment oxygen atoms as per the thread that called this function
        reaction->oxygen_atoms++;
        // wait until we have enough hydrogen and oxygen to make water
        while((reaction->hydrogen_atoms < 2) || (reaction->oxygen_atoms < 1)) {
            // put the oxygen to sleep until we have enough hydrogen
            cond_wait(&reaction->waiting_for_hydrogen, &reaction->mutex);
        }
        // once we break from the loop, we can make water
        make_water();
        // decement the hydrogen and oxygen atoms accordingly
        reaction->oxygen_atoms--;
        reaction->hydrogen_atoms = reaction->hydrogen_atoms - 2;
        // wake up two hydrogens to return and this oxygen will also return
        // so two h per one o 
        cond_signal(&reaction->waiting_for_oxygen, &reaction->mutex);
        cond_signal(&reaction->waiting_for_oxygen, &reaction->mutex);
        //cond_signal(&reaction->waiting_for_hydrogen, &reaction->mutex);
        lock_release(&reaction->mutex);
}
