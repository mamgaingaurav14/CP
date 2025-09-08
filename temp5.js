var pickGifts = function(gifts, k) {
    let q = new MaxPriorityQueue();
    for(let i=0;i<k;i++){
        q.enqueue(gift[i]);
    }
    while(k--){
        let val=q.dequeue().element;
        val=math.floor(math.sqrt(val));
        q.enqueue(val);
    }
    let i=0,sum=0;
    while(i<n){
      sum+=gifts[i];
    }
    return sum;
};

