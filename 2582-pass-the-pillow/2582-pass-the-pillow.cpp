class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the full cycles (going to the end and back to the start)
        int full_cycles = time / (n - 1);
        
        // Calculate the remaining passes after the full cycles
        int remaining_passes = time % (n - 1);
        
        if (full_cycles % 2 == 0) {
            // If the number of full cycles is even, the direction is forward
            return 1 + remaining_passes;
        } else {
            // If the number of full cycles is odd, the direction is backward
            return n - remaining_passes;
        }
    }
};
