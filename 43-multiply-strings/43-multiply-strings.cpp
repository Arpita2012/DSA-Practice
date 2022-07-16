class Solution {
public:
string multiply(string s, string r) {

    vector<string>now;
    
    if (s.size()<r.size()) swap(s,r);
    reverse(s.begin(),s.end());
    reverse(r.begin(),r.end());
    
    for(int i=0;i<r.size();++i){
        string ans;
        int carry=0;
        for(int j=0;j<s.size();++j){
            int ss=s[j]-'0';
            int rr=r[i]-'0';
            int mul=ss*rr;
            mul+=carry;
            ans+=((mul%10)+'0');
            carry=mul/10;
        }
        if (carry) ans+=(carry+'0');
        reverse(ans.begin(),ans.end());
        for(int it=0;it<i;++it){
            ans+="0";
        }
        now.push_back(ans);
    }
    
    auto summation = [&](string s,string r)->auto{
        int n1=s.size();
        int n2=r.size();

        int xx = max(n1,n2) - min(n1,n2);

        string zero;
        for(int i=0;i<xx;++i)
            zero+='0';
        if (n1<n2){
            zero+=s;
            s=zero;
        }else{
            zero+=r;
            r=zero;
        }

        string ans;
        int carry=0;
        for(int i=s.size()-1;i>=0;--i){
            int x=s[i]-'0';
            int y=r[i]-'0';
            x+=y+carry;
            if (x<=9){
                ans+=(x+'0');
                carry=0;
            }else{
                carry=1;
                x=x%10;
                ans+=(x+'0');
            }
        }
        if (carry) ans+='1';

        reverse(ans.begin(),ans.end());

        return ans;
    };
    
    string ans=now[0];
    
    for(int i=1;i<now.size();++i){
        ans= summation(ans,now[i]);
    }
    string tem;
    bool ok = false;
    for(int i=0;i<ans.size();++i){
        if (ans[i]!='0'){
            ok=true;
        }
        if (ok){
            tem+=ans[i];
        }
    }
    ans=tem;
    if (tem.size()==0) ans="0";
    
    return ans;
        
    
}
};