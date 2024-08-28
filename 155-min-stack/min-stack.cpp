class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val) {
        int mini = LONG_MAX;
        if (st.empty()) {
            st.push({val, val});
        } else {
            mini = st.top().second;
            mini = min(mini, val);
            st.push({val, mini});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    int top() {
        if (!st.empty()) {
            return st.top().first;
        } else {
            return -1;
        }
    }

    int getMin() {

        if (!st.empty()) {
            return st.top().second;
        } else {
            return -1;
        }
    }
};
// Using 2 stack
// stack<int>st;
// stack<int>mst;
//     MinStack()
//     {

//     }

//     void push(int val)
//     {
//         st.push(val);
//         if(mst.empty()||mst.top() >= val)
//         {
//             mst.push(val);
//         }
//     }

//     void pop()
//     {
//         if(!mst.empty())
//         {
//             if(mst.top()==st.top())
//             {
//                 mst.pop();
//             }
//         }
//         if(!st.empty())
//         {
//             st.pop();
//         }

//     }

//     int top()
//     {
//         return st.top();
//     }

//     int getMin()
//     {
//         return mst.top();
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */