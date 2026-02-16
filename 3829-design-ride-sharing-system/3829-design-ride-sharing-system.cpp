class RideSharingSystem {
public:
 queue<int> rider,driver; 
 set<int> cancel;
    RideSharingSystem() {
       
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        if( cancel.count(riderId)){
            cancel.erase(riderId);
        }
        
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty()) return {-1,-1};

        int rtop=rider.front();
        while(cancel.count(rtop)){
            rider.pop();
             if(rider.empty()) return {-1,-1};
            rtop=rider.front();
        }
       
        rider.pop();
        int dtop=driver.front();
        driver.pop();

        return {dtop,rtop};


        
    }
    
    void cancelRider(int riderId) {



        cancel.insert(riderId);

        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */