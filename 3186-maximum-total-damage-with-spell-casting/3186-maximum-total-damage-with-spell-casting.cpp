//T.C : O(nlogn)
//S.C : O(n)

class Solution {
public:

    typedef long long ll;

    int n;

    // frequency map
    unordered_map<ll,ll> mp;

    // memoization dp
    vector<ll> t;


    // solve(i) =
    // maximum damage we can get starting from index i
    long long solve(int i, const vector<ll>& nums) {

        // no more elements left
        if(i >= n)
            return 0;

        // already computed
        if(t[i] != -1)
            return t[i];



        // ---------------- SKIP ----------------
        // don't take current value
        ll skip = solve(i + 1, nums);



        // ---------------- TAKE ----------------
        // if we take nums[i],
        // then we cannot take:
        // nums[i]+1 and nums[i]+2
        //
        // so find first valid value >= nums[i] + 3

        int j = lower_bound(begin(nums) + i + 1,
                            end(nums),
                            nums[i] + 3)
                            - begin(nums);

        // total contribution of current value
        ll currDamage = nums[i] * mp[nums[i]];

        ll take = currDamage + solve(j, nums);



        // store and return best answer
        return t[i] = max(skip, take);
    }


    long long maximumTotalDamage(vector<int>& power) {


        // count frequency of each spell value bauce maximun total damage,,if u pick i then pick all opic i
        for(int x : power) {
            mp[x]++;
        }


        // store unique values 
        vector<ll> nums;

        for(auto &p : mp) {
            nums.push_back(p.first);
        }


        // sort unique values beacuse then we have not to consider -2 and -1,,
        // if there is -5,-3 take maximum of all it is the tricl
        sort(begin(nums), end(nums));

        n = nums.size();


        // initialize dp
        t.assign(n, -1);


        return solve(0, nums);
    }
};