 int MOD=1e9+7;
 
  long long MOD_MULTIPLY(long long a,long long b){
      return ((a%MOD)*(b%MOD))%MOD;       }

vector<int> seg_tree,vec;

 int build_tree(int idx,int left,int right){
        if(left==right) return seg_tree[idx]=vec[left];
        int mid=(left+right)/2;
        return seg_tree[idx]=MOD_MULTIPLY(build_tree(2*idx+1,left,mid),build_tree(2*idx+2,mid+1,right));
      }

      int query(int idx,int left,int right ,int ql,int qr){
        if(ql>right || qr<left) return 1;
        if (ql <= left && right <= qr) return seg_tree[idx];
        int mid=(left+right)/2;
        return MOD_MULTIPLY(query(2*idx+1,left,mid,ql,qr),query(2*idx+2,mid+1,right,ql,qr));
      }