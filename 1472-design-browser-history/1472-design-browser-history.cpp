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

    // string back(int steps) {

    //     while (steps-- && backSt.size() > 1) {
    //         curr = backSt.top();
    //         forwardSt.push(curr);

    //         backSt.pop();
    //     }

    //     return curr;
    // }
    string back(int steps) {
        while (steps-- && backSt.size() > 1) {
            forwardSt.push(backSt.top()); // push current page to forward
            backSt.pop();                 // go back
        }
        // curr = backSt.top(); // ✅ now read the actual new current page
        return backSt.top();
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