// Using 2 queues
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {}

    void push(int x) {
        que2.push(x);

        while (!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }

        swap(que1, que2);
    }

    int pop() {
        int result = que1.front();
        que1.pop();

        return result;
    }

    int top() { return que1.front(); }

    bool empty() { return que1.empty(); }
};

// Follow-up : Using 1 queue
// class MyStack {
// public:
//     queue<int> que;

//     MyStack() {

//     }

//     void push(int x) {
//         que.push(x);
//         int n = que.size();

//         for(int i=0; i<n-1; i++){
//             que.push(que.front());
//             que.pop();
//         }
//     }

//     int pop() {
//         int result = que.front();
//         que.pop();

//         return result;
//     }

//     int top() {
//         return que.front();
//     }

//     bool empty() {
//         return que.empty();
//     }
// };