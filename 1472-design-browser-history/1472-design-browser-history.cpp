class BrowserHistory {
public:
    stack<string> backSt;
    stack<string> forwardSt;

    string curr;

    BrowserHistory(string homepage) {
        curr = homepage;
        backSt.push(curr);
    }

    void visit(string url) {

        // backSt.push(curr);

        curr = url;
        backSt.push(curr);

        // clear forward history
        while (!forwardSt.empty()) {
            forwardSt.pop();
        }
    }

   string back(int steps) {
    while (steps-- && backSt.size() > 0) {
        forwardSt.push(backSt.top());
        backSt.pop();
    }

    // Overshot — restore oldest page as the floor

    // if size is 1 and back 2 that meansyou should return 1,and the backst,it should keep last atleast one lemnt
    //if backst,size()=1 and beack 2 then what will happwn it will give 1 page not chnage
    if (backSt.empty()) {
        backSt.push(forwardSt.top());  // ✅ put homepage back
        forwardSt.pop();
    }

    curr = backSt.top();
    return curr;
}

    string forward(int steps) {

        while (steps-- && forwardSt.size() > 0) {

            curr = forwardSt.top();

            backSt.push(curr);

            forwardSt.pop();
            // if (!forwardSt.empty()) {
            //     curr = forwardSt.top();
            // }
        }

        return backSt.top();
    }
};