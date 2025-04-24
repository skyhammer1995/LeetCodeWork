class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (m_indexMap.count(val)) {
            // value exists already
            return false;
        } 
        // value didn't exist in map
        m_indexMap[val] = m_values.size();
        m_values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!m_indexMap.count(val)) {
            // value doesn't exist in the map
            return false;
        } 

        // value is present
        int index = m_indexMap[val];
        m_indexMap[m_values.back()] = index;
        m_values[index] = m_values.back();
        m_values.pop_back();
        m_indexMap.erase(val);

        return true;
    }
    
    int getRandom() {
        return m_values[rand() % m_values.size()];
    }

    // I think value inserted will act as key, and value in the pair will be number of instances
    std::unordered_map<int, int> m_indexMap;
    std::vector<int> m_values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */