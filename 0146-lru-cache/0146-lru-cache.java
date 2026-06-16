class ListNode {
    int key;
    int val;
    ListNode prev;
    ListNode next;

    public ListNode(int key, int val){
        this.key = key;
        this.val = val;
    }
}

class LRUCache {
    // Doubly linkedList implementation
    int size;
    Map<Integer, ListNode> map;
    ListNode head;
    ListNode tail;

    public LRUCache(int capacity) {
        this.size = capacity;
        map = new HashMap<>();
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if(!map.containsKey(key)){
            return -1;
        }
        ListNode node = map.get(key);
        remove(node);
        add(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            ListNode toRemove = map.get(key);
            remove(toRemove);
        }
        ListNode node = new ListNode(key, value);
        map.put(key, node);
        add(node);

        if(map.size() > size){
            ListNode toRemove = head.next;
            remove(toRemove);
            map.remove(toRemove.key);
        }
    }

    public void add(ListNode node) {
        ListNode end = tail.prev;
        end.next = node;
        node.prev = end;
        node.next = tail;
        tail.prev = node;
    }

    public void remove(ListNode node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }


    // LinkedHashMap Solution : Does all on it's own, Straight-forward
    // private LinkedHashMap<Integer, Integer> map;
    // private final int CAPACITY;
    
    // public LRUCache(int capacity) {
    //     CAPACITY = capacity;
    //     map = new LinkedHashMap<Integer, Integer>(capacity, 0.75f, true){
    //         protected boolean removeEldestEntry(Map.Entry eldest) {
    //             return size() > CAPACITY;
    //         }
    //     };
    // }
    
    // public int get(int key) {
    //     return map.getOrDefault(key, -1);
    // }
    
    // public void put(int key, int value) {
    //     map.put(key, value);        
    // }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */