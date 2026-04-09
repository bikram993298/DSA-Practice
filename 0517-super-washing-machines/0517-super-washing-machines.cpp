class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        // lts assume i want to send from high number to low number  inned one move because you will hsre adjcent then adjcnent to tits adjcanet thus it will reach final desitnation





        int total = 0;
        for (int x : machines) total += x;

        int n = machines.size();
// you know we have to deide in euQLA ways
        if (total % n != 0) return -1;

        int target = total / n;
        int curr = 0;
        int ans = 0;
  // diff menas how much he have to give,if he have 5 mangoes and 2 is eevry person then,,minimum moves all be 3 mangoes,,beacuse he he have to remove 3 to make 2 himself,,and he can nto move mor ethan one mango in on e move,and in poosiited irection we can find flow,,like ow much maximum a person needs,mangoe,,

//   machines = [1, 0, 5]
// total = 6 → target = 2

// diff = [-1, -2, +3]

// ⚡ Step 3: Prefix Flow Array

// Define:

// prefix[i] = diff[0] + diff[1] + ... + diff[i]

// 👉 This represents:

// How much flow must pass through index i

// 📌 For example:
// diff = [-1, -2, +3]

// prefix:
// i=0 → -1  
// i=1 → -3  
// i=2 →  0
// 🧠 Final Answer from Array View

// At each index:

// answer = max(
//     abs(prefix[i]),   // flow passing through
//     diff[i]           // local send
// )
        for (int x : machines) {
            int diff = x - target;
            curr += diff;

            ans = max(ans, max(abs(curr), diff));
        }

        return ans;
  
    }
};