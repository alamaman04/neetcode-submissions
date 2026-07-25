class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size() ;
        if(n% groupSize !=0) return false ;
        sort(hand.begin() ,hand.end());
        unordered_map<int,int> freq ;
        for(int i=0 ;i<n;i++){
            freq[hand[i]]++ ;
        }
        hand.erase(unique(hand.begin(),hand.end()),hand.end()) ;

        n = hand.size();

        int st = 0 ;
        while(st < n ){
            while(st< n && freq[hand[st]]==0) st++ ;
            if(st==n) return true ;
            freq[hand[st]] -- ;
            int r = hand[st]+1 ;
            while( r < hand[st]+groupSize){
                if(freq[r]==0) return false ;
                freq[r] -- ;
                r++ ;
            }
        }

        return true ;


      

    }
};
