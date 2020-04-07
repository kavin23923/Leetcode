class MyCircularDeque {
public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k) {
    front = k - 1;
    rear = 0;
    size = 0;
    total = k;
    deque.resize(k);
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value) {
    if (isFull()) return false;
    deque[front] = value;
    size++;
    front = (front - 1 + total) % total;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value) {
    if (isFull()) return false;
    deque[rear] = value;
    size++;
    rear = (rear + 1) % total;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront() {
    if (isEmpty()) return false;
    front = (front + 1) % total;
    size--;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast() {
    if (isEmpty()) return false;
    rear = (rear - 1 + total) % total;
    size--;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (isEmpty()) {
      return -1;
    } else {
      return deque[(front + 1) % total];
    }
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (isEmpty()) {
      return -1;
    } else {
      return deque[(rear - 1 + total) % total];
    }
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() {
    return size == 0;
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull() {
    return size == total;
  }

private:
  vector<int> deque;
  int front;
  int rear;
  int size;
  int total;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

/**
 * If we set the front and rear as different positions at first, then it is easier to manipulate in insert function.
 */
