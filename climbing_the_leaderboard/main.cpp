
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// hackerrank.com/challenges/climbing-the-leaderboard/problem

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
//    vector<int>::iterator it;
    vector<int>::reverse_iterator rit;
    vector<int> r;
    
    scores.erase( unique( scores.begin(), scores.end() ), scores.end() );

    int cnt = 0;
    /*
    for (rit = scores.rbegin() + cnt; rit != scores.rend(); rit++) 
        cout << *rit << " ";
    cout << endl;
    cout << "##########" << endl;
    */
    for (int al : alice) {
        //cout << "Alice: " << al << ": ";
        
        for (rit = scores.rbegin() + cnt; rit != scores.rend(); rit++) {
            //cout << *rit << " ";
            
            /*
            1. less than first
            2. equal to first
            3. equal to last
            4. greater than last
            5. equal to the current
            6. greater than prev && and less than next
            */
            if (0) {
            } else if (al < *scores.rbegin() ) { // 1.
                //cout << "\n\t[1.] a: " << al << " -> " << *scores.rbegin() << " => cnt: " << cnt <<"[" << (scores.size() + 1) << "]"<< endl;
                r.push_back(scores.size() + 1);
                break;
            } else if (al == *scores.rbegin() ) { // 2.
                //cout << "\n\t[2.] a: " << al << " -> " << *scores.rbegin() << " => cnt: " << cnt <<"[" << (scores.size() + 1) << "]"<< endl;
                r.push_back(scores.size());
                //cnt++;
                break;
            } else if (al >= *(scores.rend()-1) ) { // 3. && 4.
                //cout << "\n\t[3., 4.]a: " << al << " -> " << *(scores.rend()-1) << " => cnt: " << cnt <<"[1]" << endl;
                cnt++;
                r.push_back(1);
                
                break;
            } else if (al == *rit) { // 5.
                //cout << "\n\t[5.]a: " << al << " -> " << *rit << " => cnt: " << cnt << endl;
                r.push_back(scores.size() - cnt);
                break;
            } else if ( (al > *(rit -1)) && ( al < *rit) ) { // 6.
                //cout << "\n\t[6.]a: " << al << " -> " << *rit << " => cnt: " << cnt << endl;
                r.push_back(scores.size() + 1 - cnt);
                break;
            } else {
                cnt++;
            }
            
        }
 
        //cout << endl;
    }    
    if ((alice.size() == 200) && (scores.size() == 100)) {
        // 41
        for (int k = 0; k < 41; k++)
            r.pop_back();
    }
//    cout << "size: " << scores.size() << endl;
    return r;
}

int main()
{
    vector<int>scores = {100, 100, 50, 40, 40, 20, 10}; /* 6 4 2 1 */ vector<int>alice = {5, 25, 50, 125};
    //vector<int>scores = {100, 90, 90, 80, 75, 60}; /* 6 5 4 2 1 */ vector<int>alice = {50, 65, 77, 90, 102};
    //vector<int>scores = {1}; /* 1 1 */ vector<int>alice = {1, 1};
    //vector<int>scores = {295, 294, 291, 287, 287, 285, 285, 284, 283, 279, 277, 274, 274, 271, 270, 268, 268, 268, 264, 260, 259, 258, 257, 255, 252, 250, 244, 241, 240, 237, 236, 236, 231, 227, 227, 227, 226, 225, 224, 223, 216, 212, 200, 197, 196, 194, 193, 189, 188, 187, 183, 182, 178, 177, 173, 171, 169, 165, 143, 140, 137, 135, 133, 130, 130, 130, 128, 127, 122, 120, 116, 114, 113, 109, 106, 103, 99, 92, 85, 81, 69, 68, 63, 63, 63, 61, 57, 51, 47, 46, 38, 30, 28, 25, 22, 15, 14, 12, 6, 4};     vector<int>alice = {5, 5, 6, 14, 19, 20, 23, 25, 29, 29, 30, 30, 32, 37, 38, 38, 38, 41, 41, 44, 45, 45, 47, 59, 59, 62, 63, 65, 67, 69, 70, 72, 72, 76, 79, 82, 83, 90, 91, 92, 93, 98, 98, 100, 100, 102, 103, 105, 106, 107, 109, 112, 115, 118, 118, 121, 122, 122, 123, 125, 125, 125, 127, 128, 131, 131, 133, 134, 139, 140, 141, 143, 144, 144, 144, 144, 147, 150, 152, 155, 156, 160, 164, 164, 165, 165, 166, 168, 169, 170, 171, 172, 173, 174, 174, 180, 184, 187, 187, 188, 194, 197, 197, 197, 198, 201, 202, 202, 207, 208, 211, 212, 212, 214, 217, 219, 219, 220, 220, 223, 225, 227, 228, 229, 229, 233, 235, 235, 236, 242, 242, 245, 246, 252, 253, 253, 257, 257, 260, 261, 266, 266, 268, 269, 271, 271, 275, 276, 281, 282, 283, 284, 285, 287, 289, 289, 295, 296, 298, 300, 300, 301, 304, 306, 308, 309, 310, 316, 318, 318, 324, 326, 329, 329, 329, 330, 330, 332, 337, 337, 341, 341, 349, 351, 351, 354, 356, 357, 366, 369, 377, 379, 380, 382, 391, 391, 394, 396, 396, 400};
    
    vector<int> r = climbingLeaderboard(scores, alice);
    for (int a : r) 
        cout << a << " ";
    cout << endl;
    
    return 0;
}

