/*Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]*/
class RandomizedSet {
 public:
  bool insert(int val) {
    if (valToIndex.count(val))
      return false;
    valToIndex[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (!valToIndex.count(val))
      return false;
    const int index = valToIndex[val];
    // The order of the following two lines is important when vals.size() == 1.
    valToIndex[vals.back()] = index;
    valToIndex.erase(val);
    vals[index] = vals.back();
    vals.pop_back();
    return true;
  }

  int getRandom() {
    const int index = rand() % vals.size();
    return vals[index];
  }

 private:
  unordered_map<int, int> valToIndex;  // {val: index in vals}
  vector<int> vals;
};