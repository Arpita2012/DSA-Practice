  bool CMP (pair<int,int> const & x, pair<int,int> const & y){
        return x.first < y.first;
    }
    
class MyCalendar {
public:
    vector<pair<int,int>> C;
    MyCalendar() {
        
    }
    
  
    bool book(int start, int end) {
        
        //sort(C.begin(), C.end(), &CMP);
        
        for(auto x : C){
            
            //3 cases 
            //left crossing 
            //right crossing 
            //in the middle
            
           if((start<x.first && end <= x.first )|| (start>=x.second && end > x.second ) ){
                //do nothing
               
               
            }else{
               return false;
           }
        }
        
        C.push_back({start,end});
        return true;
        
        
        /*if(C.size()==0){
            C.push_back({start,end});
            return true;
        }
        
        int N=C.size();
        
        int i;
        for(i=0;i<N;i++){
            if(C[i].first> start)
                break;
        }*/
        
        
        
        
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */