// class AuctionSystem {
// public:
//     // map[user,item]=bid;
//         //pq[item]=prirty que consisting all bids and user id
//         map<pair<int,int>,int> mp;
//         // map<int,priority_queue<int,pair<int,int>>> pq;
//         map<int, priority_queue<pair<int,int>>> pq;
//     AuctionSystem() {
    
        
//     }
    
//     void addBid(int userId, int itemId, int bidAmount) {
//         mp[{userId,itemId}]=bidAmount;
//         pq[itemId].push({bidAmount,userId});
        
//     }
    
//     void updateBid(int userId, int itemId, int newAmount) {
//          mp[{userId,itemId}]=newAmount;
//          // but you cannot acces ques in o(1) update so we will use llazy deletion
//            pq[itemId].push({newAmount,userId});
        
//     }
    
//     void removeBid(int userId, int itemId) {
//          mp.erase({userId,itemId});
        
//     }
    
//     int getHighestBidder(int itemId) {
//         //  if(!pq.count(itemId)) return -1;
//         // main concept when you updated new vlau ein bid then you cannot chnage form prioryt ques,,here comes lzy deleltion so in lazy deleltion we oush all in ques bu t,,when return we return top and check it is same value exist in map,,as remove and update can happen,,for removal check count map,,for update check bid value is same as map,and priory que or not ,other wise pop them


         
//         while(!pq[itemId].empty()){


//             auto top=pq[itemId].top();
//         int bid=top.first;
//         int user=top.second;
//         if(mp.count({user,itemId}) &&  mp[{user,itemId}]==bid){

//              return user;

//         }
//         pq[itemId].pop();

//         }
        



//       //o(logn) amortized becuase every lazy is popped once
       
//         return -1;
//     }
// };

// /**
//  * Your AuctionSystem object will be instantiated and called as such:
//  * AuctionSystem* obj = new AuctionSystem();
//  * obj->addBid(userId,itemId,bidAmount);
//  * obj->updateBid(userId,itemId,newAmount);
//  * obj->removeBid(userId,itemId);
//  * int param_4 = obj->getHighestBidder(itemId);
//  */


class AuctionSystem {
public:

    map<pair<int,int>, int> mp;

    map<int, set<pair<int,int>>> bids;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {

        if(mp.count({userId,itemId})) {
            int old = mp[{userId,itemId}];
            bids[itemId].erase({old,userId});
        }

        mp[{userId,itemId}] = bidAmount;
        bids[itemId].insert({bidAmount,userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {

        int old = mp[{userId,itemId}];

        bids[itemId].erase({old,userId});

        mp[{userId,itemId}] = newAmount;

        bids[itemId].insert({newAmount,userId});
    }

    void removeBid(int userId, int itemId) {

        int old = mp[{userId,itemId}];

        bids[itemId].erase({old,userId});

        mp.erase({userId,itemId});
    }

    int getHighestBidder(int itemId) {

        if(!bids.count(itemId) || bids[itemId].empty())
            return -1;

        return bids[itemId].rbegin()->second;
    }
};
