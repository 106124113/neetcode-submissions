class MinStack {
public:
  vector<int>arr;
        int x;
    MinStack() {
        x=-1;
    }
    
    void push(int val) {
        arr.push_back(val);
        x++;
    }
    
    void pop() {
        arr.pop_back();
        x--;
    }
    
    int top() {
        return arr[x];
    }
    
    int getMin() {
       int mini=INT_MAX;
       int a=x;
       while(a>=0){
        mini=min(mini,arr[a]);
        a--;
       } 
       return mini;
    }
};
