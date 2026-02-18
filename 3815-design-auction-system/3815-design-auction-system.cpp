class AuctionSystem {
public:
    // map[user,item]=bid;
        //pq[item]=prirty que consisting all bids and user id
        map<pair<int,int>,int> mp;
        // map<int,priority_queue<int,pair<int,int>>> pq;
        map<int, priority_queue<pair<int,int>>> pq;
    AuctionSystem() {
    
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        mp[{userId,itemId}]=bidAmount;
        pq[itemId].push({bidAmount,userId});
        
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
         mp[{userId,itemId}]=newAmount;
         // but you cannot acces ques in o(1) update so we will use llazy deletion
           pq[itemId].push({newAmount,userId});
        
    }
    
    void removeBid(int userId, int itemId) {
         mp.erase({userId,itemId});
        
    }
    
    int getHighestBidder(int itemId) {
        //  if(!pq.count(itemId)) return -1;


         
        while(!pq[itemId].empty()){


            auto top=pq[itemId].top();
        int bid=top.first;
        int user=top.second;
        if(mp.count({user,itemId}) &&  mp[{user,itemId}]==bid){

             return user;

        }
        pq[itemId].pop();

        }
        



      
       
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */